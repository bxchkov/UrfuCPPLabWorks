/*
Лабораторная работа 5
Задание 3
Программа с функцией поиска заданной подстроки в текстовом файле
и сохранения результатов поиска в отдельный файл.
*/

#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>

using namespace std;

// Функция поиска подстроки в файле и записи результатов в results.txt
// filename - имя исходного файла
// searchString - строка, которую ищем
void searchAndWrite(const char* filename, const char* searchString) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Ошибка: Файл " << filename << " не открыт" << endl;
        return;
    }

    ofstream outputFile("results.txt");
    if (!outputFile.is_open()) {
        cerr << "Ошибка: Не удалось создать файл results.txt для записи" << endl;
        file.close();
        return;
    }

    string line;
    int lineNumber = 1;
    bool foundAny = false;

    // Читаем файл построчно
    while (getline(file, line)) {
        // Ищем подстроку в текущей строке
        size_t position = line.find(searchString);

        // Если нашли (find возвращает позицию, отличную от string::npos)
        // Обратите внимание: find находит только первое вхождение в строке.
        // Если нужно найти все вхождения в одной строке, нужен цикл.
        if (position != string::npos) {
            // Записываем информацию в выходной файл
            outputFile << "Найдено в строке " << lineNumber << ", позиция " << position + 1 << ": " << line << endl;
            foundAny = true;
        }
        lineNumber++;
    }

    if (!foundAny) {
        outputFile << "Подстрока \"" << searchString << "\" не найдена в файле." << endl;
    }

    file.close();
    outputFile.close();

    cout << "Поиск завершен. Результаты сохранены в файле results.txt" << endl;
}

int main() {
    SetConsoleOutputCP(CP_UTF8); // Для нормального отображения русского языка в консоли

    const char filename[] = "test.txt";

    // Проверка наличия файла и вывод его содержимого
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Файл " << filename << " не найден. Создайте его для теста." << endl;
        // Создадим тестовый файл
        ofstream test(filename);
        test << "Hello world\nThis is a tidy file\nNobody here";
        test.close();
        file.open(filename);
    }

    cout << "--- Содержимое файла " << filename << " ---" << endl;
    cout << file.rdbuf() << endl;
    cout << "-----------------------------------" << endl;

    file.close(); // Закрываем, так как searchAndWrite откроет его заново

    string searchStr;
    cout << "Введите подстроку для поиска: ";
    // cin >> searchStr; // Читает до пробела
    getline(cin, searchStr);

    if (searchStr.empty()) {
        searchStr = "idy"; // Значение по умолчанию для теста
        cout << "Используется подстрока по умолчанию: \"" << searchStr << "\"" << endl;
    }

    searchAndWrite(filename, searchStr.c_str());

    // Дополнительно: вывод содержимого файла результатов
    ifstream resFile("results.txt");
    if (resFile.is_open()) {
        cout << endl << "--- Содержимое results.txt ---" << endl;
        cout << resFile.rdbuf();
        cout << "------------------------------" << endl;
        resFile.close();
    }

    return 0;
}
