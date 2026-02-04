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

char *decode_to_text(const char *input) {
  // TODO: implement the decoder
  return NULL;
}

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

  // started working on parsing option flags
  bool decode_mode = false;
  int join_start = 1; // this is where the joining started

  if (argc >= 2) {
    if (strcmp(argv[1], "-d" == 0 || strcmp(argv[1], "--decode") == 0)) {
      decode_mode = true;
      join_start = 2;
    }
  }

  // TODO: have an fully functioning special argument like "-d" or "--decode" after i finished decoding function

  // joining the command line arguments
  int total_chars = 0;
  for (int i = 1; i < argc; i++) {
    total_chars += strlen(argv[i]);
  }

  size_t spaces = (argc > 2) ? (size_t)(argc - 2) : 0; // spaces between arguments
  size_t total_argc_len =  total_chars + spaces + 1; // extras space for null-terminator
  
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
    *p = '\0'; // add null-terminator

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
