#pragma once

#ifndef BANK_UZYTKOWNIK_H
#define BANK_UZYTKOWNIK_H

#include "uzytkownik.h"
#include "Aukcja.h"

#include <vector>
#include <QString>

using namespace std;

class Bank_uzytkownik:public Uzytkownik
{
    int numer_konta;
    double stan_konta;

public:

    vector<Aukcja> historia_wydatkow;

    Bank_uzytkownik();

    Bank_uzytkownik(QString login, QString haslo);

    int get_nr_konta();

    double get_stan_konta();

    void set_nr_konta(int nr);

    void set_stan_konta(double stan);


    void wplac(int ile);

    void dodaj_do_historii(QString nazwa, double _cena, QString _data);
 

};

#endif 
