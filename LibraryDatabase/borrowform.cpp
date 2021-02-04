#include "borrowform.h"
#include "ui_borrowform.h"

BorrowForm::BorrowForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BorrowForm)
{
    ui->setupUi(this);
}

BorrowForm::BorrowForm(int bookId, List<User> users,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BorrowForm)
{
    ui->setupUi(this);
    for(List<User>::iterator it = users.begin();it!=users.end();++it){
        QVariant v;
        v.setValue(it->Id);
        QString item = it->Name.c_str();
        item += " ";
        item += it->Surname.c_str();
        this->ui->comboBox->addItem(QString(),v);
    }

}



BorrowForm::~BorrowForm()
{
    delete ui;
}
