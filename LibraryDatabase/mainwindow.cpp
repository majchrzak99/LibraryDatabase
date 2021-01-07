#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "userform.h"
#include "bookform.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    bookForm.exec();
}

void MainWindow::on_EditBookBtn_clicked()
{
    BookForm bookForm(this);
    bookForm.exec();
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
