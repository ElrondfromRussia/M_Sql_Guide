#include "database_helper.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>

Database_Helper::Database_Helper()
{
}

void Database_Helper::open_database()
{
    QSqlError err;
    database = QSqlDatabase::addDatabase(driver);
    database.setDatabaseName("fn1181_2018");
    database.setHostName("195.19.32.74");
    database.setPort(5432);
    if (!database.open("student", "bmstu"))
    {
        err = database.lastError();
        database = QSqlDatabase();
        QSqlDatabase::removeDatabase(database.databaseName());
    }
}

void Database_Helper::close_database()
{
    database.close();
    QSqlDatabase::removeDatabase(database.databaseName());
}

void Database_Helper::set_driver(const QString &driv)
{
    this->driver = driv;
}

void Database_Helper::get_data(const QString &str, QStringList &for_Result)
{
    int sel;
    QSqlQuery my_query(database);
    if(!str.isEmpty())
    {
        QString ask;
        ask.append("SELECT * FROM sight where city = '").append(str).append("'");
        my_query.exec(ask);
        if (my_query.lastError().type() != QSqlError::NoError)
            sel = -1;
        else if (my_query.isSelect())
            sel = 1;
        else
            sel = 0;
    }
    else
        sel = 0;

    if(sel)
    {
        QString result = "";
        QSqlRecord rec = my_query.record();

        int l = 1;
        while( my_query.next())
        {
            result = "";
            QSqlRecord record =  my_query.record();
            QString num;
            int count = record.count();
            if(count > 1)
            {

                //result.append(num.setNum(l++)).append("\t");
                result.append(record.value(1).toString().toUtf8());
            }
            for_Result.append(result);
        }
    }

}

void Database_Helper::fill_city_data(const QString &sight, QStringList &About)
{
    About.append(sight);

    int sel;

    QSqlQuery my_query(database);
    QString ask;
    ask.append("SELECT * FROM sight where sight_name = '").append(sight).append("'");
    my_query.exec(ask);
    if (my_query.lastError().type() != QSqlError::NoError)
        sel = -1;

    QSqlRecord rec = my_query.record();
    my_query.next();
    rec = my_query.record();
    int count = rec.count();
    if(count > 1)
    {
        for(int l = 2; l < count; l++)
            About.append(rec.value(l).toString().toUtf8());
    }

}
