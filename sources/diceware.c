#include "includes/diceware.h"

/* First naive version of printing the help
 * Need to figure out how to embed the text file in the compiled binary
 * instead of reading it on the fly every time (and making the executable
 * dependant on location)
 * Will also need something similar for the words lists? */
void help()
{
  int precision = sizeof(help_text)/sizeof(help_text[0]);

  printf("%.*s\n", precision, help_text);
}

int main(int argc, char **argv)
{
  help();

  return 0;
}
