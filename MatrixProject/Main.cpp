#include <iostream>
#include <locale.h>

#include "PodyJsonReader.h"
#include "Logger.h"
#include "Matrix.h"


int main() {
	using namespace std;
	setlocale(LC_ALL, "ru");
	
	const std::string config_path = "data.json";

	ConfigData data = PodyJsonReader::readData(config_path);

	cout << data.version << endl;
	cout << data.is_random_fill << endl;
	cout << data.rows_amount << endl;
	cout << data.columns_amount << endl;
	cout << data.is_random_fill << endl;

	return 0;
}