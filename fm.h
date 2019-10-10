#ifndef FM_H
#define FM_H

#include <QDialog>
#include "terceiro.h"
#include <iostream>


void limparvet();
namespace Ui {
class fm;
}

class fm : public QDialog
{
    Q_OBJECT

public:
    explicit fm(QWidget *parent = nullptr);
    ~fm();



private slots:
    void on_comprarBTN_clicked();

    void on_verificarBTN_clicked();

    void on_trajetoBTN_clicked();

    void on_lucroBTN_clicked();

    void on_sairBTN_clicked();

    void on_pushButton_6_clicked();



    void on_radioButton_toggled(bool checked);

    void on_radioButton_2_toggled(bool checked);

    void on_listWidget_itemSelectionChanged();

    void on_pushButton_5_clicked();

    void on_spRadio_toggled(bool checked);

    void on_cuRadio_toggled(bool checked);

    void on_flRadio_toggled(bool checked);

    void on_updateBtn_clicked();

private:
    Ui::fm *ui;
};

#endif // FM_H
