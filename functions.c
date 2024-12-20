#include "header.h"

void replace_text(const char *filename, const char *old_text, const char *new_text) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    char *buffer = malloc(MAX_LINE_LENGTH * sizeof(char));
    if (!buffer) {
        perror("Error allocating memory");
        fclose(file);
        exit(1);
    }
    buffer[0] = '\0';

    while (fgets(line, sizeof(line), file)) {
        char *pos;
        while ((pos = strstr(line, old_text)) != NULL) {
            strncat(buffer, line, pos - line);
            strcat(buffer, new_text);
            strcpy(line, pos + strlen(old_text));
        }
        strcat(buffer, line);
    }

    fclose(file);

    file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file for writing");
        free(buffer);
        exit(1);
    }

    fputs(buffer, file);

    free(buffer);
    fclose(file);
}

void delete_matching_lines(const char *filename, const char *pattern) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }

    regex_t regex;
    if (regcomp(&regex, pattern, REG_EXTENDED) != 0) {
        fprintf(stderr, "Invalid regular expression\n");
        fclose(file);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    char *buffer = malloc(MAX_LINE_LENGTH * sizeof(char));
    if (!buffer) {
        perror("Error allocating memory");
        regfree(&regex);
        fclose(file);
        exit(1);
    }
    buffer[0] = '\0';

    while (fgets(line, sizeof(line), file)) {
        if (regexec(&regex, line, 0, NULL, 0) != 0) {
            strcat(buffer, line);
        }
    }

    regfree(&regex);
    fclose(file);

    file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file for writing");
        free(buffer);
        exit(1);
    }

    fputs(buffer, file);

    free(buffer);
    fclose(file);
}

void insert_text(const char *filename, const char *insert_text, int front) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    char *buffer = malloc(MAX_LINE_LENGTH * sizeof(char));
    if (!buffer) {
        perror("Error allocating memory");
        fclose(file);
        exit(1);
    }
    buffer[0] = '\0';

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0'; // Remove newline character
        if (front) {
            strcat(buffer, insert_text);
            strcat(buffer, line);
        } else {
            strcat(buffer, line);
            strcat(buffer, insert_text);
        }
        strcat(buffer, "\n");
    }

    fclose(file);

    file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file for writing");
        free(buffer);
        exit(1);
    }

    fputs(buffer, file);

    free(buffer);
    fclose(file);
}
