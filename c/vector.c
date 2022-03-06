#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __unix__
#include <unistd.h>
#elif _WIN32
#include <io.h>
#define isatty _isatty
#define fileno _fileno
#endif

/* macros */
#define PROMPT_IN "In [%d]: "
#define PROMPT_CONT "    ...: "
#define PROMPT_OUT "Out[%d]: "

#define VEC_REALLOC_SIZE 255

/* declarations */
typedef enum { MATCHED, UNMATCHED_RIGHT, UNMATCHED_LEFT } ValidationResult;

typedef struct Cell {
  char data;
  struct Cell *left;
  struct Cell *right;
} Cell;

typedef struct {
  char *data;
  size_t size;
  size_t max_size;
} Vec;

/* utils */
static void die(const char *fmt, ...);
static void *emalloc(size_t size);
static void *erealloc(void *ptr, size_t new_size);

/* cell */
static Cell *cell_alloc(void);
static void cells_free(Cell **ptr);
static void cells_display(Cell *ptr);
static Cell *cell_left(Cell *ptr);
static Cell *cell_right(Cell *ptr);
static Cell *cell_append_left(Cell *ptr);
static Cell *cell_append_right(Cell *ptr);

/* vec */
static Vec *vec_alloc(void);
static void vec_free(Vec *vec);
static void vec_push(Vec *vec, char data);
static char vec_pop(Vec *vec);

/* io */
static int readline(Vec *input);
static int prompt(Vec *input);
static ValidationResult validate(Vec *parens, const char *str);

/* fuck */
static int execute(Cell **ptr, const char *str);

/* utils definition */
void die(const char *fmt, ...) {
  va_list ap;

  va_start(ap, fmt);
  vfprintf(stderr, fmt, ap);
  va_end(ap);

  if (fmt[0] && fmt[strlen(fmt) - 1] == ':') {
    fputc(' ', stderr);
    perror(NULL);
  } else {
    fputc('\n', stderr);
  }

  exit(1);
}

void *emalloc(size_t size) {
  void *p;

  if (!(p = malloc(size))) die("malloc:");
  return p;
}

void *erealloc(void *ptr, size_t new_size) {
  void *p;

  if (!(p = realloc(ptr, new_size))) die("realloc:");
  return p;
}

/* cell definition */
Cell *cell_alloc(void) {
  Cell *ptr;

  ptr = emalloc(sizeof(Cell));
  ptr->left = NULL;
  ptr->right = NULL;
  return ptr;
}

void cells_free(Cell **ptr) {
  Cell *tmp;

  while ((*ptr)->left != NULL) (*ptr) = (*ptr)->left;
  do {
    tmp = *ptr;
    *ptr = (*ptr)->right;
    free(tmp);
  } while (*ptr != NULL);
  *ptr = NULL;
}

void cells_display(Cell *ptr) {
  const char *fmt;
  Cell *head = ptr;
  int first = 0;

  while (ptr->left != NULL) ptr = ptr->left;
  putchar('[');
  for (; ptr != NULL; ptr = ptr->right) {
    if (!first)
      first = 1;
    else
      printf(", ");
    fmt = head == ptr ? ">%d<" : "%d";
    printf(fmt, ptr->data);
  }
  printf("]\n");
}

Cell *cell_left(Cell *ptr) {
  if (ptr->left == NULL) return cell_append_left(ptr);
  return ptr->left;
}

Cell *cell_right(Cell *ptr) {
  if (ptr->right == NULL) return cell_append_right(ptr);
  return ptr->right;
}

Cell *cell_append_left(Cell *ptr) {
  Cell *cell;

  cell = cell_alloc();
  cell->right = ptr;
  ptr->left = cell;
  return cell;
}

Cell *cell_append_right(Cell *ptr) {
  Cell *cell;

  cell = cell_alloc();
  cell->left = ptr;
  ptr->right = cell;
  return cell;
}

