/*
Лабораторная работа 1
Задание 3
Программа, которая меняет местами значения двух переменных
*/

#include <iostream>
#include <windows.h>

using namespace std;

// Функция принимающая значения напрямую (не производит замены, т.к. работает с копиями значений)
void swap1(int a, int b) {
    int temp;
    a = b;
    b = temp;
}

// Функция принимающая указатели на переменные
void swap2(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Функция принимающая ссылки на переменные
void swap3(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    SetConsoleOutputCP(CP_UTF8); // Для нормального отображения русского языка в консоли

    int a = 2;
    int b = 5;
    cout << "до обмена:    a = " << a << ", b = " << b << endl;
    swap1(a, b);
    cout << "после обмена: a = " << a << ", b = " << b << endl << endl;

    cout << "до обмена:    a = " << a << ", b = " << b << endl;
    swap2(&a, &b);
    cout << "после обмена: a = " << a << ", b = " << b << endl << endl;

    cout << "до обмена:    a = " << a << ", b = " << b << endl;
    swap3(a, b);
    cout << "после обмена: a = " << a << ", b = " << b << endl;
}