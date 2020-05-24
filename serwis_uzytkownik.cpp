#include "serwis.h"
#include <iostream>

Serwis_uzytkownik::Serwis_uzytkownik(QString login, QString haslo) :Uzytkownik(login, haslo){}

Serwis_uzytkownik::Serwis_uzytkownik()  {}

void Serwis_uzytkownik::dodaj_przedmiot(QString nazwa, QString login,  QString kategoria)
{
	Przedmiot tmp(nazwa, login, kategoria);
	lista_przedmiotow.push_back(tmp);
}

void Serwis_uzytkownik::dodaj_aukcje(QString nazwa, double _cena, QString _data )
{
    Aukcja tmp( nazwa,_cena,_data);
	lista_aukcji.push_back(tmp);


}
void Serwis_uzytkownik::dodaj_do_historii(QString nazwa,double _cena, QString _data)
{
	Aukcja tmp(nazwa,_cena, _data );
	historia_zakupow.push_back(tmp);
}

bool Serwis_uzytkownik:: powiaz_konto(int numer)
{
    numer_konta_powiazanego=numer;
}

int Serwis_uzytkownik::get_numer()
{
    return numer_konta_powiazanego;
}
void Serwis_uzytkownik::usun_przedmiot(int indeks)
{
    for (int i=indeks; i < lista_przedmiotow.size()-1; i++)
            swap(lista_przedmiotow[i],lista_przedmiotow[i+1]);

    lista_przedmiotow.pop_back();
}

void Serwis_uzytkownik::usun_aukcje(int indeks)
{

    for (int i=indeks; i < lista_aukcji.size()-1; i++)
            swap(lista_aukcji[i],lista_aukcji[i+1]);

    lista_aukcji.back().przedmiot->set_nie_wystawiony();
    lista_aukcji.pop_back();
}


