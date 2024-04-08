/*
Лабораторная работа 3
Задание 4
Программа сортировки чётных чисел по возрастанию, а нечётных - по убыванию
*/

#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8); // Для нормального отображения русского языка в консоли

    int arr[] = {-2, 5, -8, 1, -10, 2, 11, 0, 4, -9};
    int arrLength = sizeof(arr) / sizeof(int); // длина массива

    vector<int> evenArr = {};
    vector<int> oddArr = {};

    for (int i = 0; i < arrLength; i++) {
        if (arr[i] % 2 == 0) {
            evenArr.push_back(arr[i]);
        } else {
            oddArr.push_back(arr[i]);
        }
    }
    int evenArrLength = evenArr.size(); // длина массива
    int oddArrLength = oddArr.size(); // длина массива

    // сортировка массива чётных чисел по возрастанию
    int iMinEven;
    for (int i = 0; i < evenArrLength - 1; i++) {
        iMinEven = i;
        for (int j = i + 1; j < evenArrLength; j++) {
            if (evenArr[j] < evenArr[iMinEven]) {
                iMinEven = j;
            }
        }
        int t = evenArr[i];
        evenArr[i] = evenArr[iMinEven];
        evenArr[iMinEven] = t;
    }

    // сортировка массива нечётных чисел по убыванию
    int iMinOdd;
    for (int i = 0; i < oddArrLength - 1; i++) {
        iMinOdd = i;
        for (int j = i + 1; j < oddArrLength; j++) {
            if (oddArr[j] > oddArr[iMinOdd]) {
                iMinOdd = j;
            }
        }
        int t = oddArr[i];
        oddArr[i] = oddArr[iMinOdd];
        oddArr[iMinOdd] = t;
    }

    // Создание нового массива для объединения
    vector<int> resultArr(evenArr.size() + oddArr.size());

    // Копирование элементов из первого массива
    copy(evenArr.begin(), evenArr.end(), resultArr.begin());

    // Копирование элементов из второго массива
    copy(oddArr.begin(), oddArr.end(), resultArr.begin() + evenArr.size());

    int resultArrLength = resultArr.size(); // длина массива

    // вывод на экран
    for (int i = 0; i < resultArrLength; i++) {
        cout << resultArr[i] << ' ';
    }
}