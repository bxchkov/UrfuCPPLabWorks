/*
Лабораторная работа 1
Задание 2
Программа, иллюстрирующая разные операции с указателями
*/

#define PR(x) printf("x=%u, *x=%d, &x=%u\n", x, *x, &x)

#include <iostream>

int main() {
    int mas[] = {100, 200, 300};
    int *ptr1 = mas;
    int *ptr2 = &mas[2];
    PR(ptr1);
    ptr1++;
    PR(ptr1);
    PR(ptr2);
    ++ptr2;
    printf("ptr2-ptr1=%u\n\n", ptr2 - ptr1);

    char str[] = "Hello";
    char *ptr3 = str;
    char *ptr4 = &str[4];
    PR(ptr3);
    ptr3++;
    PR(ptr3);
    PR(ptr4);
    ++ptr4;
    printf("ptr4-ptr3=%u\n\n", ptr4 - ptr3);

    double arr[] = {1.2, 3.4, 5.6};
    double *ptr5 = arr;
    double *ptr6 = &arr[2];
    PR(ptr5);
    ptr5++;
    PR(ptr5);
    PR(ptr6);
    ++ptr6;
    printf("ptr6-ptr5=%u\n\n", ptr6 - ptr5);
}