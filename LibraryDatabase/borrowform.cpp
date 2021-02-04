#include "borrowform.h"
#include "ui_borrowform.h"

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
