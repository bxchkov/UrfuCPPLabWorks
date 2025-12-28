/*
Лабораторная работа 3
Задание 6
Программа сортировки чисел по убыванию в заданном интервале индексов
*/

#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8); // Для нормального отображения русского языка в консоли

    int arr[] = {-2, 5, -8, 1, -10, 2, 11, 0, 4, -9};
    int arrLength = sizeof(arr) / sizeof(arr[0]);

    cout << "Исходный массив: ";
    for (int i = 0; i < arrLength; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;

    int N1 = 1; // начальный индекс (включительно)
    int N2 = 7; // конечный индекс (включительно)
    // Элементы в диапазоне [1, 7]: 5, -8, 1, -10, 2, 11, 0

    cout << "Сортировка по убыванию в диапазоне индексов от " << N1 << " до " << N2 << endl;

    // Проверка границ
    if (N1 < 0 || N2 >= arrLength || N1 > N2) {
        cout << "Некорректный диапазон индексов!" << endl;
        return 1;
    }

    int iMax; // Индекс максимального элемента (для сортировки по убыванию)

    // Сортировка выбором (Selection Sort) по убыванию внутри диапазона [N1, N2]
    for (int i = N1; i < N2; i++) {
        iMax = i;
        for (int j = i + 1; j <= N2; j++) {
            // Ищем элемент БОЛЬШЕ текущего максимума
            if (arr[j] > arr[iMax]) {
                iMax = j;
            }
        }
        // Обмен элементов в исходном массиве
        if (iMax != i) {
            int t = arr[i];
            arr[i] = arr[iMax];
            arr[iMax] = t;
        }
    }

    cout << "Массив после частичной сортировки: ";
    for (int i = 0; i < arrLength; i++) { // вывод на экран
        if (i == N1) cout << "[ ";
        cout << arr[i] << ' ';
        if (i == N2) cout << "] ";
    }
    cout << endl;

    return 0;
}
