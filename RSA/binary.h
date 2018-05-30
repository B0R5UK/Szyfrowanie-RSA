#ifndef BINARY_H
#define BINARY_H
#include <vector>

#define zmienna long long

class binary
{
public:
	std::vector <int> binarna; //liczba int w postaci binarnej
	int ilebitow();
	void dectobin(zmienna n);
	void wypisz();
	void clear();

protected:

private:
};

#endif // BINARY_H
