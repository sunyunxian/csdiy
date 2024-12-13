#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add_string(char ***str_ary, int *size, char *str);
void printf_string(char **str_ary, int size);

int main(int argc, char const *argv[]) {
    char **str_array = NULL;
    int    size = 0;

    add_string(&str_array, &size, "hello");
    add_string(&str_array, &size, "word");

    printf_string(str_array, size);

    for (size_t i = 0; i < size; i++) {
        free(str_array[i]);
    }

    printf_string(str_array, size);

    return 0;
}

void add_string(char ***str_ary, int *size, char *str) {
    char **temp = realloc(*str_ary, (*size + 1) * sizeof(char *));

    if (!temp) {
        printf("realloc failed\n");
        exit(EXIT_FAILURE);
    }
    *str_ary = temp;
    (*str_ary)[*size] = malloc(strlen(str) + 1);
    strcpy((*str_ary)[*size], str);
    ++*size;
}

void printf_string(char **str_ary, int size) {
    for (size_t i = 0; i < size; i++) {
        printf("%s\n", str_ary[i]);
    }
}
