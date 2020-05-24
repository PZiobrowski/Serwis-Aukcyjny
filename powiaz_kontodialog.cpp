#include "powiaz_kontodialog.h"
#include "ui_powiaz_kontodialog.h"

powiaz_kontodialog::powiaz_kontodialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::powiaz_kontodialog)
{
    ui->setupUi(this);
}

powiaz_kontodialog::~powiaz_kontodialog()
{
    delete ui;
}

