/*
Лабораторная работа 5
Задание 5
Программа шифратор файлов (XOR шифрование)
*/

#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <cstring> // Для strlen

using namespace std;

// Функция шифрования/дешифрования файла методом XOR
// inputFile - путь к исходному файлу
// outputFile - путь к файлу результата
// key - ключ шифрования (строка)
// Особенность XOR: (A ^ K) ^ K = A. То есть повторное применение функции с тем же ключом расшифровывает данные.
void encryptFile(const char* inputFile, const char* outputFile, const char* key) {
    // Открываем файлы в бинарном режиме (ios::binary), чтобы избежать преобразования символов перевода строки
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
        cerr << "Ошибка: Ключ не может быть пустым" << endl;
        return;
    }

    size_t keyIndex = 0;
    char ch;

    // Читаем файл побайтово
    while (inFile.get(ch)) {
        // Применяем операцию XOR (исключающее ИЛИ) между байтом файла и байтом ключа
        ch = ch ^ key[keyIndex];

        // Записываем результат
        outFile.put(ch);

        // Циклический переход к следующему символу ключа
        keyIndex = (keyIndex + 1) % keyLength;
    }

    inFile.close();
    outFile.close();

    cout << "Обработка файла " << inputFile << " -> " << outputFile << " завершена." << endl;
}

int main() {
    SetConsoleOutputCP(CP_UTF8); // Для нормального отображения русского языка в консоли

    const char* inputFile = "test.txt";
    const char* encryptedFile = "5.5_Encoded.txt";
    const char* decryptedFile = "5.5_Decoded.txt";
    const char* key = "SecretKey123"; // Более сложный ключ

    // Создадим исходный файл, если его нет
    ifstream check(inputFile);
    if (!check.is_open()) {
        ofstream create(inputFile);
        create << "Hello, World! This is a secret message.";
        create.close();
    } else {
        check.close();
    }

    cout << "--- Шифрование ---" << endl;
    encryptFile(inputFile, encryptedFile, key);

    cout << endl << "--- Дешифрование (проверка) ---" << endl;
    // Расшифровываем зашифрованный файл (применяем ту же функцию)
    encryptFile(encryptedFile, decryptedFile, key);

    // Вывод результатов для сравнения
    cout << endl << "--- Исходный текст ---" << endl;
    ifstream f1(inputFile); cout << f1.rdbuf() << endl; f1.close();

    cout << "--- Зашифрованный текст (может содержать нечитаемые символы) ---" << endl;
    ifstream f2(encryptedFile); cout << f2.rdbuf() << endl; f2.close();

    cout << "--- Расшифрованный текст ---" << endl;
    ifstream f3(decryptedFile); cout << f3.rdbuf() << endl; f3.close();

    return 0;
}
