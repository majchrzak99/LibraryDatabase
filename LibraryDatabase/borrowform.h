#ifndef BORROWFORM_H
#define BORROWFORM_H

#include <QDialog>
#include "Domain/Common/List.h"
#include "Domain/Entities/borrowing.h"
#include "Domain/Entities/user.h"
namespace Ui {
class BorrowForm;
}

class BorrowForm : public QDialog
{
    Q_OBJECT

public:
    explicit BorrowForm(QWidget *parent = nullptr);
    explicit BorrowForm(int bookId, List<User> users,QWidget *parent = nullptr );
    ~BorrowForm();

private:
    Ui::BorrowForm *ui;
};

#endif // BORROWFORM_H
