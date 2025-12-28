#include <iostream>
#include <fstream> // Для работы с файловыми потоками
#include <windows.h>

using namespace std;

// Функция шифрования файла
void cryptFile(const char* sourceName, const char* destName, int key) {
    ifstream fin(sourceName, ios::binary); // Открываем для чтения
    ofstream fout(destName, ios::binary);  // Открываем для записи

    if (!fin.is_open() || !fout.is_open()) {
        cout << "Ошибка открытия файлов!" << endl;
        return;
    }

    char ch;
    // Посимвольное чтение через поток
    while (fin.get(ch)) {
        ch = ch + key; // Простейшее смещение (из ЛР5)
        fout.put(ch);  // Запись в целевой файл
    }

    fin.close();
    fout.close();
    cout << "Файл '" << sourceName << "' успешно обработан." << endl;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    
    // Создадим тестовый файл
    ofstream test("original.txt");
    test << "Hello, this is a secret message for Lab 8!";
    test.close();

    cout << "Шифрование файла..." << endl;
    cryptFile("original.txt", "encrypted.txt", 3);

    cout << "Дешифрование файла..." << endl;
    cryptFile("encrypted.txt", "decrypted.txt", -3);

    return 0;
}