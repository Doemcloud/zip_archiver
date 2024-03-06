#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <shellapi.h>

using namespace std;

void ArchiveFile(const string& filePath, const string& archivePath) {
    // Простая имитация архивации
    ifstream src(filePath, ios::binary);
    ofstream dst(archivePath, ios::binary);
    dst << src.rdbuf();
}

int main() {
    cout << "Добро пожаловать в программу архивации файлов!" << endl;
    cout << "Введите путь к файлу, который хотите архивировать: ";
    string filePath;
    getline(cin, filePath);

    cout << "Выберите действие: 1 - отменить, 2 - архивировать: ";
    int action;
    cin >> action;

    if (action == 1) {
        cout << "Операция отменена." << endl;
        return 0;
    } else if (action == 2) {
        cout << "Введите путь для сохранения архива: ";
        string archivePath;
        cin >> archivePath;
        ArchiveFile(filePath, archivePath);
        cout << "Файл успешно заархивирован." << endl;

        // Открытие папки с архивом
        string command = "explorer.exe /select," + archivePath;
        system(command.c_str());
    } else {
        cout << "Неверный выбор действия." << endl;
    }

    return 0;
}
