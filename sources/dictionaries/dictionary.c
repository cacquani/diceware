#include "dictionary.h"

char* roll()
{
  return roll(6, 0);
}

char* roll(int words)
{
  return roll(words, 0);
}

char* roll(int words, int dict)
{
  /* words: number of words to generate
   * dict:  dictionary to use, defaults to mixed
   *
   * Future developments: add alphabet, to generate passwords from a mix of
   * dictionaries but be able to narrow down to one alphabet.
   * */
  switch(dict) {
    case 1:
      printf "English dict";
      break;
    case 2:
      printf "Italian dict";
      break;
    case 3:
      printf "French dict";
      break;
    case 4:
      printf "Spanish dict";
      break;
    case 5:
      printf "German dict";
      break;
    default:
      printf "Mixed dictionaries";
      break;
  }

  return "Hello!";
}
