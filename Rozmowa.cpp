#include "Rozmowa.h"

Rozmowa::Rozmowa(QString login)
{
    odbiorca=login;
}

QString Rozmowa::get_odbiorca()
{
    return odbiorca;
}
