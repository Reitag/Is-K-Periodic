#include "is_k_periodic.h"

using namespace std;

StringArray::StringArray(int size): cl_arr(new string[size]), cl_size(size) 
{
}

StringArray::StringArray(const StringArray& other)
{
	this->cl_size = other.cl_size;
	this->cl_arr = new string[other.cl_size];

	for (int i = 0; i < cl_size; ++i)
	{
		this->cl_arr[i] = other.cl_arr[i];
	}
}

StringArray::~StringArray()
{
	delete[] cl_arr;
}

void StringArray::pushBack(char value)
{
	string* arr = new string[cl_size + 1];

	for (int i = 0; i < cl_size; ++i)
	{
		arr[i] = cl_arr[i];
	}
	arr[cl_size] = value;

	delete[] cl_arr;
	cl_arr = arr;
	++cl_size;
}

void StringArray::clearArray()
{
	string* arr = new string[0];
	delete[] cl_arr;
	cl_arr = arr;
	cl_size = 0;
}

bool StringArray::isEqual(StringArray& arr)
{
	int count = 0;
	for (int i = 0; i < cl_size - 1; ++i)
	{
		if (arr.cl_arr[i] == arr.cl_arr[i + 1])
		{
			++count;
		}
	}
	if (count == cl_size - 1)
	{
		return false;
	}
	count = 0;
	for (int i = 0; i < cl_size; ++i)
	{
		if (this->cl_arr[i] == arr.cl_arr[i])
		{
			++count;
		}
	}
	if (count == cl_size)
	{
		return true;
	}
	return false;
}

int StringArray::GetSize()
{
	return cl_size;
}

ostream& operator<<(ostream& output, const StringArray& arr)
{
	for (int i = 0; i < arr.cl_size; ++i)
	{
		output << arr.cl_arr[i] << ' ';
	}
	output << '\n';
	return output;
}

void IsKPeriodic(string& str, int& size_of_str)
{
	int size = 0;
	StringArray primary(size);
	StringArray secondary(size);

	cout << "Размер сроки: " << size_of_str << endl;
	for (int i = 0; i < size + 1; ++i)
	{
		if (size == (size_of_str / 2))
		{
			break;
		}
		cout << "-----------------------------" << endl;
		primary.pushBack(str[i]);
		++size;
		cout << "Итерация " << size << endl;
		cout << "Primary: " << primary;
		for (int j = size; j < size + size && j < size_of_str; ++j)
		{
			secondary.pushBack(str[j]); //
			if (size == 1 && str[i] == str[j])
			{
				if (size_of_str == 2)
				{
					cout << "Так как вся строка состоит из элемента \"" << str[j] << "\", её кратность равна 1." << endl;
					return;
				}
				else
				{
					for (int l = 2; l < size_of_str; ++l)
					{
						if (str[j] != str[l])
						{
							break;
						}
						else if (str[j] == str[l] && l == size_of_str - 1)
						{
							cout << "Так как вся строка состоит из элемента \"" << str[j] << "\", её кратность равна 1." << endl;
							return;
						}
					}
				}
			}
		}
		cout << "Secondary: " << secondary;
		if (primary.isEqual(secondary) && size > 1)
		{
			cout << "\nДлина символов после которых они начинают повторяться равна: " << size << "\nТеперь нужо проверить всю строку на кратность.\nДля успешной проверки, проверяемый указатель должен быть равен длине всей строки.\n" << endl;
			 
			int multiplier_for_k_index = 3;
			int k = (primary.GetSize() * 2);
			while (k < size_of_str)
			{
				secondary.clearArray();
				for (; k < primary.GetSize() * multiplier_for_k_index && k <= size_of_str; ++k)
				{
					secondary.pushBack(str[k]);
				}
				if (primary.isEqual(secondary))
				{
					cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
					++multiplier_for_k_index;
					cout << "Проверяемый указатель: " << k << endl;
					cout << "Сравниваемая подстрока: " << secondary;
				}
				else
				{
					cout << "\nК сожалению строка на проверку кратности не прошла.\n" << endl;
					return;
				}
			}
			cout << "\nСообщение успешно прошло проверку.\nКратность равна: " << size << '\n' << endl;
			return;
		}
		secondary.clearArray();
	}
	cout << "\nПериодичность не найдена.\nСтрока проверку кратности не прошла." << endl;
}