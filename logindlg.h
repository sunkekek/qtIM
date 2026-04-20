#ifndef LOGINDLG_H
#define LOGINDLG_H

#include <QDialog>
#include <QMouseEvent>
#include <QMessageBox>

namespace Ui {
class LoginDlg;
}

class LoginDlg : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDlg(QWidget *parent = nullptr);
    ~LoginDlg();


private slots:
    void on_pushButtonLogin_clicked();

private:
    Ui::LoginDlg *ui;

    bool eventFilter(QObject *obj, QEvent *event) override;
};

#endif // LOGINDLG_H
