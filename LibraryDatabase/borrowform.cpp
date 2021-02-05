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

    this->_bookId = bookId;
}



BorrowForm::~BorrowForm()
{
    delete ui;
}

void BorrowForm::on_BorrowBtn_clicked()
{
   //pobieranie danych z formularza
    _borrow.Id_book = this->_bookId;
    _borrow.borrowDate = QDateTime::currentDateTime().toString();
    _borrow.returnDate = "";
    int* userId = (int*)this->ui->comboBox->itemData(this->ui->comboBox->currentIndex()).data();
    _borrow.Id_user = *userId;

    emit borrowAdded(_borrow);
    this->close();
}
