#include "mainwindow.h"
#include "ui_mainwindow.h"



#include "serwis.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_serwis_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    gdzie_zalogowany=0;
}

void MainWindow::on_pushButton_back_main_page_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_back_page_1_clicked()
{
    if(gdzie_zalogowany==0)
        ui->stackedWidget->setCurrentIndex(1);
    else
        ui->stackedWidget->setCurrentIndex(0);

    ui->lineEdit_serwis_login->clear();
    ui->lineEdit_serwis_haslo->clear();


}

void MainWindow::on_pushButton_back_page_2_clicked()
{
    if(gdzie_zalogowany==0)
        ui->stackedWidget->setCurrentIndex(1);
    else
        ui->stackedWidget->setCurrentIndex(0);

    ui->lineEdit_serwis_register_login->clear();
    ui->lineEdit_serwis_register_haslo->clear();
    ui->lineEdit_serwis_register_haslo1->clear();
}

void MainWindow::on_pushButton_serwis_register_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_bank_log_in_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    gdzie_zalogowany=1;
}

void MainWindow::on_pushButton_back_main_page_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_bank_register_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    gdzie_zalogowany=1;
}

void MainWindow::on_pushButton_back_main_page_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_back_on_page_2_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_back_on__page_2_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_go_to_account_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    ui->listWidget_przedmioty->clear();
    ui->treeWidget_aukcje_uzytkownika->clear();
    ui->treeWidget_historia_zakupow->clear();

    vector<Przedmiot>::iterator it;
    for (it = serwis.zalogowany->lista_przedmiotow.begin(); it < serwis.zalogowany->lista_przedmiotow.end(); it++)
    {
        QString sciezka;
            if(it->get_czy_wystawiony())
                sciezka=":/rec/wystawiony.png";
            else
                sciezka=":/rec/ok.png";
            QListWidgetItem *item=new QListWidgetItem(QIcon(sciezka),it->get_nazwa_przed());
            ui->listWidget_przedmioty->addItem(item);
    }


    for (int i = 0; i < serwis.zalogowany->lista_aukcji.size(); i++)
    {
            QTreeWidgetItem *itm= new QTreeWidgetItem(ui->treeWidget_aukcje_uzytkownika);

            itm->setText(0,serwis.zalogowany->lista_aukcji[i].get_nazwa());
            itm->setText(1,serwis.zalogowany->lista_aukcji[i].przedmiot->get_nazwa_przed());
            itm->setText(2,QString::number(serwis.zalogowany->lista_aukcji[i].get_cena(),'f',2));
            itm->setText(3,serwis.zalogowany->lista_aukcji[i].get_data());

            ui->treeWidget_aukcje_uzytkownika->addTopLevelItem(itm);
    }

    for (int i = 0; i < serwis.zalogowany->historia_zakupow.size(); i++)
    {
            QTreeWidgetItem *itm= new QTreeWidgetItem(ui->treeWidget_historia_zakupow);

            itm->setText(0,serwis.zalogowany->historia_zakupow[i].get_nazwa());
            itm->setText(1,QString::number(serwis.zalogowany->historia_zakupow[i].get_cena(),'f',2));
            itm->setText(2,serwis.zalogowany->historia_zakupow[i].get_data());

            ui->treeWidget_historia_zakupow->addTopLevelItem(itm);
    }

}


void MainWindow::on_pushButton_serwis_make_account_clicked()
{
    if(gdzie_zalogowany==0)
        zarejestruj_temp(serwis);
     else
        zarejestruj_temp(bank);


}

