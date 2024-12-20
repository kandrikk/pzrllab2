#include "header.h"

int main(int argc, char *argv[]) {
    validate_arguments(argc, argv);

    const char *filename = argv[1];

    if (strcmp(argv[2], "-r") == 0 && argc == 5) {
        replace_text(filename, argv[3], argv[4]);
    } else if (strcmp(argv[2], "-d") == 0 && argc == 4) {
        delete_matching_lines(filename, argv[3]);
    } else if (strcmp(argv[2], "-i") == 0 && argc == 5) {
        if (strcmp(argv[3], "-f") == 0) {
            insert_text(filename, argv[4], 1);
        } else if (strcmp(argv[3], "-b") == 0) {
            insert_text(filename, argv[4], 0);
        } else {
            fprintf(stderr, "Invalid flag for insertion: use -f for front or -b for back.\n");
            exit(1);
        }
    } else {
        fprintf(stderr, "Invalid arguments.\n");
        exit(1);
    }

    return 0;
}

