#include "stdafx.h"
#ifndef RSA_H
#define RSA_H
#define zmienna long long
#include <vector>
#include <string>

using namespace std;

class RSA
{
public: //ogarnij gdzie te vectory wsadzic bro
	string wiadomosc;
	zmienna wiadomoscint; //wiadomosc int
	zmienna wiadomoscintpo; //int po zaszyfrowaniu
	zmienna odszyfrowanaint; //odszyfrowana int



	vector <int> wiadomoscprzed;  //wiadomosc string w postaci int przez zaszyfrowaniem
	vector <int> wiadomoscpo; //wiadomosc string w ostaci int po zaszyfrowaniu
	vector <int> odszyfrowana; //odszyfrowana wiadomosc string w postaci int
	zmienna e, n, d; // (e,n) ,, (d,n)..
	void pobierzwiadomosc();
	void generujklucze(zmienna a, zmienna b);;
	void szyfrujrsa();
	void odszyfrujrsa();
	void szyfrujrsachar();
	void odszyfrujrsachar();
	void wyswietl(vector<int> wektor);
	void zamienstring();


protected:

private:
};

#endif // RSA_H