template <class T>
void MainWindow::zarejestruj_temp(T &obiekt)
{
    if(ui->lineEdit_serwis_register_haslo->text()=="" or ui->lineEdit_serwis_register_login->text()=="")
        return;

    bool tworz=0;

    for (int i = 0; i < (int)obiekt.lista_uzytkownikow.size(); i++)
    {
        if (obiekt.lista_uzytkownikow[i].get_login() == ui->lineEdit_serwis_register_login->text())
        {
            QMessageBox::warning(this,"Uwaga!","Podany login jest już zajęty !");
            tworz=1;
            break;
        }
    }
     if(tworz==0 )
     {
         if( ui->lineEdit_serwis_register_haslo->text()==ui->lineEdit_serwis_register_haslo1->text() )
         {
             obiekt.dodaj_uzytkownika(ui->lineEdit_serwis_register_login->text(),ui->lineEdit_serwis_register_haslo->text());
             QMessageBox::information(this,"Powodzenie","Dodano nowe konto!");

             ui->lineEdit_serwis_register_login->clear();
             ui->lineEdit_serwis_register_haslo->clear();
             ui->lineEdit_serwis_register_haslo1->clear();

             if constexpr(is_same<T,Serwis>::value)
                  ui->stackedWidget->setCurrentIndex(1);

             if constexpr(is_same<T,Bank>::value)
                 ui->stackedWidget->setCurrentIndex(0);

         }else
            QMessageBox::warning(this,"Uwaga!","Podane hasła nie zgadzaja się !");
     }
}

void MainWindow::on_pushButton_serwis_log_in_clicked()
{
    if(!serwis.czy_zalogowany())
    {
        ui->stackedWidget->setCurrentIndex(2);
    }else
    {
        QMessageBox::StandardButton reply=QMessageBox::question(this,"Wylogowanie","Czy na pewno chcesz się wylogować ?",QMessageBox::Yes | QMessageBox::No);
        if(reply==QMessageBox::Yes)
        {
            serwis.wyloguj();
            ui->pushButton_serwis_log_in->setText("Zaloguj się");
            ui->pushButton_go_to_account->setDisabled(1);
        }else
            return;
    }

}

void MainWindow::on_pushButton_serwis_log_in_OK_clicked()
{
    if(gdzie_zalogowany==0)
    {
        zaloguj_temp(serwis);
    }else
    {
        zaloguj_temp(bank);
    }
}

void MainWindow::go_to_bank()
{
    ui->doubleSpinBox_pieniadze->clear();
    ui->label_numer_konta->setText(QString::number(bank.zalogowany->get_nr_konta()));
    QString help=QString::number(bank.zalogowany->get_stan_konta());
    help.push_back(" zł");
    ui->label_stan_konta->setText(help);

    ui->treeWidget_historia_wydatkow->clear();

    for(int i=0;i<bank.zalogowany->historia_wydatkow.size();i++)
    {
        QTreeWidgetItem *itm= new QTreeWidgetItem(ui->treeWidget_historia_wydatkow);

        itm->setText(0,bank.zalogowany->historia_wydatkow[i].get_nazwa());
        itm->setText(1,QString::number(bank.zalogowany->historia_wydatkow[i].get_cena(),'f',2));
        itm->setText(2,bank.zalogowany->historia_wydatkow[i].get_data());

        ui->treeWidget_historia_wydatkow->addTopLevelItem(itm);
    }

}

template <class T>
void MainWindow::zaloguj_temp(T &obiekt)
{
    if(ui->lineEdit_serwis_login->text()=="" or ui->lineEdit_serwis_haslo->text()=="")
        return;

    if(!obiekt.zaloguj(ui->lineEdit_serwis_login->text(),ui->lineEdit_serwis_haslo->text()))
        QMessageBox::warning(this,"Uwaga!","Błędne login lub hasło !");
    else
    {
        if constexpr(is_same<T,Serwis>::value)
        {
            ui->pushButton_serwis_log_in->setText("Wyloguj się");
            ui->lineEdit_serwis_login->clear();
            ui->lineEdit_serwis_haslo->clear();
            ui->pushButton_go_to_account->setEnabled(1);
            on_pushButton_go_to_account_clicked();
        }
        if constexpr(is_same<T,Bank>::value)
        {
            ui->lineEdit_serwis_login->clear();
            ui->lineEdit_serwis_haslo->clear();
            ui->stackedWidget->setCurrentIndex(6);
            go_to_bank();
        }
    }

}

