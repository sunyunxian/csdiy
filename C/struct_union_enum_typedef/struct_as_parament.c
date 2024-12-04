#include <stdio.h>

typedef struct point {
    int x;
    int y;
} point;

void pass_struct(struct point p);
void pass_struct_pointer(struct point *p);

int main(int argc, char const *argv[]) {
    // 值传递不会修改原有数据
    point p1 = {1, 2};
    pass_struct(p1);
    printf("p1 x = %d\n", p1.x);

    // 指针传递会修改原有数据
    point p2 = {3, 4};
    pass_struct_pointer(&p2);
    printf("p2 x = %d\n", p2.x);

    return 0;
}

void pass_struct(point p) { p.x = 0; }
void pass_struct_pointer(point *p) { p->x = 0; }
