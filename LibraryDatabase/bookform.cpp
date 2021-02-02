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


void BookForm::on_SaveBtn_clicked()
{
    //pobieranie danych z formularza
    Book book;
    book.Title = this->ui->TitleLineEdit->text().toStdString();
    book.Author = this->ui->AuthorLineEdit->text().toStdString();
    emit bookAdded(book);

}
