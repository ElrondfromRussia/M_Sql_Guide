#ifndef DATABASE_HELPER_H
#define DATABASE_HELPER_H

#include <QSqlDatabase>
#include <QSqlError>

class Database_Helper
{
public:
    Database_Helper(); //конструктор

    void open_database();
    void close_database();
    void set_driver(const QString &driv);
    void get_data(const QString &str, QStringList &for_Result);
    void fill_city_data(const QString &sight, QStringList &About);

private:
    QSqlDatabase database;
    QString driver;
};

#endif // DATABASE_HELPER_H
