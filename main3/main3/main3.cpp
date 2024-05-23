#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    ifstream input("input.txt");
    if (!input.is_open()) {
        cerr << "Ошибка открытия файла input.txt" << endl;
        return 1;
    }

    ofstream outputUpper("upper.txt");
    if (!outputUpper.is_open()) {
        cerr << "Ошибка открытия файла upper.txt" << endl;
        return 1;
    }

    ofstream outputLower("lower.txt");
    if (!outputLower.is_open()) {
        cerr << "Ошибка открытия файла lower.txt" << endl;
        return 1;
    }

    char ch;
    int digitCount = 0;

    while (input.get(ch)) {
        if (isupper(ch)) {
            outputUpper << ch;
        }
        else if (islower(ch)) {
            outputLower << ch;
        }
        else if (isdigit(ch)) {
            digitCount++;
        }
    }

    input.close();
    outputUpper.close();
    outputLower.close();

    cout << "Большие латинские буквы записаны в файл upper.txt" << endl;
    cout << "Малые латинские буквы записаны в файл lower.txt" << endl;
    cout << "Количество цифр: " << digitCount << endl;

    return 0;
}