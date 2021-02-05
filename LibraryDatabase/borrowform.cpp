#include "borrowform.h"
#include "ui_borrowform.h"
#include "QDebug"
#include "mainwindow.h"

BorrowForm::BorrowForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BorrowForm)
{
    ui->setupUi(this);
}

BorrowForm::BorrowForm(int bookId, QMap<int,QString> dict,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BorrowForm)
{
    ui->setupUi(this);
    this->comboSource = dict;
    for(QMap<int,QString>::iterator it = comboSource.begin();it!=comboSource.end();++it){
        QVariant v;
        v.setValue(it.key());
        this->ui->comboBox->addItem(it.value(),v);
    }

}



BorrowForm::~BorrowForm()
{
    delete ui;
}

void BorrowForm::on_BorrowBtn_clicked()
{
    qDebug() << "Witam";

   //pobieranie danych z formularza
    _borrow.Id_book = 1;
    _borrow.Id_book = 1;
    _borrow.borrowDate = "05.02.2021";
    _borrow.returnDate = " ";
    _borrow.Id_user = 1;

    emit borrowAdded(_borrow);
    this->close();
}
