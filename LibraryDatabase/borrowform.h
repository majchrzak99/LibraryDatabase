#ifndef BORROWFORM_H
#define BORROWFORM_H

#include <QDialog>
#include "Domain/Common/List.h"
#include "Domain/Entities/borrowing.h"
#include "Domain/Entities/user.h"
#include <QMap>
namespace Ui {
class BorrowForm;
}

class BorrowForm : public QDialog
{
    Q_OBJECT

public:
    explicit BorrowForm(QWidget *parent = nullptr);
    explicit BorrowForm(int bookId, QMap<int,QString> dict,QWidget *parent = nullptr );
    ~BorrowForm();

private:
    Ui::BorrowForm *ui;
    QMap<int,QString> comboSource;
};

#endif // BORROWFORM_H
