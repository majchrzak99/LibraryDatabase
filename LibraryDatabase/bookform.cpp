#include "bookform.h"
#include "ui_bookform.h"

BookForm::BookForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookForm)
{
    ui->setupUi(this);
}

BookForm::~BookForm()
{
    delete ui;
}
