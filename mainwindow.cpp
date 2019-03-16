#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QStringListModel>
#include <QException>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QStringList drivers = QSqlDatabase::drivers();
    if (drivers.isEmpty())
        QMessageBox::information(this, tr("Драйвер"),
                                 tr("Драйвера не найдены!"));
    if(!drivers.contains("QPSQL"))
        QMessageBox::information(this, tr("Драйвер"),
                                 tr("Приложению необходим драйвер для PSQL!"));

    QString dr = drivers.at(drivers.indexOf("QPSQL"));
    ui->setupUi(this);
    Helper = new Database_Helper();
    Helper->set_driver(dr);
    works = false;

    ui->sight_list->setItemDelegate(new SimpleDelegate(ui->sight_list));

    ic_on = new QPixmap(":/icons/icon_on.png");
    ic_of = new QPixmap(":/icons/icon_of.png");

    setWindowTitle("Достопримечательности");
    setWindowIcon(QIcon(":/icons/colosseum.png"));

    cities<<"Екатеринбург" << "Нижний Новгород" << "Краснодар"
         <<"Красноярск" << "Новосибирск" << "Санкт-Петербург"
        << "Самара" << "Сочи" << "Уфа";
    ui->city_box->addItem("");
    for(QString city : cities)
        ui->city_box->addItem(city);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_label_on_of_clicked()
{
    if(!works)
    {
        ui->label_on_of->setPixmap(*ic_on);
        works = true;
        Helper->open_database();
        active_base = 1;
    }
    else
    {
        ui->label_on_of->setPixmap(*ic_of);
        works = false;
        Helper->close_database();
        active_base = 0;
        ui->sight_list->setModel(new QStringListModel());
        ui->city_box->setCurrentIndex(0);
    }
}

void MainWindow::on_city_box_activated(const QString &arg1)
{
    QStringList ResultList;
    QStringListModel *model = new QStringListModel(ui->sight_list);;

    if(works)
    {
        if(!arg1.isEmpty())
            Helper->get_data(arg1, ResultList);
        //тут можно сделать цикл по списку
        //в цикле каждому элементу добавлять иконку
        //чтоб типа забавнее было:
        //model.setData(index, str, Qt::DisplayRole);
        //model.setData(index, "ToolTip for " + str, Qt::ToolTipRole);
        //model.setData(index, QIcon(str + ".jpg"), Qt::DecorationRole);
        //вот таким вот образом, как сверху
        model->setStringList(ResultList);
        ui->sight_list->setModel(model);
    }
    else
    {
        QMessageBox::information(this, tr("База данных"),
                                 tr("Выполните включение (справа сверху)!"));
    }
}

void MainWindow::on_sight_list_doubleClicked(const QModelIndex &index)
{
    try
    {
    QStringList about;
    QString city = index.data().toString();
    Helper->fill_city_data(city, about);
    //в about нам приходит инфа о достопримечательности
    //далее эту инфу отдаем view_window в качестве параметров
    if(about.count() > 7)
    {
        sight_view = new view_window(about, this);
    }
    }
    catch(QException e)
    {
        QMessageBox::information(this, tr("Halt"),
                                 tr("Bad connection!"));
    }
}
