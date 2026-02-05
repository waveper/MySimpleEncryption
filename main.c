#include <stdio.h>
#include <stdint.h> // include
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*
this is bitwise-not encoder(decoder later)
it's not really a secure encryption function, but i will combine XOR encrytion for more security
input/output to the CLI
likely turn text into bitwise-notted hex
*/

// also this code is not entirely vibe-codded

static int hex_value(unsigned char c) {
  if (c >= '0' && c <= '9') return (int)(c - '0');
  if (c >= 'a' && c <= 'f') return (int)(c - 'a') + 10;
  if (c >= 'A' && c <= 'F') return (int)(c - 'A') + 10;
  return -1;
}

char *decode_to_text(const char *input) {
  if (!input) return NULL;

  size_t hex_count = 0;
  for (const unsigned char *p = (const unsigned char *)input; *p; ++p) {
    if (*p == ' ') continue;
    if (hex_value(*p) < 0) return NULL;
    hex_count++;
  }

  if (hex_count % 2 != 0) return NULL;
  size_t out_len = hex_count / 2;
  char *output = malloc(out_len + 1);
  if (!output) return NULL;

  size_t out_i = 0;
  int high = -1;
  for (const unsigned char *p = (const unsigned char *)input; *p; ++p) {
    if (*p == ' ') continue;
    int v = hex_value(*p);
    if (v < 0) {
      free(output);
      return NULL;
    }
    if (high < 0) {
      high = v;
    } else {
      unsigned char byte = (unsigned char)((high << 4) | v);
      unsigned char decoded = (unsigned char)((~byte) & 0xFFu);
      output[out_i++] = (char)decoded;
      high = -1;
    }
  }

  output[out_i] = '\0';
  return output;
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
    fprintf(stderr, "-d or --decode   decoding bitwised-not hex back to text(double hex, support spaces)\n");
    return 1;
  }

  // started working on parsing option flags
  bool decode_mode = false;
  int join_start = 1; // this is where the joining started

  if (argc >= 2) {
    if (strcmp(argv[1], "-d") == 0 || strcmp(argv[1], "--decode") == 0) {
      decode_mode = true;
      join_start = 2;
      if (argc < 3) {
        fprintf(stderr, "Error: no input to decode\n");
        return 1;
      }
    }
  }

  // TODO: have an fully functioning special argument like "-d" or "--decode" after i finished decoding function

  // joining the command line arguments
  int total_chars = 0;
  for (int i = join_start; i < argc; i++) {
    total_chars += (int)strlen(argv[i]);
  }

  size_t spaces = (argc - join_start > 1) ? (size_t)(argc - join_start - 1) : 0; // spaces between arguments
  size_t total_argc_len =  (size_t)total_chars + spaces + 1; // extras space for null-terminator
  
  char *joined_argc = malloc(total_argc_len);
  if (!joined_argc) {
    fprintf(stderr, "Error: failed join arguments malloc\n"); // finally, a reason ful error
    return 2;
  }

  char *p = joined_argc;
  for (int i = join_start; i < argc; i++) {
    size_t l = strlen(argv[i]);
    memcpy(p, argv[i], l);
    p += l;
    if (i < argc - 1) {
      *p++ = ' ';
    }
  }
    *p = '\0'; // add null-terminator

  char *result = NULL;
  if (decode_mode) {
    result = decode_to_text(joined_argc);
  } else {
    result = to_bitwise_hex(joined_argc);
  }
  if (!result) {
    fprintf(stderr, "Error: invalid input or failed allocation\n");
    free(joined_argc);
    return 2;
  }

  printf("Output: %s\n", result);

  free(result); // free() my soul /j
  free(joined_argc);
  return 0;
}
