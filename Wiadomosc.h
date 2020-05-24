#pragma once

#include <QString>

using namespace std;

class Wiadomosc
{
    QString nadawca;
    QString tresc;
    QString data;


public:

    Wiadomosc(QString _nadawca,QString _tresc, QString _data):nadawca(_nadawca),tresc(_tresc),data(_data){}

    QString get_nadawca();
    QString get_tresc();
    QString get_data();

};

