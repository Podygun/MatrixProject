#include "Matrix.h"
#include <iostream>
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

}

void Matrix::Generate() 
{
	for (short i = 0; i < getRowsAmount(); i++)
	{
		for (short j = 0; j < getColsAmount(); j++)
		{

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
	for (short i = 0; i < getRowsAmount(); i++)
	{
		for (short j = 0; j < getColsAmount(); j++)
		{
			cout << matrix[i][j] << " ";
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
