
#include "loing.h"
#include "ui_loing.h"




Loing::Loing(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Loing)
{
    ui->setupUi(this);
 QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", "mainBase");
 qDebug() << db.lastError();
 db.setHostName("192.168.1.95");
 db.setDatabaseName("TestBase");
 db.setUserName("afonso");
 db.setPassword("test");
 if (!db.open()) {
     QMessageBox::critical(0,"Connection error","Could not connect to the database, please check your internet connection.");
     }
}

Loing::~Loing()
{
    delete ui;
    QSqlDatabase db = QSqlDatabase::database("mainBase");
    db.close();
}


void Loing::on_loginButton_clicked()
{

    QSqlDatabase db = QSqlDatabase::database("mainBase");



    QString passCltext = ui->passEdit->text();
    QString userName = ui->userEdit->text();
   QString md5pass = QString(QCryptographicHash::hash((passCltext.toLatin1()),QCryptographicHash::Sha512).toHex());
   if(userName==""){
        QMessageBox::critical(0, "No username provided","You left the username blank");
        return;     }
    if(passCltext==""){
     QMessageBox::critical(0, "No password provided","You left the password blank");
     return;
    }




    QSqlQuery query(db);
    query.prepare("SELECT `hashPass` FROM `TestBase`.`Users` WHERE `userName` = :user_name");
    query.bindValue(":user_name", userName);
    bool logsuf=true;
    if (!query.exec()) {
        qDebug() << query.lastError().text();
        logsuf == false;
        return;
    }
    if(logsuf==false){
    return;
    }
    query.first();
    QVariant v = query.value(0);
    if(md5pass==v.toString()){
        QMessageBox::information(0,"Login Sucessfull","Login Sucessfull");
        //open window here

    }else{
        QMessageBox::critical(0, "Invalid credentials","The credentials that you entered are incorrect");
        return;
    }


}





void Loing::on_checkBox_toggled(bool checked)
{
    int currentState = ui->checkBox->checkState();
    if (currentState==0){
        ui->passEdit->setEchoMode(QLineEdit::Password);
    }else{
        ui->passEdit->setEchoMode(QLineEdit::Normal);
    }

}

void Loing::on_pushButton_2_clicked()
{

RegWin = new RegisterWindow(this);
RegWin->setWindowTitle("Register");
RegWin->show();

}
