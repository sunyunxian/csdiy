#include <stdio.h>

int count_space_by_array(const char s[]);
int count_space_by_pointer(const char *s);

int main(void) {
    char s[] = "Hello World ";
    printf("\"%s\" count space = %d\n", s, count_space_by_array(s));

    const char *p = "Hello World ";
    printf("\"%s\" count space = %d\n", s, count_space_by_pointer(p));

    return 0;
}

int count_space_by_array(const char s[]) {
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ') {
            count++;
        }
    }
    return count;
}

int count_space_by_pointer(const char *s) {
    int count = 0;
    for (; *s != '\0'; s++) {
        if (*s == ' ') {
            count++;
        }
    }
    return count;
}