void MainWindow::on_pushButton_dodaj_przedmiot_clicked()
{
    PrzedmiotDialog pd(this);
    pd.setWindowTitle("Dodaj przedmiot");
    int help = pd.exec();

    if(help==QDialog::Rejected)
        return;
    if(help==QDialog::Accepted)
    {
        vector<Przedmiot>::iterator it;
        for (it = serwis.zalogowany->lista_przedmiotow.begin(); it < serwis.zalogowany->lista_przedmiotow.end(); it++)
        {
            if(it->get_nazwa_przed().toLower()==pd.get_nazwa().toLower())
            {
                QMessageBox::warning(this,"Uwaga!","Posiadasz już podany przedmiot !");
                return;
            }
        }
        serwis.zalogowany->dodaj_przedmiot(pd.get_nazwa(),serwis.zalogowany->get_login(),pd.get_kategoria());
        on_pushButton_go_to_account_clicked();
    }

}


void MainWindow::on_pushButton_usun_przedmiot_clicked()
{

    if(ui->listWidget_przedmioty->currentRow()==-1)
        return;

    if(serwis.zalogowany->lista_przedmiotow[ui->listWidget_przedmioty->currentRow()].get_czy_wystawiony())
    {
        QMessageBox::critical(this,"Uwaga !","Przedmiot jest wystawiony na aukcję ! \n Przed usunięciem zamknij aukcję !");
        return;
    }else
    {
        QMessageBox::StandardButton reply=QMessageBox::question(this,"Usuwanie","Czy na pewno usunąć przedmiot ?",QMessageBox::Yes | QMessageBox::No);
        if(reply==QMessageBox::Yes)
        {

             serwis.zalogowany->usun_przedmiot(ui->listWidget_przedmioty->currentRow());
            on_pushButton_go_to_account_clicked();

        }else
            return;
    }

}

void MainWindow::on_pushButton_wystaw_przedmiot_clicked()
{

    if(ui->listWidget_przedmioty->currentRow()==-1)
        return;

    if(serwis.zalogowany->lista_przedmiotow[ui->listWidget_przedmioty->currentRow()].get_czy_wystawiony())
    {
        QMessageBox::information(this,"Uwaga !","Przedmiot jest już wystawiony !");
        return;
    }else
    {

        AukcjaDialog ad(this);
        ad.setWindowTitle("Wystaw na aukcję");
        int help = ad.exec();

        if(help==QDialog::Rejected)
            return;
        if(help==QDialog::Accepted)
        {
            vector<Serwis_uzytkownik>::iterator it;
            for (it = serwis.lista_uzytkownikow.begin(); it < serwis.lista_uzytkownikow.end(); it++)
            {
                vector<Aukcja>::iterator it1;
                for (it1 = it->lista_aukcji.begin(); it1 < it->lista_aukcji.end(); it1++)
                {
                    if(it1->get_nazwa()==ad.get_nazwa())
                    {
                        QMessageBox::warning(this,"Uwaga!","Istnieje już aukcja o takiej nazwie!");
                        return;
                    }
                }
            }

         serwis.zalogowany->dodaj_aukcje( ad.get_nazwa(), ad.get_cena(), pozyskaj_date());
         serwis.zalogowany->lista_aukcji.back().dodaj_przedmiot_do_aukcji(serwis.zalogowany->lista_przedmiotow[ui->listWidget_przedmioty->currentRow()]);
         QMessageBox::information(this,"Sukces!","Dodano nową aukcję!");

         on_pushButton_go_to_account_clicked();

        }

    }

}

void MainWindow::on_pushButton_zmien_kategorie_przedmiotu_clicked()
{
    if(ui->listWidget_przedmioty->currentRow()==-1)
        return;

    PrzedmiotDialog pd(this);
    pd.setWindowTitle("Modyfikuj przedmiot");
    pd.set_line_disabled();
    pd.set_kategoria(serwis.zalogowany->lista_przedmiotow[ui->listWidget_przedmioty->currentRow()].get_kategoria());
    pd.set_nazwa(serwis.zalogowany->lista_przedmiotow[ui->listWidget_przedmioty->currentRow()].get_nazwa_przed());
    int help = pd.exec();

    if(help==QDialog::Rejected)
        return;
    if(help==QDialog::Accepted)
    {
      serwis.zalogowany->lista_przedmiotow[ui->listWidget_przedmioty->currentRow()].set_kategoria(pd.get_kategoria());
        QMessageBox::information(this,"Sukces!","Kategoria została zmodyfikowana!");

        on_pushButton_go_to_account_clicked();
    }


}

