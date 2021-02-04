#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Domain/Common/list.h"
#include "Domain/Entities/book.h"
#include "Domain/Entities/user.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    int howManyBooks();

    void refreshBooksTable();

    void on_DeleteBookBtn_clicked();

    void on_DeleteUserBtn_clicked();

    void on_AddBookBtn_clicked();

    void on_AddUserBtn_clicked();

    void on_EditUserBtn_clicked();

    void on_EditBookBtn_clicked();

    void onBookChanged(Book book);

    void onUserChanged(User user);

    void on_BorrowBookBtn_clicked();

    void on_pushButton_clicked();

    void refreshBorrowTable();

private:
    Ui::MainWindow *ui;
    List<Book> _books;
    List<User> _users;
    void refreshUsersTable();
};
#endif // MAINWINDOW_H
