#ifndef BOOKFORM_H
#define BOOKFORM_H

#include <QDialog>

namespace Ui {
class BookForm;
}

class BookForm : public QDialog
{
    Q_OBJECT

public:
    explicit BookForm(QWidget *parent = nullptr);
    ~BookForm();

private:
    Ui::BookForm *ui;
};

#endif // BOOKFORM_H
