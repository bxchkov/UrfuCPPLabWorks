/*
Лабораторная работа 5
Задание 2
Программа, подсчитывающая количество пробельных (whitespace) и непробельных символов в текстовом файле
*/

#include <iostream>
#include <windows.h>
#include <fstream>
#include <cctype> // Для функции isspace

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8); // Для нормального отображения русского языка в консоли

    // Имя файла жестко задано в коде, но можно запрашивать у пользователя
    const char filename[] = "test.txt";

    // Открываем файл для чтения
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Ошибка: Файл \"" << filename << "\" не найден или не может быть открыт." << endl;
        // Создадим файл для теста, чтобы программа не падала сразу, если его нет
        ofstream testFile(filename);
        testFile << "Hello World!\nThis is a test file.\n\tWith tabs.";
        testFile.close();
        cout << "Создан тестовый файл " << filename << ". Пожалуйста, перезапустите программу или она продолжит работу с ним." << endl;
        file.open(filename); // Пробуем открыть снова
        if (!file.is_open()) return 1;
    }

    int emptyCount = 0;    // Счетчик пробельных символов (пробел, табуляция, перевод строки)
    int nonEmptyCount = 0; // Счетчик остальных символов

    char ch;
    // file.get(ch) считывает символы по одному, включая пробелы и переводы строк.
    // (оператор >> пропускает пробельные символы по умолчанию, поэтому здесь нужен get)
    while (file.get(ch)) {
        // isspace проверяет, является ли символ пробельным (стандартная функция из <cctype>)
        // Это эквивалентно проверке ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r' и т.д.
        if (isspace(static_cast<unsigned char>(ch))) {
            emptyCount++;
        } else {
            nonEmptyCount++;
        }
    }

    // Вывод содержимого файла для наглядности
    cout << "--- Содержимое файла ---" << endl;
    file.clear(); // Сбрасываем флаг EOF (конец файла), чтобы можно было работать с файлом дальше
    file.seekg(0, ios::beg); // Перемещаем курсор чтения в начало файла
    cout << file.rdbuf() << endl; // Выводим всё содержимое
    cout << "------------------------" << endl;

    // Вывод результатов подсчета
    cout << "Количество пробельных символов (пробелы, табы, enter): " << emptyCount << endl;
    cout << "Количество непробельных символов: " << nonEmptyCount << endl;
    cout << "Всего символов: " << emptyCount + nonEmptyCount << endl;

    file.close();
    return 0;
}
