/*
Лабораторная работа 3
Задание 6
Программа сортировки чисел по убыванию в интервале индексов
*/

#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8); // Для нормального отображения русского языка в консоли

    int arr[] = {-2, 5, -8, 1, -10, 2, 11, 0, 4, -9};
    vector<int> arrResultASC = {};

    int N1 = 1; // начальный индекс
    int N2 = 7; // конечный индекс (-8, 1, -10, 2, 11)

    int iMin;
    // сортировка по убыванию
    for (int i = N1; i <= N2; i++) {
        iMin = i;
        for (int j = i + 1; j <= N2; j++) {
            if (arr[j] > arr[iMin]) {
                iMin = j;
            }
        }
        int t = arr[i];
        arrResultASC.push_back(arr[iMin]);
        arr[iMin] = t;
    }

    int arrResultASCLength = arrResultASC.size(); // длина массива

    for (int i = 0; i < arrResultASCLength; i++) { // вывод на экран
        cout << arrResultASC[i] << ' ';
    }
    cout << endl;
}