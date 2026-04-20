#include "logindlg.h"
#include "ui_logindlg.h"

LoginDlg::LoginDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDlg)
{
    ui->setupUi(this);
    // this->setWindowIcon(nullptr);
    // this->setWindowTitle(nullptr);
    setWindowFlags(Qt::FramelessWindowHint);
    ui->label_exit->installEventFilter(this);
}

LoginDlg::~LoginDlg()
{
    delete ui;
}

void LoginDlg::on_pushButtonLogin_clicked()
{
    if (ui->lineEditUserId->text() == tr("keke")
        && ui->lineEditPasswd->text() == tr("1234")){
        accept();
    } else {
        ui->lineEditUserId->clear();
        ui->lineEditPasswd->clear();
        QMessageBox::warning(this, tr("提示"),
                             tr("密码错误"),
                             QMessageBox::Yes);
    }
}


// 重写事件过滤器
bool LoginDlg::eventFilter(QObject *obj, QEvent *event) {
    // 判断是谁触发的事件，以及是不是鼠标按下事件
    if (obj == ui->label_exit && event->type() == QEvent::MouseButtonPress)
    {

        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if (mouseEvent->button() == Qt::LeftButton)
        {
            this->close(); // 执行关闭操作
            return true; // 返回 true 表示事件已被处理，不再向下传递
        }
    }
    // 其他情况交给父类处理
    return QDialog::eventFilter(obj, event);
}
