#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <includes/Repository.h>

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



private slots:
    void on_browseBtn1_clicked();

    void on_browseBtn2_clicked();

    void on_enterToRepo_clicked();

    void on_addBtn_clicked();

    void on_commitBtn_clicked();

private:
    Ui::MainWindow *ui;
    QString selectedFolder;
    Repository* repo;
    QString fileToAdd;

};
#endif // MAINWINDOW_H
