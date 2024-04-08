/*
Лабораторная работа 3
Задание 3
Программа сортировки методом быстрой сортировки
*/

#include <iostream>
#include <windows.h>

using namespace std;

void swap(int arr[], int pos1, int pos2) {
    int temp;
    temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

int partition(int arr[], int low, int high, int pivot) {
    int i = low;
    int j = low;
    while (i <= high) {
        if (arr[i] > pivot) {
            i++;
        } else {
            swap(arr, i, j);
            i++;
            j++;
        }
    }
    return j - 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int pos = partition(arr, low, high, pivot);

        quickSort(arr, low, pos - 1);
        quickSort(arr, pos + 1, high);
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8); // Для нормального отображения русского языка в консоли

    int arr[] = {-2, 5, -8, 1, -10, 2, 11, 0, 4, -9};
    int arrLength = sizeof(arr) / sizeof(int);

    quickSort(arr, 0, arrLength - 1);
    cout << "Массив в отсортированном виде: ";
    for (int i = 0; i < arrLength; i++) {
        cout << arr[i] << " ";
    }
}