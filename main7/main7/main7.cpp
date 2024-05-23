#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	int k, l, m, n;
	cout << "Enter the number of matrices in the first file: ";
	cin >> k;
	cout << "Enter the number of matrices in the second file: ";
	cin >> l;
	cout << "Enter the dimension of the matrices (m x n): ";
	cin >> m >> n;

	vector<vector<vector<int>>> matrices1(k, vector<vector<int>>(m, vector<int>(n)));
	vector<vector<vector<int>>> matrices2(l, vector<vector<int>>(m, vector<int>(n)));

	ifstream file1("file1.txt");
	ifstream file2("file2.txt");

	if (!file1.is_open() || !file2.is_open()) {
		cout << "Error opening files." << endl;
		return 1;
	}

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < m; j++) {
			for (int l = 0; l < n; l++) {
				file1 >> matrices1[i][j][l];
			}
		}
	}

	for (int i = 0; i < l; i++) {
		for (int j = 0; j < m; j++) {
			for (int l = 0; l < n; l++) {
				file2 >> matrices2[i][j][l];
			}
		}
	}

	file1.close();
	file2.close();

	int min_size = min(k, l);

	for (int i = 0; i < min_size; i += 2) {
		vector<vector<int>> temp = matrices1[i];
		matrices1[i] = matrices2[i];
		matrices2[i] = temp;
	}

	ofstream outfile1("file1.txt");
	ofstream outfile2("file2.txt");

	if (!outfile1.is_open() || !outfile2.is_open()) {
		cout << "Error opening output files." << endl;
		return 1;
	}

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < m; j++) {
			for (int l = 0; l < n; l++) {
				outfile1 << matrices1[i][j][l] << " ";
			}
			outfile1 << endl;
		}
		outfile1 << endl;
	}

	for (int i = 0; i < l; i++) {
		for (int j = 0; j < m; j++) {
			for (int l = 0; l < n; l++) {
				outfile2 << matrices2[i][j][l] << " ";
			}
			outfile2 << endl;
		}
		outfile2 << endl;
	}

	outfile1.close();
	outfile2.close();

	cout << "Successfully swapped odd matrices between the two files." << endl;

	return 0;
}