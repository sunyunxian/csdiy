def sort(list: list[int]):
    length: int = len(list)
    for i in range(1, length):
        j = i
        while j > 0:
            if less(list, j, j - 1):
                exch(list, j, j - 1)
            j -= 1


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
