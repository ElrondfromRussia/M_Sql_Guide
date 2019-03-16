#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <database_helper.h>
#include <view_window.h>
#include <QtWidgets/QtWidgets>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_label_on_of_clicked();

    void on_city_box_activated(const QString &arg1);

    void on_sight_list_doubleClicked(const QModelIndex &index);

private:
    int active_base;
    bool works;
    QStringList cities;
    QPixmap *ic_on;
    QPixmap *ic_of;
    Ui::MainWindow *ui;
    Database_Helper * Helper;
    view_window * sight_view;
};


class SimpleDelegate : public QStyledItemDelegate
{
public:
    SimpleDelegate(QObject* pobj = 0) : QStyledItemDelegate(pobj)
    {
    }
    void paint(QPainter* pPainter,
               const QStyleOptionViewItem& option,
               const QModelIndex& index
               ) const
    {
        if (option.state & QStyle::State_MouseOver)
        {
            QRect rect = option.rect;
            QLinearGradient gradient(0, 0, rect.width(), rect.height());
            gradient.setColorAt(0, Qt::white);
            gradient.setColorAt(0.5, Qt::blue);
            gradient.setColorAt(1, Qt::green);
            pPainter->setBrush(gradient);
            pPainter->drawRect(rect);
        }
        QStyledItemDelegate::paint(pPainter, option, index);
    }
};

#endif // MAINWINDOW_H
