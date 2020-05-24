#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "serwis.h"
#include "bank.h"
#include "Aukcja.h"
#include "przedmiotdialog.h"
#include "aukcjadialog.h"
#include "powiaz_dialog.h"
#include "chatdialog.h"
#include "funkcje.h"


#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>

#include <typeinfo>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <regex>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    template <class T>
    void zarejestruj_temp(T &obiekt);
    template <class T>
    void zaloguj_temp(T &obiekt);
    void wypisz_przedmioty();
    void go_to_bank();

private slots:
    void on_pushButton_serwis_clicked();

    void on_pushButton_back_main_page_clicked();

    void on_pushButton_serwis_log_in_clicked();

    void on_pushButton_back_page_1_clicked();

    void on_pushButton_back_page_2_clicked();

    void on_pushButton_serwis_register_clicked();

    void on_pushButton_bank_log_in_clicked();

    void on_pushButton_back_main_page_3_clicked();

    void on_pushButton_bank_register_clicked();

    void on_pushButton_back_main_page_4_clicked();

    void on_pushButton_serwis_make_account_clicked();

    void on_pushButton_register_clicked();

    void on_pushButton_serwis_log_in_OK_clicked();

    void on_pushButton_back_on_page_2_2_clicked();

    void on_pushButton_go_to_account_clicked();

    void on_pushButton_dodaj_przedmiot_clicked();

    void on_pushButton_usun_przedmiot_clicked();

    void on_pushButton_wystaw_przedmiot_clicked();

    void on_pushButton_zmien_kategorie_przedmiotu_clicked();

    void on_pushButton_modyfikuj_aukcje_clicked();

    void on_pushButton_usun_aukcje_clicked();

    void on_pushButton_back_on__page_2_3_clicked();

    void on_pushButton_serwis_aukcje_clicked();

    void on_comboBox_kategorie_currentTextChanged(const QString &arg1);

    void on_pushButton_sort_cena_rosnaco_clicked();

    void on_pushButton_sort_cena_malejaco_clicked();

    void on_pushButton_sort_nazwa_AZ_clicked();

    void on_pushButton_sort_nazwa_ZA_clicked();

    void on_pushButton_sort_data_od_nowego_clicked();

    void on_pushButton_sort_data_od_starego_clicked();

    void on_pushButton_szukaj_aukcje_clicked();

    void on_comboBox_kategorie_activated(const QString &arg1);

    void on_pushButton_bank_log_out_clicked();

    void on_pushButton_wplac_pieniadze_clicked();

    void on_pushButton_powiaz_z_bankiem_clicked();

    void on_pushButton_kup_teraz_clicked();

    void on_pushButton_go_on_chat_clicked();

private:
    Ui::MainWindow *ui;

    Serwis serwis;
    Bank bank;
    bool gdzie_zalogowany;
    vector<Aukcja *> przedmioty;
};
#endif // MAINWINDOW_H
