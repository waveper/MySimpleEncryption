#include <stdio.h>
#include <stdint.h> // for uint8_t... idk, the AI recommended me this
#include <string.h>

// this is bitwise not encoder
// input output to the CLI

char decimal_to_hex(int decimal_digit) { //convert single digit decimal to hex
  if (decimal_digit >= 0 && decimal_digit <= 9) {
    return (char)(decimal_digit + '0');
  } else if (decimal_digit >= 10 && decimal_digit <= 15) {
    // 'A' is ASCII 65. 10 maps to 'A', 11 to 'B', etc.
    return (char)(decimal_digit - 10 + 'A');
  } else {
    // Handle invalid input
    return '?'; 
  }
}

void to_bitwise(char* buffer, size_t size) {
  size_t length = strlen(buffer); // get length
  unsigned int charde; //characters after turn into decimal
  char output[1000]; //what??, 1000?.... yes...
  int bitwised;
  char hexed[1000];

  for (size_t idx = 0; idx < length; idx++) {
    charde = (int)buffer[idx];
    bitwised = ~charde;
    hexed = decimal_to_hex(bitwised);
    strcat(output, hexed);
    idx++;
  }
}

// all error are appearing for sure
int main(void) {
    // testing
    char out = to_bitwise("hello?");
    printf("Output: %d\n", out);
    return 0;
}
