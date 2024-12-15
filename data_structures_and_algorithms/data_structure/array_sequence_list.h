/*
使用 array 实现顺序表，也就是 arrayList
也可以叫 SequenceList

线性表连续春初空间可以使用静态的数组实现，也可以使用动态内存实现

静态数组：char data[100];
动态：char *data = (char *)malloc(N * sizeof(char))
*/

typedef char elements;

typedef struct {
    elements *array;       // 动态空间的起始地址，指向了动态申请的堆内存
    int       capacity;    // 动态空间的可以容纳的元素个数，也就是容量
    int       length;      // 实际元素个数，也就是长度
} ArraySequenceList;

// 初始化传入的数据，并且给出初始化的大小
int  init(ArraySequenceList *array_sequence_list, int capacity);

int  destroy(ArraySequenceList *array_sequence_list); // 销毁
void print(ArraySequenceList array_sequence_list); // 打印
int  length(ArraySequenceList array_sequence_list); // 长度
int  append(ArraySequenceList *array_sequence_list, elements element); // 尾部添加
int  set(ArraySequenceList *array_sequence_list, int index, elements element); // 根据索引设置值
char get(ArraySequenceList array_sequence_list, int index); // 根据索引获取值
int  clear(ArraySequenceList *array_sequence_list); // 清除所有数据
int  is_empty(ArraySequenceList array_sequence_list); // 是否为空
int  insert(ArraySequenceList *array_sequence_list, int index, elements element);   // 插入值
int  delete(ArraySequenceList *array_sequence_list, int index);// 删除值
int find(ArraySequenceList array_sequence_list, elements element); // 查找值
