#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    QRect rec1(60,60,100,100);
     QRect rec2(20,20,40,40);
    QPen framepen(Qt::red);
    framepen.setWidth(6);

    QBrush brush1 (Qt::blue,Qt::DiagCrossPattern);
    painter.fillRect(rec1,brush1);

    QBrush brush2 (Qt::blue,Qt::SolidPattern);
    painter.fillRect(rec2,brush2);


    painter.setPen(framepen);
    painter.drawRect(rec1);

    painter.drawEllipse(rec2);

}
