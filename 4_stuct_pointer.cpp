#include <stdio.h>

typedef struct student {
    int num;
    char name[10];
    int age;
} stu, *pstu;

int main() {
    stu s = {12, "aic", 31};
    pstu p = &s;
    printf("num : %d , name : %s , age : %d\n", p->num, p->name, p->age);
    printf("%d\n", sizeof(stu));
    stu *st = &s;
    printf("num : %d , name : %s , age : %d\n", st->num, st->name, st->age);

    return 0;
}

