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
    refreshUsersTable();
    //    QStandardItemModel *model = new QStandardItemModel(5,5,this);
    //    QStringList horzHeaders;
    //    horzHeaders << "ID książki" << "Tytuł książki" << "Autor" << "Rok wydania" << "Kraj publikacji" << "Numer ISBN";
    //    model->setHorizontalHeaderLabels(horzHeaders);
    //    ui->BookTable->setModel(model);
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
}

void MainWindow::on_EditBookBtn_clicked()
{
    BookForm bookForm(this);
    bookForm.exec();
}

void MainWindow::onBookChanged(Book book)
{
    this->_books.Add(book);

    if(book.Id == 0)
    {
        this->_books.Add(book);
        //saveDataToFile(book);
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

void MainWindow::saveDataToFile()
{

    //   QString filename = "Data.csv";
    //   QFile file(filename);
    //   if (file.open(QIODevice::WriteOnly | QIODevice::Append))
    //   {
    //       QTextStream stream(&file);
    //       stream << QString::number(book.Id) <<","<< book.Title.c_str()<<"," << book.Author.c_str()<<"," << book.PublishDate.c_str()<<"," << book.PublishCountry.c_str()<<"," << book.IsbnNumber.c_str() << Qt::endl;
    //       file.close();
    //   }
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
    QObject::connect(&userForm,&UserForm::userChanged,this,&MainWindow::onUserChanged);
    userForm.exec();
}

void MainWindow::on_EditUserBtn_clicked()
{
    //pobrać zaznaczoną encję i przekazać do konstruktora
    QItemSelectionModel *select = ui->UserTable->selectionModel();
    int selectedId = 0;

    if(select->hasSelection())
    {
        int rowidx = ui->UserTable->selectionModel()->currentIndex().row();

        selectedId  = ui->UserTable->model()->data(ui->UserTable->model()->index(rowidx,0)).toInt();
    }
    User *tmp = this->_users.FirstOrDefault([&](User u){return u.Id == selectedId;});
    UserForm userForm(this,*tmp);
    QObject::connect(&userForm,&UserForm::userChanged,this,&MainWindow::onUserChanged);
    userForm.exec();
}

void MainWindow::on_DeleteUserBtn_clicked()
{
    QMessageBox msgBox(QMessageBox::Warning,"Potwierdź","Czy na pewno?",QMessageBox::Yes|QMessageBox::No);
    msgBox.setButtonText(QMessageBox::Yes,"Tak");
    msgBox.setButtonText(QMessageBox::No,"Nie");

    QItemSelectionModel *select = ui->UserTable->selectionModel();
    int selectedId = 0;

    if(select->hasSelection())
    {
        int rowidx = ui->UserTable->selectionModel()->currentIndex().row();

        selectedId  = ui->UserTable->model()->data(ui->UserTable->model()->index(rowidx,0)).toInt();
    }

    User* userToDelete = _users.FirstOrDefault([&](User u){return  u.Id == selectedId;});

    if(userToDelete == nullptr)
        return;
    int result = msgBox.exec();
    switch (result)
    {
    case QMessageBox::Yes:
        _users.Remove(userToDelete);
        refreshUsersTable();
        break;
    case QMessageBox::No:
        break;
    }
}
void MainWindow::onUserChanged(User user)
{
    if(user.Id == 0)
    {
        int max = 1;
        for(List<User>::iterator it = _users.begin(); it != _users.end(); ++it){
            if(it->Id >= max)
                max = it->Id + 1;
        }
        user.Id = max;
        this->_users.Add(user);
    }
    else
    {
        User *tmp = this->_users.FirstOrDefault([&](User u){return u.Id == user.Id;});
        if(tmp != nullptr){

            tmp->Name = user.Name;
            tmp->Pesel = user.Pesel;
            tmp->Place = user.Place;
            tmp->Street = user.Street;
            tmp->Surname = user.Surname;
            tmp->HouseFlatNo = user.HouseFlatNo;
        }
    }
    refreshUsersTable();
}

void MainWindow::refreshUsersTable()
{
    QStandardItemModel *model = new QStandardItemModel();
    QStringList horzHeaders;
    horzHeaders << "ID" << "Imię" << "Nazwisko" << "Pesel" << "Miejscowość" << "Ulica" << "Nr domu/mieszkania";
    model->setHorizontalHeaderLabels(horzHeaders);

    for(List<User>::iterator it = _users.begin();it != _users.end();++it){
        QList<QStandardItem*> items;
        items.append(new QStandardItem(it->sId().c_str()));
        items.append(new QStandardItem(it->Name.c_str()));
        items.append(new QStandardItem(it->Surname.c_str()));
        items.append(new QStandardItem(it->Pesel.c_str()));
        items.append(new QStandardItem(it->Place.c_str()));
        items.append(new QStandardItem(it->Street.c_str()));
        items.append(new QStandardItem(it->HouseFlatNo.c_str()));

        model->appendRow(items);
    }
    if(ui->UserTable->model() != nullptr)
        delete ui->UserTable->model();

    ui->UserTable->setModel(model);
    ui->UserTable->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
    ui->UserTable->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
}

/// ENDREGION
