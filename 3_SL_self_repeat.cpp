/*
#include <stdio.h>

#define MaxZise 50

typedef int Elemtype;

typedef struct {
    Elemtype data[MaxZise];
    int length;
} SList, *PSList;

//增
Elemtype InsertList(SList &L, int i, Elemtype e) {
    if (i < 1 || i > L.length + 1)
        return false;
    if (i >= MaxZise)
        return false;
    for (int j = L.length; i <= j; j--)
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = e;
    L.length++;
    return true;
}

//删
Elemtype DeleteList(SList &L, int i, Elemtype &e) {
    if (i < 1 || i > L.length + 1)
        return false;
    if (L.length == 0)
        return false;
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++)
        L.data[j - 1] = L.data[j];

}

//改


//查
int main() {

    return 0;
}

*/

#include <stdio.h>

#define MaxSize 50

typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int length;
} SList, *PsList;

bool InsertSList(SList &L, int i, ElemType e) {
    if (i < 1 || i > L.length + 1)
        return false;
    if (L.length >= MaxSize)
        return false;
    for (int j = L.length; i <= j; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

bool ListDelete(SList &L, int i, ElemType &e) {
    if (i < 1 || i > L.length + 1)
        return false;
    if (L.length == 0)
        return false;
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++) {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}

void SListPrint(SList &L) {
    for (int i = 0; i < L.length; ++i) {
        printf("%3d", L.data[i]);
    }
    printf("\n");
}

ElemType locateSlist(SList &L, ElemType e) {
    int i;
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] == e)
            return i + 1;
        return 0;
    }
}


int main() {

}