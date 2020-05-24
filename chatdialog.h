#ifndef CHATDIALOG_H
#define CHATDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include "serwis_uzytkownik.h"
#include "Rozmowa.h"
#include "Wiadomosc.h"
#include "funkcje.h"

namespace Ui {
class ChatDialog;
}

class ChatDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChatDialog(QWidget *parent = nullptr,QString zalogowany="");
    ~ChatDialog();

    void zaladuj(vector<Serwis_uzytkownik>&wejscie);

    void wyswietl_wiadomosci();


private slots:
    void on_pushButton_szukaj_clicked();

    void on_pushButton_wejdz_na_chat_clicked();

    void on_pushButton_wroc_clicked();

    void on_pushButton_wyslij_clicked();

    void on_plainTextEdit_napisz_textChanged();

private:
    Ui::ChatDialog *ui;
    vector<Serwis_uzytkownik*>uzytkownicy;
    QString login_zalogowany;
    QString kontakt;
};

#endif // CHATDIALOG_H
