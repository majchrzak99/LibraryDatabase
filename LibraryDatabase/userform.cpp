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
    this->ui->NameLineEdit->setText(_user.Name);
    this->ui->SurnameLineEdit->setText(_user.Surname);
    this->ui->PeselLineEdit->setText(_user.Pesel);
    this->ui->PlaceLineEdit->setText(_user.Place);
    this->ui->HouseFlatNoLineEdit->setText(_user.HouseFlatNo);
    this->ui->StreetLineEdit->setText(_user.Street);
}
UserForm::~UserForm()
{
    delete ui;
}

void UserForm::on_SaveBtn_clicked()
{
    _user.Name = this->ui->NameLineEdit->text();
    _user.Surname = this->ui->SurnameLineEdit->text();
    _user.Pesel = this->ui->PeselLineEdit->text();
    _user.Place = this->ui->PlaceLineEdit->text();
    _user.HouseFlatNo = this->ui->HouseFlatNoLineEdit->text();
    _user.Street = this->ui->StreetLineEdit->text();

    emit userChanged(_user);
    this->close();
}
