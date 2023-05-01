#include <stdio.h>

#define MaxSize 50 //define 不需要分号
typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];//定义的数组,用来存元素
    int length;//当前顺序表中有多少个元素
} SqList;

bool ListInsert(SqList &L, int i, ElemType e);

void PrintList(SqList &L);

bool ListDelete(SqList &L, int i, ElemType &e);

ElemType LocateElem(SqList &L, ElemType e);


//动态分配
int main() {
    SqList L;
    bool ret;
    ElemType del;
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.length = 3;
    ret = ListInsert(L, 2, 60);
    if (ret) {
        printf("插入成功\n");
        PrintList(L);
    } else {
        printf("插入失败\n");
    }

    ret = ListDelete(L, 1, del);
    if (ret) {
        printf("打印成功\n");
        printf("删除元素的值为%d\n", del);
        PrintList(L);
    } else {
        printf("删除失败\n");
    }

    ElemType Elem_pos;
    Elem_pos = LocateElem(L, 60);
    if (Elem_pos) {
        printf("查找成功\n");
        printf("元素的位置:%d\n", Elem_pos);
    } else {
        printf("查找失败\n");
    }
    return 0;
}

bool ListInsert(SqList &L, int i, ElemType e) {
    //检查插入位置是否合法
    if (i < 1 || i > L.length + 1)
        return false;
    if (L.length >= MaxSize)
        return false;
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;

}

void PrintList(SqList &L) {
    for (int i = 0; i < L.length; i++) {
        printf("%3d", L.data[i]);
    }
    printf("\n");
}

bool ListDelete(SqList &L, int i, ElemType &e) {
    if (i < 1 || i > L.length + 1)
        return false;
    if (L.length == 0)
        return false;
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++)
        L.data[j - 1] = L.data[j];
    L.length--;
    return true;
}

ElemType LocateElem(SqList &L, ElemType e) {
    int i;
    for (i = 0; i < L.length; i++) {
        if (L.data[i] == e)
            return i + 1; //加1就是元素在顺序表中的位置
        return 0;
    }
}
