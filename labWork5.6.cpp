/*
Лабораторная работа 5
Задание 6
Программа шифратор файлов с возможностью вводить имя файла и ключ через аргументы командной строки
(или через консольный ввод, если аргументы не переданы)
*/

#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

// Функция шифрования (та же, что и в задании 5)
void encryptFile(const char* inputFile, const char* outputFile, const char* key) {
    ifstream inFile(inputFile, ios::binary);
    if (!inFile.is_open()) {
        cerr << "Ошибка: Не удалось открыть входной файл " << inputFile << endl;
        return;
    }

    ofstream outFile(outputFile, ios::binary);
    if (!outFile.is_open()) {
        cerr << "Ошибка: Не удалось открыть выходной файл " << outputFile << endl;
        inFile.close();
        return;
    }

    size_t keyLength = strlen(key);
    if (keyLength == 0) {
        cerr << "Ошибка: Ключ пуст!" << endl;
        return;
    }

    size_t keyIndex = 0;
    char ch;
    while (inFile.get(ch)) {
        ch = ch ^ key[keyIndex];
        outFile.put(ch);
        keyIndex = (keyIndex + 1) % keyLength;
    }

    inFile.close();
    outFile.close();

    cout << "Файл успешно обработан: " << outputFile << endl;
}

// main принимает аргументы командной строки:
// argc - количество аргументов
// argv - массив строк аргументов (argv[0] - имя программы)
int main(int argc, char* argv[]) {
    SetConsoleOutputCP(CP_UTF8); // Для нормального отображения русского языка в консоли

    string inputFileName;
    string outputFileName;
    string key;

    // Проверяем, переданы ли аргументы при запуске
    // Ожидаем формат: program.exe input.txt output.txt secret_key
    if (argc == 4) {
        inputFileName = argv[1];
        outputFileName = argv[2];
        key = argv[3];
    } else {
        // Если аргументов нет или их мало, спрашиваем у пользователя
        cout << "Аргументы командной строки не заданы или заданы неверно." << endl;
        cout << "Использование: program.exe <input_file> <output_file> <key>" << endl;
        cout << "Введите данные вручную:" << endl;

        cout << "Введите имя входного файла: ";
        getline(cin, inputFileName);
        if (inputFileName.empty()) inputFileName = "test.txt"; // Дефолтное значение

        cout << "Введите имя выходного файла: ";
        getline(cin, outputFileName);
        if (outputFileName.empty()) outputFileName = "out.txt";

        cout << "Введите ключ шифрования: ";
        getline(cin, key);
        if (key.empty()) key = "default_key";
    }

    cout << "Входной файл: " << inputFileName << endl;
    cout << "Выходной файл: " << outputFileName << endl;
    cout << "Ключ: " << key << endl;

    // Проверка существования входного файла
    ifstream check(inputFileName.c_str());
    if (!check.good()) {
        cout << "Входной файл не существует. Создаю тестовый файл..." << endl;
        ofstream test(inputFileName.c_str());
        test << "This is a test message for encryption.";
        test.close();
    }
    check.close();

    encryptFile(inputFileName.c_str(), outputFileName.c_str(), key.c_str());

    return 0;
}
