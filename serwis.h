#pragma once

#ifndef SERWIS_H
#define SERWIS_H

#include "serwis_uzytkownik.h"
#include <vector>
#include <QMessageBox>
#include <QString>

using namespace std;

class Serwis
{

public:

    vector<Serwis_uzytkownik> lista_uzytkownikow;
    Serwis_uzytkownik* zalogowany= nullptr;
    
    Serwis();

    void dodaj_uzytkownika(QString _login, QString _haslo);

    bool zaloguj(QString login, QString haslo);

    void wyloguj();

    bool czy_zalogowany();

    ~Serwis();

};

#endif 
