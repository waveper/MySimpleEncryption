#include <stdio.h>
#include <stdint.h> // for uint8_t... idk, the AI recommended me this

// this is bitwise not encoder
// input output to the CLI

void to_bitwise(char* buffer, size_t size) {
  size_t length; // length and characters index
  unsigned int idx = 0;
  unsigned int charde; //characters after turn into decimal
  char output[1000]; //what??, 1000?.... yes...
  int bitwised;

  length = strlen(buffer);

  for (length) {
    charde = (int)buffer[idx];
    bitwised = ~charde

    idx++;
  }
}

int main() {
    // not working on yet
    return 0;
}
