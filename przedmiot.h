#pragma once

#ifndef PRZEDMIOT_H
#define PRZEDMIOT_H

#include <QString>

using namespace std;

class Przedmiot
{
    QString nazwa_przedmiotu;
    QString nazwa_wlasciciela;
    QString kategoria;
    bool czy_wystawiony = 0;

public:


    Przedmiot() {};

    Przedmiot(QString nazwa_przedmiotu, QString nazwa_wlasciciela,   QString kategoria) :nazwa_przedmiotu(nazwa_przedmiotu), nazwa_wlasciciela(nazwa_wlasciciela), kategoria(kategoria), czy_wystawiony(0) {};

    void set_czy_wystawiony();
    void set_nie_wystawiony();

    void set_kategoria(QString nowa);

    QString get_nazwa_przed();

    QString get_nazwa_wlasciciela();

    QString get_kategoria();

    bool get_czy_wystawiony();

    Przedmiot operator =(Przedmiot przed);

    void set_nazwa(QString n);


};

#endif 
