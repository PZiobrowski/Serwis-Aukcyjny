#include "uzytkownik.h"

Uzytkownik::Uzytkownik(QString _login, QString _haslo)
{
    login = _login;
    haslo = _haslo;
}

Uzytkownik::Uzytkownik()
{


}

Uzytkownik::~Uzytkownik()
{


}

QString Uzytkownik::get_haslo()
{
    return haslo;
}

QString Uzytkownik::get_login()
{
    return login;
}

void Uzytkownik::set_haslo(QString s)
{
    haslo=s;
}

void Uzytkownik::set_login(QString s)
{
    login=s;
}
