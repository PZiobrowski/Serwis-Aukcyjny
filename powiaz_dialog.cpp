#include "powiaz_dialog.h"
#include "ui_powiaz_dialog.h"

powiaz_dialog::powiaz_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::powiaz_dialog)
{
    ui->setupUi(this);
}

powiaz_dialog::~powiaz_dialog()
{
    delete ui;
}

int powiaz_dialog::get_numer()
{
    return ui->lineEdit_numer_konta->text().toInt();
}
QString powiaz_dialog::get_haslo()
{
    return ui->lineEdit_haslo->text();
}

void powiaz_dialog::on_buttonBox_powiazywanie_accepted()
{
    accept();
}

void powiaz_dialog::on_buttonBox_powiazywanie_rejected()
{
    reject();
}
