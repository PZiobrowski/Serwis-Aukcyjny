#pragma once

#ifndef BANK_H
#define BANK_H

#include "bank_uzytkownik.h"

#include <vector>
#include <QString>

using namespace std;

class Bank
{

public:

    vector<Bank_uzytkownik> lista_uzytkownikow;
    Bank_uzytkownik* zalogowany=nullptr;
    
    Bank();

    void dodaj_uzytkownika(QString _login, QString _haslo);

    bool zaloguj(QString login, QString haslo);

    void wyloguj();

    ~Bank();

};

#endif 