Vec *vec_alloc(void) {
  Vec *vec;

  vec = emalloc(sizeof(Vec));
  vec->data = NULL;
  vec->max_size = vec->size = 0;
  return vec;
}

/* vec definition */
void vec_free(Vec *vec) {
  free(vec->data);
  vec->max_size = vec->size = 0;
  vec->data = NULL;
}

void vec_push(Vec *vec, char data) {
  if (vec->size == vec->max_size) {
    vec->max_size += VEC_REALLOC_SIZE;
    vec->data = erealloc(vec->data, vec->max_size);
  }
  vec->data[vec->size++] = data;
}

char vec_pop(Vec *vec) {
  vec->size -= 1;
  if (vec->size < vec->max_size - VEC_REALLOC_SIZE) {
    vec->max_size -= VEC_REALLOC_SIZE;
    vec->data = erealloc(vec->data, vec->max_size);
  }
  return vec->data[vec->size];
}

/* io definition */
int readline(Vec *input) {
  char c;

  while ((c = getchar()) != '\n' && c != EOF) {
    if (strchr("><+-[],.", c)) vec_push(input, c);
  }
  return c == EOF;
}

int prompt(Vec *input) {
  static int count = 1;
  Vec parens = {0};
  ValidationResult vr = MATCHED;
  int offset, iseof;

  do {
  loop:
    switch (vr) {
      case UNMATCHED_RIGHT:
        fputs("error: unmatched parens\n", stderr);
        vec_free(input);
        vec_free(&parens);
      case MATCHED:
        printf(PROMPT_IN, count++);
        break;
      case UNMATCHED_LEFT:
        printf(PROMPT_CONT);
        break;
    }

    offset = input->size;
    iseof = readline(input);
    if (iseof) break;

    if (input->size == 0) goto loop;

    vr = validate(&parens, input->data + offset);
  } while (vr != MATCHED);

  vec_push(input, '\0');
  vec_free(&parens);

  return iseof;
}

ValidationResult validate(Vec *parens, const char *str) {
  int free_p = 0;
  if (parens == NULL) {
    parens = vec_alloc();
    free_p = 1;
  }

  for (; *str; str++) {
    switch (*str) {
      case '[':
        vec_push(parens, *str);
        break;
      case ']':
        if (parens->size == 0) return UNMATCHED_RIGHT;
        vec_pop(parens);
        break;
    }
  }
  if (free_p) {
    vec_free(parens);
    free(parens);
  }
  return parens->size == 0 ? MATCHED : UNMATCHED_LEFT;
}

#if 0

/* fuck */
int
execute(Cell **ptr, const char *cmd)
{
    int pc, sub_pc;

    pc = sub_pc = 0;
    for (; *cmd != '\0'; cmd++) {
        pc++;
        switch (*cmd) {
        case '>':
            *ptr = cell_right(*ptr);
            break;
        case '<':
            *ptr = cell_left(*ptr);
            break;
        case '+':
            (*ptr)->data++;
            break;
        case '-':
            (*ptr)->data--;
            break;
        case '.':
            putchar((*ptr)->data);
            break;
        case ',':
            (*ptr)->data = getchar();
            break;
        case '[':
            while ((*ptr)->data) sub_pc = execute(ptr, cmd + 1);
            cmd += sub_pc;
            pc += sub_pc;
            break;
        case ']':
            return pc;
        }
    }
    return pc;
}
#endif

int main(int argc, char *argv[]) {
  Cell *ptr;
  Vec input = {0};
  int iseof;
  int interactive;

  ptr = cell_alloc();
  interactive = isatty(fileno(stdin));

  if (interactive) {
    do {
      iseof = prompt(&input);
      if (!iseof) printf("%s\n", input.data);
      vec_free(&input);
    } while (!iseof);
  } else {
    while (!readline(&input))
      ;
    vec_push(&input, '\0');
    printf("input.data: %s\n", input.data);
  }

  vec_free(&input);
  cells_free(&ptr);
}
