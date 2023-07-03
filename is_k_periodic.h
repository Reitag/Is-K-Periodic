#pragma once
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class StringArray
{
private:
	int cl_size = 0;
	string* cl_arr = nullptr;

public:
	StringArray() = default;
	StringArray(int size);
	StringArray(const StringArray& other);
	~StringArray();
	void pushBack(char value);
	void clearArray();
	bool isEqual(StringArray& arr);
	int GetSize();
	friend ostream& operator<<(ostream& output, const StringArray& arr);
};

void IsKPeriodic(string& str, int& size_of_str);