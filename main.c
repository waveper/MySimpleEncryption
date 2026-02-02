#include <stdio.h>
#include <stdint.h> // Recommended for fixed-width types like uint8_t

int main() {
    // Using an unsigned fixed-width integer type is crucial 
    // to avoid issues with signed integers and two's complement representation.
    uint8_t original_data = 5; // Binary: 00000101
    uint8_t encoded_data;
    uint8_t decoded_data;

    // Encoding (Bitwise NOT operation)
    encoded_data = ~original_data; // Binary: 11111010
    // We cast to uint8_t because the result of the ~ operator is automatically promoted to an int.
    encoded_data = (uint8_t)~original_data; 

    // Decoding (Applying the same Bitwise NOT operation reverses the process)
    decoded_data = (uint8_t)~encoded_data; // Binary: 00000101

    printf("Original data: %u\n", original_data);
    printf("Encoded data: %u\n", encoded_data);
    printf("Decoded data: %u\n", decoded_data);

    return 0;
}