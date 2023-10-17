#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
	printf("Usage: %s <filename>\n", argv[0]);
	return 1;
    }

    FILE *file = fopen(argv[1], "r+");
    if (file == NULL) {
	printf("Error: Could not open file '%s'\n", argv[1]);
	return 1;
    }

    int ch, spacesReplaced = 0;
    int leadingSpaces = 0;
    int isLineStart = 1;  // Flag to identify the start of a line

    while ((ch = fgetc(file)) != EOF) {
	if (ch == ' ' && isLineStart) {
	    leadingSpaces++;
	} else {
	    if (leadingSpaces > 0) {
		// Replace leading spaces with tabs
		int tabsToInsert = leadingSpaces / 4;  // Each tab replaces 4 spaces
		int spacesLeft = leadingSpaces % 4;
		for (int i = 0; i < tabsToInsert; i++) {
		    fputc('\t', file);
		    spacesReplaced += 4;
		}
		for (int i = 0; i < spacesLeft; i++) {
		    fputc(' ', file);
		    spacesReplaced++;
		}
		leadingSpaces = 0;
	    }
	    fputc(ch, file);

	    if (ch == '\n') {
		isLineStart = 1;  // Next line is a new line
	    } else {
		isLineStart = 0;  // Still within the same line
	    }
	}
    }

    fclose(file);

    printf("Spaces replaced with tabs: %d\n", spacesReplaced);

    return 0;
}
