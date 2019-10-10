#include "cn.h"


QSqlDatabase cn::_db = QSqlDatabase::addDatabase("MYSQL");
cn::cn(QObject *parent) : QObject(parent)
{

}
