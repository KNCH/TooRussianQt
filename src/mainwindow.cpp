#include "mainwindow.h"
#include "ui_mainwindow.h"

/*!
 * \brief Constructor.
 *
 * Sets up the main window and creates a decode-module.
 * \see MainWindow
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    decodeModule = new Decode();

    this->setWindowIcon(QIcon(":tooRussianIcon/icon.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ButtonRuEn_clicked()
{
    decodeModule->setRawString(this->ui->textArea0->toPlainText());
    decodeModule->ruToEn();

    this->ui->textArea0->setText(decodeModule->getOutString());
}

void MainWindow::on_ButtonEnRu_clicked()
{
    decodeModule->setRawString(this->ui->textArea0->toPlainText());
    decodeModule->enToRu();

    this->ui->textArea0->setText(decodeModule->getOutString());

}

void MainWindow::on_buttonExit_clicked()
{

}
