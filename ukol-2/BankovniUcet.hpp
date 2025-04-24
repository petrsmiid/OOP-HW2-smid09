#pragma once

#include <iostream>
using namespace std;

/*
* Globální funkce. 
* Zjistí délku øetìzce. 
*/
int Length_Str(char* s);

/*
 * Tøída popisuje bankovní úèet.
 */
class BankovniUcet
{
private:

	/*
	* Konstanta objektu. Defaultní hodnota pro max. výbìr.
	*/
	enum { MAX_VYBER = 1000 };

	/*
	* Hodnota max. výbìru nastavena na úètu.
	*/
	int max_vyber;

	/*
	* Zùstatek na úètu.
	*/
	double zustatek;

	/*
	* Èíslo úètu (dynamicky alokovaný øetìzec).
	*/
	char *cislo_uctu;

	/*
	* Poèet vkladu.
	*/
	int n_vklad;

	/*
	* Poèet výbìru.
	*/
	int n_vyber;

	/*
	* Soucet vkladu (Celkovy vklad).
	*/
	double suma_vklad;

	/*
	* Souèet výbìru (Celkový výbìr).
	*/
	double suma_vyber;

public:	

	/*
	* Konstruktor parametrický. 
	* Provede inicializaci objektu bankovního úètu podle pøedaného èísla úètu (použije kopii hodnoty øetìzce a vytvoøí øetìzec atributu nezbytnì nutné délky), hodnota max. výbìru bude defaultní hodnota specifikovana konstantou MAX_VYBER.
	*/
	BankovniUcet(char *cislo_uctu);

	/*
	* Konstruktor parametrický. 
	* Provede inicializaci objektu bankovního úètu z pøedaných hodnot èísla úètu  (použije kopii hodnoty øetìzce a vytvoøí øetìzec atributu nezbytnì nutné délky) a maximálního výbìru. 
	*/
	BankovniUcet(char *cislo_uctu, int max_vyber);

	/*
	* Destruktor.
	* Provede uvolnìní objektu.
	*/
	~BankovniUcet();

	// ----

	/*
	* Vrátí aktuální zùstatek na úètu (hodnotu nastavenou v atributu zustatek).
	*/
	double GetZustatek() const;

	/*
	* Vrátí nastavené èíslo úètu, resp. odkaz na text.
	*/
	char* GetCisloUctu() const;

	/*
	* Vrátí nastavený maximální výbìr z úètu (hodnotu nastavenou v atributu max_vyber).
	*/
	int GetMaxVyber() const;

	/*
	* Pøenastaví hodnotu maximálního výbìru na úètu pokud bude nastavovaná hodnota platnou hodnotou kladného èísla. V opaèném pøípadì nastavení neprobìhne.
	*/
	void SetMaxVyber(int max_vyber);

	/*
	* Vrátí poèet vkladù (hodnotu nastavenou v atributu n_vklad).
	*/
	int Get_n_vklad() const;

	/*
	* Vrátí poèet výbìrù (hodnotu nastavenou v atributu n_vyber).
	*/
	int Get_n_vyber() const;

	/*
	* Vrátí sumu vkladù (hodnotu nastavenou v atributu suma_vklad).
	*/
	double Get_suma_vklad() const;

	/*
	* Vrátí sumu výbìrù (hodnotu nastavenou v atributu suma_vyber). 
	*/
	double Get_suma_vyber() const;

	// ----

	/*
	* Zajistí vložení èástky kolik na úèet, pokud bude èástka splòovat podmínku nezáporného èísla. Návratovou hodnotou vrátí pøíznak provedení operace - true : provedeno, false : neprovedeno. 
	*/
	bool Vlozit(double kolik);

	/*
	* Zajistí výbìr èástky kolik z úètu, pokud bude èástka splòovat podmínku nezáporného èísla a podmínku pro omezení výbìru (< max_vyber).
	*/
	bool Vybrat(double kolik);

	// ----

	/*
	* Pøetížení operátoru výstupu, který zapíše do výstupního proudu informace o úèetu ve tvaru:
	* èíslo úètu : zùstatek Kè
	* poèet vkladù : +suma Kè
	* poèet výbìrù : -suma Kè
	*/
	friend ostream& operator<<(ostream &os, const BankovniUcet &u);
};



