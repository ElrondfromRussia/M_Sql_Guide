/********************************************************************************
** Form generated from reading UI file 'view_window.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEW_WINDOW_H
#define UI_VIEW_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_view_window
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *sight_name_lbl;
    QLabel *pict_lbl;
    QTextEdit *descript;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *view_window)
    {
        if (view_window->objectName().isEmpty())
            view_window->setObjectName(QStringLiteral("view_window"));
        view_window->resize(420, 433);
        centralwidget = new QWidget(view_window);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, -1, 401, 391));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        sight_name_lbl = new QLabel(verticalLayoutWidget);
        sight_name_lbl->setObjectName(QStringLiteral("sight_name_lbl"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sight_name_lbl->sizePolicy().hasHeightForWidth());
        sight_name_lbl->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
        font.setUnderline(true);
        sight_name_lbl->setFont(font);
        sight_name_lbl->setAlignment(Qt::AlignCenter);
        sight_name_lbl->setWordWrap(true);

        verticalLayout->addWidget(sight_name_lbl);

        pict_lbl = new QLabel(verticalLayoutWidget);
        pict_lbl->setObjectName(QStringLiteral("pict_lbl"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pict_lbl->sizePolicy().hasHeightForWidth());
        pict_lbl->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(12);
        pict_lbl->setFont(font1);
        pict_lbl->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(pict_lbl);

        descript = new QTextEdit(verticalLayoutWidget);
        descript->setObjectName(QStringLiteral("descript"));
        QFont font2;
        font2.setPointSize(11);
        descript->setFont(font2);
        descript->setReadOnly(true);

        verticalLayout->addWidget(descript);

        view_window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(view_window);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 420, 21));
        view_window->setMenuBar(menubar);
        statusbar = new QStatusBar(view_window);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        view_window->setStatusBar(statusbar);

        retranslateUi(view_window);

        QMetaObject::connectSlotsByName(view_window);
    } // setupUi

    void retranslateUi(QMainWindow *view_window)
    {
        view_window->setWindowTitle(QApplication::translate("view_window", "MainWindow", 0));
        sight_name_lbl->setText(QApplication::translate("view_window", "Sight_Name", 0));
        pict_lbl->setText(QApplication::translate("view_window", "Picture", 0));
    } // retranslateUi

};

namespace Ui {
    class view_window: public Ui_view_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_WINDOW_H
