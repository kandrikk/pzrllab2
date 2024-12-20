#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define MAX_LINE_LENGTH 1024

void replace_text(const char *filename, const char *old_text, const char *new_text);
void delete_matching_lines(const char *filename, const char *pattern);
void insert_text(const char *filename, const char *insert_text, int front);
void validate_arguments(int argc, char *argv[]);


#endif //HEADER_H