#ifndef FILEUTIL_H
#define FILEUTIL_H

#include <QString>
#include <QDebug>
using namespace std;

namespace FileUtil{


const char pathSeparator = '/';

QString getFolderPath(QString path){
    return path.left(path.lastIndexOf(pathSeparator));
}

QString getFileName(QString path){
    return path.right(path.lastIndexOf(pathSeparator)+1);
}

}
#endif // FILEUTIL_H
