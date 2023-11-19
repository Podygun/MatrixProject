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

	logger.log(LogLevel::INFO, "Запуск программы");
	
	ConfigData data = PodyJsonReader::readData(config_path);
	
	PrintConfig(data);

	logger.log(LogLevel::INFO, "Инициализация двумерного массива");
	std::vector<std::vector<int>> matrix(data.rows_amount, std::vector<int>(data.columns_amount, 0));

	if (data.is_random_fill)
		Generate(matrix, data.rows_amount, data.columns_amount);
	else
		HandInput(matrix, data.rows_amount, data.columns_amount);

	std::cout << std::endl << "Матрица до сортировки: " << std::endl;
	PrintMatrix(matrix);
		
	Sort(matrix);

	std::cout<< std::endl << "Матрица после сортировки: " << std::endl;
	PrintMatrix(matrix);

	logger.log(LogLevel::INFO, "Конец программы");
	std::cout << "\nEnter, чтобы завершить...";
	_getch();
	return 0;
}

const void PrintConfig(const ConfigData &data) {
	std::cout << std::endl << "Версия программы: " << data.version << std::endl;
	std::cout << "Случайное заполнение: " << data.is_random_fill << std::endl;
	std::cout << "Кол-во строк: " << data.rows_amount << std::endl;
	std::cout << "Кол-во столб: " << data.columns_amount << std::endl << std::endl;
}

const void PrintInfo() {
	std::cout << "Разработчик: Владислав Подыганов | ИВТ-13" << std::endl<<std::endl;
	std::cout << "Задача: Отсортировать четные строки матрицы MxN по возрастанию,\nа нечетные - по убыванию" << std::endl << std::endl;
}

void Generate(std::vector<std::vector<int>>& arr, int rows, int cols)
{
	PodyLogger logger;
	logger.log(LogLevel::DEBUG, "Генерация случайных значений массива");

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
	logger.log(LogLevel::INFO, "Ручное заполнение массива");
	

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
	logger.log(LogLevel::DEBUG, "Сортировка матрицы");

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

		// Используем std::istringstream для попытки преобразования в int
		std::istringstream stream(input);
		if (stream >> value && stream.eof()) {
			break;  // Ввод корректен, выходим из цикла
		}
		else {
			logger.log(LogLevel::ERROR, "Ввод целых чисел");
			// Очищаем буфер ввода, чтобы избежать зацикливания при некорректном вводе
			std::cin.clear();
			//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	return value;
}