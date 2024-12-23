class Selection:

    def sort(self, list: list):
        length: int = len(list)
        for i in range(length):
            min: int = i
            for j in range(i, length):
                if self.less(list, j, min):
                    min = j
            self.exch(list, i, min)

    def less(self, list: list, i: int, j: int) -> bool:
        return list[i] < list[j]

    def exch(self, list: list, i: int, j: int) -> None:
        list[i], list[j] = list[j], list[i]

    def show(self, list: list) -> None:
        for i in list:
            print(i)

    def _main(self):
        test_list = [1, 3, 2, 10, 8, 7, 20, 1]
        self.sort(test_list)
        self.show(test_list)


if __name__ == "__main__":
    Selection()._main()
