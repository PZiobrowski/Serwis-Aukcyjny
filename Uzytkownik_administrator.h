#pragma once

#include <QString>

#include "uzytkownik.h"

using namespace std;

class Uzytkownik_administrator:public Uzytkownik
{
    Uzytkownik_administrator(QString login, QString haslo) :Uzytkownik(login, haslo) {};


};

