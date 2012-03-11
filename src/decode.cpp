#include "decode.h"

/*!
 * \brief Constructor.
 *
 * Clears the strings.
 * \see Decode
 */
Decode::Decode(QObject *parent) :
    QObject(parent)
{
    /* clear strings */
    outString.clear();
    rawString.clear();

    /* open database; give error message, if connection to database failed */
    if (!openDB())
    {
        QMessageBox::critical(0, parent->tr(":: TooRussian | Cannot open database ::"),
                              parent->tr("Unable to establish a database connection.\n"
                                         "Click Close to exit."), QMessageBox::Close);
        exit(0);
    }
}

/*!
 * \brief Open database.
 *
 * Opens database with symbols data.
 * \see Decode
 */
bool Decode::openDB()
{
    // Find QSLite driver
    db = QSqlDatabase::addDatabase("QSQLITE");

    // Check if the database-file exists
    const QString path = QDir::toNativeSeparators((QCoreApplication::applicationDirPath().append(QDir::separator()).append("TooRussianDB.db")));
    if (!(QFile::exists(path)))
    {
        return false;
    }

    db.setDatabaseName(path);


    // Open databasee
    return db.open();
}

/*!
 * \brief Method enToRu.
 *
 * Decodes the english-keyboard-layout-entered russian text
 * and saves it in the variable "outString".
 * \see Decode
 */
void Decode::enToRu()
{
    if (!rawString.isEmpty())
    {
        QSqlQuery query;
        int symNumber; // variable for the number of all symbols in the database

        /* get the number of all symbols in database */
        query.exec("SELECT COUNT(*) FROM tooTable;");
        if (query.next())
        {
            symNumber = query.value(0).toInt();
        }


        /* replace each occurance of every symbol in the database */
        for (int i=1; i<=symNumber; i++)
        {
            query.exec(QString("SELECT id,en,ru FROM tooTable where id=" + QString::number(i)));
            if (query.next())
            {
                rawString = rawString.replace(trUtf8(query.value(1).toString().toUtf8()), trUtf8(query.value(2).toString().toUtf8()));
            }
        }
    }
    outString = rawString;
}

/*!
 * \brief Method ruToEn.
 *
 * Decodes the russian-keyboard-layout-entered english text
 * and saves it in the variable "outString".
 * \see Decode
 */
void Decode::ruToEn()
{
    if (!rawString.isEmpty())
    {
        QSqlQuery query;
        int symNumber; // variable for the number of all symbols in the database

        /* get the number of all symbols in database */
        query.exec("SELECT COUNT(*) FROM tooTable;");
        if (query.next())
        {
            symNumber = query.value(0).toInt();
        }


        /* replace each occurance of every symbol in the database */
        for (int i=1; i<=symNumber; i++)
        {
            query.exec(QString("SELECT id,en,ru FROM tooTable where id=" + QString::number(i)));
            if (query.next())
            {
                rawString = rawString.replace(trUtf8(query.value(2).toString().toUtf8()), trUtf8(query.value(1).toString().toUtf8()));
            }
        }
    }
    outString = rawString;
}

/*!
 * \brief Setter for outString.
 *
 * \see Decode
 */
void Decode::setOutString(QString newString)
{
    this->outString = newString;
}

/*!
 * \brief Getter for outString.
 *
 * \see Decode
 */
QString Decode::getOutString()
{
    return this->outString;
}

/*!
 * \brief Setter for rawString.
 *
 * \see Decode
 */
void Decode::setRawString(QString newString)
{
    this->rawString = newString;
}

/*!
 * \brief Getter for rawString.
 *
 * \see Decode
 */
QString Decode::getRawString()
{
    return this->rawString;
}
