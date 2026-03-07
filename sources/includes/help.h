#ifndef __HELP_H__
#define __HELP_H__

#include <stdio.h>
#include "help_text.h"

/* Declaration - print the help from the embedded byte array */
void help();

/* Body - print the help from the embedded byte array */
void help()
{
  int precision = sizeof(help_text)/sizeof(help_text[0]);

  printf("%.*s\n", precision, help_text);
}

#endif
