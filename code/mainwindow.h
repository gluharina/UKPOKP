#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
//#include "../code/ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Ui::MainWindow *ui;
    MainWindow(QWidget *parent = nullptr): QMainWindow(parent)
      , ui(new Ui::MainWindow) { ui->setupUi(this);};
    ~MainWindow() {  delete ui;};
    bool CheckLineEdit(Ui::MainWindow *w);

private slots:
    void on_StartButton_clicked();
    void on_ClButton_clicked();

};
#endif // MAINWINDOW_H
