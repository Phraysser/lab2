#include <iostream>
#include <fstream>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    ifstream file("a.txt");
    if (!file.is_open()) {
        cout << "Ошибка открытия файла" << endl;
        return 1;
    }

    int zeroCount = 0;
    double negativeSum = 0.0;
    double num;

    while (file >> num) {
        if (num == 0) {
            zeroCount++;
        }
        else if (num < 0) {
            negativeSum += num;
        }
    }

    file.close();

    cout << "Содержимое файла a.txt:" << endl;
    file.open("a.txt");
    while (file >> num) {
        cout << num << " ";
    }
    file.close();

    cout << endl << "Количество нулевых элементов: " << zeroCount << endl;
    cout << "Сумма отрицательных элементов: " << negativeSum << endl;

    return 0;
}