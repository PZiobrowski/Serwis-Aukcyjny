#ifndef POWIAZ_DIALOG_H
#define POWIAZ_DIALOG_H

#include <QDialog>

namespace Ui {
class powiaz_dialog;
}

class powiaz_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit powiaz_dialog(QWidget *parent = nullptr);
    ~powiaz_dialog();

    int get_numer();
    QString get_haslo();

private slots:
    void on_buttonBox_powiazywanie_accepted();

    void on_buttonBox_powiazywanie_rejected();

private:
    Ui::powiaz_dialog *ui;
};

#endif // POWIAZ_DIALOG_H
