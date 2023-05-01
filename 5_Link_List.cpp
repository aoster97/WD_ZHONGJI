#include <stdio.h>
#include <cstdlib>

typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

LinkList CreateList1(LinkList &L) {
    LNode *s;                                // 头节点的指针,是方便操作的
    int x;
    L = (LinkList) malloc(sizeof(LNode));    // 为头结点的指针分配一个空间,并赋值为null
    L->next = NULL;                          // L的data里面没有放任何数据
    scanf("%d", &x);
    while (x != 9999) {                      // 输入数据
        s = (LNode *) malloc(sizeof(LNode)); // 为新数据创建一个节点
        s->data = x;                         // 将新数据传给结构体的data
        s->next = L->next;                   // 让新节点的指针指向原有链表的第一个元素
        L->next = s;                         // 然后将头部节点指向新节点,s就变成了第一个元素
        scanf("%d", &x);                     // 可以多个输入,内容都在缓存区,会依次读入
    }
}

LinkList CreateList2(LinkList &L) {
    int x;
    L = (LinkList) malloc(sizeof(LNode));
    LNode *s, *r = L;
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;  //始终指向尾部的节点
        scanf("%d", &x);
    }
    r->data = NULL;
    return L;
}

void PrintList(LinkList L) {
    L = L->next;
    while (L != NULL) {
        printf("%3d", L->data);
        L = L->next;
    }
    printf("\n");
}

LNode *GetElem;


int main() {
    LinkList L1, L2;                         //链表头,是结构体的指针类型
    LinkList search;                         //用来储存拿到的某一节点
    CreateList1(L1);
    PrintList(L1);
    CreateList2(L2);
    PrintList(L2);
    return 0;
}

