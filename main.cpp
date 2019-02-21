#include <QDebug>
#include <QApplication>
#include <QTextEdit>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    QTextEdit textEdit;
    textEdit.show();
//    qDebug() << "hello";
    return app.exec();
}