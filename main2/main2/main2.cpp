#include <iostream>
#include <fstream>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    ifstream input("a.txt");
    if (!input.is_open()) {
        std::cout << "Ошибка открытия файла a.txt" << std::endl;
        return 1;
    }

    ofstream output("a2.txt");
    if (!output.is_open()) {
        cout << "Ошибка открытия файла a2.txt" << endl;
        return 1;
    }

    double num;
    while (input >> num) {
        if (num != 0) {
            output << num / 5 << " ";
        }
    }

    input.close();
    output.close();

    cout << "Содержимое файла a.txt:" << std::endl;
    input.open("a.txt");
    while (input >> num) {
        cout << num << " ";
    }
    input.close();
    cout << endl;
    cout << "Ненулевые элементы файла a.txt успешно записаны в файл a2.txt с делением на 5" << endl;

    return 0;
}