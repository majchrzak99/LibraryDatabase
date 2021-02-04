#ifndef BORROWFORM_H
#define BORROWFORM_H

#include <QDialog>

namespace Ui {
class BorrowForm;
}

class BorrowForm : public QDialog
{
    Q_OBJECT

public:
    explicit BorrowForm(QWidget *parent = nullptr);
    ~BorrowForm();

private:
    Ui::BorrowForm *ui;
};

#endif // BORROWFORM_H
