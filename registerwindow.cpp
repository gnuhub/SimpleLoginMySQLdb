#include "registerwindow.h"
#include "ui_registerwindow.h"

RegisterWindow::RegisterWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_pushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::database("mainBase");
    QString emailEdit = ui->lineEdit_3->text();
    QString userEdit = ui->lineEdit->text();
    QString passEdit = ui->lineEdit_2->text();
    QString md5pass = QString(QCryptographicHash::hash((passEdit.toLatin1()),QCryptographicHash::Md5).toHex());
    QVariant v,a;
    QSqlQuery query(db);
    if(userEdit==""){
        QMessageBox::critical(0,"No Username", "You did not enter a username");
        return;
    }
    if(passEdit==""){
        QMessageBox::critical(0,"No Password", "You did not enter a password");
        return;
    }
    if(emailEdit==""){
        QMessageBox::critical(0,"No email", "You did not enter a email");
      return;
    }

//-------------------------------------------------------------------------------------------------------------------
    query.prepare(QString("SELECT `userName` FROM `TestBase`.`Users` WHERE `userName` LIKE ?"));
   query.bindValue(0, userEdit);

   if (!query.exec()) {
        qDebug() << query.lastError().text();
        return;
       }

    query.first();
   v = query.value(0);
    if (v.toString()!=""){
            QMessageBox::critical(0,"Error","The username " + v.toString()  + " already exists");
            return;
    }
    //----------------------------------------------------------------------------------------------------------

        query.prepare(QString("SELECT `email`,`userName`  FROM `TestBase`.`Users` WHERE `email` LIKE ?"));
        query.bindValue(0, emailEdit);
        if (!query.exec()) {
            qDebug() << query.lastError().text();
            return;
        }
query.first();
v = query.value(0);
a = query.value(1);
        if(v.toString()!=""){
            QMessageBox::critical(0,"Error","The email " + v.toString()  + " already exists and is registred to the account " + a.toString());
            return;
        }




        //-----------------------------------------
        query.prepare(" INSERT INTO `TestBase`.`Users` (`userName` ,`hashPass` ,`email` )VALUES (?, ?, ?)");
        query.bindValue(0, userEdit);
        query.bindValue(1, md5pass);
        query.bindValue(2, emailEdit);

        if (!query.exec()) {
            qDebug() << query.lastError().text();
            QMessageBox::critical(0,"Error","Due to an error your registration could not be completed");
            return;
        }else{
            QMessageBox::information(0,"Registration sucessfull","Your registration has been sucessfull");
        }


}

void RegisterWindow::on_pushButton_2_clicked()
{
close();
}
