#include <stdio.h>
#include <stdint.h> // include
#include <string.h>
#include <stdlib.h>

/*
this is bitwise not encoder
input/output to the CLI
likely turn text into bitwise-notted hex
*/

// also this code is not entirely vibe-codded

char *to_bitwise(const char *input) {
  if (!input) return NULL; // if input was something not a thing, returm null
;
  size_t len = strlen(input); // getting length
  size_t out_len = len * 2 + 1; // getting output length

  char *output = malloc(out_len);
  if (!output) return NULL;

  for (size_t i = 0; i < len; ++i) {
    unsigned char chari = (unsigned char)input[i];
    unsigned int bitwised = (~chari) & 0xFFu; // no idea, AI reccommend me this
    
    snprintf(output + i * 2, 3, "%02X", bitwised); // the hell?
  }
  output[out_len - 1] = '\0'; // add null-terminator at the end

  return output;
}

int main(int argc, char *argv[]) { // input from terminal
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <text-to-encode>\n", argv[0]);
    return 1;
  }

  // joining the command line arguments
  int total_argc_len = 0;
  for (int i = 1; i < argc; i++) {
    total_argc_len += strlen(argv[i]) + 1; // extra space for null-terminator
  }

  printf("Total arguments: %d\n", total_argc_len); // testing

  // TODO: joining all command line arguments without user need to double quoted it

  char *encoded = to_bitwise(argv[1]);
  if (!encoded) {
    fprintf(stderr, "Error: idk whats the cause\n");
    return 2;
  }

  printf("Output: %s\n", encoded);
  free(encoded); // free() my soul /j
  return 0;
}
