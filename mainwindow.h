#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QTextEdit>
#include <QPushButton>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QVBoxLayout *vLayoutMenu;
    QVBoxLayout *vLayoutContact;
    QVBoxLayout *vLayoutChatContext;

    //会话记录
    QListWidget *chatHistory;
};
#endif // MAINWINDOW_H
