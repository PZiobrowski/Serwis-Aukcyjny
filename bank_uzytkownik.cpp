#include "bank_uzytkownik.h"

#include <iostream>

Bank_uzytkownik::Bank_uzytkownik(QString login, QString haslo):Uzytkownik(login, haslo)
{
	stan_konta = 0;
	numer_konta = (rand() % 899999)+100000;
}

Bank_uzytkownik::Bank_uzytkownik(){}

int Bank_uzytkownik::get_nr_konta()
{
	return numer_konta;
}

double Bank_uzytkownik::get_stan_konta()
{
    return stan_konta;
}

void Bank_uzytkownik::set_nr_konta(int nr)
{
    numer_konta=nr;
}

void Bank_uzytkownik::set_stan_konta(double stan)
{
    stan_konta=stan;
}


void Bank_uzytkownik::wplac(int ile)
{
		stan_konta += ile;
}

void Bank_uzytkownik::dodaj_do_historii(QString nazwa, double _cena, QString _data)
{
    Aukcja tmp(nazwa,_cena, _data );
    historia_wydatkow.push_back(tmp);
}
