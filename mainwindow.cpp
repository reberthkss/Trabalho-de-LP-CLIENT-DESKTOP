#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QDebug>
#include "fm.h"




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("qtcreator");
    db.setUserName("admin");
    db.setPassword("Reth0153a!a");
    bool ok = db.open();

    if(ok){

        QString user = ui->usuarioTXT->text();
        QString passw = ui->senhaTXT->text();

            QSqlQuery query;
            query.exec("SELECT * FROM contas WHERE usuario='"+user+"' and senha='"+passw+"'");


          if(user == NULL){
              QMessageBox::information(this,tr("Erro"),tr("Por favor preencha o campo do usuário"));
              return;
          }
            else{
              if(passw == NULL){
                  QMessageBox::information(this,tr("Erro"),tr("Por favor preencha o campo da senha"));
                  return;
                  }
              else{
                  if(query.next()){
                        QMessageBox::information(this,tr("Sucesso"),tr("logado com sucesso"));
                        this->close();
                        limparvet();

                        fm f;
                        f.setModal(true);
                        f.exec();
                    }else{
                        QMessageBox::information(this,tr("Erro"),tr("Erro no login"));
                        }
                }
            }


}
   }
