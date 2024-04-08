/*
Лабораторная работа 3
Задание 2
Программа сортировки методом пузырька
*/

#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8); // Для нормального отображения русского языка в консоли

    int arr[] = {-2, 5, -8, 1, -10, 2, 11, 0, 4, -9};

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            if (arr[j] > arr[j + 1]) {
                int b = arr[j]; // создали дополнительную переменную
                arr[j] = arr[j + 1]; // меняем местами
                arr[j + 1] = b;     //  значения элементов
            }
        }
    }

    for (int i : arr) {
        cout << i << " "; // выводим элементы массива
    }
}
