#include "Aukcja.h"

#include <QDebug>

Aukcja::Aukcja(Przedmiot &_przedmiot, QString nazwa, double _cena, QString _data) : cena(_cena), data(_data), nazwa_aukcji(nazwa)
{
    przedmiot= & _przedmiot;
}


void Aukcja::dodaj_przedmiot_do_aukcji( Przedmiot & _przedmiot)
{
    przedmiot = & _przedmiot;
    _przedmiot.set_czy_wystawiony();
}

QString Aukcja::get_nazwa()
{
	return nazwa_aukcji;
}

double Aukcja::get_cena()
{
	return cena;
}

QString Aukcja::get_data()
{
	return data;
}

void Aukcja:: set_nazwa(QString nowa)
{
    nazwa_aukcji=nowa;
}

void Aukcja:: set_cena(double nowa)
{
    cena=nowa;
}
