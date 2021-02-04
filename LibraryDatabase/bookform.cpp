#include "bookform.h"
#include "ui_bookform.h"


BookForm::BookForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookForm)
{
    ui->setupUi(this);
}

BookForm::BookForm(QWidget *parent,Book book) :
    QDialog(parent),
    ui(new Ui::BookForm)
{
    ui->setupUi(this);
    this->_book = book;
    this->ui->TitleLineEdit->setText(_book.Title);
    this->ui->AuthorLineEdit->setText(_book.Author);
    this->ui->PublishDateLineEdit->setText(_book.PublishDate);
    this->ui->CountryPublishLineEdit->setText(_book.PublishCountry);
    this->ui->IsbnNumberLineEdit->setText(_book.IsbnNumber);
}

BookForm::~BookForm()
{
    delete ui;
}


void BookForm::on_SaveBtn_clicked()
{
    //pobieranie danych z formularza

    _book.Title = this->ui->TitleLineEdit->text();
    _book.Author = this->ui->AuthorLineEdit->text();
    _book.PublishDate = this->ui->PublishDateLineEdit->text();
    _book.PublishCountry = this->ui->CountryPublishLineEdit->text();
    _book.IsbnNumber = this->ui->IsbnNumberLineEdit->text();

    emit bookAdded(_book);
    this->close();
}
