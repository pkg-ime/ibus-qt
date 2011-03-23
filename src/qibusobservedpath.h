#ifndef _Q_IBUS_OBSERVED_PATH_H_
#define _Q_IBUS_OBSERVED_PATH_H_

#include <QDir>
#include <QDebug>
#include <QDateTime>
#include <QXmlStreamWriter>
#include <QtXml/QDomNode>
#include "qibusserializable.h"

namespace IBus {

class ObservedPath;
typedef Pointer<ObservedPath> ObservedPathPointer;

class ObservedPath : public Serializable
{
    Q_OBJECT;

public:
    ObservedPath () {}
    ObservedPath (QString path): m_path(path) {}

    ~ObservedPath () {}

public:
    virtual bool serialize (QDBusArgument &argument);
    virtual bool deserialize (const QDBusArgument &argument);

public:
    bool parseXmlNode (const QDomNode & node);
    const QString & path() const { return m_path; }
    int mtime() const { return m_mtime; }

#if 0
    bool isObservedPathModified () const;
    void setObservedPathStat ();
    void traverseObservedPath (QVector<ObservedPathPointer> & observedPathVec) const;


    bool isRegularFile() const
    {
        QFileInfo fi(m_path);
        return fi.isFile();
    }

    bool isDirFile() const
    {
        QFileInfo fi(m_path);
        return fi.isDir();
    }
#endif

private:
    QString m_path;
    uint    m_mtime;
    bool    m_isDir;
    bool    m_isExist;

    IBUS_SERIALIZABLE
};

};

#endif
