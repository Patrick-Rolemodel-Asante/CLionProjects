#include "main.h"

int main() {
    unsigned int n = 10;
    unsignedIntToBinary(&n);
    printf("\n");
    unsignedIntToHex(&n);
    printf("\n");
    unsignedIntToOct(&n);
    printf("\n");
    unsignedToSigned(n);
    printf("\n");
    specialS("Best\\nSchool");
    return 0;
}
