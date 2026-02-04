#include <stdio.h>
#include <stdint.h> // include
#include <string.h>
#include <stdlib.h>

/*
this is bitwise-not encoder(decoder later)
it's not really a secure encryption function, but i will combine XOR encrytion for more security
input/output to the CLI
likely turn text into bitwise-notted hex
*/

// also this code is not entirely vibe-codded

// TODO: add the decoder

char *to_bitwise_hex(const char *input) {
  if (!input) return NULL; // if input was something not a thing, returm null

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
    fprintf(stderr, "Usage: %s <options> <text-to-encode>\n", argv[0]);
    fprintf(stderr, "-d or --decode   decoding bitwised-not hex to text\n");
    return 1;
  }

  // TODO: have an special argument like "-d" or "--decode" after i finished decoding function

  // joining the command line arguments
  int total_argc_len = 0;
  for (int i = 1; i < argc; i++) {
    total_argc_len += strlen(argv[i]) + 1; // extra space for null-terminator
  }
  
  char *joined_argc = malloc(total_argc_len);
  if (!joined_argc) {
    fprintf(stderr, "Error: failed join arguments malloc\n"); // finally, a reason ful error
    return 2;
  }

  char *p = joined_argc;
  for (int i = 1; i < argc; i++) {
    size_t l = strlen(argv[i]);
    memcpy(p, argv[i], l);
    p += l;
    if (i < argc - 1) {
      *p++ = ' ';
    }
  }

  char *encoded = to_bitwise_hex(joined_argc);
  if (!encoded) {
    fprintf(stderr, "Error: idk whats the cause\n");
    free(joined_argc);
    return 2;
  }

  printf("Output: %s\n", encoded);

  free(encoded); // free() my soul /j
  free(joined_argc);
  return 0;
}
