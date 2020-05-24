#pragma once

#include "przedmiot.h"

#include <QString>

class Aukcja
{

    QString nazwa_aukcji;
    double cena;
    QString data;

public:

    Przedmiot* przedmiot=nullptr;

	Aukcja() {};

    Aukcja(Przedmiot &_przedmiot, QString nazwa, double _cena, QString _data);

    Aukcja(QString nazwa,double _cena, QString _data ) :przedmiot(nullptr), cena(_cena), data(_data), nazwa_aukcji(nazwa) {};

    QString get_nazwa();

    double get_cena();

    void set_nazwa(QString nowa);

    void set_cena(double nowa);

    QString get_data();

    void dodaj_przedmiot_do_aukcji( Przedmiot& przedmiot);
};

