#ifndef SMWINDOW_H
#define SMWINDOW_H

#include <QDialog>

namespace Ui {
class SMWindow;
}

class SMWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SMWindow(QWidget *parent = 0);
    ~SMWindow();

private:
    Ui::SMWindow *ui;
};

#endif // SMWINDOW_H
