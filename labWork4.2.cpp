/*
Лабораторная работа 4
Задание 2
Программа для работы со строками (собственная реализация стандартных функций)
*/

#include <iostream>
#include <windows.h>

using namespace std;

// Определение длины строки (способ 1: использование цикла while и индексации)
int stringLength1(const char *str) {
    int len = 0;
    while (str[len] != '\0') { // Пока не встретим нуль-терминатор
        len++;
    }
    return len;
}

// Определение длины строки (способ 2: использование арифметики указателей)
int stringLength2(char *str) {
    char *ptr = str; // Сохраняем начальный адрес
    while (*ptr != '\0') { // Двигаем указатель ptr до конца строки
        ptr++;
    }
    return ptr - str; // Разность адресов дает количество элементов (символов)
}

// Определение длины строки (способ 3: рекурсивная функция)
int stringLength3(char *str) {
    if (*str == '\0') { // Базовый случай: конец строки
        return 0;
    } else {
        // Рекурсивный шаг: 1 + длина оставшейся части строки
        return 1 + stringLength3(str + 1);
    }
}

// Функция копирования строк (аналог strcpy)
// Копирует source в destination. Destination должен иметь достаточный размер.
char *stringCopy(char *destination, const char *source) {
    char *temp = destination; // Сохраняем указатель на начало, чтобы вернуть его

    // Копируем каждый символ из source в destination
    while (*source != '\0') {
        *destination = *source;
        ++destination;
        ++source;
    }

    // Не забываем поставить нуль-терминатор в конце скопированной строки
    *destination = '\0';

    return temp;
}

// Функция сравнения строк (аналог strcmp)
// Возвращает 0, если равны; >0, если a > b; <0, если a < b
int stringCompare(const char *a, const char *b) {
    // Идем по строкам, пока символы совпадают и строка не кончилась
    while (*a == *b && *a != '\0') {
        a++;
        b++;
    }

    // Если вышли из цикла, значит либо нашли различие, либо обе строки кончились
    if (*a == '\0' && *b == '\0') {
        return 0; // Строки идентичны
    }

    // Сравниваем коды первых различающихся символов
    // Приводим к unsigned char для корректного сравнения (стандартное поведение strcmp)
    return *(unsigned char*)a - *(unsigned char*)b;
}

// Функция конкатенации строк (аналог strcat)
// Добавляет source в конец destination.
char *stringConcat(char *destination, const char *source) {
    char *temp = destination; // Сохраняем начало

    // Сдвигаем указатель destination до конца текущей строки (до \0)
    while (*destination != '\0') {
        ++destination;
    }

    // Копируем source начиная с позиции, где был \0
    while (*source != '\0') {
        *destination = *source;
        ++destination;
        ++source;
    }

    // Ставим новый нуль-терминатор
    *destination = '\0';

    return temp;
}

int main() {
    SetConsoleOutputCP(CP_UTF8); // Для нормального отображения русского языка в консоли

    // ВАЖНО: str1 должен быть достаточно большим для конкатенации в будущем.
    // Иначе stringConcat перезапишет память за пределами массива, что приведет к ошибке.
    char str1[100] = "qwerty";
    char str2[] = "1234567890";

    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl << endl;

    // Тестирование функций длины строки
    cout << "--- Тест stringLength ---" << endl;
    cout << "Длина str1 (способ 1) = " << stringLength1(str1) << endl;
    cout << "Длина str2 (способ 1) = " << stringLength1(str2) << endl;
    cout << "Длина str1 (способ 2) = " << stringLength2(str1) << endl;
    cout << "Длина str1 (способ 3) = " << stringLength3(str1) << endl << endl;

    // Тестирование stringCompare
    cout << "--- Тест stringCompare ---" << endl;
    // Сравниваем "qwerty" и "1234567890". 'q' > '1', ожидаем положительное число.
    int cmpResult = stringCompare(str1, str2);
    cout << "Сравнение str1 и str2: " << cmpResult << (cmpResult > 0 ? " (str1 > str2)" : (cmpResult < 0 ? " (str1 < str2)" : " (равны)")) << endl << endl;

    // Тестирование stringConcat
    cout << "--- Тест stringConcat ---" << endl;
    cout << "До конкатенации str1: " << str1 << endl;
    stringConcat(str1, str2);
    cout << "После конкатенации str1: " << str1 << endl << endl;

    // Тестирование stringCopy
    // Сейчас str1 = "qwerty1234567890". Скопируем туда str2 ("1234567890").
    cout << "--- Тест stringCopy ---" << endl;
    stringCopy(str1, str2);
    cout << "После копирования str2 в str1: " << str1 << endl;

    return 0;
}
