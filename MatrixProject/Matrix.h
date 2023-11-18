#pragma once
class Matrix
{
private:
	int _cols;
	int _rows;
	

public:
	int** matrix;

	Matrix(const int rows, const int cols);

	int getRowsAmount() const;
	int getColsAmount() const;

	void Generate();
	void HandInput();
	void Print() const;
	void Sort();

	~Matrix();
};

