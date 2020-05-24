#pragma once

#include "Wiadomosc.h"

#include <vector>
#include <QString>

using namespace std;

class Rozmowa
{
    QString  odbiorca;
public:

    vector<Wiadomosc> rozmowa;

    Rozmowa(QString login);

    QString get_odbiorca();



};

