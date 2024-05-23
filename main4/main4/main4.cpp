#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    ifstream input("input.txt");
    if (!input.is_open()) {
        cerr << "Ошибка открытия файла input.txt" << endl;
        return 1;
    }

    vector<int> numbers;
    int num;
    int position = 1;
    while (input >> num) {
        if (position % 2 == 0 && num > 0) {
            numbers.push_back(num);
        }
        position++;
    }

    input.close();

    if (numbers.empty()) {
        cout << "В файле нет положительных чисел на четных позициях" << endl;
        return 0;
    }

    int sum = 0;
    for (int n : numbers) {
        sum += n;
    }

    double average = static_cast<double>(sum) / numbers.size();

    cout << "Среднее значение среди положительных чисел на четных позициях: " << average << endl;

    return 0;
}