void MainWindow::on_pushButton_modyfikuj_aukcje_clicked()
{
    if(!ui->treeWidget_aukcje_uzytkownika->currentItem())
        return;

    AukcjaDialog ad(this);
    ad.setWindowTitle("Modyfikuj aukcję");
    ad.set_nazwa(serwis.zalogowany->lista_aukcji[ui->treeWidget_aukcje_uzytkownika->indexOfTopLevelItem(ui->treeWidget_aukcje_uzytkownika->currentItem())].get_nazwa());
    ad.set_cena(serwis.zalogowany->lista_aukcji[ui->treeWidget_aukcje_uzytkownika->indexOfTopLevelItem(ui->treeWidget_aukcje_uzytkownika->currentItem())].get_cena());
    int help = ad.exec();

    if(help==QDialog::Rejected)
        return;
    if(help==QDialog::Accepted)
    {
        vector<Serwis_uzytkownik>::iterator it;
        for (it = serwis.lista_uzytkownikow.begin(); it < serwis.lista_uzytkownikow.end(); it++)
        {
            for (int i=0; i < it->lista_aukcji.size(); i++)
            {
                if(it->lista_aukcji[i].get_nazwa()==ad.get_nazwa() && i!=ui->treeWidget_aukcje_uzytkownika->indexOfTopLevelItem(ui->treeWidget_aukcje_uzytkownika->currentItem()))
                {
                    QMessageBox::warning(this,"Uwaga!","Istnieje już aukcja o takiej nazwie!");
                    return;
                }
            }
        }

     serwis.zalogowany->lista_aukcji[ui->treeWidget_aukcje_uzytkownika->indexOfTopLevelItem(ui->treeWidget_aukcje_uzytkownika->currentItem())].set_nazwa(ad.get_nazwa());
     serwis.zalogowany->lista_aukcji[ui->treeWidget_aukcje_uzytkownika->indexOfTopLevelItem(ui->treeWidget_aukcje_uzytkownika->currentItem())].set_cena(ad.get_cena());
     QMessageBox::information(this,"Sukces!","Pomyślnie zmodyfikowano aukcję!");

     on_pushButton_go_to_account_clicked();
    }

}


void MainWindow::on_pushButton_usun_aukcje_clicked()
{
    if(!ui->treeWidget_aukcje_uzytkownika->currentItem())
        return;


      QMessageBox::StandardButton reply=QMessageBox::question(this,"Usuwanie","Czy na pewno usunąć aukcję ?",QMessageBox::Yes | QMessageBox::No);
      if(reply==QMessageBox::Yes)
      {
          serwis.zalogowany->usun_aukcje(ui->treeWidget_aukcje_uzytkownika->indexOfTopLevelItem(ui->treeWidget_aukcje_uzytkownika->currentItem()));
          on_pushButton_go_to_account_clicked();
      }else
            return;
}

void MainWindow::on_pushButton_serwis_aukcje_clicked()
{
   ui->stackedWidget->setCurrentIndex(5);
   przedmioty.clear();

   vector<Serwis_uzytkownik>::iterator it;
   if(ui->comboBox_kategorie->currentText()=="Wszystkie")
   {
       for(it=serwis.lista_uzytkownikow.begin();it<serwis.lista_uzytkownikow.end();it++)
           for(int i=0;i<it->lista_aukcji.size();i++)
               przedmioty.push_back(&it->lista_aukcji[i]);
   }
   else
   {
       for(it=serwis.lista_uzytkownikow.begin();it<serwis.lista_uzytkownikow.end();it++)
           for(int i=0;i<it->lista_aukcji.size();i++)
           {
               if(it->lista_aukcji[i].przedmiot->get_kategoria()==ui->comboBox_kategorie->currentText())
                   przedmioty.push_back(&it->lista_aukcji[i]);
           }

   }

     wypisz_przedmioty();

}

