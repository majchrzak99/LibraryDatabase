#ifndef USERFORM_H
#define USERFORM_H

#include <QDialog>
#include <Domain/Entities/user.h>

namespace Ui {
class UserForm;
}

class UserForm : public QDialog
{
    Q_OBJECT

public:
    explicit UserForm(QWidget *parent = nullptr);
    explicit UserForm(QWidget *parent,User user) ;
    ~UserForm();

private slots:
    void on_SaveBtn_clicked();

signals:
    void userChanged(User user);
private:
    Ui::UserForm *ui;
    User _user;
};

#endif // USERFORM_H
