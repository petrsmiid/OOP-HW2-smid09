#pragma once

#include "BankovniUcet.hpp"

/*
* Tøída obsluhuje práci s úètem. 
*/
class PraceSUctem
{
public:

	/*
	* Zobrazí menu na standardní výstup (dle zadání).
	*/
	void tisk_menu();

	/*
	* Zobrazí pokyn 'Zadej volbu' na standardní výstup a zajistí naètení znaku ze standardního vstupu. 
	* Naètený znak vrátí návratovou hodnot (bez kontroly, jakýkoliv znak).
	*/
	char volba_menu();

	/*
	* Otestuje znak, jestli je platnou volbou menu. Výsledek testování vrátí návratovou hodnotu true - OK, false - chybný znak.
	*/
	bool test_volba_menu(char volba);

	/*
	* S využitím funkcí výše zajistí zobrazení menu. A následnì opakované naètení volby menu, pokud bude zadána neplatná volba.
	*/
	char zajisti_volba_menu_kontrola();

	/*
	* Zajistí vytvoøení objektu bankovního úètu s defaultní hodnotou maximálního výbìru. Odkaz na vytvoøený objekt vrátí návratovou hodnotou. 
	*/
	BankovniUcet* operace_vytvorit_bankovni_ucet(char *cislo_uctu);

	/*
	*  Zajistí vytvoøení objektu bankovního úètu s daným èíslem úètu a hodnotou maximálního výbìru. Odkaz na vytvoøený objekt vrátí návratovou hodnotou. 
	*/
	BankovniUcet* operace_vytvorit_bankovni_ucet(char* cislo_uctu, int max_vyber);

	/*	
	* Dotáže se, zda se má vytvoøit úèet s defaultní hodnotou maximálního vkladu nebo se zadanou hodnotou maximálního vkladu. 
	* Zajistí naètení èísla úètu a pøípadnì hodnoty maximálního vkladu, zajistí vytvoøení odpovídajícího úètu. 
	* Viz zadání úkolu.
	*/
	BankovniUcet* zajistit_vytvorit_bankovni_ucet();

	/*
	* Zajistí vložení èástky kolik na úèet a zobrazí výsledek provedení operace. Viz zadání úkolu. 
	*/
	void operace_vlozit_na_ucet(BankovniUcet* u, double kolik);

	/*
	* Pro pøedaný bankovní úèet provede vklad zadané èástky pro vložení. 
	* Využije výše definovaných metod. 
	*/
	void zajistit_vlozit_na_ucet(BankovniUcet* u);

	/*
	* Zajistí výbìr èástky kolik z úèet a zobrazí výsledek provedení operace. Viz zadání úkolu. 
	*/
	void operace_vybrat_z_uctu(BankovniUcet* u, double kolik);

	/*
	* Pro pøedaný bankovní úèet provede výbìr zadané èástky pro výbìr.
	* Využije výše definovaných metod.
	*/
	void zajistit_vybrat_z_uctu(BankovniUcet* u);

	/*
	* Zajistí zobrazení informací o úètì na standardním výstupu. 
	* Využije se pøetížení operátoru <<.
	*/
	void operace_tisk_info_ucet(BankovniUcet *u);

	/*
	* Zajistí zápis informací o úètu do souboru definovaného parametrem. 
	*/
	void operace_ulozit_do_souboru(BankovniUcet* u, char* filename);

	/*
	* Pro pøedaný úèet, zajistí zápis informací o úètì do zadaného souboru.
	* Využije se výše definovaných metod.
	*/
	void zajisti_ulozit_do_souboru(BankovniUcet* u);

	// ----

	/*
	* Zajistí kompletní realizaci obsluhy a práce úètem, viz zadání úkolu. 
	*/
	void realizace();

};
