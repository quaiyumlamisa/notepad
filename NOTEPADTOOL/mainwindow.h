#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QFile>
#include<QFileDialog>
#include<QTextStream>
#include<QMessageBox>
#include<QString>
#include<QFont>
#include<QFontDialog>
#include<QColorDialog>
#include<QColor>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionExit_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionCut_triggered();

    void on_actionUndo_triggered();

    void on_actionFont_triggered();

    void on_actionColor_triggered();

    void on_actionBackground_color_triggered();

    void on_actionBackgroundcolor_Edit_text_triggered();



private:
    Ui::MainWindow *ui;
    QString currentFile = " ";




};

#endif // MAINWINDOW_H
