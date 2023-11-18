#pragma once
#include <string>

class ConfigData
{
public:
	std::string version;
	bool is_random_fill;
	int rows_amount;
	int columns_amount;

	// friend std::ostream& operator<< (std::ostream& out, const ConfigData& point);

};

//std::ostream& operator<< (std::ostream& out, const ConfigData& data)
//{
//	// Поскольку operator<< является другом класса Point, то мы имеем прямой доступ к членам Point
//	out << "version: " << data.version << 
//		", \nis_random_fill: " << data.is_random_fill << 
//		", \nrows: " << data.rows_amount <<
//		", \ncols: " << data.columns_amount << "\n";
//
//	return out;
//}

