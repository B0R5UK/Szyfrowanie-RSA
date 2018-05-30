// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "binary.h"
#include "funkcje.h"
#include "RSA.h"
#include <string>
#define zmienna long long


//liczby pierwsze sluzace do generowania kluczy RSA

#define p  39443 //pierwsza l. pierwsza
#define q  38281 //druga l pierwsza


using namespace std;

int main()
{
	funkcje fun;
	RSA rsa;


	int wybor = 1;
	cout << "======== PROGRAM DO IMPLEMENTACJI SZYFROWANIA I DESZYFROWANIA RSA ========" << endl;
	cout << "dla liczb pierwszych p : " << p << " oraz q : " << q << endl;
	rsa.generujklucze(p, q);
	while (wybor != 0)
	{
		cout << endl << "1. Szyfrowanie wiadomosci w postaci tekstowej" << endl << "2. Szyfrowanie wiadomosci w postaci numerycznej" << endl << "0. Wyjscie!" << endl;
		cin >> wybor;
		switch (wybor)
		{
		case 1:
			rsa.pobierzwiadomosc();
			rsa.szyfrujrsachar();
			cout << endl;
			rsa.odszyfrujrsachar();
			break;

		case 2:
			rsa.szyfrujrsa();
			rsa.odszyfrujrsa();
			break;

		case 0:
			cout << endl << "WYJSCIE !!!";
			break;

		}
	}



	return 0;
}
