/*
Лабораторная работа 3
Задание 4
Программа сортировки чётных чисел по возрастанию, а нечётных - по убыванию
*/

#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm> // Для copy

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8); // Для нормального отображения русского языка в консоли

    int arr[] = {-2, 5, -8, 1, -10, 2, 11, 0, 4, -9};
    int arrLength = sizeof(arr) / sizeof(int); // длина массива

    cout << "Исходный массив: ";
    for (int i = 0; i < arrLength; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;

    // Используем векторы для динамического хранения четных и нечетных чисел
    vector<int> evenArr;
    vector<int> oddArr;

    // Разделение исходного массива на два вектора
    for (int i = 0; i < arrLength; i++) {
        if (arr[i] % 2 == 0) {
            evenArr.push_back(arr[i]);
        } else {
            oddArr.push_back(arr[i]);
        }
    }
    int evenArrLength = evenArr.size();
    int oddArrLength = oddArr.size();

    // Сортировка массива чётных чисел по возрастанию (методом выбора)
    int iMinEven;
    for (int i = 0; i < evenArrLength - 1; i++) {
        iMinEven = i;
        for (int j = i + 1; j < evenArrLength; j++) {
            if (evenArr[j] < evenArr[iMinEven]) {
                iMinEven = j;
            }
        }
        // Обмен элементов
        int t = evenArr[i];
        evenArr[i] = evenArr[iMinEven];
        evenArr[iMinEven] = t;
    }

    // Сортировка массива нечётных чисел по убыванию (методом выбора)
    int iMaxOdd; // Переименовал для ясности, так как ищем максимум для сортировки по убыванию
    for (int i = 0; i < oddArrLength - 1; i++) {
        iMaxOdd = i;
        for (int j = i + 1; j < oddArrLength; j++) {
            // Ищем элемент БОЛЬШЕ текущего максимума
            if (oddArr[j] > oddArr[iMaxOdd]) {
                iMaxOdd = j;
            }
        }
        // Обмен элементов
        int t = oddArr[i];
        oddArr[i] = oddArr[iMaxOdd];
        oddArr[iMaxOdd] = t;
    }

    // Создание нового вектора для объединения результатов
    vector<int> resultArr(evenArr.size() + oddArr.size());

    // Копирование элементов из вектора четных чисел в начало resultArr
    copy(evenArr.begin(), evenArr.end(), resultArr.begin());

    // Копирование элементов из вектора нечетных чисел сразу после четных
    copy(oddArr.begin(), oddArr.end(), resultArr.begin() + evenArr.size());

    int resultArrLength = resultArr.size();

    cout << "Результат (четные по возрастанию, нечетные по убыванию): ";
    // Вывод на экран
    for (int i = 0; i < resultArrLength; i++) {
        cout << resultArr[i] << ' ';
    }
    cout << endl;

    return 0;
}
