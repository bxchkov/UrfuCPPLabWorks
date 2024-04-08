/*
Лабораторная работа 5
Задание 6
Программа шифратор файлов с возможностью вводить имя файла и ключ в командной строке
*/

#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>

using namespace std;

void encryptFile(const char* inputFile, const char* outputFile, const char* key) {
    ifstream inFile(inputFile, ios::binary);
    if (!inFile.is_open()) {
        cerr << "Ошибка открытия входного файла" << endl;
        return;
    }

    ofstream outFile(outputFile, ios::binary);
    if (!outFile.is_open()) {
        cerr << "Ошибка открытия выходного файла" << endl;
        return;
    }

    size_t keyLength = strlen(key);
    size_t keyIndex = 0;
    char ch;
    while (inFile.get(ch)) {
        ch = ch ^ key[keyIndex]; // Шифрование/Дешифрование символа
        outFile.put(ch);
        keyIndex = (keyIndex + 1) % keyLength; // Переход к следующему символу ключа
    }

    inFile.close();
    outFile.close();

    cout << "Шифрование/Дешифрование завершено" << endl;
}

int main() {
    SetConsoleOutputCP(CP_UTF8); // Для нормального отображения русского языка в консоли

    const char* inputFile = "test.txt";
    const char* outputFile = "5.6_Encoded.txt";
    const char* key = "a";

    encryptFile(inputFile, outputFile, key);

    // Проверка правильности программы: зашифровать зашифрованный файл еще раз с тем же ключом
    encryptFile(outputFile, "5.6_Encoded2.txt", key);
}