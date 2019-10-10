#include "fm.h"
#include "ui_fm.h"
#include "terceiro.h"
#include "mainwindow.h"
#include "qmessagebox.h"
#include <iostream>


using namespace std;

int _janela[23];
int _corredor[23];
// 1 = janela 2 = corredor
int opt = 0;
// 1 = são paulo 2 = curitiba 3 = Florianopolis
int opt2 = 0;
int qt = 0;
int lucro = 0;

//CONSTRUCTOR
fm::fm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fm)
{
    ui->setupUi(this);
    ui->listWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->tabWidget->setCurrentIndex(0);
    QPixmap pix("C:/Users/Rodrigo/Documents/Onibus/trajeto.jpg");
    ui->trajetoLabel->setPixmap(pix);


}



//DESTROCTOR
fm::~fm()
{
    delete ui;
}


//FUNÇÕES

char* efetCompra(int opt,int opt2,int qt,int *assentos,int size){
    bool teste;
    int qt1 = qt;
    //qDebug() << "opt = " << opt;
   // qDebug() << "opt2 = " << opt2;
    //qDebug() << "qt = " << qt;
    /*for(int i =0 ; i < size ; i ++){
    qDebug() << "assento = " << *(assentos+i)+1;
    }*/
    qDebug() << "tamanho = " << size;

    if(qt > size){
        return "A quantidade de assentos selecionados é menor que a quantidade solicitada \n \t\t\t VENDA NÃO REALIZADA!!";
    }else{
        if( qt < size){
            return "A quantidade de assentos não pode ser maior que a quantidade solicitada \n \t\t\t VENDA NÃO REALIZADA!!";
        }else{
            switch(opt){
                case 1:
                for(int i = 0 ; i < size ; i++){
                    if(_janela[*(assentos+i)] == 1){
                        qDebug() << "janela";
                        return "Venda não realizada. Um ou mais assentos já estão ocupados!!!";
                    }
                    }
                break;
            case 2:
                for(int i = 0 ; i < size ; i++){
                    if(_corredor[*(assentos+i)] == 1){
                        qDebug() << "corredor";
                        return "Venda não realizada. Um ou mais assentos estão ocupados!!!";
                    }
                }
                break;
            }



            while(qt != 0){
                //TALVEZ EXISTA UM BUG NA HORA QUE SELECIONAR MULTIPLOS ASSENTOS
                //
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

            switch(opt2){
            case 1:
                qDebug() << "entrou no switch";
                qDebug() << qt;
                lucro = lucro + (qt1*28);
                break;
            case 2:
                lucro = lucro + qt1*159;
                break;
            case 3:
                lucro = lucro + qt1*188;
                break;
            }

             teste = opt2 == 1;

            qDebug() << teste;




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
    int cont = 0;
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
            cont++;
        }
        int size = indexes.size();
        QMessageBox::information(this,"INFO",efetCompra(opt,opt2,qt,assentos,size));
         }
}
     ui->janelaLista->clear();
     ui->corredorLista->clear();

     for(int i = 0 ; i < 23 ; i++){
         QString janelaStatus;
         QString corredorStatus;

         if(_janela[i] == 0 ){
             janelaStatus = "DISPONIVEL";
         }else{
             janelaStatus = "OCUPADO";
         }

         if(_corredor[i] == 0){
             corredorStatus = "DISPONIVEL";
         }else{
             corredorStatus = "OCUPADO";
         }


         ui->janelaLista->addItem("Assento "+QString::number(i+1) + tr(" [%0]").arg(janelaStatus));
         ui->corredorLista->addItem("Assento " + QString::number(i+1) + tr(" [%0]").arg(corredorStatus));


          //qDebug() << tr("%0").arg(janelaStatus);
     }

     //ui->lucroList->addItem(tr("Lucro = %0").arg(QString::number(lucro)));
        qDebug() << cont;
}


void fm::on_radioButton_toggled(bool checked)
{
    ui->listWidget->clear();
    for(int i = 0; i < 23; i++){
            ui->listWidget->addItem("Assento "+QString::number(i+1));
    }

    for(int i = 0; i <= 23 ; i++){
        if(i == 0){
            ui->comboBox->addItem("");
        }else{
        ui->comboBox->addItem(QString::number(i));
        }
    }


    opt = 1;

    qDebug() << "marcado1";
    qDebug() << "opt = " << opt;
}

void fm::on_radioButton_2_toggled(bool checked)
{
    ui->listWidget->clear();

    for(int i = 0; i < 23; i++){
            ui->listWidget->addItem("Assento "+QString::number(i+1));
    }

    for(int i = 0; i <= 23 ; i++){
        if(i == 0){
            ui->comboBox->addItem("");
        }else{
        ui->comboBox->addItem(QString::number(i));
        }
    }

    //opt // 1 = janela 2 = corredor
    opt = 2;
    qDebug() << "marcado2";
    qDebug() << "opt = " << opt;
}

void fm::on_listWidget_itemSelectionChanged()
{


}

void fm::on_pushButton_5_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
}

void fm::on_spRadio_toggled(bool checked)
{
    opt2 = 1;
}

void fm::on_cuRadio_toggled(bool checked)
{
    opt2 = 2;
}

void fm::on_flRadio_toggled(bool checked)
{
    opt2 = 3;
}

void fm::on_updateBtn_clicked()
{
    ui->lucroList->clear();
    ui->lucroList->addItem(tr("Lucro = R$ %0").arg(lucro));
}
