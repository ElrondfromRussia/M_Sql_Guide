#ifndef MY_LABEL_H
#define MY_LABEL_H

#include <QLabel>
#include <QWidget>
#include <QObject>

class My_Label : public QLabel
{
    Q_OBJECT
public:
    My_Label(QWidget * parent = 0 ):QLabel(parent){}
    ~My_Label(){}
signals:
    void clicked();
private slots:
    void mousePressEvent ( QMouseEvent * event )
    {
         emit clicked();
    }
};
#endif // MY_LABEL_H
