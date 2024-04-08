/*
Лабораторная работа 3
Задание 1
Программа сортировки методом минимального и максимального
*/

#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8); // Для нормального отображения русского языка в консоли

    int arr[] = {-2, 5, -8, 1, -10, 2, 11, 0, 4, -9};

    int iMin;
    int arrLength = sizeof(arr) / sizeof(int); // длина массива

    // сортировка
    for (int i = 0; i < arrLength - 1; i++) {
        iMin = i;
        for (int j = i + 1; j < arrLength; j++) {
            if (arr[j] < arr[iMin]) {
                iMin = j;
            }
        }
        int t = arr[i];
        arr[i] = arr[iMin];
        arr[iMin] = t;
    }

    for (int i = 0; i < arrLength; i++) { // вывод на экран
        cout << arr[i] << ' ';
    }
}