#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream inputFile("file_f.txt", ios::binary);
    ofstream outputFile("file_g.txt", ios::binary);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error opening files." << endl;
        return 1;
    }

    outputFile << inputFile.rdbuf();

    inputFile.close();
    outputFile.close();

    cout << "File copied successfully." << endl;

    return 0;
}