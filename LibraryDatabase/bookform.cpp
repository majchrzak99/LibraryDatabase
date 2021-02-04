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
    this->ui->TitleLineEdit->setText(_book.Title.c_str());
    this->ui->AuthorLineEdit->setText(_book.Author.c_str());
    this->ui->PublishDateLineEdit->setText(_book.PublishDate.c_str());
    this->ui->CountryPublishLineEdit->setText(_book.PublishCountry.c_str() );
    this->ui->IsbnNumberLineEdit->setText(_book.IsbnNumber.c_str());
}

BookForm::~BookForm()
{
    delete ui;
}


void BookForm::on_SaveBtn_clicked()
{
    //pobieranie danych z formularza

    _book.Title = this->ui->TitleLineEdit->text().toStdString();
    _book.Author = this->ui->AuthorLineEdit->text().toStdString();
    _book.PublishDate = this->ui->PublishDateLineEdit->text().toStdString();
    _book.PublishCountry = this->ui->CountryPublishLineEdit->text().toStdString();
    _book.IsbnNumber = this->ui->IsbnNumberLineEdit->text().toStdString();

    emit bookAdded(_book);
    this->close();
}
