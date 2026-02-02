#include <stdio.h>
#include <stdint.h> // for uint8_t... idk, the AI recommended me this
#include <string.h>

// this is bitwise not encoder
// input output to the CLI

void to_bitwise(char* buffer, size_t size) {
  size_t length = strlen(buffer); // get length
  unsigned int charde; //characters after turn into decimal
  char output[1000]; //what??, 1000?.... yes...
  int bitwised;
  char hexed[3]; // for null-terminator

  for (size_t idx = 0; idx < length; idx++) {
    charde = (int)buffer[idx];
    bitwised = ~charde;
    sprintf(hexed, "%02X", bitwised); // convert into hex
    strcat(output, hexed);
  }
}

// all error are appearing for sure
int main(void) {
    // testing
    char out = to_bitwise("hello?");
    printf("Output: %d\n", out);
    return 0;
}
