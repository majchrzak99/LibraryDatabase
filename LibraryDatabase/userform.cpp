#include "userform.h"
#include "ui_userform.h"

UserForm::UserForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserForm)
{
    ui->setupUi(this);
}
UserForm::UserForm(QWidget *parent,User user) :
    QDialog(parent),
    ui(new Ui::UserForm)
{
    ui->setupUi(this);
    this->_user = user;
}
UserForm::~UserForm()
{
    delete ui;
}

void UserForm::on_SaveBtn_clicked()
{
    _user.Name = this->ui->NameLineEdit->text().toStdString();
    _user.Surname = this->ui->SurnameLineEdit->text().toStdString();
    _user.Pesel = this->ui->PeselLineEdit->text().toStdString();
    _user.Place = this->ui->PlaceLineEdit->text().toStdString();
    _user.HouseFlatNo = this->ui->HouseFlatNoLineEdit->text().toStdString();
    _user.Street = this->ui->StreetLineEdit->text().toStdString();

    emit userChanged(_user);
    this->close();
}
