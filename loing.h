#ifndef LOING_H
#define LOING_H

#include <QCryptographicHash>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QObject>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QMainWindow>
#include "registerwindow.h"

namespace Ui {
class Loing;
}

class Loing : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Loing(QWidget *parent = 0);
    ~Loing();
    
private slots:
    void on_pushButton_2_clicked();
    void on_checkBox_toggled(bool checked);
    void on_loginButton_clicked();

private:
    Ui::Loing *ui;
    RegisterWindow *RegWin;


};

#endif // LOING_H
