#ifndef POWIAZ_KONTODIALOG_H
#define POWIAZ_KONTODIALOG_H

#include <QDialog>

namespace Ui {
class powiaz_kontodialog;
}

class powiaz_kontodialog : public QDialog
{
    Q_OBJECT

public:
    explicit powiaz_kontodialog(QWidget *parent = nullptr);
    ~powiaz_kontodialog();

    int get_numer();
    QString get_haslo();

private:
    Ui::powiaz_kontodialog *ui;
};

#endif // POWIAZ_KONTODIALOG_H
