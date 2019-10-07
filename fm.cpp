#include "fm.h"
#include "ui_fm.h"
#include "terceiro.h"
#include "mainwindow.h"
#include "qmessagebox.h"
#include <iostream>

using namespace std;

int _janela[23];
int _corredor[23];
int opt = 0;
int qt = 0;

//CONSTRUCTOR
fm::fm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fm)
{
    ui->setupUi(this);
    ui->listWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->tabWidget->setCurrentIndex(0);

}



//DESTROCTOR
fm::~fm()
{
    delete ui;
}


//FUNÇÕES

char* efetCompra(int opt,int qt,int *assentos,int size){
    qDebug() << "opt = " << opt;
    qDebug() << "qt = " << qt;
    for(int i =0 ; i < size ; i ++){
    qDebug() << "assento = " << *(assentos+i)+1;
    }
    qDebug() << "tamanho = " << size;

    if(qt > size){
        return "A quantidade de assentos selecionados é menor que a quantidade solicitada \n \t\t\t VENDA NÃO REALIZADA!!";
    }else{
        if( qt < size){
            return "A quantidade de assentos não pode ser maior que a quantidade solicitada \n \t\t\t VENDA NÃO REALIZADA!!";
        }else{

            while(qt != 0){
                for(int i = 0; i < size; i ++){
                    switch(opt){
                    case 1:
                        if(_janela[*(assentos+i)] == 0){

                        _janela[*(assentos+i)] = 1;
                        }else{
                            return "Assento Ocupado";
                        }
                        break;
                    case 2:
                        if(_corredor[*(assentos+i)] == 0){
                            _corredor[*(assentos+i)] = 1;
                        }else{
                            return "Assento Ocupado";
                        }
                        break;
                    }
                    qt--;
                }
            }
            return "Venda realizada com sucesso";
        }
    }
}
void limparvet(){
    for(int i = 0 ; i < 23 ; i++){
        _janela[i] = 0;
        _corredor[i] = 0;
    }
}

void fm::on_comprarBTN_clicked()
{
    ui->listWidget->clear();
    ui->comboBox->clear();
    ui->radioButton->setAutoExclusive(false);
    ui->radioButton->setChecked(false);
    ui->radioButton->setAutoExclusive(true);
    ui->radioButton_2->setAutoExclusive(false);
    ui->radioButton_2->setChecked(false);
    ui->radioButton_2->setAutoExclusive(true);
    ui->tabWidget->setCurrentIndex(1);
}

void fm::on_verificarBTN_clicked()
{
    ui->tabWidget->setCurrentIndex(2);
}

void fm::on_trajetoBTN_clicked()
{
    ui->tabWidget->setCurrentIndex(3);
}

void fm::on_lucroBTN_clicked()
{
    ui->tabWidget->setCurrentIndex(4);
}

void fm::on_sairBTN_clicked()
{
    this->close();
}

void fm::on_pushButton_6_clicked()
{
    qt = ui->comboBox->currentIndex();
     if(qt == 0){
        QMessageBox::warning(this,"ERRO","Por favor, selecione a quantidade de assentos a serem comprados antes de efetivar a venda");
     }else{
         if(opt == 0){
             QMessageBox::warning(this,"ERRO","Por favor, selecione a posição.");
         }else{
        QModelIndexList indexes = ui->listWidget->selectionModel()->selectedIndexes();
        int assentos[indexes.size()];
        for(int i = 0 ; i < indexes.size() ; i++){
            assentos[i] = indexes[i].row();
        }
        int size = indexes.size();
        QMessageBox::information(this,"INFO",efetCompra(opt,qt,assentos,size));
         }
}
}


void fm::on_radioButton_toggled(bool checked)
{
    ui->listWidget->clear();
    for(int i = 0; i <= 23; i++){
            ui->listWidget->addItem("Assento "+QString::number(i+1));
        if(i == 0){
            ui->comboBox->addItem("");
        }else{
        ui->comboBox->addItem(QString::number(i));
        }
    }

    opt = 1;
}

void fm::on_radioButton_2_toggled(bool checked)
{
    ui->listWidget->clear();

    for(int i = 0; i < 23; i++){
            ui->listWidget->addItem("Assento "+ QString::number(i+1));
        if(i == 0){
            ui->comboBox->addItem("");
        }else{
            ui->comboBox->addItem(QString::number(i));
        }
    }

    //opt // 1 = janela 2 = corredor
    opt = 2;

}

void fm::on_listWidget_itemSelectionChanged()
{


}

void fm::on_pushButton_5_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
}
