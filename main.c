#include <stdio.h>
#include <stdint.h> // include
#include <string.h>
#include <stdlib.h>

/*
this is bitwise not encoder
input/output to the CLI
*/

// also this code is not entirely vibe-codded

char *to_bitwise(const char *input) {
  if (!input) return NULL; // if input was something not a thing, returm null
  size_t length = strlen(input); // get length
  unsigned int charde; //characters after turn into decimal
  char *output[1000]; //what??, 1000?.... yes...

  for (size_t i = 0; i < length; ++i) {
    charde = (unsigned char)input[i];
    unsigned int bitwised = ~charde & 0xFFu; // no idea, AI reccommend me this
    snprintf(output + i * 2, 3, "%02X", bitwised); // the hell?
  }
  return output;
}

// all error are appearing for sure
int main(int argc, char *argv[]) { // input from terminal
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <text-to-encode>\n", argv[0]);
    return 1;
  }

  char *encoded = to_bitwise(argv[1]);
  if (!encoded) {
    fprintf(stderr, "Error: idk whats the cause\n");
    return 2;
  }

  printf("Output: %s\n", encoded);
  free(encoded);
  return 0;
}
