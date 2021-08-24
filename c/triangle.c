#include <criterion/criterion.h>

extern char triangle(const char *clrs);

static void assert_data(const char *clrs, char expected)
{
    char actual[2] = { 0 };
    *actual = triangle(clrs);
    if (*actual != expected)
        cr_assert_fail("*Actual*: %s\nExpected: %c\n  Colors: %s\n",
            *actual ? actual : "\\0", expected, clrs);
    else
        cr_assert(1);

}


Test(Sample_Test, should_return_the_color)
{
    assert_data("GB", 'R');
    assert_data("RRR", 'R');
    assert_data("RGBG", 'B');
    assert_data("RBRGBRB", 'G');
    assert_data("RBRGBRBGGRRRBGBBBGG", 'G');
    assert_data("B", 'B');
}

char triangle(const char *clrs)
{
  int i, cur_len = strlen(clrs);
  char dynamic[30];

  if (cur_len == 1)
    return clrs[0];
  
  strcpy(dynamic, clrs);
  

  for (; cur_len > 1; cur_len = i - 1)
  {
    for (i = 0; dynamic[i]; i++)
    {
      if (dynamic[i] == dynamic[i + 1])   // "RR" "GG" "BB"
        continue;

      switch (dynamic[i])
      {
        case 'R': dynamic[i] = (dynamic[i+1] == 'G') ? 'B': 'G'; break;
        case 'G': dynamic[i] = (dynamic[i+1] == 'R') ? 'B': 'R'; break;
        case 'B': dynamic[i] = (dynamic[i+1] == 'G') ? 'R': 'G'; break;
      }
    }
    dynamic[i - 1] = '\0';
  }

  return dynamic[0];

}





