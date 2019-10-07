#ifndef TERCEIRO_H
#define TERCEIRO_H

#include <QDialog>

namespace Ui {
class terceiro;
}

class terceiro : public QDialog
{
    Q_OBJECT

public:
    explicit terceiro(QWidget *parent = nullptr);
    ~terceiro();

private:
    Ui::terceiro *ui;
};

#endif // TERCEIRO_H
