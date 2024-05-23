#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

struct PhoneOwner {
	std::string lastName;
	std::string firstName;
	std::string middleName;
	struct Address {
		std::string postcode;
		std::string country;
		std::string region;
		std::string district;
		std::string city;
		std::string street;
		std::string house;
		std::string apartment;
	} address;
	std::string phoneNumber;
};

int main() {
	std::ifstream inputFile("phone_owners.txt");
	std::ofstream outputFile("phone_owners_filtered.txt");

	if (!inputFile.is_open() || !outputFile.is_open()) {
		std::cerr << "Error opening files." << std::endl;
		return 1;
	}

	std::string line;
	while (std::getline(inputFile, line)) {
		PhoneOwner owner;
		std::stringstream ss(line);
		std::getline(ss, owner.lastName, ';');
		std::getline(ss, owner.firstName, ';');
		std::getline(ss, owner.middleName, ';');
		std::getline(ss, owner.address.postcode, ';');
		std::getline(ss, owner.address.country, ';');
		std::getline(ss, owner.address.region, ';');
		std::getline(ss, owner.address.district, ';');
		std::getline(ss, owner.address.city, ';');
		std::getline(ss, owner.address.street, ';');
		std::getline(ss, owner.address.house, ';');
		std::getline(ss, owner.address.apartment, ';');
		std::getline(ss, owner.phoneNumber, ';');

		if (owner.phoneNumber.substr(0, 3) == "720") {
			outputFile << owner.lastName << ";" << owner.firstName << ";" << owner.middleName << ";" << owner.address.postcode << ";" << owner.address.country << ";" << owner.address.region << ";" << owner.address.district << ";" << owner.address.city << ";" << owner.address.street << ";" << owner.address.house << ";" << owner.address.apartment << ";" << owner.phoneNumber << std::endl;
		}
	}

	inputFile.close();
	outputFile.close();

	return 0;
}