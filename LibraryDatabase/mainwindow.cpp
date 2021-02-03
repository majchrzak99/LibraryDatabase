#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "userform.h"
#include "bookform.h"
#include <QString>
#include <QList>
#include <QStringList>
#include <QDir>
#include <QDebug>
#include <QDialog>
#include <QtCore>
#include <QtGui>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStandardItemModel *model = new QStandardItemModel(5,5,this);
    QStringList horzHeaders;
    horzHeaders << "ID książki" << "Tytuł książki" << "Autor" << "Rok wydania" << "Kraj publikacji" << "Numer ISBN";
    model->setHorizontalHeaderLabels(horzHeaders);
    ui->BookTable->setModel(model);
}


MainWindow::~MainWindow()
{
    delete ui;
}


/// REGION Borrowings




/// ENDREGION





/// REGION Books
void MainWindow::on_AddBookBtn_clicked()
{

    BookForm bookForm(this);
    QObject::connect(&bookForm,&BookForm::bookAdded,this,&MainWindow::onBookChanged);
    bookForm.exec();

    //Przykładowa obsługa listy
    //    Book book;
    //    book.Id = 1;
    //    book.Title = "test";
    //    book.Author = "Autor";
    //    book.IsbnNumber = "1234";
    //    book.PublishDate = "2020-01-20";
    //    book.PublishCountry = "PL";
    //    _books.Add(book);

    //    Book tmp = _books.FirstOrDefault([](Book x){return x.Id == 1;});

    //    _books.Remove(&book);

    //Pobieranie wartości z textboxa

}

void MainWindow::on_EditBookBtn_clicked()
{
    BookForm bookForm(this);
    bookForm.exec();
}

void MainWindow::onBookChanged(Book book)
{
    this->_books.Add(book);
    //qDebug() << "element: "<<(_books.begin() != _books.begin() ? "tak":"nie" )<< "\n";
    for(List<Book>::iterator it = _books.begin();it != _books.end();++it)
    {
        qDebug() << "element: "<<it->Title.c_str() << "\n";
    }

    if(book.Id == 0)
    {
        this->_books.Add(book);
        saveDataToFile(book);
    }
    else
    {
        Book *tmp = this->_books.FirstOrDefault([&](Book b){return b.Id == book.Id;});
        tmp->Title = book.Title;
        tmp->Author = book.Author;
        tmp->PublishCountry = book.PublishCountry;
        tmp->PublishDate = book.PublishDate;
        tmp->IsbnNumber = book.IsbnNumber;
    }
}

void MainWindow::saveDataToFile(Book book)
{
    QString filename = "data.csv";
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly | QIODevice::Append))
    {
       QTextStream stream(&file);
       stream << QString::number(book.Id) <<","<< book.Title.c_str()<<"," << book.Author.c_str()<<"," << book.PublishDate.c_str()<<"," << book.PublishCountry.c_str()<<"," << book.IsbnNumber.c_str() << Qt::endl;
    }
}


void MainWindow::on_DeleteBookBtn_clicked()
{
    QMessageBox msgBox(QMessageBox::Warning,"Potwierdź","Czy na pewno?",QMessageBox::Yes|QMessageBox::No);
    msgBox.setButtonText(QMessageBox::Yes,"Tak");
    msgBox.setButtonText(QMessageBox::No,"Nie");

    int result = msgBox.exec();
    switch (result)
    {
    case QMessageBox::Yes:
        break;
    case QMessageBox::No:
        break;
    }

}

/// ENDREGION




/// REGION User

void MainWindow::on_AddUserBtn_clicked()
{
    UserForm userForm(this);
    userForm.exec();
}

void MainWindow::on_EditUserBtn_clicked()
{
    UserForm userForm(this);
    userForm.exec();
}

void MainWindow::on_DeleteUserBtn_clicked()
{
    QMessageBox msgBox(QMessageBox::Warning,"Potwierdź","Czy na pewno?",QMessageBox::Yes|QMessageBox::No);
    msgBox.setButtonText(QMessageBox::Yes,"Tak");
    msgBox.setButtonText(QMessageBox::No,"Nie");

    int result = msgBox.exec();
    switch (result)
    {
    case QMessageBox::Yes:
        break;
    case QMessageBox::No:
        break;
    }
}

/// ENDREGION
