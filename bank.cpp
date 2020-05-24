#include "bank.h"
#include "bank_uzytkownik.h"

#include <iostream>
#include <fstream>

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>


Bank::Bank()
{
    try
    {
        QFile File("uzytkownicy_bank.txt");

        if (File.open(QFile::ReadOnly | QFile::Text))
        {
            QTextStream in(&File);

            while (!File.atEnd())
            {
                QString tmp_login, tmp_haslo,tmp1;
                int nr;
                double stan;

                tmp_login=File.readLine();
                if (tmp_login == "")
                    break;
                tmp_login.remove(tmp_login.size()-1,2);
                tmp_haslo=File.readLine();
                tmp_haslo.remove(tmp_haslo.size()-1,2);

                Bank_uzytkownik tmp(tmp_login,tmp_haslo);

                tmp1=File.readLine();
                nr=tmp1.toInt();
                tmp1=File.readLine();
                stan=tmp1.toDouble();

                tmp.set_nr_konta(nr);
                tmp.set_stan_konta(stan);

                lista_uzytkownikow.push_back(tmp);
            }

            File.flush();
            File.close();
        }
        else
        {
            int q;
            throw q;
        }

        QFile File1("uzytkownicy_bank_dane.txt");

        if (File1.open(QFile::ReadOnly | QFile::Text))
        {

            int ile_historii;
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
    }
    catch(int)
    {
        QMessageBox::critical(nullptr,"Uwaga!","Nie udało się otworzyć pliku !!!");
        exit(0);
    }

}

void Bank::dodaj_uzytkownika(QString _login, QString _haslo)
{

    if (lista_uzytkownikow.size() != 0)
	{		
		int help;
		do
		{
			help = 0;
			Bank_uzytkownik tmp(_login, _haslo);

			for (int i = 0; i < lista_uzytkownikow.size(); i++)
				if (tmp.get_nr_konta() == lista_uzytkownikow[i].get_nr_konta())
					help = 1;
			if(help==0)
				lista_uzytkownikow.push_back(tmp);
		} while (help == 1);
	}else
    {
		Bank_uzytkownik tmp(_login, _haslo);
		lista_uzytkownikow.push_back(tmp);
    }


}

bool Bank::zaloguj(QString _login, QString _haslo)
{
	for (int i = 0; i < lista_uzytkownikow.size(); i++)
	{
		if (lista_uzytkownikow[i].get_login() == _login && lista_uzytkownikow[i].get_haslo() == _haslo)
		{
			zalogowany = &lista_uzytkownikow[i];
            return 1 ;
		}
			
	}
        return 0;
}

void Bank::wyloguj()
{
    zalogowany=nullptr;
}
Bank::~Bank()
{
    try
    {
         QFile File("uzytkownicy_bank.txt");

        if (File.open(QFile::WriteOnly | QFile::Text))
        {
            QTextStream out(&File);

            for (int i=0; i< lista_uzytkownikow.size(); i++)
            {
                out << lista_uzytkownikow[i].get_login() << endl;
                out << lista_uzytkownikow[i].get_haslo()<<endl;
                out << lista_uzytkownikow[i].get_nr_konta() << endl;
                out << lista_uzytkownikow[i].get_stan_konta()<<endl;
            }
            File.flush();
            File.close();
        }
        else
        {
            int q;
            throw  q;
        }

        QFile File1("uzytkownicy_bank_dane.txt");
        if (File1.open(QFile::WriteOnly | QFile::Text))
        {
            QTextStream out(&File1);

            for (int i = 0; i < (int)lista_uzytkownikow.size(); i++)
            {
                out << lista_uzytkownikow[i].historia_wydatkow.size() << endl;

                vector<Aukcja>::iterator it;
                for (it = lista_uzytkownikow[i].historia_wydatkow.begin(); it < lista_uzytkownikow[i].historia_wydatkow.end(); it++)
                {
                    out << it->get_nazwa() << endl;
                    out << it->get_cena() << endl;
                    out << it->get_data() << endl;
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
    }
    catch(int)
    {
        QMessageBox::critical(nullptr,"Uwaga!","Nie udało się utworzyć pliku !!!");
    }
}
