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
    book.PublishDate = this->ui->PublishDateLineEdit->text().toStdString();
    book.PublishCountry = this->ui->CountryPublishLineEdit->text().toStdString();
    book.IsbnNumber = this->ui->IsbnNumberLineEdit->text().toStdString();

    emit bookAdded(book);
    this->close();
}
