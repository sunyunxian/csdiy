"""
数组实现顺序表
"""

from typing import Any


class ArraySequenceList:
    def __init__(self, capacity: int) -> None:
        self.capacity: int = capacity
        self.data: list = [None] * self.capacity
        self._length: int = 0

    def length(self) -> int:
        return self._length

    def clear(self) -> None:
        self._length = 0

    def is_empty(self) -> bool:
        return self._length == 0

    def get(self, i) -> Any:
        if i < 0 or i > self._length - 1:
            raise Exception("第 i 个元素不存在")
        return self.data[i]

    def insert(self, i: int, element: Any) -> None:

        for j in range(self._length, i - 1, -1):
            self.data[j] = self.data[j - 1]
        self.data[i] = element
        self._length += 1

    def remove(self, i: int) -> None:
        for j in range(i, self._length):
            self.data[j] = self.data[j + 1]
        self._length -= 1

    def index(self, x):
        pass

    def display(self) -> None:
        for i in range(self._length):
            print(self.data[i], end=" ")
        print()


if __name__ == "__main__":
    array_sequence_list = ArraySequenceList(capacity=10)
    array_sequence_list.insert(0, 0)
    array_sequence_list.insert(1, 10)
    array_sequence_list.insert(2, 20)
    print(array_sequence_list.length())
    array_sequence_list.display()
