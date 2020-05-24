#pragma once

#ifndef SERWIS_UZYTKOWNIK_H
#define SERWIS_UZYTKOWNIK_H

#include "uzytkownik.h"
#include "przedmiot.h"
#include "Aukcja.h"
#include "Rozmowa.h"

#include <vector>
#include <QString>

using namespace std;

class Serwis_uzytkownik :public Uzytkownik
{  
    int numer_konta_powiazanego=0;

public:

    vector<Przedmiot> lista_przedmiotow;
    vector<Aukcja> lista_aukcji;
    vector<Aukcja> historia_zakupow;
    vector<Rozmowa> czat;

    Serwis_uzytkownik();
    
    Serwis_uzytkownik(QString login, QString haslo);

    void dodaj_przedmiot(QString nazwa, QString login, QString kategoria);

    void dodaj_aukcje( QString nazwa, double _cena, QString _data);

    void dodaj_do_historii(QString nazwa, double _cena, QString _data);

    bool powiaz_konto(int numer);

    int get_numer();

    void usun_aukcje(int indeks);

    void usun_przedmiot(int indeks);

};

#endif 
