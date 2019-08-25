#ifndef UI_MAINDIALOG_H
#define UI_MAINDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <Qt3Support/Q3MimeSourceFactory>

class Ui_MainDialog
{
public:
    QWidget *widget;
    QWidget *widget_2;
    QWidget *widget_3;
    QWidget *widget_4;
    QWidget *widget_5;
    QWidget *layoutWidget_3;
    QWidget *widget_6;
    QWidget *widget_7;
    QWidget *widget_8;
    QWidget *widget_9;
    QWidget *widget_10;
    QWidget *widget_11;
    QVBoxLayout *vboxLayout;
    QVBoxLayout *vboxLayout1;
    QLabel *textLabel1;
    QLabel *label;
    QLabel *label_2;
    QSpacerItem *spacerItem;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem1;
    QGridLayout *gridLayout;
    QRadioButton *gbggRadio;
    QRadioButton *genesisRadio;
    QRadioButton *snesRadio;
    QRadioButton *nesRadio;
    QSpacerItem *spacerItem2;
    QSpacerItem *spacerItem3;
    QHBoxLayout *hboxLayout1;
    QSpacerItem *spacerItem4;
    QGridLayout *gridLayout1;
    QLabel *textLabel4_2_2_2;
    QLineEdit *compareEdit;
    QLabel *textLabel2_2_2_2;
    QLabel *textLabel3_2_2_2;
    QLineEdit *addressEdit;
    QLineEdit *valueEdit;
    QSpacerItem *spacerItem5;
    QSpacerItem *spacerItem6;
    QSplitter *splitter;
    QWidget *layoutWidget_3_2;
    QHBoxLayout *hboxLayout2;
    QSpacerItem *spacerItem7;
    QVBoxLayout *vboxLayout2;
    QLineEdit *gamegenieEdit;
    QLabel *textLabel5_2_2_2_2_2;
    QSpacerItem *spacerItem8;

