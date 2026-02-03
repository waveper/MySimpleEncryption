#include <stdio.h>
#include <stdint.h> // for uint8_t... idk, the AI recommended me this
#include <string.h>

/*
this is bitwise not encoder
input/output to the CLI
*/

char *to_bitwise(char* buffer, size_t size) {
  size_t length = strlen(buffer); // get length
  unsigned int charde; //characters after turn into decimal
  char output[1000]; //what??, 1000?.... yes...
  unsigned int bitwised;
  char hexed[3]; // for null-terminator

  for (size_t i = 0; i < length; ++i) {
    charde = (int)buffer[i];
    bitwised = ~charde;
    sprintf(hexed, "%02X", bitwised); // convert into hex
    strcat(output, hexed);
  }
  return output;
}

// all error are appearing for sure
int main(int argc, char *argv[]) { // input from terminal
    char *encoded = to_bitwise(argv[1]);
    printf("Output: %s\n", encoded);
    return 0;
}
