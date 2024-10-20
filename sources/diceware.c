#include "includes/diceware.h"

int main(int argc, char **argv)
{
  /* First naive version of printing the help
   * Need to figure out how to embed the text file in the compiled binary
   * instead of reading it on the fly every time (and making the executable
   * dependant on location)
   * Will also need something similar for the words lists? */
  int c;
  FILE *file;
  file = fopen("sources/files/help", "r");
  if (file) {
    while ((c = getc(file)) != EOF)
      putchar(c);
    fclose(file);
  }

  return 0;
}
