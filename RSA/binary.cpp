#include "stdafx.h"
#include "binary.h"
#include <vector>
#include <iostream>

#define zmienna long long



using namespace std;



void binary::dectobin(zmienna n)
{
	while (n != 0)
	{
		// binarna.insert(binarna.begin(),n%2);
		binarna.push_back(n % 2);
		n = n / 2;
	}
}


int binary::ilebitow()
{
	return binarna.size();
}

void binary::wypisz()
{
	cout << "LICZBA W BIN TO : ";
	for (int i = 0; i<binarna.size(); i++)
	{
		std::cout << binarna[i];
	}

}

void binary::clear()
{
	binarna.clear();
}
