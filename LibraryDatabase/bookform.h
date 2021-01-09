#ifndef BOOKFORM_H
#define BOOKFORM_H

#include <QDialog>
#include "Domain/Entities/book.h"

namespace Ui {
class BookForm;
}

class BookForm : public QDialog
{
    Q_OBJECT

public:
    explicit BookForm(QWidget *parent = nullptr);
    ~BookForm();

private slots:
    void on_SaveBtn_clicked();
signals:
    void bookAdded(Book book);
private:
    Ui::BookForm *ui;
};

#endif // BOOKFORM_H
