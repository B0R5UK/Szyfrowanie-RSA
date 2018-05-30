#include "stdafx.h"
#include "funkcje.h"
#define zmienna long long
#include "binary.h"
#include <iostream>
#include <math.h>

using namespace std;



//a- podstawa, b- potega mod- modulo///////////////////////
zmienna funkcje::potegowaniemod(zmienna a, zmienna b, zmienna mod)
{
	zmienna wynik = 1, x;
	binary bin;  //tworzymy sobie obiekt
	bin.dectobin(b); //poetga do binarnej
	int ktora;
	//bin.wypisz();
	//cout<<endl;
	x = a;
	for (int i = 0; i<bin.ilebitow(); i++)
	{
		if (bin.binarna[i] == 1) //jesli w bianrnym zpaisie wystepuje 1
		{
			wynik = wynik * x;
			wynik = wynik % mod;
		}
		x = x*x;
		x = x%mod;
	}
	return wynik;
	bin.clear();
}
/////////////////////////////////////////////////////////

zmienna funkcje::NWD(zmienna a, zmienna b)  //liczenie NW alg euklidesa
{
	zmienna tmp;
	while (b != 0)
	{
		tmp = b;
		b = a%b;
		a = tmp;
	}

	return a;
}



int funkcje::wzgledniepierwsza(zmienna a, zmienna b)
{
	if (NWD(a, b) == 1)
	{
		//cout<<"liczby sa wzglednie pierwsze"<<endl;
		return 1;
	}
	else
	{
		//cout<<"liczby nie sa wzglednie peirwsze"<<endl;
		return 0;
	}
}

zmienna funkcje::eul(zmienna a, zmienna b)
{
	return (a - 1) * (b - 1);
}

//narazie wyznaczam najmneijsza nwm czy dobrze!!

zmienna funkcje::znajdznwd(zmienna a)
{
	for (zmienna i = 2; i<a; i++)
	{
		if (wzgledniepierwsza(i, a) == 1)
		{
			return i;
		}
	}

	return 0;
}
/////////////////////////////////////////////////////////////////////
// a - podstawa, mod - modulo
zmienna funkcje::odwrotnoscmod(zmienna a, zmienna mod) //rozszerzonym euklidesem zwraca x - odwrotnosc a modulo mod
{
	zmienna u, w, x, z, q;
	u = 1; w = a;
	x = 0; z = mod;

	while (w)
	{
		if (w < z)
		{
			q = u; u = x; x = q;
			q = w; w = z; z = q;
		}
		q = w / z;
		u -= q * x;
		w -= q * z;
	}
	if (z == 1)
	{
		if (x < 0) x += mod;
		//cout << x << endl;
		return x;
	}
	else return 0;
}






