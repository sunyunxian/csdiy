def sort(list: list[int]):
    length: int = len(list)
    # 算法是除以 2
    gap: int = length // 2

    while gap > 0:
        for i in range(gap, length):
            j = i
            while j >= gap and less(list, j, j - gap):
                exch(list, j, j - gap)
                j -= gap
        gap //= 2


def less(list: list, i: int, j: int) -> bool:
    # i,j  都是索引
    return list[i] < list[j]


def exch(list: list, i: int, j: int) -> None:
    # i,j 都是索引
    list[i], list[j] = list[j], list[i]


if __name__ == "__main__":
    a: list = [9, 7, 1, 2, 6, 5, 3, 10, 4]
    print(a)
    sort(a)
    print(a)
