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
	cout << "�����������: ��������� ���������" << endl;
	cout << "������: ���-13" << endl;
}

void Service::end()
{
	cout << "����� ������, ����� �����... ";
}
