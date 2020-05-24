#include "serwis.h"
#include "serwis_uzytkownik.h"
#include "Rozmowa.h"
#include "Wiadomosc.h"

#include <iostream>
#include <fstream>
#include <QString>
#include <QFile>
#include <QTextStream>

#include<QDebug>


Serwis::Serwis()
{
    try
    {
        QFile File("uzytkownicy_serwis.txt");

        if (File.open(QFile::ReadOnly | QFile::Text))
        {
            QTextStream in(&File);

            while (!File.atEnd())
            {
                QString tmp_login, tmp_haslo,help;
                int tmp;
                tmp_login=File.readLine();
                if (tmp_login == "")
                    break;
                tmp_login.remove(tmp_login.size()-1,2);
                tmp_haslo=File.readLine();
                tmp_haslo.remove(tmp_haslo.size()-1,2);

                help=File.readLine();
                help.remove(help.size()-1,2);
                tmp = help.toInt();

                Serwis_uzytkownik tmp1(tmp_login,tmp_haslo);
                tmp1.powiaz_konto(tmp);
                lista_uzytkownikow.push_back(tmp1);

            }

            File.flush();
            File.close();
        }
        else
        {
            int q;
            throw q;
        }

        QFile File1("uzytkownicy_serwis_dane.txt");

        if (File1.open(QFile::ReadOnly | QFile::Text ))
        {

            int ile_historii, ile_aukcji, ile_przedmiotow;
            QString help1, help2, help3;
            double cena;
            int indeks = 0;

            while (!File1.atEnd())
            {
                help1=File1.readLine();
                help1.remove(help1.size()-1,2);
                if (help1 == "")
                    break;
                ile_historii = help1.toInt();

                help1=File1.readLine();
                help1.remove(help1.size()-1,2);
                ile_przedmiotow = help1.toInt();

                help1=File1.readLine();
                help1.remove(help1.size()-1,2);
                ile_aukcji = help1.toInt();


                    for (int i = 0; i < ile_historii; i++)
                    {
                        help1=File1.readLine();
                        help1.remove(help1.size()-1,2);
                        help3=File1.readLine();
                        help3.remove(help3.size()-1,2);
                        cena = help3.toDouble();
                        help2=File1.readLine();
                        help2.remove(help2.size()-1,2);
                        lista_uzytkownikow[indeks].dodaj_do_historii(help1, cena, help2);
                    }

                    for (int i = 0; i < ile_przedmiotow; i++)
                    {
                        help1=File1.readLine();
                        help1.remove(help1.size()-1,2);
                        help2=File1.readLine();
                        help2.remove(help2.size()-1,2);
                        lista_uzytkownikow[indeks].dodaj_przedmiot(help1, lista_uzytkownikow[indeks].get_login(),help2);

                    }


                    for (int i = 0; i < ile_aukcji; i++)
                    {
                        help1=File1.readLine();
                        help1.remove(help1.size()-1,2);
                        help3=File1.readLine();
                        help3.remove(help3.size()-1,2);
                        cena = help3.toDouble();
                        help2=File1.readLine();
                        help2.remove(help2.size()-1,2);
                        lista_uzytkownikow[indeks].dodaj_aukcje( help1, cena, help2);
                        lista_uzytkownikow[indeks].lista_aukcji.back().dodaj_przedmiot_do_aukcji(lista_uzytkownikow[indeks].lista_przedmiotow[i]);
                    }


                indeks++;
            }
            File1.close();
            File1.flush();
        }
        else
        {
            int q = 7;
            throw q;
        }

        QFile File3("Czat.txt");

        if (File3.open(QFile::ReadOnly | QFile::Text))
        {

            for(int i=0;i<lista_uzytkownikow.size();i++)
            {

               qDebug()<<lista_uzytkownikow.size();
                QString help;
                int ile_rozmow,ile_wiadomosci;
                help=File3.readLine();

                if (help == "")
                    break;

                help.remove(help.size()-1,2);
                ile_rozmow = help.toInt();

                for(int j=0;j<ile_rozmow;j++)
                {
                    qDebug()<<"2";
                   help=File3.readLine();
                   help.remove(help.size()-1,2);
                   Rozmowa tmp1(help);
                   lista_uzytkownikow[i].czat.push_back(tmp1);

                   help=File3.readLine();
                   help.remove(help.size()-1,2);
                   ile_wiadomosci = help.toInt();

                   for(int k=0;k<ile_wiadomosci;k++)
                   {
                       qDebug()<<"3";
                       QString nadawca,tresc,data;

                       nadawca=File3.readLine();
                       nadawca.remove(nadawca.size()-1,2);

                       tresc=File3.readLine();
                       tresc.remove(tresc.size()-1,2);

                       data=File3.readLine();
                       data.remove(data.size()-1,2);

                       Wiadomosc tmp2(nadawca,tresc,data);

                       lista_uzytkownikow[i].czat[j].rozmowa.push_back(tmp2);

                   }

                }


            }

            File3.flush();
            File3.close();
        }
        else
        {
            int q;
            throw q;
        }




    }
    catch(int)
    {
        QMessageBox::critical(nullptr,"Uwaga!","Nie udało się otworzyć pliku !!!");
        exit(0);
    }
}

