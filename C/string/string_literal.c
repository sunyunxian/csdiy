#include <stdio.h>

void string_escape(void);
void string_splicing(void);
void string_index(void);
char digit_to_hex_char(int digit);

int main(void) {
    string_escape();

    string_splicing();

    string_index();

    int i = 10;
    printf("%d = %c\n", i, digit_to_hex_char(i));

    return 0;
}

void string_escape(void) {
    printf("String escape\n");

    const char *string_escape = "Candy\nIs dandy\nBut liquor\nIs quicker.\n  --Ogden Nash\n";

    printf("%s\n", string_escape);
}

void string_splicing(void) {
    printf("String splicing\n");
    printf(
        "When you come to a fork in the road, take it.   \
    --Yogi Berra\n");
    printf(
        "When you come to a fork in the road, take it. "
        "--Yogi Berra\n");
    printf(
        "When you come to a fork in the road, take it.   "
        "--Yogi Berra");
}

void string_index(void) {
    printf("String index\n");

    char *p;
    p = "abc";
    printf("%s\n", p);

    char c;
    c = "abc"[1];
    printf("%c\n", c);
}

char digit_to_hex_char(int digit) { return "0123456789ABCDEF"[digit]; }
