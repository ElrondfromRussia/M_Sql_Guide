#ifndef VIEW_WINDOW_H
#define VIEW_WINDOW_H


#include <QMainWindow>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QUrl>
#include <QMessageBox>
#include <database_helper.h>

namespace Ui {
class view_window;
}

class view_window : public QMainWindow
{
    Q_OBJECT


public:
    explicit view_window(QWidget *parent = 0);
    view_window(QStringList &Sight_About, QWidget *parent = 0);
    ~view_window();

    void fill_window();
private slots:
    void on_load(QNetworkReply* reply);
    //void on_pushButton_marshr_clicked();

signals:
    void loaded(QPixmap pix);

private:
    Ui::view_window *ui;
    QString sight_name;
    QString adress;
    QString rezim;
    QString description;
    QString picture_url;
    QString city;
    float latitude;
    float longitude;

    Database_Helper * Helper;

    QNetworkAccessManager* nam;
    QNetworkReply* reply;

};

#endif // VIEW_WINDOW_H
