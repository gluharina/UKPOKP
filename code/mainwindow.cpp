#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "list.h"

bool MainWindow::CheckLineEdit(Ui::MainWindow *w)
{
   if(w->Word->text().isEmpty())
       return 0;
   return 1;
}

void MainWindow::on_StartButton_clicked()
{
   ui->OutputW->clear();
   if(!CheckLineEdit(ui))
   {
       ui->OutputW->setText("Введите");
       return;
   }
   QString Rezult;
   Rezult = Balan(ui->Word->text(), Rezult);
   ui->OutputW->append(Rezult);
}

void MainWindow::on_ClButton_clicked()
{
    ui->OutputW->clear();
    ui->Word->clear();
    return;
}




