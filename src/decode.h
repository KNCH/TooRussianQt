#ifndef DECODE_H
#define DECODE_H

#include <QObject>
#include <QMessageBox>
#include <QDir>
#include <QFile>
#include <QCoreApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QDebug>

/*!
 * \class Decode
 * \brief Decodes and encodes entered text.
 *
 * \author  KNCH
 * \version 0.2
 * \date    11.03.2012
 */
class Decode : public QObject
{
    Q_OBJECT

public:
    explicit Decode(QObject *parent = 0);

    bool     openDB();
    void     enToRu();
    void     ruToEn();

    void     setOutString(QString newString);
    QString  getOutString();
    void     setRawString(QString newString);
    QString  getRawString();

private:
    /*!
     * \brief output string
     *
     * \see Decode
     */
    QString outString;

    /*!
     * \brief string for encoding/decoding
     *
     * \see Decode
     */
    QString rawString;

    /*!
     * \brief database for encoding/decoding
     *
     * \see Decode
     */
    QSqlDatabase db;
signals:

public slots:


};

#endif // DECODE_H
