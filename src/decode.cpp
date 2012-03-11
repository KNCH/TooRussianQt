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

    //    if (!openDB())
    //    {
    //        qDebug("=(((");
    //        QMessageBox::critical(0, parent->tr("Cannot open database"),
    //                              parent->tr("Unable to establish a database connection.\n"
    //                                         "This example needs SQLite support. Please read "
    //                                         "the Qt SQL driver documentation for information how "
    //                                         "to build it.\n\n"
    //                                         "Click Cancel to exit."), QMessageBox::Cancel);
    //    }
    if (openDB())
        qDebug("DB is opened");

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
    const QString path = QDir::toNativeSeparators((QCoreApplication::applicationDirPath().append(QDir::separator()).append("testDB.db")));
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
        int symNumber;
        query.exec("SELECT COUNT(*) FROM tooTable;");

        if (query.next())
        {
            symNumber = query.value(0).toInt();
        }


        for (int i=1; i<=65; i++)
        {
            query.exec(QString("SELECT id,en,ru FROM tooTable where id=" + QString::number(i)));
//            qDebug(QString("select * from person where id =%1").arg(i).toUtf8());
//            qDebug(QString("select * from person where id =" + QString::number(i)).toUtf8());
            query.next();
            rawString = rawString.replace(trUtf8(query.value(1).toString().toUtf8()), trUtf8(query.value(2).toString().toUtf8()));
            qDebug(query.value(0).toString().toUtf8());
            qDebug(query.value(1).toString().toUtf8());
            qDebug(query.value(2).toString().toUtf8());
        }
    }
    //    qDebug("" + QString::number(query.value(0).toInt()).toUtf8());
    //    qDebug("" + symNumber);

    //    int symNumber = SELECT Count(*) FROM tooTable;
    //    if (!rawString.isEmpty())
    //    {
    //        rawString = rawString.replace(trUtf8("q"), trUtf8("й"));
    //        rawString = rawString.replace(trUtf8("w"), trUtf8("ц"));
    //        rawString = rawString.replace(trUtf8("e"), trUtf8("у"));
    //        rawString = rawString.replace(trUtf8("r"), trUtf8("к"));
    //        rawString = rawString.replace(trUtf8("t"), trUtf8("е"));
    //        rawString = rawString.replace(trUtf8("y"), trUtf8("н"));
    //        rawString = rawString.replace(trUtf8("u"), trUtf8("г"));
    //        rawString = rawString.replace(trUtf8("i"), trUtf8("ш"));
    //        rawString = rawString.replace(trUtf8("o"), trUtf8("щ"));
    //        rawString = rawString.replace(trUtf8("p"), trUtf8("з"));
    //        rawString = rawString.replace(trUtf8("a"), trUtf8("ф"));
    //        rawString = rawString.replace(trUtf8("s"), trUtf8("ы"));
    //        rawString = rawString.replace(trUtf8("d"), trUtf8("в"));
    //        rawString = rawString.replace(trUtf8("f"), trUtf8("а"));
    //        rawString = rawString.replace(trUtf8("g"), trUtf8("п"));
    //        rawString = rawString.replace(trUtf8("h"), trUtf8("р"));
    //        rawString = rawString.replace(trUtf8("j"), trUtf8("о"));
    //        rawString = rawString.replace(trUtf8("k"), trUtf8("л"));
    //        rawString = rawString.replace(trUtf8("l"), trUtf8("д"));
    //        rawString = rawString.replace(trUtf8("z"), trUtf8("я"));
    //        rawString = rawString.replace(trUtf8("x"), trUtf8("ч"));
    //        rawString = rawString.replace(trUtf8("c"), trUtf8("с"));
    //        rawString = rawString.replace(trUtf8("b"), trUtf8("и"));
    //        rawString = rawString.replace(trUtf8("n"), trUtf8("т"));
    //        rawString = rawString.replace(trUtf8("m"), trUtf8("ь"));
    //        rawString = rawString.replace(trUtf8(";"), trUtf8("ж"));
    //        rawString = rawString.replace(trUtf8(","), trUtf8("б"));
    //        rawString = rawString.replace(trUtf8("v"), trUtf8("м"));
    //        rawString = rawString.replace(trUtf8("`"), trUtf8("ё"));
    //        rawString = rawString.replace(trUtf8("["), trUtf8("х"));
    //        rawString = rawString.replace(trUtf8("\'"),trUtf8("э"));
    //        rawString = rawString.replace(trUtf8("."),trUtf8("ю"));
    //        rawString = rawString.replace(trUtf8("/"), trUtf8("."));

    //        rawString = rawString.replace(trUtf8("Q"), trUtf8("Й"));
    //        rawString = rawString.replace(trUtf8("W"), trUtf8("Ц"));
    //        rawString = rawString.replace(trUtf8("E"), trUtf8("У"));
    //        rawString = rawString.replace(trUtf8("R"), trUtf8("К"));
    //        rawString = rawString.replace(trUtf8("T"), trUtf8("Е"));
    //        rawString = rawString.replace(trUtf8("Y"), trUtf8("Н"));
    //        rawString = rawString.replace(trUtf8("U"), trUtf8("Г"));
    //        rawString = rawString.replace(trUtf8("I"), trUtf8("Щ"));
    //        rawString = rawString.replace(trUtf8("O"), trUtf8("Щ"));
    //        rawString = rawString.replace(trUtf8("P"), trUtf8("З"));
    //        rawString = rawString.replace(trUtf8("A"), trUtf8("Ф"));
    //        rawString = rawString.replace(trUtf8("S"), trUtf8("Ы"));
    //        rawString = rawString.replace(trUtf8("D"), trUtf8("В"));
    //        rawString = rawString.replace(trUtf8("F"), trUtf8("А"));
    //        rawString = rawString.replace(trUtf8("G"), trUtf8("П"));
    //        rawString = rawString.replace(trUtf8("H"), trUtf8("Р"));
    //        rawString = rawString.replace(trUtf8("J"), trUtf8("О"));
    //        rawString = rawString.replace(trUtf8("K"), trUtf8("Л"));
    //        rawString = rawString.replace(trUtf8("L"), trUtf8("Д"));
    //        rawString = rawString.replace(trUtf8("Z"), trUtf8("Я"));
    //        rawString = rawString.replace(trUtf8("X"), trUtf8("Ч"));
    //        rawString = rawString.replace(trUtf8("C"), trUtf8("С"));
    //        rawString = rawString.replace(trUtf8("B"), trUtf8("И"));
    //        rawString = rawString.replace(trUtf8("N"), trUtf8("Т"));
    //        rawString = rawString.replace(trUtf8("M"), trUtf8("Ь"));
    //        rawString = rawString.replace(trUtf8(":"), trUtf8("Ж"));
    //        rawString = rawString.replace(trUtf8("<"), trUtf8("Б"));
    //        rawString = rawString.replace(trUtf8("V"), trUtf8("М"));
    //        rawString = rawString.replace(trUtf8("~"), trUtf8("Ё"));
    //        rawString = rawString.replace(trUtf8("{"), trUtf8("Х"));
    //        rawString = rawString.replace(trUtf8("\""),trUtf8("Э"));
    //        rawString = rawString.replace(trUtf8(">"), trUtf8("Ю"));
    //    }
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
        rawString = rawString.replace(trUtf8("й"), trUtf8("q"));
        rawString = rawString.replace(trUtf8("ц"), trUtf8("w"));
        rawString = rawString.replace(trUtf8("у"), trUtf8("e"));
        rawString = rawString.replace(trUtf8("к"), trUtf8("r"));
        rawString = rawString.replace(trUtf8("е"), trUtf8("t"));
        rawString = rawString.replace(trUtf8("н"), trUtf8("y"));
        rawString = rawString.replace(trUtf8("г"), trUtf8("u"));
        rawString = rawString.replace(trUtf8("ш"), trUtf8("i"));
        rawString = rawString.replace(trUtf8("щ"), trUtf8("o"));
        rawString = rawString.replace(trUtf8("з"), trUtf8("p"));
        rawString = rawString.replace(trUtf8("ф"), trUtf8("a"));
        rawString = rawString.replace(trUtf8("ы"), trUtf8("s"));
        rawString = rawString.replace(trUtf8("в"), trUtf8("d"));
        rawString = rawString.replace(trUtf8("а"), trUtf8("f"));
        rawString = rawString.replace(trUtf8("п"), trUtf8("g"));
        rawString = rawString.replace(trUtf8("р"), trUtf8("h"));
        rawString = rawString.replace(trUtf8("о"), trUtf8("j"));
        rawString = rawString.replace(trUtf8("л"), trUtf8("k"));
        rawString = rawString.replace(trUtf8("д"), trUtf8("l"));
        rawString = rawString.replace(trUtf8("я"), trUtf8("z"));
        rawString = rawString.replace(trUtf8("ч"), trUtf8("x"));
        rawString = rawString.replace(trUtf8("с"), trUtf8("c"));
        rawString = rawString.replace(trUtf8("и"), trUtf8("b"));
        rawString = rawString.replace(trUtf8("т"), trUtf8("n"));
        rawString = rawString.replace(trUtf8("ь"), trUtf8("m"));
        rawString = rawString.replace(trUtf8("ж"), trUtf8(";"));
        rawString = rawString.replace(trUtf8("б"), trUtf8(","));
        rawString = rawString.replace(trUtf8("м"), trUtf8("v"));
        rawString = rawString.replace(trUtf8("ё"), trUtf8("`"));
        rawString = rawString.replace(trUtf8("х"), trUtf8("["));
        rawString = rawString.replace(trUtf8("э"), trUtf8("\'"));
        rawString = rawString.replace(trUtf8("."), trUtf8("/"));
        rawString = rawString.replace(trUtf8("ю"), trUtf8("."));

        rawString = rawString.replace(trUtf8("Й"), trUtf8("Q"));
        rawString = rawString.replace(trUtf8("Ц"), trUtf8("W"));
        rawString = rawString.replace(trUtf8("У"), trUtf8("E"));
        rawString = rawString.replace(trUtf8("К"), trUtf8("R"));
        rawString = rawString.replace(trUtf8("Е"), trUtf8("T"));
        rawString = rawString.replace(trUtf8("Н"), trUtf8("Y"));
        rawString = rawString.replace(trUtf8("Г"), trUtf8("U"));
        rawString = rawString.replace(trUtf8("Щ"), trUtf8("I"));
        rawString = rawString.replace(trUtf8("Щ"), trUtf8("O"));
        rawString = rawString.replace(trUtf8("З"), trUtf8("P"));
        rawString = rawString.replace(trUtf8("Ф"), trUtf8("A"));
        rawString = rawString.replace(trUtf8("Ы"), trUtf8("S"));
        rawString = rawString.replace(trUtf8("В"), trUtf8("D"));
        rawString = rawString.replace(trUtf8("А"), trUtf8("F"));
        rawString = rawString.replace(trUtf8("П"), trUtf8("G"));
        rawString = rawString.replace(trUtf8("Р"), trUtf8("H"));
        rawString = rawString.replace(trUtf8("О"), trUtf8("J"));
        rawString = rawString.replace(trUtf8("Л"), trUtf8("K"));
        rawString = rawString.replace(trUtf8("Д"), trUtf8("L"));
        rawString = rawString.replace(trUtf8("Я"), trUtf8("Z"));
        rawString = rawString.replace(trUtf8("Ч"), trUtf8("X"));
        rawString = rawString.replace(trUtf8("С"), trUtf8("C"));
        rawString = rawString.replace(trUtf8("М"), trUtf8("V"));
        rawString = rawString.replace(trUtf8("И"), trUtf8("B"));
        rawString = rawString.replace(trUtf8("Т"), trUtf8("N"));
        rawString = rawString.replace(trUtf8("Ь"), trUtf8("M"));
        rawString = rawString.replace(trUtf8("Ж"), trUtf8(":"));
        rawString = rawString.replace(trUtf8("Б"), trUtf8("<"));
        rawString = rawString.replace(trUtf8("Ё"), trUtf8("~"));
        rawString = rawString.replace(trUtf8("Х"), trUtf8("{"));
        rawString = rawString.replace(trUtf8("Э"), trUtf8("\""));
        rawString = rawString.replace(trUtf8("Ю"), trUtf8(":"));
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
