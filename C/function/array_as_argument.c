#include <stdio.h>

/*
数组作为函数的参数
一维数组作为参数
func(int arr[]) = func(int *arr)

二维数组作为参数
func(int arr[][4]) = func(int (*arr)[4])

*/
#define ROWS     3
#define COLS     4
#define MAX_NAME 50

typedef struct {
    char name[MAX_NAME];
    int  age;
} Person;

// static 静态声明，限定了作用域只在本文件
static void print_2d_array(int rows, int cols, int arr[][COLS]);
static void modify_person_array(Person *person, size_t size);

void call_func();
void func_array(int array[], int length);
void func_array_ptr(int *array, int length);

int main(int argc, char const *argv[]) {
    call_func();

    int matrix[ROWS][COLS] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    printf("2D Array:\n");
    print_2d_array(ROWS, COLS, matrix);

    Person person[] = {{"a", 1}, {"b", 3}, {"c", 5}};
    size_t size_person = sizeof(person) / sizeof(person[0]);
    printf("Before modification:\n");
    for (size_t i = 0; i < size_person; i++) {
        printf("%s: %d\n", person[i].name, person[i].age);
    }

    modify_person_array(person, size_person);
    printf("After modification:\n");
    for (size_t i = 0; i < size_person; i++) {
        printf("%s: %d\n", person[i].name, person[i].age);
    }

    return 0;
}

void call_func() {
    int array[] = {1, 3, 5};
    int array_length = sizeof(array) / sizeof(array[0]);
    int array_element_size = sizeof(int);
    func_array(array, array_length);
    func_array_ptr(array, array_length);
}

void func_array(int array[], int length) {
    for (size_t i = 0; i < length; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }
    printf("\n");
}
void func_array_ptr(int *array, int length) {
    for (size_t i = 0; i < length; i++) {
        printf("*(array+%d) = %d\n", i, *(array + i));
    }
    printf("\n");

    for (size_t i = 0; i < length; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }
    printf("\n");
}

void print_2d_array(int rows, int cols, int arr[][COLS]) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            printf("arr[%d][%d] = %d\n", i, j, arr[i][j]);
        }
    }
}

static void modify_person_array(Person *person, size_t size) {
    for (size_t i = 0; i < size; i++) {
        person[i].age += 1;
    }
}