    void setupUi(QDialog *MainDialog)
    {
    MainDialog->setObjectName(QString::fromUtf8("MainDialog"));
    MainDialog->resize(QSize(322, 252).expandedTo(MainDialog->minimumSizeHint()));
    widget = new QWidget(MainDialog);
    widget->setObjectName(QString::fromUtf8("widget"));
    widget->setGeometry(QRect(9, 213, 359, 84));
    widget_2 = new QWidget(MainDialog);
    widget_2->setObjectName(QString::fromUtf8("widget_2"));
    widget_2->setGeometry(QRect(140, 225, 97, 60));
    widget_3 = new QWidget(MainDialog);
    widget_3->setObjectName(QString::fromUtf8("widget_3"));
    widget_3->setGeometry(QRect(9, 123, 359, 84));
    widget_4 = new QWidget(MainDialog);
    widget_4->setObjectName(QString::fromUtf8("widget_4"));
    widget_4->setGeometry(QRect(9, 71, 359, 46));
    widget_5 = new QWidget(MainDialog);
    widget_5->setObjectName(QString::fromUtf8("widget_5"));
    widget_5->setGeometry(QRect(50, 135, 277, 60));
    layoutWidget_3 = new QWidget(MainDialog);
    layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
    layoutWidget_3->setGeometry(QRect(9, 121, 385, 55));
    widget_6 = new QWidget(MainDialog);
    widget_6->setObjectName(QString::fromUtf8("widget_6"));
    widget_6->setGeometry(QRect(66, 122, 272, 53));
    widget_7 = new QWidget(MainDialog);
    widget_7->setObjectName(QString::fromUtf8("widget_7"));
    widget_7->setGeometry(QRect(9, 157, 447, 89));
    widget_8 = new QWidget(MainDialog);
    widget_8->setObjectName(QString::fromUtf8("widget_8"));
    widget_8->setGeometry(QRect(94, 158, 278, 87));
    widget_9 = new QWidget(MainDialog);
    widget_9->setObjectName(QString::fromUtf8("widget_9"));
    widget_9->setGeometry(QRect(283, 159, 88, 85));
    widget_10 = new QWidget(MainDialog);
    widget_10->setObjectName(QString::fromUtf8("widget_10"));
    widget_10->setGeometry(QRect(189, 159, 88, 85));
    widget_11 = new QWidget(MainDialog);
    widget_11->setObjectName(QString::fromUtf8("widget_11"));
    widget_11->setGeometry(QRect(95, 159, 88, 85));
    vboxLayout = new QVBoxLayout(MainDialog);
    vboxLayout->setSpacing(6);
    vboxLayout->setMargin(8);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    vboxLayout1 = new QVBoxLayout();
    vboxLayout1->setSpacing(0);
    vboxLayout1->setMargin(0);
    vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
    textLabel1 = new QLabel(MainDialog);
    textLabel1->setObjectName(QString::fromUtf8("textLabel1"));
    QSizePolicy sizePolicy((QSizePolicy::Policy)1, (QSizePolicy::Policy)1);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(textLabel1->sizePolicy().hasHeightForWidth());
    textLabel1->setSizePolicy(sizePolicy);
    textLabel1->setAlignment(Qt::AlignCenter);

    vboxLayout1->addWidget(textLabel1);

    label = new QLabel(MainDialog);
    label->setObjectName(QString::fromUtf8("label"));
    QSizePolicy sizePolicy1((QSizePolicy::Policy)5, (QSizePolicy::Policy)1);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
    label->setSizePolicy(sizePolicy1);
    label->setAlignment(Qt::AlignCenter);

    vboxLayout1->addWidget(label);

    label_2 = new QLabel(MainDialog);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    QSizePolicy sizePolicy2((QSizePolicy::Policy)5, (QSizePolicy::Policy)1);
    sizePolicy2.setHorizontalStretch(0);
    sizePolicy2.setVerticalStretch(0);
    sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
    label_2->setSizePolicy(sizePolicy2);
    label_2->setAlignment(Qt::AlignCenter);

    vboxLayout1->addWidget(label_2);


    vboxLayout->addLayout(vboxLayout1);

    spacerItem = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

    vboxLayout->addItem(spacerItem);

    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(0);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    spacerItem1 = new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout->addItem(spacerItem1);

    gridLayout = new QGridLayout();
    gridLayout->setSpacing(1);
    gridLayout->setMargin(0);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    gbggRadio = new QRadioButton(MainDialog);
    gbggRadio->setObjectName(QString::fromUtf8("gbggRadio"));

    gridLayout->addWidget(gbggRadio, 1, 1, 1, 1);

    genesisRadio = new QRadioButton(MainDialog);
    genesisRadio->setObjectName(QString::fromUtf8("genesisRadio"));

    gridLayout->addWidget(genesisRadio, 1, 0, 1, 1);

    snesRadio = new QRadioButton(MainDialog);
    snesRadio->setObjectName(QString::fromUtf8("snesRadio"));

    gridLayout->addWidget(snesRadio, 0, 1, 1, 1);

    nesRadio = new QRadioButton(MainDialog);
    nesRadio->setObjectName(QString::fromUtf8("nesRadio"));
    nesRadio->setChecked(true);

    gridLayout->addWidget(nesRadio, 0, 0, 1, 1);


    hboxLayout->addLayout(gridLayout);

    spacerItem2 = new QSpacerItem(10, 16, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout->addItem(spacerItem2);


    vboxLayout->addLayout(hboxLayout);

    spacerItem3 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

    vboxLayout->addItem(spacerItem3);

    hboxLayout1 = new QHBoxLayout();
    hboxLayout1->setSpacing(6);
    hboxLayout1->setMargin(0);
    hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
    spacerItem4 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout1->addItem(spacerItem4);

    gridLayout1 = new QGridLayout();
    gridLayout1->setSpacing(5);
    gridLayout1->setMargin(0);
    gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
    textLabel4_2_2_2 = new QLabel(MainDialog);
    textLabel4_2_2_2->setObjectName(QString::fromUtf8("textLabel4_2_2_2"));
    textLabel4_2_2_2->setAlignment(Qt::AlignCenter);

    gridLayout1->addWidget(textLabel4_2_2_2, 1, 2, 1, 1);

    compareEdit = new QLineEdit(MainDialog);
    compareEdit->setObjectName(QString::fromUtf8("compareEdit"));
    QSizePolicy sizePolicy3((QSizePolicy::Policy)7, (QSizePolicy::Policy)0);
    sizePolicy3.setHorizontalStretch(1);
    sizePolicy3.setVerticalStretch(0);
    sizePolicy3.setHeightForWidth(compareEdit->sizePolicy().hasHeightForWidth());
    compareEdit->setSizePolicy(sizePolicy3);

    gridLayout1->addWidget(compareEdit, 0, 2, 1, 1);

    textLabel2_2_2_2 = new QLabel(MainDialog);
    textLabel2_2_2_2->setObjectName(QString::fromUtf8("textLabel2_2_2_2"));
    QSizePolicy sizePolicy4((QSizePolicy::Policy)5, (QSizePolicy::Policy)1);
    sizePolicy4.setHorizontalStretch(0);
    sizePolicy4.setVerticalStretch(0);
    sizePolicy4.setHeightForWidth(textLabel2_2_2_2->sizePolicy().hasHeightForWidth());
    textLabel2_2_2_2->setSizePolicy(sizePolicy4);
    textLabel2_2_2_2->setAlignment(Qt::AlignCenter);

    gridLayout1->addWidget(textLabel2_2_2_2, 1, 0, 1, 1);

    textLabel3_2_2_2 = new QLabel(MainDialog);
    textLabel3_2_2_2->setObjectName(QString::fromUtf8("textLabel3_2_2_2"));
    textLabel3_2_2_2->setAlignment(Qt::AlignCenter);

    gridLayout1->addWidget(textLabel3_2_2_2, 1, 1, 1, 1);

    addressEdit = new QLineEdit(MainDialog);
    addressEdit->setObjectName(QString::fromUtf8("addressEdit"));
    QSizePolicy sizePolicy5((QSizePolicy::Policy)7, (QSizePolicy::Policy)0);
    sizePolicy5.setHorizontalStretch(2);
    sizePolicy5.setVerticalStretch(0);
    sizePolicy5.setHeightForWidth(addressEdit->sizePolicy().hasHeightForWidth());
    addressEdit->setSizePolicy(sizePolicy5);

    gridLayout1->addWidget(addressEdit, 0, 1, 1, 1);

    valueEdit = new QLineEdit(MainDialog);
    valueEdit->setObjectName(QString::fromUtf8("valueEdit"));
    QSizePolicy sizePolicy6((QSizePolicy::Policy)7, (QSizePolicy::Policy)0);
    sizePolicy6.setHorizontalStretch(1);
    sizePolicy6.setVerticalStretch(0);
    sizePolicy6.setHeightForWidth(valueEdit->sizePolicy().hasHeightForWidth());
    valueEdit->setSizePolicy(sizePolicy6);

    gridLayout1->addWidget(valueEdit, 0, 0, 1, 1);


    hboxLayout1->addLayout(gridLayout1);

    spacerItem5 = new QSpacerItem(10, 16, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout1->addItem(spacerItem5);


    vboxLayout->addLayout(hboxLayout1);

    spacerItem6 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

    vboxLayout->addItem(spacerItem6);

    splitter = new QSplitter(MainDialog);
    splitter->setObjectName(QString::fromUtf8("splitter"));
    splitter->setOrientation(Qt::Horizontal);
    layoutWidget_3_2 = new QWidget(splitter);
    layoutWidget_3_2->setObjectName(QString::fromUtf8("layoutWidget_3_2"));
    hboxLayout2 = new QHBoxLayout(layoutWidget_3_2);
    hboxLayout2->setSpacing(6);
    hboxLayout2->setMargin(0);
    hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
    spacerItem7 = new QSpacerItem(10, 16, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout2->addItem(spacerItem7);

    vboxLayout2 = new QVBoxLayout();
    vboxLayout2->setSpacing(0);
    vboxLayout2->setMargin(0);
    vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
    gamegenieEdit = new QLineEdit(layoutWidget_3_2);
    gamegenieEdit->setObjectName(QString::fromUtf8("gamegenieEdit"));

    vboxLayout2->addWidget(gamegenieEdit);

    textLabel5_2_2_2_2_2 = new QLabel(layoutWidget_3_2);
    textLabel5_2_2_2_2_2->setObjectName(QString::fromUtf8("textLabel5_2_2_2_2_2"));
    textLabel5_2_2_2_2_2->setAlignment(Qt::AlignCenter);

    vboxLayout2->addWidget(textLabel5_2_2_2_2_2);


    hboxLayout2->addLayout(vboxLayout2);

    spacerItem8 = new QSpacerItem(10, 16, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout2->addItem(spacerItem8);


    vboxLayout->addWidget(splitter);

    textLabel4_2_2_2->setBuddy(compareEdit);
    textLabel2_2_2_2->setBuddy(valueEdit);
    textLabel3_2_2_2->setBuddy(addressEdit);
    textLabel5_2_2_2_2_2->setBuddy(gamegenieEdit);
    QWidget::setTabOrder(nesRadio, snesRadio);
    QWidget::setTabOrder(snesRadio, genesisRadio);
    QWidget::setTabOrder(genesisRadio, gbggRadio);
    QWidget::setTabOrder(gbggRadio, valueEdit);
    QWidget::setTabOrder(valueEdit, addressEdit);
    QWidget::setTabOrder(addressEdit, compareEdit);
    QWidget::setTabOrder(compareEdit, gamegenieEdit);
    retranslateUi(MainDialog);

    QMetaObject::connectSlotsByName(MainDialog);
    } // setupUi

    void retranslateUi(QDialog *MainDialog)
    {
    MainDialog->setWindowTitle(QApplication::translate("MainDialog", "Game Genie Encoder/Decoder 0.90"));
    textLabel1->setText(QApplication::translate("MainDialog", "<html><head><meta name=\"qrichtext\" content=\"1\" /></head><body style=\" white-space: pre-wrap; font-family:MS Shell Dlg; font-weight:400; font-style:normal; text-decoration:none;\"><p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Game Genie Encoder/Decoder 0.90</p></body></html>"));
    label->setText(QApplication::translate("MainDialog", "<html><head><meta name=\"qrichtext\" content=\"1\" /></head><body style=\" white-space: pre-wrap; font-family:MS Shell Dlg; font-weight:400; font-style:normal; text-decoration:none;\"><p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#000000;\">Copyright (C) 2005 emuWorks</span></p></body></html>"));
    label_2->setText(QApplication::translate("MainDialog", "<html><head><meta name=\"qrichtext\" content=\"1\" /></head><body style=\" white-space: pre-wrap; font-family:MS Shell Dlg; font-weight:400; font-style:normal; text-decoration:none;\"><p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">http://games.technoplaza.net/</p></body></html>"));
    gbggRadio->setText(QApplication::translate("MainDialog", "Game &Boy / Game Gear"));
    gbggRadio->setShortcut(QApplication::translate("MainDialog", "Alt+B"));
    genesisRadio->setText(QApplication::translate("MainDialog", "&Genesis"));
    genesisRadio->setShortcut(QApplication::translate("MainDialog", "Alt+G"));
    snesRadio->setText(QApplication::translate("MainDialog", "&Super Nintendo"));
    snesRadio->setShortcut(QApplication::translate("MainDialog", "Alt+S"));
    nesRadio->setText(QApplication::translate("MainDialog", "&Nintendo"));
    nesRadio->setShortcut(QApplication::translate("MainDialog", "Alt+N"));
    textLabel4_2_2_2->setText(QApplication::translate("MainDialog", "&Compare"));
    textLabel2_2_2_2->setText(QApplication::translate("MainDialog", "&Value"));
    textLabel3_2_2_2->setText(QApplication::translate("MainDialog", "&Address"));
    textLabel5_2_2_2_2_2->setText(QApplication::translate("MainDialog", "Game G&enie"));
    Q_UNUSED(MainDialog);
    } // retranslateUi

};

namespace Ui {
    class MainDialog: public Ui_MainDialog {};
} // namespace Ui

#endif // UI_MAINDIALOG_H
