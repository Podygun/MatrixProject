#include <conio.h>
#include <iostream>
#include <locale.h>
#include "Logger.h"
#include "Matrix.h"
#include "PodyJsonReader.h"


using namespace std;

const void PrintConfig(const ConfigData&);


int main() {
	setlocale(LC_ALL, "ru");
	
	const std::string config_path = "data.json";

	ConfigData data = PodyJsonReader::readData(config_path);
	PrintConfig(data);

	Matrix m = Matrix(data.rows_amount, data.columns_amount);
	m.HandInput();
	m.Print();
	

	_getch();
	return 0;
}

const void PrintConfig(const ConfigData &data) {
	cout << "version: " << data.version << endl;
	cout << "is_random_fill: " << data.is_random_fill << endl;
	cout << "rows_amount: " << data.rows_amount << endl;
	cout << "columns_amount: " << data.columns_amount << endl;
}