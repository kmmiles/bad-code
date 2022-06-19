void print_usage(char *prog_name) {
  const char *pn = prog_name ? prog_name : "labeller-cli";
  fprintf(stderr, "Usage: %s \n");
  fprintf(stderr, "\t%s infile:FILE1 outfile:FILE2\n", pn);
  fprintf(stderr, "\t%s iofile:FILE\n", pn);
  exit(EXIT_FAILURE);
}
