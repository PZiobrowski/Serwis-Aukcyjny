#ifndef PRZEDMIOTDIALOG_H
#define PRZEDMIOTDIALOG_H

#include <QDialog>

namespace Ui {
class PrzedmiotDialog;
}

class PrzedmiotDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PrzedmiotDialog(QWidget *parent = nullptr);
    ~PrzedmiotDialog();

    QString get_nazwa();
    QString get_kategoria();
    void set_line_disabled();
    void set_kategoria(QString nowa);
    void set_nazwa(QString nowa);

private slots:
    void on_buttonBox_dodawanie_przedmiotu_accepted();

    void on_buttonBox_dodawanie_przedmiotu_rejected();

private:
    Ui::PrzedmiotDialog *ui;

};

#endif // PRZEDMIOTDIALOG_H
