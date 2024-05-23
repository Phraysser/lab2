#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::vector<int> numbers;
    setlocale(LC_ALL, "Russian");
    // Ввод целых чисел и запись их в бинарный файл
    std::cout << "Введите целые числа (для завершения введите 0):\n";
    int num;
    while (true) {
        std::cin >> num;
        if (num == 0) {
            break;
        }
        numbers.push_back(num);
    }

    std::ofstream outfile("numbers.bin", std::ios::binary);
    if (!outfile) {
        std::cerr << "Ошибка открытия файла." << std::endl;
        return 1;
    }

    for (int n : numbers) {
        outfile.write(reinterpret_cast<char*>(&n), sizeof(int));
    }

    outfile.close();

    // Увеличение чисел в файле вдвое
    std::ifstream infile("numbers.bin", std::ios::binary);
    if (!infile) {
        std::cerr << "Ошибка открытия файла." << std::endl;
        return 1;
    }

    std::vector<int> modifiedNumbers;
    while (infile.read(reinterpret_cast<char*>(&num), sizeof(int))) {
        num *= 2;
        modifiedNumbers.push_back(num);
    }

    infile.close();

    // Вывод чисел до и после изменения
    std::cout << "Числа до изменения данных в файле:\n";
    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    std::cout << "Числа после изменения данных в файле:\n";
    for (int n : modifiedNumbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}