void Serwis::dodaj_uzytkownika(QString _login, QString _haslo)
{
    Serwis_uzytkownik tmp(_login, _haslo);
    lista_uzytkownikow.push_back(tmp);
}

bool Serwis::zaloguj(QString _login, QString _haslo)
{
    for (int i = 0; i < lista_uzytkownikow.size(); i++)
    {
        if (lista_uzytkownikow[i].get_login() == _login && lista_uzytkownikow[i].get_haslo() == _haslo)
        {
            zalogowany = &lista_uzytkownikow[i];
            return 1;
        }
    }
    return 0;
}

void Serwis::wyloguj()
{
   zalogowany = nullptr;
}

bool Serwis::czy_zalogowany()
{
    if(zalogowany!=nullptr)
        return 1;
    return 0;
}

Serwis::~Serwis()
{
    try
    {             
         QFile File("uzytkownicy_serwis.txt");

        if (File.open(QFile::WriteOnly | QFile::Text))
        {
            QTextStream out(&File);

            for (int i=0; i< lista_uzytkownikow.size(); i++)
            {
                out << lista_uzytkownikow[i].get_login() << endl;
                out << lista_uzytkownikow[i].get_haslo() <<endl;
                out << lista_uzytkownikow[i].get_numer() <<endl;

            }
            File.flush();
            File.close();
        }
        else
        {
            int q;
            throw  q;
        }

        QFile File1("uzytkownicy_serwis_dane.txt");
        if (File1.open(QFile::WriteOnly | QFile::Text))
        {
            QTextStream out(&File1);

            for (int i = 0; i < (int)lista_uzytkownikow.size(); i++)
            {
                out << lista_uzytkownikow[i].historia_zakupow.size() << endl;
                out << lista_uzytkownikow[i].lista_przedmiotow.size() << endl;
                out << lista_uzytkownikow[i].lista_aukcji.size() << endl;

                vector<Aukcja>::iterator it;
                for (it = lista_uzytkownikow[i].historia_zakupow.begin(); it < lista_uzytkownikow[i].historia_zakupow.end(); it++)
                {
                    out << it->get_nazwa() << endl;
                    out << it->get_cena() << endl;
                    out << it->get_data() << endl;
                }

                for (int j = 0; j < lista_uzytkownikow[i].lista_przedmiotow.size(); j++)
                {
                    if(lista_uzytkownikow[i].lista_przedmiotow[j].get_czy_wystawiony())
                    {
                        out << lista_uzytkownikow[i].lista_przedmiotow[j].get_nazwa_przed() << endl;
                        out << lista_uzytkownikow[i].lista_przedmiotow[j].get_kategoria() << endl;
                    }
                }

                for (int j = 0; j < lista_uzytkownikow[i].lista_przedmiotow.size(); j++)
                {
                    if(!lista_uzytkownikow[i].lista_przedmiotow[j].get_czy_wystawiony())
                    {
                        out << lista_uzytkownikow[i].lista_przedmiotow[j].get_nazwa_przed() << endl;
                        out << lista_uzytkownikow[i].lista_przedmiotow[j].get_kategoria() << endl;
                    }
                }

                for (int j=0;j<lista_uzytkownikow[i].lista_aukcji.size();j++)
                {
                    out << lista_uzytkownikow[i].lista_aukcji[j].get_nazwa() << endl;
                    out << lista_uzytkownikow[i].lista_aukcji[j].get_cena() << endl;
                    out << lista_uzytkownikow[i].lista_aukcji[j].get_data() << endl;
                }
            }
            File1.flush();
            File1.close();
        }
        else
        {
            int q = 7;
            throw q;
        }


        QFile File2("Czat.txt");

       if (File2.open(QFile::WriteOnly | QFile::Text))
       {
           QTextStream out(&File2);

           for (int i=0; i< lista_uzytkownikow.size(); i++)
           {
               out<<lista_uzytkownikow[i].czat.size()<<endl;
               for (int j=0; j< lista_uzytkownikow[i].czat.size(); j++)
               {
                   out << lista_uzytkownikow[i].czat[j].get_odbiorca()<<endl;
                   out << lista_uzytkownikow[i].czat[j].rozmowa.size()<<endl;

                   for (int k=0; k < lista_uzytkownikow[i].czat[j].rozmowa.size(); k++)
                   {
                       out<<lista_uzytkownikow[i].czat[j].rozmowa[k].get_nadawca()<<endl;
                       out<<lista_uzytkownikow[i].czat[j].rozmowa[k].get_tresc()<<endl;
                       out<<lista_uzytkownikow[i].czat[j].rozmowa[k].get_data()<<endl;
                   }
               }

           }
           File2.flush();
           File2.close();
       }
       else
       {
           int q;
           throw  q;
       }

    }
    catch(int)
    {
        QMessageBox::critical(nullptr,"Uwaga!","Nie udało się utworzyć pliku !!!");
    }
}
