#include "stdafx.h"
#include "RSA.h"
#include "binary.h"
#include "funkcje.h"
#define zmienna long long
#include <iostream>
#include <string>
funkcje fun;

using namespace std;



void RSA::generujklucze(zmienna a, zmienna b)
{
	zmienna euler = fun.eul(a, b);
	n = a*b;
	//eulr w funkcjach
	//znajdujemy male e ktore jest wzglednie peirwsze z eulera
	e = fun.znajdznwd(euler);
	d = fun.odwrotnoscmod(e, euler); //wez ta funkcje ogarnij bo jakas krzywa

	cout << "wyznaczono e : " << e << " euler : " << euler << " oraz d : " << d << endl;
	cout << "KLUCZ PUBLICZNY TO PARA LICZB (e,n) : (" << e << "," << n << ")" << endl;
	cout << "KLUCZ PRYWATNY TO PARA LICZB (d,n) : (" << d << "," << n << ")" << endl;
}

void RSA::pobierzwiadomosc()
{
	cout << "podaj wiadomosc do zaszyfrowania : : ";
	getline(cin, wiadomosc);
	getline(cin, wiadomosc);
	zamienstring();
}


//szyfruje wiadomosc tekstowa
void RSA::szyfrujrsachar()
{
	cout << endl << "wiadomosc do zaszyfrowania : ";
	wyswietl(wiadomoscprzed);
	cout << "szyfrowanie przy uzyciu klucza publicznego RSA (e,n) : (" << e << "," << n << ")" << endl;
	//moze to wjebac w funkcje ? ogolnie to c = t(podanytekst) ^ e mod n - uzywam szybkiego pot modulo
	for (int i = 0; i<wiadomoscprzed.size(); i++)
	{
		wiadomoscpo.push_back(fun.potegowaniemod(wiadomoscprzed[i], e, n));
	}
	cout << endl << "wiadomosc po zaszyfrowaniu na int : ";
	wyswietl(wiadomoscpo);
}

//odszyfrowujechary
void RSA::odszyfrujrsachar()
{
	cout << "odszyfrowywanie przy uzyciu klucza prywatnego RSA (d,n) : (" << d << "," << n << ")" << endl;
	for (int i = 0; i<wiadomoscpo.size(); i++)
	{
		//t = c(podanytekst) ^ d mod n - uzywam szybkiego pot modulo
		odszyfrowana.push_back(fun.potegowaniemod(wiadomoscpo[i], d, n));
	}

	cout << endl << "wiadomosc po odszyfrowaniu : ";
	wyswietl(odszyfrowana);
	//sprzata po sobie
	wiadomoscpo.clear();
	wiadomoscprzed.clear();
	odszyfrowana.clear();
}





//zamienia string na liste int
void RSA::zamienstring()
{
	int n;
	for (int i = 0; i<wiadomosc.length(); i++)
	{
		n = wiadomosc[i];
		wiadomoscprzed.push_back(n);
	}
}





//wyswietla podany vector intow
void RSA::wyswietl(vector<int> wektor)
{
	for (int i = 0; i<wektor.size(); i++)
	{
		cout << wektor[i];
	}
	cout << " W CHARACH : ";
	char test;

	for (int i = 0; i<wektor.size(); i++)
	{
		test = wektor[i];
		cout << test;
	}
	cout << endl;
}

void RSA::szyfrujrsa()
{
	cout << "podaj wiadomosc do zaszyfrowania : : " << endl;
	cin >> wiadomoscint;
	cout << "szyfrowanie przy uzyciu klucza publicznego RSA (e,n) : (" << e << "," << n << ")";
	wiadomoscintpo = fun.potegowaniemod(wiadomoscint, e, n);
	cout << "Wiadomosc po zaszyfrowaniu : " << wiadomoscintpo << endl;

}

void RSA::odszyfrujrsa()
{
	cout << "odszyfrowanie przy uzyciu klucza publicznego RSA (d,n) : (" << d << "," << n << ")" << endl;
	odszyfrowanaint = fun.potegowaniemod(wiadomoscintpo, d, n);
	cout << "Wiadomosc po odszyfrowaniu : " << odszyfrowanaint << endl;

}



