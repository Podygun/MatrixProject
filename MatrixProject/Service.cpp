#include "Service.h"
#include <iostream>

using namespace std;

void Service::printSeparator()
{
	cout << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << endl;
}

void Service::logo()
{
	cout << "Разработчик: Владислав Подыганов" << endl;
	cout << "Группа: ИВТ-13" << endl;
}

void Service::end()
{
	cout << "Любая кнопка, чтобы выйти... ";
}
