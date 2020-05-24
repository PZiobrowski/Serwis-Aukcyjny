#include "przedmiotdialog.h"
#include "ui_przedmiotdialog.h"

PrzedmiotDialog::PrzedmiotDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrzedmiotDialog)
{
    ui->setupUi(this);
}

PrzedmiotDialog::~PrzedmiotDialog()
{
    delete ui;
}

QString PrzedmiotDialog::get_nazwa()
{
    return ui->lineEdit_nazwa_przedmiotu->text();
}
QString PrzedmiotDialog::get_kategoria()
{
   return ui->comboBox_kategoria_przedmiot->currentText();
}

void PrzedmiotDialog::on_buttonBox_dodawanie_przedmiotu_accepted()
{
    accept();
}

void PrzedmiotDialog::on_buttonBox_dodawanie_przedmiotu_rejected()
{
    reject();
}
void PrzedmiotDialog:: set_line_disabled()
{
    ui->lineEdit_nazwa_przedmiotu->setDisabled(1);
}

void PrzedmiotDialog:: set_kategoria(QString nowa)
{
    ui->comboBox_kategoria_przedmiot->setCurrentText(nowa);
}

void PrzedmiotDialog:: set_nazwa(QString nowa)
{
    ui->lineEdit_nazwa_przedmiotu->setText(nowa);

}
