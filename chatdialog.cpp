#include "chatdialog.h"
#include "ui_chatdialog.h"

ChatDialog::ChatDialog(QWidget *parent,QString zalogowany) :
    QDialog(parent),
    ui(new Ui::ChatDialog)
{
    ui->setupUi(this);
    login_zalogowany=zalogowany;
}

ChatDialog::~ChatDialog()
{
    delete ui;
}

void ChatDialog::zaladuj(vector<Serwis_uzytkownik>&wejscie)
{
    ui->listWidget_lista_uzytkownikow->clear();

    for(int i=0;i<wejscie.size();i++)
    {

         uzytkownicy.push_back(&wejscie[i]);
         if(wejscie[i].get_login()!=login_zalogowany)
         {
             QListWidgetItem *item=new QListWidgetItem(QIcon(":/rec/uzytkownik.png"),uzytkownicy.back()->get_login());
             ui->listWidget_lista_uzytkownikow->addItem(item);
          }
    }

}

void ChatDialog::on_pushButton_szukaj_clicked()
{
    if(ui->lineEdit_login->text()=="")
        return;

    for(int i=0;i<uzytkownicy.size();i++)
    {
        if(uzytkownicy[i]->get_login()==ui->lineEdit_login->text())
        {
            ui->listWidget_lista_uzytkownikow->setCurrentRow(i);
            ui->lineEdit_login->clear();
            return;
        }
    }
    QMessageBox::warning(this,"Uwaga!","Nie znaleziono uzytkownika!");
    ui->lineEdit_login->clear();
}

void ChatDialog::on_pushButton_wejdz_na_chat_clicked()
{
    if(ui->listWidget_lista_uzytkownikow->currentRow()==-1)
        return;

    kontakt=ui->listWidget_lista_uzytkownikow->currentItem()->text();
    ui->stackedWidget->setCurrentIndex(1);

    wyswietl_wiadomosci();

}

void ChatDialog::on_pushButton_wroc_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void ChatDialog::on_pushButton_wyslij_clicked()
{

    QString s= ui->plainTextEdit_napisz->toPlainText();
    if(ui->plainTextEdit_napisz->toPlainText().contains("\n"))
    {
        s.resize(s.size()-2);
    }

    bool help=0;

    for(int i=0;i<uzytkownicy.size();i++)
    {
        if(uzytkownicy[i]->get_login()==login_zalogowany)
        {
            for(int j=0;j<uzytkownicy[i]->czat.size();j++)
            {
                if(uzytkownicy[i]->czat[j].get_odbiorca()==ui->listWidget_lista_uzytkownikow->currentItem()->text())
                {
                    Wiadomosc tmp(login_zalogowany,s,pozyskaj_date());
                    uzytkownicy[i]->czat[j].rozmowa.push_back(tmp);
                    help=1;
                    break;
                }
            }
            if(help==0)
            {
                Rozmowa tmp(ui->listWidget_lista_uzytkownikow->currentItem()->text());
                uzytkownicy[i]->czat.push_back(tmp);
                Wiadomosc tmp1(login_zalogowany,s,pozyskaj_date());
                uzytkownicy[i]->czat.back().rozmowa.push_back(tmp1);
            }

            break;
        }
    }

    for(int i=0;i<uzytkownicy.size();i++)
    {
        if(uzytkownicy[i]->get_login()==ui->listWidget_lista_uzytkownikow->currentItem()->text())
        {
            for(int j=0;j<uzytkownicy[i]->czat.size();j++)
            {
                if(uzytkownicy[i]->czat[j].get_odbiorca()==login_zalogowany)
                {
                    Wiadomosc tmp(login_zalogowany,s,pozyskaj_date());
                    uzytkownicy[i]->czat[j].rozmowa.push_back(tmp);
                    help=1;
                    break;
                }
            }
            if(help==0)
            {
                Rozmowa tmp(login_zalogowany);
                uzytkownicy[i]->czat.push_back(tmp);
                Wiadomosc tmp1(login_zalogowany,s,pozyskaj_date());
                uzytkownicy[i]->czat.back().rozmowa.push_back(tmp1);
            }

            break;
        }
    }

    wyswietl_wiadomosci();



}

void ChatDialog::wyswietl_wiadomosci()
{
    ui->textEdit_wyswietl->clear();

    for(int i=0;i<uzytkownicy.size();i++)
    {
        if(uzytkownicy[i]->get_login()==login_zalogowany)
        {
            for(int j=0;j<uzytkownicy[i]->czat.size();j++)
            {
                if(uzytkownicy[i]->czat[j].get_odbiorca()==ui->listWidget_lista_uzytkownikow->currentItem()->text())
                {
                    for(int k=0;k<uzytkownicy[i]->czat[j].rozmowa.size();k++)
                    {
                        QString help="< ";
                        help.push_back(uzytkownicy[i]->czat[j].rozmowa[k].get_data());
                        help.push_back(" ");
                        help.push_back(uzytkownicy[i]->czat[j].rozmowa[k].get_nadawca());
                        help.push_back(" > ");
                        help.push_back(uzytkownicy[i]->czat[j].rozmowa[k].get_tresc());

                        ui->textEdit_wyswietl->append(help);
                    }
                    break;
                }

            }

            break;
        }
    }

}

void ChatDialog::on_plainTextEdit_napisz_textChanged()
{
    if(ui->plainTextEdit_napisz->toPlainText().contains("\n"))
        on_pushButton_wyslij_clicked();
}
