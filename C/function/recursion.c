#include <stdint.h>
#include <stdio.h>

u_int64_t factorial(uint64_t n);
u_int64_t factorial_iterator(u_int64_t n);
u_int32_t fib(u_int32_t n);

int main(int argc, char const *argv[]) {
    uint64_t number = 5;
    printf("%lld! = %lld\n", number, factorial(number));
    printf("%lld! = %lld\n", number, factorial_iterator(number));

    uint32_t fib_number = 6;
    printf("fib number %d = %d\n", fib_number, fib(fib_number));

    return 0;
}

u_int64_t factorial(uint64_t n) {
    // 阶乘递归的方式
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

u_int64_t factorial_iterator(u_int64_t n) {
    /*
    阶乘是数学中的一个概念，通常用符号 n! 表示，表示从 1 乘到 n 的所有正整数的乘积。具体来说：

    - 0! = 1（根据定义）
    - n! = n * (n-1) * (n-2) * ... * 2 * 1（对于任何正整数 n）

    例如：
    - 5! = 5  4  3  2  1 = 120
    - 3! = 3  2  1 = 6

    */
    u_int64_t ret = 1;
    if (n == 0) {
        return ret;
    } else {
        for (n; n > 1; n--) {
            ret *= n;
        }
    }
    return ret;
}

u_int32_t fib(u_int32_t n) {
    /*
    斐波那契数列
    F(0) = 0，F(1) = 1

    F(n) = F(n - 1) + F(n - 2)，其中 n > 1

    0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 98
    */
    uint32_t first = 0, second = 1, next = 0;
    if (n <= 0) {
        return first;
    }
    if (n == 1) {
        return second;
    }
    for (uint32_t i = 2; i <= n; i++) {
        next = first + second;
        first = second;
        second = next;
    }
    return next;
}
