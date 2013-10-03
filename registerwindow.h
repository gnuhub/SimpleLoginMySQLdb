#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QDialog>
#include <QCryptographicHash>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QObject>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QMainWindow>


namespace Ui {
    class RegisterWindow;
}

class RegisterWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterWindow(QWidget *parent = 0);
    ~RegisterWindow();

private:
    Ui::RegisterWindow *ui;

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
};

#endif // REGISTERWINDOW_H
