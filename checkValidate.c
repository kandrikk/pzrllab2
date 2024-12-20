#include "header.h"

void validate_arguments(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Error: Insufficient arguments provided.\n");
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Error: Cannot open file %s\n", argv[1]);
        exit(1);
    }
    fclose(file);
}