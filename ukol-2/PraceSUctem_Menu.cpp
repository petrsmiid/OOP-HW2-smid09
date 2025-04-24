#include <iostream>
#include <fstream>
using namespace std;
#include "PraceSUctem_Menu.hpp"

void PraceSUctem::tisk_menu()
{
	cout << "1 - vytvorit ucet\n";
	cout << "2 - vlozit na ucet\n";
	cout << "3 - vybrat z uctu\n";
	cout << "4 - zobrazit stav uctu\n";
	cout << "5 - ulozit do souboru\n";
	cout << "K - KONEC\n";
}

char PraceSUctem::volba_menu()
{
	char volba;

	cout << "Zadej volbu: ";
	cin >> volba;
	return volba;
}

bool PraceSUctem::test_volba_menu(char volba)
{
	return (volba >= '1' && volba <= '5' || volba == 'K' || volba == 'k');
	// nebo
	// (volba == '1' || volba == '2' || volba == '3' || volba == '4' || volba == '5' || volba == 'k' || volba == 'K')
}

char PraceSUctem::zajisti_volba_menu_kontrola()
{
	char volba;

	tisk_menu();
	do
	{
		volba = volba_menu();
	} while (test_volba_menu(volba) == false);
	return volba;
}

// -----

BankovniUcet* PraceSUctem::operace_vytvorit_bankovni_ucet(char* cislo_uctu)
{
	/* TODO */
	return nullptr;
}

BankovniUcet* PraceSUctem::operace_vytvorit_bankovni_ucet(char* cislo_uctu, int max_vyber)
{
	/* TODO */
	return nullptr;
}

BankovniUcet* PraceSUctem::zajistit_vytvorit_bankovni_ucet()
{
	/* TODO */
	return nullptr;
}

// -----

void PraceSUctem::operace_vlozit_na_ucet(BankovniUcet* u, double kolik)
{
	/* TODO */
}

void PraceSUctem::zajistit_vlozit_na_ucet(BankovniUcet* u)
{
	/* TODO */
}

// --

void PraceSUctem::operace_vybrat_z_uctu(BankovniUcet* u, double kolik)
{
	/* TODO */
}

void PraceSUctem::zajistit_vybrat_z_uctu(BankovniUcet* u)
{
	/* TODO */
}

// -----

void PraceSUctem::operace_tisk_info_ucet(BankovniUcet* u)
{
	/* TODO */
}

// --

void PraceSUctem::operace_ulozit_do_souboru(BankovniUcet* u, char *filename)
{
	/* TODO */
}

void PraceSUctem::zajisti_ulozit_do_souboru(BankovniUcet* u)
{
	/* TODO */
}

// -----

void PraceSUctem::realizace()
{
	BankovniUcet* ucet = NULL;
	char volba;

	do
	{
		volba = zajisti_volba_menu_kontrola();
		switch (volba)
		{
		case '1':
			ucet = zajistit_vytvorit_bankovni_ucet();
			break;

		case '2':
			zajistit_vlozit_na_ucet(ucet);
			break;

		case '3':
			zajistit_vybrat_z_uctu(ucet);
			break;

		case '4':
			operace_tisk_info_ucet(ucet);
			break;

		case '5':
			zajisti_ulozit_do_souboru(ucet);
			break;
		}
	} while (volba != 'K' && volba != 'k');

	delete ucet;
}
