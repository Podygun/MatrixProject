#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include "Matrix.h"

using namespace std;

Matrix::Matrix(const int rows, const int cols)
{
	this->_cols = cols;
	this->_rows = rows;

	matrix = { new int* [rows] {} };  // выделяем память под двухмерный массив

	// выделяем память для вложенных массивов
	for (unsigned i{}; i < rows; i++)
	{
		matrix[i] = new int[cols] {};
	}


}

void Matrix::Sort()
{
	for (int i = 0; i < getRowsAmount() - 1; i++)
	{
		// Если строка чётная
		if (i % 2 == 0) 
		{
			// Сортировка по возрастанию для четных строк
			for (int j = 0; j < getColsAmount() - 1; j++)
			{
				
				if (matrix[i][j] < matrix[i][j + 1])
				{
					int temp = matrix[i][j];
					matrix[i][j] = matrix[i][j + 1];
					matrix[i][j + 1] = temp;
				}
				
			}
		}
		else 
		{
			// Сортировка по убыванию для нечетных строк
			for (int j = 0; j < getColsAmount() - 1; j++)
			{
				
					if (matrix[i][j] > matrix[i][j + 1])
					{
						int temp = matrix[i][j];
						matrix[i][j] = matrix[i][j + 1];
						matrix[i][j + 1] = temp;
					}
				
			}
		}
		
	}
}

void Matrix::Generate() 
{
	const int min_value = -50;
	const int max_value = 100;

	srand(time(NULL));

	for (short i = 0; i < getRowsAmount(); i++)
	{
		for (short j = 0; j < getColsAmount(); j++)
		{
			
			matrix[i][j] = min_value + rand() % (max_value - min_value + 1);
		}
	}
}

void Matrix::HandInput() 
{
	for (short i = 0; i < getRowsAmount(); i++)
	{
		for (short j = 0; j < getColsAmount(); j++)
		{
			cout << "[" << i << "][" << j << "] = ";
			cin >> matrix[i][j];
		}
	}
}

void Matrix::Print() const
{
	cout << endl;
	for (short i = 0; i < getRowsAmount(); i++)
	{
		for (short j = 0; j < getColsAmount(); j++)
		{
			cout<<setw(4) << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int Matrix::getRowsAmount() const
{
	return _rows;
}

int Matrix::getColsAmount() const
{
	return _cols;
}

Matrix::~Matrix()
{
	for (unsigned i{}; i < getRowsAmount(); i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}
