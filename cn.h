#ifndef CN_H
#define CN_H


#include <QObject>
#include <QSqlDatabase>
class cn : public QObject
{
    Q_OBJECT
public:
    explicit cn(QObject *parent = nullptr);

    static cn *_obj;
    static cn *obj();

    static QSqlDatabase _db;
    static QSqlDatabase db();



signals:

public slots:
};

#endif // CN_H
