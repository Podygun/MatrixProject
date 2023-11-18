#pragma once
class Matrix
{

private:
	size_t _cols;
	size_t _rows;

public:
	Matrix(size_t rows, size_t cols);

	void Sort();
	void Print();

	size_t getRowsAmount();
	size_t getColsAmount();

	~Matrix();
};

