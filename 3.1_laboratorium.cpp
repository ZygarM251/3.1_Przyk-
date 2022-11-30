#include<iostream>
using namespace std;
#define ZadanieC


#ifdef ZadanieA

using namespace std;

int main(void)
{
	setlocale(LC_ALL, "");

	constexpr int SIZE = 5;
	int tab[SIZE][SIZE] = {};
	int suma_w[SIZE] = {}, suma_k[SIZE] = {};
	bool jestrownek = true, jestrownew = true;
	// Element początkowy:
	int w = 0, k = SIZE / 2; //2.5 więc do 2 a indeks od 0 więc 3 element
	tab[w][k] = 1;

	//Następne elementy:
	for (int n = 2; n <= SIZE * SIZE; n += 1)
	{
		//Przesuń współrzędne
		w -= 1; k += 1;
		//Sprawdź i skoryguj naruszenie granic tablicy:
		if (w < 0)
			w += SIZE;
		if (k >= SIZE)
			k -= SIZE;
		//Sprawdź, czy element tablicy był już zapisany:
		if (tab[w][k] != 0)
		{
			//Przesuń współrzędne i sprawdź granice:
			w += 2;
			k -= 1;
			if (w >= SIZE)
				w -= SIZE;
			if (k < 0)
				k += SIZE;

		}
		//Zapisz element:
		tab[w][k] = n;
	}
	cout << "Czy w kwadracie nie ma powtarzających się wyrazów? ";
	bool unikat = true;
	for (int x = 0; x < SIZE; x++)
	{
		for (int y = 0; y < SIZE; y++)
		{
			if (tab[x][y] == tab[x + 1][y + 1])
			{
				unikat = false;
			}
		}
	}
	if (unikat = true)
	{
		cout << "TAK!" << endl;
	}
	else
	{
		cout << "NIE!" << endl;
	}
	int przekatna1 = 0, przekatna2 = 0;
	cout << "Czy suma wyrazów na obu przekątnych jest równa 65? ";
	for (int x = 0; x < SIZE; x++)
	{
		for (int y = 0; y < SIZE; y++)
		{
			if (x == y)
			{
				przekatna1 += tab[x][y];
			}
			if (x + y == 4)
			{
				przekatna2 += tab[x][y];
			}
		}
	}
	if (przekatna1 == 65 && przekatna2 == 65)
	{
		cout << "TAK!" << endl;
	}
	else
	{
		cout << "NIE!" << endl;
	}
	cout << "Czy suma wyrażeń w kolumnach jest równa 65? ";
	for (int x = 0; x < SIZE; x++)
	{
		for (int y = 0; y < SIZE; y++)
		{
			suma_k[y] += tab[x][y];
		}

	}
	for (int x = 0; x < 5; x++)
	{
		if (65 != suma_k[x])
		{
			jestrownek = false;
		}
		else
		{
			jestrownek = true;
		}
	}
	if (jestrownek = true)
	{
		cout << "TAK!" << endl;
	}
	else
	{
		cout << "NIE!" << endl;
	}
	cout << "Czy suma wyrazów w wierszach jest równa 65? ";
	for (int x = 0; x < SIZE; x++)
	{
		for (int y = 0; y < SIZE; y++)
		{
			suma_w[x] += tab[x][y];
		}
		for (int x = 0; x < 5; x++)
		{
			if (65 != suma_w[x])
			{
				jestrownew = false;
			}
			else
			{
				jestrownew = true;
			}
		}
	}
	if (jestrownew = true)
	{
		cout << "TAK!" << endl;
	}
	else
	{
		cout << "NIE!" << endl;
	}
	//Wyświetl tablicę:
	for (int x = 0; x < SIZE; x += 1)
	{
		for (int y = 0; y < SIZE; y += 1)
		{
			cout << tab[x][y] << "\t";
		}
		cout << endl;
	}


}
#endif

#ifdef ZadanieB


void main(void)
{
	//Tekst do przeszukania:
	char tekst[] = "{}()[";
	int liczniki[3];
	//Wyszukiwanie nawiasów:
	int i = 0;
	while (tekst[i])
	{
		switch (tekst[i])
		{
		case '(':
			liczniki[0] += 1;
			i++;
			break;
		case ')':
			liczniki[0] -= 1;
			i += 1;
			break;
		case '[':
			liczniki[1] += 1;
			i++;
			break;
		case ']':
			liczniki[1] -= 1;
			i++;
			break;
		case '{':
			liczniki[2] += 1;
			i++;
			break;
		case '}':
			liczniki[2] -= 1;
			i++;
			break;
		default:
			i += 1;
		}
		if (liczniki[0] < 0 && liczniki[1] < 0 && liczniki[2] < 0) break;
	}
	if (liczniki[0] > 0) cout << "Bledna liczba ()\n";
	if (liczniki[1] > 0) cout << "Bledna liczba []\n";
	if (liczniki[2] > 0) cout << "Bledna liczba {}\n";
	cout << "Liczebnosci nawiasow sa OK\n";
}
#endif

#ifdef ZadanieC


void main(void)
{
	constexpr int ROZMIAR_DANYCH = 100, ROZMIAR_KLUCZA = 4;
	constexpr int NAJWYZSZY_KOD_ZNAKU = 127;
	char tekstWe[ROZMIAR_DANYCH];
	char klucz[ROZMIAR_KLUCZA];
	char szyfr[ROZMIAR_DANYCH];
	char tekstWy[ROZMIAR_DANYCH];

	//Pobranie danych:
	cout << "Wiadomosc: ";
	fgets(tekstWe, ROZMIAR_DANYCH - 1, stdin);
	cout << "Klucz szyfrujacy: ";
	fgets(klucz, ROZMIAR_KLUCZA - 1, stdin);

	//Szyfrowanie:
	for (int i = 0; i < ROZMIAR_DANYCH; i += 1)
	{
		szyfr[i] = (tekstWe[i] + klucz[i % ROZMIAR_KLUCZA]) % NAJWYZSZY_KOD_ZNAKU;
	}
	cout << "Szyfrogram: " << szyfr << endl;

	// Odszyfrowanie:
	for (int i = 0; i < ROZMIAR_DANYCH; i += 1)
	{
		tekstWy[i] = (szyfr[i] - klucz[i % ROZMIAR_KLUCZA]) % NAJWYZSZY_KOD_ZNAKU;
	}
	cout << "Wiadomosc: " << tekstWy << endl;
}
#endif