void MainWindow::wypisz_przedmioty()
{
    ui->treeWidget_wszystkie_aukcje->clear();

    for(int i =0;i<przedmioty.size();i++)
    {
        QTreeWidgetItem *itm= new QTreeWidgetItem(ui->treeWidget_wszystkie_aukcje);

        itm->setText(0,przedmioty[i]->get_nazwa());
        itm->setText(1,QString::number(przedmioty[i]->get_cena(),'f',2));
        itm->setText(2,przedmioty[i]->przedmiot->get_nazwa_wlasciciela());
        itm->setText(3,przedmioty[i]->get_data());

        ui->treeWidget_aukcje_uzytkownika->addTopLevelItem(itm);

        QTreeWidgetItem *itm1= new QTreeWidgetItem();

        QString help="Przedmiot: ";
        help.push_back(przedmioty[i]->przedmiot->get_nazwa_przed());
        itm1->setText(0,help);

        itm->addChild(itm1);

    }
}

void MainWindow::on_comboBox_kategorie_activated(const QString &arg1)
{
    on_pushButton_serwis_aukcje_clicked();
}

void MainWindow::on_pushButton_sort_cena_rosnaco_clicked()
{
    int rozmiar=przedmioty.size()-1;
    bool zamiana;

    while (true)
    {
     zamiana=false;
        for (int i=0;i<rozmiar;i++)
         {
            if (przedmioty[i]->get_cena()>przedmioty[i+1]->get_cena())
             {
                zamiana=true;
                swap(przedmioty[i],przedmioty[i+1]);
             }
          }
    if (!zamiana)
        break;

    rozmiar--;
    }
    wypisz_przedmioty();

}

void MainWindow::on_pushButton_sort_cena_malejaco_clicked()
{
    int rozmiar=przedmioty.size()-1;
    bool zamiana;

    while (true)
    {
     zamiana=false;
        for (int i=0;i<rozmiar;i++)
         {
            if (przedmioty[i]->get_cena()<przedmioty[i+1]->get_cena())
             {
                zamiana=true;
                swap(przedmioty[i],przedmioty[i+1]);
             }
          }
    if (!zamiana)
        break;

    rozmiar--;
    }
    wypisz_przedmioty();
}

void MainWindow::on_pushButton_sort_nazwa_AZ_clicked()
{
    int rozmiar=przedmioty.size()-1;
    bool zamiana;

    while (true)
    {
     zamiana=false;
        for (int i=0;i<rozmiar;i++)
         {
            if (przedmioty[i]->get_nazwa().toLower()>przedmioty[i+1]->get_nazwa().toLower())
             {
                zamiana=true;
                swap(przedmioty[i],przedmioty[i+1]);
             }
          }
    if (!zamiana)
        break;

    rozmiar--;
    }
    wypisz_przedmioty();
}

void MainWindow::on_pushButton_sort_nazwa_ZA_clicked()
{
    int rozmiar=przedmioty.size()-1;
    bool zamiana;

    while (true)
    {
     zamiana=false;
        for (int i=0;i<rozmiar;i++)
         {
            if (przedmioty[i]->get_nazwa().toLower()<przedmioty[i+1]->get_nazwa().toLower())
             {
                zamiana=true;
                swap(przedmioty[i],przedmioty[i+1]);
             }
          }
    if (!zamiana)
        break;

    rozmiar--;
    }
    wypisz_przedmioty();
}

void MainWindow::on_pushButton_sort_data_od_nowego_clicked()
{
    int rozmiar=przedmioty.size()-1;
    bool zamiana;

    while (true)
    {
     zamiana=false;
        for (int i=0;i<rozmiar;i++)
         {
            if (przedmioty[i]->get_data()<przedmioty[i+1]->get_data())
             {
                zamiana=true;
                swap(przedmioty[i],przedmioty[i+1]);
             }
          }
    if (!zamiana)
        break;

    rozmiar--;
    }
    wypisz_przedmioty();
}

void MainWindow::on_pushButton_sort_data_od_starego_clicked()
{
    int rozmiar=przedmioty.size()-1;
    bool zamiana;

    while (true)
    {
     zamiana=false;
        for (int i=0;i<rozmiar;i++)
         {
            if (przedmioty[i]->get_data()>przedmioty[i+1]->get_data())
             {
                zamiana=true;
                swap(przedmioty[i],przedmioty[i+1]);
             }
          }
    if (!zamiana)
        break;

    rozmiar--;
    }
    wypisz_przedmioty();
}

