/*
Лабораторная работа 5
Задание 3
Программа, с функцией поиска в текстовом файле заданной подстроки
*/

#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

void searchAndWrite(const char* filename, const char* searchString) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Файл " << filename << " не открыт" << endl;
        return;
    }

    ofstream outputFile("results.txt");
    if (!outputFile.is_open()) {
        cerr << "Не удалось открыть файл для записи" << endl;
        return;
    }

    string line;
    int lineNumber = 1;
    while (getline(file, line)) {
        size_t position = line.find(searchString);
        if (position != string::npos) {
            outputFile << "Найдено в строке " << lineNumber << ", столбец " << position << ": " << line << endl;
        }
        lineNumber++;
    }

    file.close();
    outputFile.close();

    cout << "Результаты поиска сохранены в файле results.txt" << endl;
}

int main() {
    SetConsoleOutputCP(CP_UTF8); // Для нормального отображения русского языка в консоли

    const char filename[] = "test.txt";

    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Файл " << filename << " не открыт" << endl;
        return 1;
    }

    cout << "Содержимое txt файла: \"" << file.rdbuf() << "\"" << endl;
    file.clear(); // Сбрасываем флаги состояния для чтения файла с начала
    file.seekg(0, ios::beg); // Устанавливаем указатель на начало файла

    const char searchString[] = "idy"; // Искомая подстрока
    cout << "Ищем подстроку: \"" << searchString << "\"" << endl;

    searchAndWrite(filename, searchString);

    int emptyCount = 0;
    int nonEmptyCount = 0;

    // Функция для подсчета пустых и непустых символов
    char ch;
    while (file.get(ch)) {
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r') {
            emptyCount++;
        } else {
            nonEmptyCount++;
        }
    }

    // Вывод результатов
    cout << "Количество пустых символов: " << emptyCount << endl;
    cout << "Количество непустых символов: " << nonEmptyCount << endl;
}