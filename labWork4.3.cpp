/*
Лабораторная работа 4
Задание 3
Программа, использующая динамическую память (malloc) для работы со строками
*/

#define _CRT_SECURE_NO_WARNINGS // Для strcpy

#include <iostream>
#include <windows.h>
#include <cstdlib> // Для malloc, free
#include <cstring> // Для strcpy

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8); // Для нормального отображения русского языка в консоли

    // Выделение памяти с помощью malloc (Memory Allocation).
    // malloc возвращает указатель void*, поэтому нужно приведение типов к char*.
    // sizeof(char) всегда равен 1, но для переносимости лучше писать.

    // Выделяем память под "qwerty" (6 символов + 1 нуль-терминатор = 7 байт)
    char *str1 = (char *) malloc(7 * sizeof(char));
    if (str1 == NULL) { // Всегда полезно проверять, удалось ли выделить память
        cout << "Ошибка выделения памяти для str1" << endl;
        return 1;
    }

    // Выделяем память под "1234567890" (10 символов + 1 нуль-терминатор = 11 байт)
    char *str2 = (char *) malloc(11 * sizeof(char));
    if (str2 == NULL) {
        cout << "Ошибка выделения памяти для str2" << endl;
        free(str1); // Не забываем освободить уже выделенную память перед выходом
        return 1;
    }

    // Копируем строковые литералы в выделенную память
    strcpy(str1, "qwerty");
    strcpy(str2, "1234567890");

    cout << "str1 (динамическая память): " << str1 << endl;
    cout << "str2 (динамическая память): " << str2 << endl;

    // Освобождение памяти с помощью free.
    // Если этого не сделать, произойдет утечка памяти (memory leak).
    free(str1);
    free(str2);

    // После free указатели становятся "висячими" (dangling pointers).
    // Хорошей практикой является зануление указателей, если они могут быть использованы позже,
    // но в конце main это не обязательно.
    str1 = NULL;
    str2 = NULL;

    return 0;
}
