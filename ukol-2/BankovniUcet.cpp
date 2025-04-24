#include "BankovniUcet.hpp"

int Length_Str(char* s)
{
	int n = 0;
	while (s[n] != '\0')
		n++;
	return n;
}

// ---

BankovniUcet::BankovniUcet(char* cislo_uctu) : BankovniUcet(cislo_uctu, MAX_VYBER)
{
	;
}

BankovniUcet::BankovniUcet(char* cislo_uctu, int max_vyber)
{
	/* TODO */
	this->cislo_uctu = new char[12];
	strcpy_s(this->cislo_uctu, 12, cislo_uctu);
	this->max_vyber = max_vyber;
}

BankovniUcet::~BankovniUcet()
{
	/* TODO */
	delete(this->cislo_uctu);
}

// ----

double BankovniUcet::GetZustatek() const
{
	/* TODO */
	return this->zustatek;
}

char* BankovniUcet::GetCisloUctu() const
{
	/* TODO */
	return this->cislo_uctu;
}

int BankovniUcet::GetMaxVyber() const
{
	/* TODO */
	return this->max_vyber;
}

void BankovniUcet::SetMaxVyber(int max_vyber)
{
	/* TODO */
	this->max_vyber = max_vyber;
}

int BankovniUcet::Get_n_vklad() const
{
	/* TODO */
	return this->n_vklad;
}

int BankovniUcet::Get_n_vyber() const
{
	/* TODO */
	return this->n_vyber;
}

double BankovniUcet::Get_suma_vklad() const
{
	/* TODO */
	return this->suma_vklad;
}

double BankovniUcet::Get_suma_vyber() const
{
	/* TODO */
	return this->suma_vyber;
}

// ----

bool BankovniUcet::Vlozit(double kolik)
{
	/* TODO */
	if (kolik > 0)
	{
		this->zustatek += kolik;
		this->suma_vklad += kolik;
		this->n_vklad++;
		return true;
	}
	return false;
}

bool BankovniUcet::Vybrat(double kolik)
{
	/* TODO */
	if ((this->zustatek - kolik >= 0) && kolik > 0 && kolik <= max_vyber)
	{
		this->zustatek -= kolik;
		this->suma_vyber += kolik;
		this->n_vyber++;
		return true;
	}
	return false;
}

// ----

/*friend*/ ostream& operator<<(ostream& os, const BankovniUcet& u)
{
	/* TODO */
	return os << u.cislo_uctu << " : " << u.zustatek << " Kc\n" << u.n_vklad << " : +" << u.suma_vklad << " Kc\n" << u.n_vyber << " : -" << u.suma_vyber << " Kc\n";;
}
