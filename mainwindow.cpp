#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QPushButton"
#include "QFileDialog"


using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_browseBtn1_clicked()
{
    QString selectedFolder = QFileDialog::getExistingDirectory(this, tr("Select Folder"), QDir::homePath());

    ui->lineEdit->setText(selectedFolder);
}


void MainWindow::on_browseBtn2_clicked()
{
    QString selectedFile = QFileDialog::getOpenFileName(this, tr("Select File"), QDir::homePath());

    ui->lineEdit_2->setText(selectedFile);
}

