#ifndef AUKCJADIALOG_H
#define AUKCJADIALOG_H

#include <QDialog>

namespace Ui {
class AukcjaDialog;
}

class AukcjaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AukcjaDialog(QWidget *parent = nullptr);
    ~AukcjaDialog();

    QString get_nazwa();
    double get_cena();
    void set_nazwa(QString nowa);
    void set_cena(double nowa);


private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::AukcjaDialog *ui;
};

#endif // AUKCJADIALOG_H
