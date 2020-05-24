#include "przedmiot.h"
#include <QDebug>

void Przedmiot::set_czy_wystawiony()
{
	czy_wystawiony = 1;
}
void Przedmiot::set_nie_wystawiony()
{
    czy_wystawiony=0;
}

void Przedmiot::set_kategoria(QString nowa)
{
    kategoria=nowa;
}

QString Przedmiot::get_nazwa_przed()
{
	return nazwa_przedmiotu;
}

QString Przedmiot::get_nazwa_wlasciciela()
{
	return nazwa_wlasciciela;
}

QString Przedmiot::get_kategoria()
{
	return kategoria;
}

bool Przedmiot::get_czy_wystawiony()
{
	return czy_wystawiony;
}

Przedmiot  Przedmiot :: operator =(Przedmiot przed)
{
    this->nazwa_przedmiotu=przed.nazwa_przedmiotu;
}

void Przedmiot:: set_nazwa(QString n)
{
    nazwa_przedmiotu=n;
}
