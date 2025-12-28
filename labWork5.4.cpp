/*
Лабораторная работа 5
Задание 4
Программа, переносящая номера страницы в последнюю строку.
Предполагается, что входной файл содержит текст, разделенный на страницы символом '\f' (Form Feed),
и номер страницы может находиться в начале страницы.
*/

#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <vector>
#include <cctype> // для isdigit

using namespace std;

// Функция для извлечения числа из строки (если строка содержит "Page 12", вернет 12)
int extractPageNumber(const string& line) {
    string numberStr = "";
    for (char c : line) {
        if (isdigit(c)) {
            numberStr += c;
        }
    }
    if (numberStr.empty()) return 0;
    return stoi(numberStr); // Преобразование строки в целое число
}

int main() {
    SetConsoleOutputCP(CP_UTF8); // Для нормального отображения русского языка в консоли

    string inputFileName = "test2.txt";
    string outputFileName = "test2output.txt";

    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    if (!inputFile.is_open()) {
        cerr << "Ошибка: Не удается открыть файл " << inputFileName << endl;
        // Создадим тестовый файл для демонстрации
        ofstream test(inputFileName);
        test << "1\nHeader text\nContent line 1\nContent line 2\n\f";
        test << "2\nHeader text page 2\nContent line 3\nContent line 4";
        test.close();
        cout << "Создан тестовый файл " << inputFileName << ". Перезапустите для обработки." << endl;
        inputFile.open(inputFileName);
        if (!inputFile.is_open()) return 1;
    }

    if (!outputFile.is_open()) {
        cerr << "Ошибка: Не удается создать файл " << outputFileName << endl;
        return 1;
    }

    string line;
    string pageNumberStr = "";
    vector<string> pageContent;

    // Читаем файл построчно
    while (getline(inputFile, line)) {
        // Проверяем наличие символа разрыва страницы '\f' (Form Feed, ASCII 12)
        size_t ffPos = line.find('\f');

        if (ffPos != string::npos) {
            // Если символ найден, значит страница закончилась.
            // Строка может содержать текст до \f и текст новой страницы после \f (редко, но возможно).
            // Для простоты считаем, что \f разделяет страницы.

            // Добавляем часть строки до \f в контент
            string beforeFF = line.substr(0, ffPos);
            if (!beforeFF.empty()) {
                 // Проверка, не является ли эта строка номером страницы (если она была последней перед \f)
                 // Но по логике задачи номер обычно вверху.
                 // Упростим: просто добавим в контент.
                 pageContent.push_back(beforeFF);
            }

            // Записываем накопленную страницу в выходной файл
            for (const string& contentLine : pageContent) {
                outputFile << contentLine << endl;
            }
            // Если был найден номер страницы, пишем его в конце
            if (!pageNumberStr.empty()) {
                outputFile << extractPageNumber(pageNumberStr) << endl;
            }
            // Разделитель страниц в выходном файле (опционально)
            outputFile << "-------------------- (End of Page) --------------------" << endl;

            // Сброс для новой страницы
            pageNumberStr = "";
            pageContent.clear();

            // Если после \f что-то есть, это начало новой страницы
            string afterFF = line.substr(ffPos + 1);
            if (!afterFF.empty()) {
                // Проверяем, является ли это номером страницы
                if (isdigit(afterFF[0])) {
                    pageNumberStr = afterFF;
                } else {
                    pageContent.push_back(afterFF);
                }
            }

        } else {
            // Обычная строка
            // Логика определения номера страницы:
            // Если это первая строка страницы (pageContent пуст и pageNumberStr пуст) и она начинается с цифры
            if (pageContent.empty() && pageNumberStr.empty() && !line.empty() && isdigit(line[0])) {
                pageNumberStr = line;
            } else {
                pageContent.push_back(line);
            }
        }
    }

    // Записываем последнюю страницу (если файл не заканчивается на \f)
    if (!pageContent.empty() || !pageNumberStr.empty()) {
        for (const string& contentLine : pageContent) {
            outputFile << contentLine << endl;
        }
        if (!pageNumberStr.empty()) {
            outputFile << extractPageNumber(pageNumberStr) << endl;
        }
    }

    inputFile.close();
    outputFile.close();

    cout << "Обработка завершена. Результат в " << outputFileName << endl;

    // Вывод результата для проверки
    ifstream res(outputFileName);
    cout << endl << "--- Результат ---" << endl;
    cout << res.rdbuf();
    cout << "-----------------" << endl;

    return 0;
}
