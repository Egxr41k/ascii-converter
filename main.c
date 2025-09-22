#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
   	// check arguments count
	if(argc < 2) {
		printf("Usage: %s <file>\n", argv[0]);
		return 1;
    }

    const char *file = argv[1];
    FILE *fptr;
    char line[256]; // Buffer to hold each line

    fptr = fopen(file, "r"); // Open file in read mode

    if (fptr == NULL) {
        printf("Error opening file!\n");
        return 1; // Indicate an error
    }

    unsigned char bytes[2048];
    // Read the file bytes
    fread(bytes, 3, 1, fptr);

    if (bytes[0] == 0xff
        && bytes[1] == 0xd8
        && bytes[2] == 0xff) {
        printf("This Image is in JPEG format!\n");
    } else {
        printf("Incorrect file format!\n");
        fclose(fptr);
        return 1;
    }

    for (int i = 0; i < 2048; i++){
        printf("%x  ", bytes[i]);
    }

    fclose(fptr);
    return 0;
}
