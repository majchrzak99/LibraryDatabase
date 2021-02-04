#include "borrowform.h"
#include "ui_borrowform.h"

BorrowForm::BorrowForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BorrowForm)
{
    ui->setupUi(this);
}

BorrowForm::~BorrowForm()
{
    delete ui;
}
