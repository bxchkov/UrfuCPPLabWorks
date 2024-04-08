/*
Лабораторная работа 5
Задание 4
Программа, переносящая номера страницы в последнюю строку
*/

#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Функция для обработки строки и извлечения номера страницы
int extractPageNumber(string line) {
    string number = "";
    for (char c : line) {
        if (isdigit(c)) {
            number += c;
        }
    }
    return stoi(number); // Преобразование строки в целое число
}

int main() {
    SetConsoleOutputCP(CP_UTF8); // Для нормального отображения русского языка в консоли

    ifstream inputFile("test2.txt"); // Имя вашего входного файла
    ofstream outputFile("test2output.txt"); // Имя вашего выходного файла

    if (!inputFile.is_open()) {
        cout << "Не получается открыть исходный файл" << endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        cout << "Не получается открыть выходной файл" << endl;
        return 1;
    }

    string line;
    string pageNumber = "";
    vector<string> pageLines;

    while (getline(inputFile, line)) {
        if (line.find('\f') != string::npos) { // Проверка на управляющий символ новой страницы
            // Если нашли символ перехода на новую страницу, обрабатываем текущую страницу
            if (!pageNumber.empty()) {
                for (const string& pageLine : pageLines) {
                    outputFile << pageLine << endl;
                }
                outputFile << extractPageNumber(pageNumber) << endl; // Переносим номер страницы в конец
                pageNumber = ""; // Сбрасываем значение номера страницы
                pageLines.clear(); // Очищаем строки текущей страницы
            }
        } else if (!line.empty() && isdigit(line[0])) {
            pageNumber = line; // Сохраняем номер страницы
        } else {
            pageLines.push_back(line); // Сохраняем строку текущей страницы
        }
    }

    // Обработка последней страницы (без символа перехода на новую страницу в конце)
    if (!pageNumber.empty() && !pageLines.empty()) {
        for (const string& pageLine : pageLines) {
            outputFile << pageLine << endl;
        }
        outputFile << extractPageNumber(pageNumber) << endl;
    }

    inputFile.close();
    outputFile.close();

    cout << "Успешный успех" << endl;
}