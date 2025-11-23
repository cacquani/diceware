#include "text_to_array.h"

int main(int argc, char **argv)
{
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <input_file> <array_name> [<output_file>]\n", argv[0]);
    return 1;
  }

  FILE *infile;
  infile = fopen(argv[1], "rb");
  if (!infile) {
    perror("Error opening input file");
    return 1;
  }

  fseek(infile, 0, SEEK_END);
  long size = ftell(infile);
  rewind(infile);

  unsigned char *buffer = malloc(size);
  if (!buffer) {
    fclose(infile);
    perror("Unable to allocate buffer");
    return 1;
  }

  fread(buffer, 1, size, infile);
  fclose(infile);

  long i;

  if (argc == 3) {
    printf("const unsigned char %s[%lu] = {\n", argv[2], size);
    for (i = 0; i < size; i++) {
      printf("0x%02x,%s", buffer[i], (i + 1) % 16 == 0 ? "\n" : " ");
    }
    printf("\n};\n");
  } else if (argc == 4) {
    FILE *outfile;
    outfile = fopen(argv[3], "w");
    if (!outfile) {
      perror("Error opening output file");
      return 1;
    }

    fprintf(outfile, "const unsigned char %s[%lu] = {\n", argv[2], size);
    for (i = 0; i < size; i++) {
      fprintf(outfile, "0x%02x,%s", buffer[i], (i + 1) % 16 == 0 ? "\n" : " ");
    }
    fprintf(outfile, "\n};\n");

    fclose(outfile);
  }

  free(buffer);
  return 0;
}
