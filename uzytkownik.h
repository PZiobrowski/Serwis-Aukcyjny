#pragma once

#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H

#include <QString>

using namespace std;

class Uzytkownik
{
    QString login;
    QString haslo;

public:

    Uzytkownik();

    ~Uzytkownik();

    Uzytkownik(QString _login, QString _haslo);

    QString get_haslo();

    QString get_login();

    void set_login(QString s);

    void set_haslo(QString s);

};

#endif 
