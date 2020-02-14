#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
class Inspector;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:

    void onLoadFile();

private:
    Ui::MainWindow *uiMainWindow;
    Ui::Inspector* uiInspector;
};

#endif // MAINWINDOW_H
