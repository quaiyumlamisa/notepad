
#include "mainwindow.h"


#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{


    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    currentFile.clear();
    ui->textEdit->setText(QString());
}

void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog:: getOpenFileName(this, "Open the file");
    QFile file(filename);
    currentFile=filename;
    if(!file.open(QIODevice::ReadOnly | QFile:: Text))
    {
         QMessageBox::warning(this,"Warning","Can't open file : " + file.errorString());

    }
    setWindowTitle(filename);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}

void MainWindow::on_actionSave_triggered()
{
    QString filename= QFileDialog::getSaveFileName(this,"save");
    QFile file(filename);
    if(!file.open(QFile::WriteOnly | QFile:: Text))
    {

        QMessageBox:: warning(this,"Warning" ,"Can't save file : " +file.errorString());
        return;
    }
     currentFile=filename;
      setWindowTitle(filename);
       QTextStream out(&file);
       QString text=ui->textEdit->toPlainText();
       out<<text;
       file.close();
}








void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}


void MainWindow::on_actionCopy_triggered()
{
   ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
     ui->textEdit->paste();
}

void MainWindow::on_actionCut_triggered()
{
     ui->textEdit->cut();
}

void MainWindow::on_actionUndo_triggered()
{
     ui->textEdit->undo();
}

void MainWindow::on_actionFont_triggered()
{
   bool ok;
   QFont font = QFontDialog::getFont(&ok, this);
   if(ok)
   {
      ui->textEdit->setFont(font);


   }

   else {
       return;
   }
}

void MainWindow::on_actionColor_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white,this,"Choose Color");
    if(color.isValid())
    {
       ui->textEdit->setTextColor(color);
    }
    else {
        return;
    }
}

void MainWindow::on_actionBackground_color_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white,this,"Choose Color");
    if(color.isValid())
    {
        ui->textEdit->setTextBackgroundColor(color);
    }
    else {
        return;
    }
}

void MainWindow::on_actionBackgroundcolor_Edit_text_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white,this,"Choose Color");
    if(color.isValid())
    {
        ui->textEdit->setPalette(QPalette(color));
    }
    else {
        return;
    }
}



