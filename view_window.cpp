#include "view_window.h"
#include "ui_view_window.h"

view_window::view_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::view_window)
{
    ui->setupUi(this);
}

view_window::view_window(QStringList &Sight_About, QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::view_window)
{
    ui->setupUi(this);

    Helper = new Database_Helper();
    Helper->set_driver("QPSQL");

    nam = new QNetworkAccessManager(this);
    connect(nam, SIGNAL(finished(QNetworkReply*)), this, SLOT(on_load(QNetworkReply*)));
    connect(this, SIGNAL(loaded(QPixmap)),
            ui->pict_lbl, SLOT(setPixmap(QPixmap)));

    sight_name = Sight_About.at(0);
    adress = Sight_About.at(1);
    rezim = Sight_About.at(4);
    description = Sight_About.at(3);
    picture_url = Sight_About.at(7);
    latitude =  QString(Sight_About.at(5)).toFloat();
    longitude =  QString(Sight_About.at(6)).toFloat();
    city = Sight_About.at(2);
    qDebug() << latitude;
    qDebug() << longitude;

    setWindowTitle(city);
    setWindowIcon(QIcon(":/icons/colosseum.png"));

    fill_window();

    ui->descript->setFocusPolicy(Qt::NoFocus);
}

view_window::~view_window()
{
    delete ui;
}

void view_window::fill_window()
{
//    ui->sight_name_lbl->setText(sight_name);

//    //тут надо бы как-то через QUrl подгружать картинку......
//    //хз, как х)
//    //QImage *s_pic = new QImage();
//    //ui->pict_lbl->setPixmap(QPixmap::fromImage());

//    QString full_desc;
//    full_desc.append("<html><body>");
//    full_desc.append("<p align=center>").append("<u><b>Описание:</b></u> ").
//            append(description).append("</p>");
//    full_desc.append("<p align=center>").append("<u><b>� ежим работы:</b></u> ").
//            append(rezim).append("</p>");
//    full_desc.append("<p align=center>").append("<font color = '#aa3377'><u><b>Адрес:</b></u></font> ").
//            append(adress).append("</p>");
//    full_desc.append("</body></html>");
//    ui->descript->appendHtml(full_desc);
    ui->sight_name_lbl->setText(sight_name);

    QTextDocument *doc = new QTextDocument();

    QString full_desc;
    full_desc.append("<html><body>");
    full_desc.append("<h3><p align=center>").append("<u>Описание</u></p></h3><p align=center>").
            append("<font size = 4>").append(description).append("</font></p>");
    full_desc.append("<h3><p align=center>").append("<u>режим работы</u></p></h3><p align=center>").
            append("<font size = 4>").append(rezim).append("</font></p>");
    full_desc.append("<h3><p align=center>").append("<u>адрес</u></p></h3><p align=center>").
            append("<font size = 4>").append(adress).append("</font></p>");
    full_desc.append("</body></html>");

    doc->setHtml(full_desc);

    ui->descript->setDocument(doc);

    nam->get(QNetworkRequest(QUrl(picture_url)));

}

void view_window::on_load(QNetworkReply *reply)
{
    if(reply->error() != QNetworkReply::NoError)
    {
        QMessageBox::information(this, tr("Сеть"),
                                 tr("Нет сети!"));
        //return;
    }
    QPixmap pixmap;
    pixmap.loadFromData(reply->readAll());
    emit loaded(pixmap);
    reply->deleteLater();

    show();
}
