#ifndef USERFORM_H
#define USERFORM_H

#include <QDialog>

namespace Ui {
class UserForm;
}

class UserForm : public QDialog
{
    Q_OBJECT

public:
    explicit UserForm(QWidget *parent = nullptr);
    ~UserForm();

private:
    Ui::UserForm *ui;
};

#endif // USERFORM_H
