#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char filename[100];
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    strcpy(filename, argv[1]);
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    printf("Enter text to be saved in the file:\n");
    char line[255];
    while (fgets(line, sizeof(line), stdin) != NULL) {
        fprintf(file, "%s", line);
    }
    fclose(file);
    printf("Text saved to %s\n", filename);
    return 0;
}
