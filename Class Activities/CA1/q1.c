#include<stdio.h>

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int main() {
    int a = 11;
    int b = 1;
    int n;
    printf("Hello");
    printf("a before swap:%d b before swap:%d\n", a, b);
    swap(&a, &b);
    printf("a after swap:%d b after swap:%d\n", a, b);
}