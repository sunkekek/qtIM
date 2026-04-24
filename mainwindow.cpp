#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("IM-Chat");

    ui->centralwidget->setLayout(ui->horizontalLayout);

    // 关键：设置尺寸策略
    ui->widgetMenu->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->widgetContact->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->widgetChatContext->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // 给三列添加三个垂直布局
    vLayoutMenu = new QVBoxLayout(ui->widgetMenu);
    vLayoutContact = new QVBoxLayout(ui->widgetContact);
    vLayoutChatContext = new QVBoxLayout(ui->widgetChatContext);

    // chat菜单栏设置
    // 打开应用后默认进入聊天窗口
    QLabel *labelMenuChat = new QLabel();
    QPixmap pixmap(":/resources/icons/qq.jpg");
    if (pixmap.isNull()) {
        labelMenuChat->setText("图片加载失败");
    } else {
        labelMenuChat->setFixedSize(35, 35);
        labelMenuChat->setPixmap(pixmap);
        // 可选：自动缩放以适应布局（推荐）
        labelMenuChat->setScaledContents(true); // 图片会拉伸填满 QLabel 尺寸
        // 或者保持比例缩放（更美观）：
        // imageLabel->setPixmap(pixmap.scaled(200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    vLayoutMenu->addWidget(labelMenuChat,1, Qt::AlignHCenter);

    // chat最近联系人栏设置
    chatHistory = new QListWidget;
    chatHistory->setStyleSheet("QListWidget {border:none}");
    vLayoutContact->addWidget(chatHistory);
    QListWidgetItem *item1 = new QListWidgetItem("测试-联系人1");
    QListWidgetItem *item2 = new QListWidgetItem("测试-联系人2");

    chatHistory->addItem(item1);
    chatHistory->addItem(item2);

    // chat对话栏设置
    // 顶部的聊天信息与···
    QWidget *titleWidget = new QWidget;
    titleWidget->setStyleSheet("QWidget {background-color: rgb(255, 255, 0)}");
    QHBoxLayout *titleHLayout = new QHBoxLayout;
    titleHLayout->addWidget(new QLabel("聊天信息"), 1, Qt::AlignLeft|Qt::AlignTop);
    titleHLayout->addWidget(new QLabel("· · ·"), 1, Qt::AlignRight|Qt::AlignTop);
    titleWidget->setLayout(titleHLayout);
    vLayoutChatContext->addWidget(titleWidget,1, Qt::AlignVCenter);

    // 聊天记录
    QLabel *chatMsg = new QLabel("1"
                                 "\n"
                                 "1"
                                 "\n"
                                 "1"
                                 "\n"
                                 "1"
                                 "\n"
                                 "1"
                                 "\n"
                                 "1"
                                 "\n"
                                 "1"
                                 "\n"
                                 "1"
                                 "\n"
                                 "1"
                                 "\n"
                                 "1"
                                 "\n"
                                 "11111111111111111111");
    chatMsg->setStyleSheet("QLabel {background-color: rgb(0, 255, 0)}");
    chatMsg->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    vLayoutChatContext->addWidget(chatMsg, 10, Qt::AlignVCenter);

    // 输入框
    QWidget *chatInput = new QWidget;
    chatInput->setStyleSheet("QWidget {background-color: rgb(0, 0, 255)}");
    vLayoutChatContext->addWidget(chatInput, 3, Qt::AlignVCenter);

    QVBoxLayout *inputLayout = new QVBoxLayout;
    chatInput->setLayout(inputLayout);
    // 输入操作
    QWidget *inputOpt = new QWidget;

    QHBoxLayout *inputOptLayout = new QHBoxLayout;
    inputOpt->setLayout(inputOptLayout);
    QLabel *label1 = new QLabel("表情包");
    QLabel *label2 = new QLabel("选择文件");
    QLabel *label3 = new QLabel("截屏");
    inputOptLayout->addWidget(label1);
    inputOptLayout->addWidget(label2);
    inputOptLayout->addWidget(label3);

    inputLayout->addWidget(inputOpt,1);

    // 输入框
    QTextEdit *inputEdit = new QTextEdit;
    inputLayout->addWidget(inputEdit,8);
    // 发送按钮
    QPushButton *sendBtn = new QPushButton("发送");
    inputLayout->addWidget(sendBtn,1);



    // 统一居顶部设置
    vLayoutMenu->addStretch();
    vLayoutContact->addStretch();
    vLayoutChatContext->addStretch();


}

MainWindow::~MainWindow()
{
    delete ui;


    delete vLayoutMenu;
    delete vLayoutContact;
    delete vLayoutChatContext;

    delete chatHistory;
}
