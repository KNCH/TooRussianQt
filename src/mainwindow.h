#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "decode.h"

/*!
 * \namespace Ui
 * \brief Qt-Widget-UI namespace.
 *
 */
namespace Ui
{
class MainWindow;
}

/*!
 * \class MainWindow
 * \brief Main window of the the program.
 *
 * \author  KNCH
 * \version 0.1
 * \date    01.12.2011
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_ButtonRuEn_clicked();

    void on_ButtonEnRu_clicked();

    void on_buttonExit_clicked();

private:
    /*!
     * \brief UI.
     *
     * \see MainWindow
     */
    Ui::MainWindow *ui;
    /*!
     * \brief Decode-Module
     *
     * \see Decode
     */
    Decode *decodeModule;
};

#endif // MAINWINDOW_H
