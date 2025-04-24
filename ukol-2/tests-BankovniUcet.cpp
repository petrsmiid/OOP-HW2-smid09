#include "BankovniUcet.hpp"

#include "catch.hpp"



TEST_CASE("Object creation and inicialization", "[all]") {
	SECTION("#1") {
		//char cislo_uctu[] = { "123456/0800" };
		char* cislo_uctu1 = new char[12]{ "123456/0800" };
		BankovniUcet* u1 = new BankovniUcet(cislo_uctu1);
		// test init
		REQUIRE(strcmp(u1->GetCisloUctu(), cislo_uctu1) == 0);
		REQUIRE(u1->GetMaxVyber() == 1000);
		// test kopie 
		REQUIRE(u1->GetCisloUctu() != cislo_uctu1);
		delete[] cislo_uctu1;
		cislo_uctu1 = NULL;
		REQUIRE(strcmp(u1->GetCisloUctu(), "123456/0800") == 0);
		char* p = u1->GetCisloUctu();
		REQUIRE(u1->GetCisloUctu() != NULL);
		delete u1;
		//REQUIRE(p == NULL);
	}

	SECTION("#2") {
		char* cislo_uctu2 = new char[12]{ "654321/0800" };
		BankovniUcet* u2 = new BankovniUcet(cislo_uctu2);
		// test init
		REQUIRE(strcmp(u2->GetCisloUctu(), cislo_uctu2) == 0);
		delete u2;
		delete[] cislo_uctu2;
	}	

	SECTION("#3") {
		char* cislo_uctu3 = new char[12]{ "123456/0800" };
		BankovniUcet* u3 = new BankovniUcet(cislo_uctu3, 2500);
		//REQUIRE(strcmp(u1->GetCisloUctu(), cislo_uctu1) == 0);
		REQUIRE(u3->GetMaxVyber() == 2500);
		delete u3;
		//REQUIRE(p == NULL);
	}

	SECTION("#4") {
		char* cislo_uctu4 = new char[12]{ "654321/0800" };
		BankovniUcet* u4 = new BankovniUcet(cislo_uctu4, 3500);
		REQUIRE(u4->GetMaxVyber() == 3500);
		delete u4;
		delete[] cislo_uctu4;
	}
}

TEST_CASE("Work with object", "[all]") {
		SECTION("#1") {
			bool op;
			char* cislo_uctu1 = new char[12]{ "123456/0800" };
			BankovniUcet* u1 = new BankovniUcet(cislo_uctu1);
			//REQUIRE(strcmp(u1->GetCisloUctu(), cislo_uctu1) == 0);

			//REQUIRE(u1->GetMaxVyber() == 1000);
			REQUIRE(u1->GetZustatek() == 0.0);
			REQUIRE(u1->Get_n_vklad() == 0);
			REQUIRE(u1->Get_n_vyber() == 0);
			REQUIRE(u1->Get_suma_vklad() == 0.0);
			REQUIRE(u1->Get_suma_vyber() == 0.0);

			op = u1->Vlozit(500);
			REQUIRE(op == true);
			REQUIRE(u1->GetZustatek() == 500.0);
			REQUIRE(u1->Get_n_vklad() == 1);
			REQUIRE(u1->Get_n_vyber() == 0);
			REQUIRE(u1->Get_suma_vklad() == 500.0);
			REQUIRE(u1->Get_suma_vyber() == 0.0);

			op = u1->Vlozit(300);
			REQUIRE(op == true);
			REQUIRE(u1->GetZustatek() == 800.0);
			REQUIRE(u1->Get_n_vklad() == 2);
			REQUIRE(u1->Get_n_vyber() == 0);
			REQUIRE(u1->Get_suma_vklad() == 800.0);
			REQUIRE(u1->Get_suma_vyber() == 0.0);

			op = u1->Vlozit(-100.0);
			REQUIRE(op == false);
			REQUIRE(u1->GetZustatek() == 800.0);
			REQUIRE(u1->Get_n_vklad() == 2);
			REQUIRE(u1->Get_n_vyber() == 0);
			REQUIRE(u1->Get_suma_vklad() == 800.0);
			REQUIRE(u1->Get_suma_vyber() == 0.0);

			// ----

			op = u1->Vybrat(600);
			REQUIRE(op == true);
			REQUIRE(u1->GetZustatek() == 200.0);
			REQUIRE(u1->Get_n_vklad() == 2);
			REQUIRE(u1->Get_n_vyber() == 1);
			REQUIRE(u1->Get_suma_vklad() == 800.0);
			REQUIRE(u1->Get_suma_vyber() == 600.0);

			op = u1->Vybrat(250);
			REQUIRE(op == false);
			REQUIRE(u1->GetZustatek() == 200.0);
			REQUIRE(u1->Get_n_vklad() == 2);
			REQUIRE(u1->Get_n_vyber() == 1);
			REQUIRE(u1->Get_suma_vklad() == 800.0);
			REQUIRE(u1->Get_suma_vyber() == 600.0);

			op = u1->Vybrat(200);
			REQUIRE(op == true);
			REQUIRE(u1->GetZustatek() == 0.0);
			REQUIRE(u1->Get_n_vklad() == 2);
			REQUIRE(u1->Get_n_vyber() == 2);
			REQUIRE(u1->Get_suma_vklad() == 800.0);
			REQUIRE(u1->Get_suma_vyber() == 800.0);

			op = u1->Vybrat(-100);
			REQUIRE(op == false);
			REQUIRE(u1->GetZustatek() == 0.0);
			REQUIRE(u1->Get_n_vklad() == 2);
			REQUIRE(u1->Get_n_vyber() == 2);
			REQUIRE(u1->Get_suma_vklad() == 800.0);
			REQUIRE(u1->Get_suma_vyber() == 800.0);

			// ----

			u1->Vlozit(400);
			REQUIRE(u1->GetZustatek() == 400.0);
			REQUIRE(u1->Get_n_vklad() == 3);
			REQUIRE(u1->Get_n_vyber() == 2);
			REQUIRE(u1->Get_suma_vklad() == 1200.0);
			REQUIRE(u1->Get_suma_vyber() == 800.0);

			// ----

			u1->SetMaxVyber(250);
			REQUIRE(u1->GetMaxVyber() == 250);
			op = u1->Vybrat(300);
			REQUIRE(op == false);

			delete u1;
		}
}
