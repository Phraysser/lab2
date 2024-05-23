#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct CableClient {
	string name;
	float payment;
	int monthsPaid;
	int monthsAhead;
};

void writeBinaryFile() {
	ofstream outFile("clients.bin", ios::binary);

	if (!outFile) {
		cout << "Error opening file!" << endl;
		return;
	}

	CableClient clients[] = {
	{"John Doe", 50.0, 3, 1},
	{"Jane Smith", 60.0, 2, 0},
	{"Alice Johnson", 70.0, 5, 5},
	};

	for (int i = 0; i < 3; i++) {
		outFile.write((char*)&clients[i], sizeof(CableClient));
	}

	outFile.close();
}

void readAndModifyBinaryFile() {
	ifstream inFile("clients.bin", ios::binary);

	if (!inFile) {
		cout << "Error opening file!" << endl;
		return;
	}

	ofstream tempFile("temp.bin", ios::binary);

	if (!tempFile) {
		cout << "Error opening file!" << endl;
		return;
	}

	CableClient client;

	while (inFile.read((char*)&client, sizeof(CableClient))) {
		if (client.monthsAhead == 5) {
			client.payment *= 0.93; // decrease the payment by 7%
		}

		tempFile.write((char*)&client, sizeof(CableClient));

		// Display client information
		cout << "Name: " << client.name << endl;
		cout << "Payment: " << client.payment << endl;
		cout << "Months paid: " << client.monthsPaid << endl;
		cout << "Months ahead: " << client.monthsAhead << endl;
		cout << "------------------------" << endl;
	}

	inFile.close();
	tempFile.close();

	remove("clients.bin");
	rename("temp.bin", "clients.bin");
}

int main() {
	writeBinaryFile();
	readAndModifyBinaryFile();

	return 0;
}