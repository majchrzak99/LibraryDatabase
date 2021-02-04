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
#include <QTableView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->BookTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->BookTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->UserTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->UserTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->BorrowingTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->BorrowingTable->setSelectionBehavior(QAbstractItemView::SelectRows);


    /// LOADING DATA FROM FILES

    QFile file("books-data.csv");
    if (file.open(QIODevice::ReadOnly))
    {
        int lineindex = 0;
        QTextStream in(&file);

        while (!in.atEnd()) {
            QString fileLine = in.readLine();
            QStringList lineToken = fileLine.split(",", QString::SkipEmptyParts);
            Book book;
            book.Id = lineToken.at(0).toInt();
            book.Title = lineToken.at(1).toStdString();
            book.Author = lineToken.at(2).toStdString();
            book.PublishDate = lineToken.at(3).toStdString();
            book.PublishCountry = lineToken.at(4).toStdString();
            book.IsbnNumber = lineToken.at(5).toStdString();
            this->_books.Add(book);
            lineindex++;
        }
        file.close();
    }


    QFile file2("users-data.csv");
    if (file2.open(QIODevice::ReadOnly))
    {
        int lineindex = 0;
        QTextStream in(&file2);

        while (!in.atEnd()) {
            QString fileLine = in.readLine();
            QStringList lineToken = fileLine.split(",", QString::SkipEmptyParts);
            User user;
            user.Id = lineToken.at(0).toInt();
            user.Name = lineToken.at(1).toStdString();
            user.Surname = lineToken.at(2).toStdString();
            user.Pesel = lineToken.at(3).toStdString();
            user.Place = lineToken.at(4).toStdString();
            user.Street = lineToken.at(5).toStdString();
            user.HouseFlatNo = lineToken.at(6).toStdString();
            this->_users.Add(user);
            lineindex++;
        }
        file2.close();
    }



    refreshUsersTable();
    refreshBooksTable();

    connect(ui->BookTable, SIGNAL(clicked(const QModelIndex &)), this, SLOT(onRowClicked(const QModelIndex &)));
}


MainWindow::~MainWindow()
{
    delete ui;
}





/// REGION Borrowings

void MainWindow::on_BorrowBookBtn_clicked()
{
    //if(boorowing
    // User* userToDelete = _users.FirstOrDefault([&](User u){return  u.Id == selectedId;});

    //
}


/// ENDREGION








/// REGION Books



int MainWindow::howManyBooks()
{
    int counter = 0;
    for(List<Book>::iterator it = _books.begin();it != _books.end();++it)
        counter++;

    return counter;
}

void MainWindow::refreshBooksTable()
{
    int tableRows = howManyBooks();
    int i = 0;
    QStandardItemModel *model = new QStandardItemModel(tableRows,6,this);

    for(List<Book>::iterator it = _books.begin();it != _books.end();++it)
    {
        model->setData(model->index(i, 0, QModelIndex()), it->Id);
        model->setData(model->index(i, 1, QModelIndex()), it->Title.c_str());
        model->setData(model->index(i, 2, QModelIndex()), it->Author.c_str());
        model->setData(model->index(i, 3, QModelIndex()), it->PublishDate.c_str());
        model->setData(model->index(i, 4, QModelIndex()), it->PublishCountry.c_str());
        model->setData(model->index(i, 5, QModelIndex()), it->IsbnNumber.c_str());
        i++;
    }


    QStringList horzHeaders;
    horzHeaders << "ID książki" << "Tytuł książki" << "Autor" << "Rok wydania" << "Kraj publikacji" << "Numer ISBN";
    model->setHorizontalHeaderLabels(horzHeaders);
    ui->BookTable->setModel(model);
}


void MainWindow::on_AddBookBtn_clicked()
{
    BookForm bookForm(this);
    QObject::connect(&bookForm,&BookForm::bookAdded,this,&MainWindow::onBookChanged);
    bookForm.exec();
}

void MainWindow::on_EditBookBtn_clicked()
{
    QItemSelectionModel *select = ui->BookTable->selectionModel();
    int selectedId = 0;

    if(select->hasSelection())
    {
        int rowidx = ui->BookTable->selectionModel()->currentIndex().row();

        selectedId  = ui->BookTable->model()->data(ui->BookTable->model()->index(rowidx,0)).toInt();
    }
    Book *tmp = this->_books.FirstOrDefault([&](Book u){return u.Id == selectedId;});
    BookForm bookForm(this, *tmp);
    QObject::connect(&bookForm,&BookForm::bookAdded,this,&MainWindow::onBookChanged);
    bookForm.exec();
}



void MainWindow::onBookChanged(Book book)
{
    if(book.Id == 0)
    {
        int max = 1;
        for(List<Book>::iterator it = _books.begin(); it != _books.end(); ++it)
        {
            if(it->Id >= max)
                max = it->Id + 1;
        }
        book.Id = max;

        this->_books.Add(book);

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

    refreshBooksTable();
}






void MainWindow::on_DeleteBookBtn_clicked()
{
    QMessageBox msgBox(QMessageBox::Warning,"Potwierdź","Czy na pewno?",QMessageBox::Yes|QMessageBox::No);
    msgBox.setButtonText(QMessageBox::Yes,"Tak");
    msgBox.setButtonText(QMessageBox::No,"Nie");


    QItemSelectionModel *select = ui->BookTable->selectionModel();
    int selectedId = 0;

    if(select->hasSelection())
    {
        int rowidx = ui->BookTable->selectionModel()->currentIndex().row();

        selectedId  = ui->BookTable->model()->data(ui->BookTable->model()->index(rowidx,0)).toInt();
    }

    Book* bookToDelete = _books.FirstOrDefault([&](Book u){return  u.Id == selectedId;});

    if(bookToDelete == nullptr)
        return;
    int result = msgBox.exec();
    switch (result)
    {
    case QMessageBox::Yes:
        _books.Remove(bookToDelete);
        refreshBooksTable();
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







/// REGION Global

void MainWindow::on_pushButton_clicked()
{
       QString filename = "books-data.csv";
       QString filename2 = "users-data.csv";
       QString filename3 = "borrowings-data.csv";

       QFile file(filename);
       if (file.open(QIODevice::WriteOnly | QIODevice::Text))
       {
           QTextStream stream(&file);
           for(List<Book>::iterator it = _books.begin();it != _books.end();++it)
           {
               stream << QString::number(it->Id) << ", " << it->Title.c_str()<<"," << it->Author.c_str() <<"," << it->PublishDate.c_str() <<"," << it->PublishCountry.c_str() <<"," << it->IsbnNumber.c_str() << Qt::endl;
           }
           file.close();
       }

       QFile file2(filename2);
       if (file2.open(QIODevice::WriteOnly | QIODevice::Text))
       {
           QTextStream stream(&file2);
           for(List<User>::iterator i = _users.begin(); i != _users.end(); ++i)
           {
               stream << QString::number(i->Id) << "," << i->Name.c_str()<< "," << i->Surname.c_str() << "," << i->Pesel.c_str() <<"," << i->Place.c_str() <<"," << i->HouseFlatNo.c_str() << ", " << i->Street.c_str() << Qt::endl;
           }
           file2.close();
       }
}

///ENDREGION
