#include <algorithm>
#include <conio.h>
#include <iostream>
#include <locale.h>
#include <ranges>

#include <vector>
#include "Matrix.h"
#include "PodyJsonReader.h"
#include "PodyLogger.h"


void Generate(std::vector<std::vector<int>>&, int, int);
void HandInput(std::vector<std::vector<int>>&, int, int);
const void PrintConfig(const ConfigData&);
const void PrintInfo();
const void PrintMatrix(const std::vector<std::vector<int>>&);
int InputInt(const std::string);
void Sort(std::vector<std::vector<int>>&);


int main() {
	setlocale(LC_ALL, "ru");
	PrintInfo();

	const std::string config_path = "data.json";

	PodyLogger logger;

	logger.log(LogLevel::INFO, "������ ���������");
	
	ConfigData data = PodyJsonReader::readData(config_path);
	
	PrintConfig(data);

	logger.log(LogLevel::INFO, "������������� ���������� �������");
	std::vector<std::vector<int>> matrix(data.rows_amount, std::vector<int>(data.columns_amount, 0));

	if (data.is_random_fill)
		Generate(matrix, data.rows_amount, data.columns_amount);
	else
		HandInput(matrix, data.rows_amount, data.columns_amount);

	std::cout << std::endl << "������� �� ����������: " << std::endl;
	PrintMatrix(matrix);
		
	Sort(matrix);

	std::cout<< std::endl << "������� ����� ����������: " << std::endl;
	PrintMatrix(matrix);

	logger.log(LogLevel::INFO, "����� ���������");
	std::cout << "\nEnter, ����� ���������...";
	_getch();
	return 0;
}

const void PrintConfig(const ConfigData &data) {
	std::cout << std::endl << "������ ���������: " << data.version << std::endl;
	std::cout << "��������� ����������: " << data.is_random_fill << std::endl;
	std::cout << "���-�� �����: " << data.rows_amount << std::endl;
	std::cout << "���-�� �����: " << data.columns_amount << std::endl << std::endl;
}

const void PrintInfo() {
	std::cout << "�����������: ��������� ��������� | ���-13" << std::endl<<std::endl;
	std::cout << "������: ������������� ������ ������ ������� MxN �� �����������,\n� �������� - �� ��������" << std::endl << std::endl;
}

void Generate(std::vector<std::vector<int>>& arr, int rows, int cols)
{
	PodyLogger logger;
	logger.log(LogLevel::DEBUG, "��������� ��������� �������� �������");

	const int min_value = -50;
	const int max_value = 100;

	srand(time(NULL));

	for (short i = 0; i < rows; i++)
		for (short j = 0; j < cols; j++)
			arr[i][j] = min_value + rand() % (max_value - min_value + 1);
}

void HandInput(std::vector<std::vector<int>>& arr, int rows, int cols)
{
	PodyLogger logger;
	logger.log(LogLevel::INFO, "������ ���������� �������");
	

	for (short i = 0; i < rows; i++)
		for (short j = 0; j < cols; j++) 
		{
			std::ostringstream oss;
			oss << "[" << i << "][" << j << "] = ";
			int digit = InputInt(oss.str());
			arr[i][j] = digit;
		}
			
}

const void PrintMatrix(const std::vector<std::vector<int>>& arr) 
{
	for (const auto& row : arr) {
		for (int value : row) 
			std::cout << std::setw(4) << value;
		std::cout << std::endl;
	}
}

void Sort(std::vector<std::vector<int>>& arr)
{
	PodyLogger logger;
	logger.log(LogLevel::DEBUG, "���������� �������");

	int row_number = 1;

	for (auto& row : arr) {
		if (row_number % 2 == 0) 
			std::sort(row.begin(), row.end());
		else
			std::sort(row.rbegin(), row.rend());
		++row_number;
	}
}

int InputInt(const std::string message) 
{
	PodyLogger logger;

	int value;
	while (true) {
		std::cout << message;
		std::string input;
		std::getline(std::cin, input);

		// ���������� std::istringstream ��� ������� �������������� � int
		std::istringstream stream(input);
		if (stream >> value && stream.eof()) {
			break;  // ���� ���������, ������� �� �����
		}
		else {
			logger.log(LogLevel::ERROR, "���� ����� �����");
			// ������� ����� �����, ����� �������� ������������ ��� ������������ �����
			std::cin.clear();
			//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	return value;
}