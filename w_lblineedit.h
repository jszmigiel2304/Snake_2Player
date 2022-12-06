#ifndef W_LBLINEEDIT_H
#define W_LBLINEEDIT_H

#include <QLineEdit>
#include <QObject>
#include <QWidget>

class w_lbLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    w_lbLineEdit(QWidget *parent = nullptr, QObject * eventFilter = nullptr);
    ~w_lbLineEdit();
};

#endif // W_LBLINEEDIT_H
