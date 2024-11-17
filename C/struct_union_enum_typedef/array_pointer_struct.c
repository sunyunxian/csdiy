#include <stdio.h>
#define ARRAY_LEN 3

struct student {
    int   id;
    int   age;
    char *name;
};

int main(int argc, char const *argv[]) {
    struct student s1[ARRAY_LEN] = {{1, 10, "a"}, {2, 20, "b"}, {3, 30, "c"}};

    for (int i = 0; i < ARRAY_LEN; i++) {
        printf("s1 id = %d, age = %d, name = %s\n", s1[i].id, s1[i].age, s1[i].name);
    }
    struct student  s2 = {4, 40, "d"};
    struct student *p = &s2;
    printf("s2 id = %d, age = %d, name = %s\n", p->id, p->age, p->name);
    printf("s2 id = %d, age = %d, name = %s\n", (*p).id, (*p).age, (*p).name);
    return 0;
}
