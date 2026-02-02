#include "includes/diceware.h"

/* Print the help from the embedded byte array */
void help()
{
  int precision = sizeof(help_text)/sizeof(help_text[0]);

  printf("%.*s\n", precision, help_text);
}

/* Roll [dice] d6 */
int roll(int dice)
{
  int i, x = 0;
  int result = 0;

  if (dice <= 0 || dice > MAX) return result;

  /* Seed rand */
  srand(time(NULL));

  /* Roll dice and concatenate */
  for (i = 0; i < dice; i++)
  {
    x = 1 + rand()/((RAND_MAX + 1u)/6);
    result += (pow(10, i) * x);
  }

  return result;
}

int main(int argc, char **argv)
{
  if (argc == 1) {
    help();
    return 0;
  }

  if(!strcmp(argv[1], "roll")) {
    printf("Generated %06d\n\n", roll(6));
  } else {
    help();
  }

  return 0;
}
