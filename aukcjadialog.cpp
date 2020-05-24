#include "aukcjadialog.h"
#include "ui_aukcjadialog.h"

AukcjaDialog::AukcjaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AukcjaDialog)
{
    ui->setupUi(this);
}

AukcjaDialog::~AukcjaDialog()
{
    delete ui;
}

QString AukcjaDialog::get_nazwa()
{
    return ui->lineEdit_nazwa_aukcji->text();
}
double AukcjaDialog::get_cena()
{
   return ui->doubleSpinBox_cena_aukcji->value();
}

void AukcjaDialog::on_buttonBox_accepted()
{
    accept();
}

void AukcjaDialog::on_buttonBox_rejected()
{
    reject();
}

void AukcjaDialog:: set_cena(double nowa)
{
    ui->doubleSpinBox_cena_aukcji->setValue(nowa);
}

void AukcjaDialog:: set_nazwa(QString nowa)
{
    ui->lineEdit_nazwa_aukcji->setText(nowa);
}
