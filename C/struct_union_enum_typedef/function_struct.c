#include <stdio.h>

struct point {
    int x;
    int y;
};

void pass_struct(struct point p);
void pass_struct_pointer(struct point *p);

int main(int argc, char const *argv[]) {
    struct point p1 = {1, 2};
    pass_struct(p1);
    printf("p1 x = %d\n", p1.x);
    struct point p2 = {3, 4};
    pass_struct_pointer(&p2);
    printf("p2 x = %d\n", p2.x);
    return 0;
}
void pass_struct(struct point p) { p.x = 0; }
void pass_struct_pointer(struct point *p) { p->x = 0; }