void MainWindow::on_pushButton_szukaj_aukcje_clicked()
{

    int j=0;
    for(int i=0;i<przedmioty.size();i++)
    {
       if(ui->lineEdit_nazwa_uzytkownik_szukana->text()=="")
       {
            if(przedmioty[i]->przedmiot->get_nazwa_przed().contains(ui->lineEdit_nazwa_aukcja_szukana->text(),Qt::CaseInsensitive))
            {
                swap(przedmioty[i], przedmioty[j]);
                j++;
            }
       }else if(ui->lineEdit_nazwa_aukcja_szukana->text()=="")
       {
           if(przedmioty[i]->przedmiot->get_nazwa_wlasciciela().contains(ui->lineEdit_nazwa_uzytkownik_szukana->text(),Qt::CaseInsensitive))
           {
               swap(przedmioty[i], przedmioty[j]);
               j++;
           }
       }else
       {
           if(przedmioty[i]->przedmiot->get_nazwa_przed().contains(ui->lineEdit_nazwa_aukcja_szukana->text(),Qt::CaseInsensitive) && przedmioty[i]->przedmiot->get_nazwa_wlasciciela().contains(ui->lineEdit_nazwa_uzytkownik_szukana->text(),Qt::CaseInsensitive))
           {
               swap(przedmioty[i], przedmioty[j]);
               j++;
           }
       }
    }
    int help=przedmioty.size();
    for(int k=j;k<help;k++)
        przedmioty.pop_back();

    wypisz_przedmioty();
}

void MainWindow::on_pushButton_bank_log_out_clicked()
{
    QMessageBox::StandardButton reply=QMessageBox::question(this,"Uwaga","Czy na pewno chcesz się wylogować ?",QMessageBox::Yes | QMessageBox::No);
    if(reply==QMessageBox::Yes)
    {
        bank.wyloguj();
       ui->stackedWidget->setCurrentIndex(0);
    }else
        return;


}

void MainWindow::on_pushButton_wplac_pieniadze_clicked()
{
    if(ui->doubleSpinBox_pieniadze->value()==0)
        return;

    QMessageBox::StandardButton reply=QMessageBox::question(this,"Uwaga","Potrwierdzasz wpłatę ?",QMessageBox::Yes | QMessageBox::No);
    if(reply==QMessageBox::Yes)
    {
        bank.zalogowany->wplac(ui->doubleSpinBox_pieniadze->value());
        bank.zalogowany->dodaj_do_historii("Wplata",ui->doubleSpinBox_pieniadze->value(),pozyskaj_date());
        go_to_bank();

    }else
        return;

}

void MainWindow::on_pushButton_powiaz_z_bankiem_clicked()
{
    if(serwis.zalogowany->get_numer()!=0)
    {
        QMessageBox::information(this,"","Do tego konta jest już podłączone konto bankowe !");
        return;
    }

    powiaz_dialog pd(this);
    pd.setWindowTitle("Powiąż konto");
    int help = pd.exec();

    if(help==QDialog::Rejected)
        return;
    if(help==QDialog::Accepted)
    {
        vector<Bank_uzytkownik>:: iterator it;
        for(it=bank.lista_uzytkownikow.begin();it<bank.lista_uzytkownikow.end();it++)
        {
            if(it->get_nr_konta()==pd.get_numer() && it->get_haslo()==pd.get_haslo())
            {
                serwis.zalogowany->powiaz_konto(pd.get_numer());
                QMessageBox::information(this,"Suckes!","Konta powiązano poprawnie !");
                return;
            }

        }
        QMessageBox::warning(this,"Uwaga!","Błędne hasło !");
    }

}

