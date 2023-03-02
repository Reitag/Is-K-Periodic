#include "is_k_periodic.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Программа, которая находит кратность строки" << endl;
	string str;
	cout << "Сообщение: ";
	getline(cin, str);
	int k = str.size();
	IsKPeriodic(str, k);

	system("pause");

	return 0;
}