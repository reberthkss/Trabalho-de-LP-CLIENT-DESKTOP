#include "terceiro.h"
#include "ui_terceiro.h"

terceiro::terceiro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::terceiro)
{
    ui->setupUi(this);
}

terceiro::~terceiro()
{
    delete ui;
}