void MainWindow::on_pushButton_kup_teraz_clicked()
{
    if(!ui->treeWidget_wszystkie_aukcje->currentItem())
        return;
    if(serwis.zalogowany==nullptr)
    {
        QMessageBox::warning(this,"Uwaga !", "Aby kupic przedmiot musisz się zalogować !");
        return;
    }

    QMessageBox::StandardButton reply=QMessageBox::question(this,"Uwaga","Czy na pewno chcesz kupić ten przedmiot ?",QMessageBox::Yes | QMessageBox::No);
    if(reply==QMessageBox::Yes)
    {
        int indeks;
        if(ui->treeWidget_wszystkie_aukcje->currentItem()->parent()==nullptr)
            indeks = ui->treeWidget_wszystkie_aukcje->indexOfTopLevelItem(ui->treeWidget_wszystkie_aukcje->currentItem());
        else
            indeks = ui->treeWidget_wszystkie_aukcje->indexOfTopLevelItem(ui->treeWidget_wszystkie_aukcje->currentItem()->parent());

        if(przedmioty[indeks]->przedmiot->get_nazwa_wlasciciela()==serwis.zalogowany->get_login())
        {
            QMessageBox::warning(this,"Uwaga !","Nie możesz kupić własnego przedmiotu !");
            return;
        }

        vector<Bank_uzytkownik>::iterator it;
        for(it=bank.lista_uzytkownikow.begin();it<bank.lista_uzytkownikow.end();it++)
        {
            if(it->get_nr_konta()==serwis.zalogowany->get_numer())
            {
                if(it->get_stan_konta()< przedmioty[indeks]->get_cena())
                {
                    QMessageBox::critical(this,"Uwaga !","Nie masz wystarczających środków na koncie !");
                    return;
                }
                else
                {
                    it->set_stan_konta(it->get_stan_konta()-przedmioty[indeks]->get_cena());
                    it->dodaj_do_historii(przedmioty[indeks]->get_nazwa(),przedmioty[indeks]->get_cena()*(-1),pozyskaj_date());
                    serwis.zalogowany->dodaj_do_historii(przedmioty[indeks]->get_nazwa(),przedmioty[indeks]->get_cena(),pozyskaj_date());

                    vector<Serwis_uzytkownik>::iterator it1;
                    for(it1=serwis.lista_uzytkownikow.begin();it1<serwis.lista_uzytkownikow.end();it1++)
                    {                                          
                        if(it1->get_login()==przedmioty[indeks]->przedmiot->get_nazwa_wlasciciela())
                        {
                            vector<Bank_uzytkownik>::iterator it2;
                            for(it2=bank.lista_uzytkownikow.begin();it2<bank.lista_uzytkownikow.end();it2++)
                            {
                                if(it2->get_nr_konta()==it1->get_numer())
                                {
                                    it2->set_stan_konta(it2->get_stan_konta()+przedmioty[indeks]->get_cena());
                                    it2->dodaj_do_historii(przedmioty[indeks]->get_nazwa(),przedmioty[indeks]->get_cena(),pozyskaj_date());
                                    break;
                                }
                            }

                            for(int i=0;i<it1->lista_aukcji.size();i++)
                            {
                                if(it1->lista_aukcji[i].get_nazwa()==przedmioty[indeks]->get_nazwa())
                                {
                                    it1->usun_aukcje(i);

                                   for(int j=0;j<it1->lista_przedmiotow.size();j++)
                                   {
                                       if(it1->lista_przedmiotow[j].get_nazwa_przed()==it1->lista_aukcji[i].przedmiot->get_nazwa_przed())
                                       {
                                           it1->usun_przedmiot(j);
                                           break;
                                       }
                                   }

                                   break;
                                }
                            }

                            break;
                        }
                    }

                    QMessageBox::information(this,"Sukces !","Zakupiono przedmiot!");
                    on_pushButton_serwis_aukcje_clicked();

                }
                break;
            }
        }

    }else
        return;
}

void MainWindow::on_pushButton_go_on_chat_clicked()
{
    ChatDialog cd(this,serwis.zalogowany->get_login());
    cd.zaladuj(serwis.lista_uzytkownikow);
    cd.setWindowTitle("Chat");
    cd.exec();

}



/// CMENTARZ !!!

void MainWindow::on_pushButton_register_clicked(){}
void MainWindow::on_comboBox_kategorie_currentTextChanged(const QString &arg1){}













