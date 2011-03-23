#ifndef __Q_IBUS_FACTORY_ADAPTOR_H_
#define __Q_IBUS_FACTORY_ADAPTOR_H_

#include <QLinkedList>
#include <QDBusConnection>
#include <QDBusObjectPath>
#include "qibusobject.h"

class IBusFactoryAdaptor;

namespace IBus {

class Engine;
typedef Pointer<Engine> EnginePointer;

class EngineFactory : public Object
{
    Q_OBJECT;

private :
    Q_INVOKABLE EngineFactory (const QDBusConnection &conn, uint id = 0);
    ~EngineFactory ();

public:
    void addMetaObject (const QString &name, const QMetaObject *metaObject);
    static EngineFactory *getEngineFactory (const QDBusConnection &conn);

protected:
    virtual QString createEngine (const QString &name);

private Q_SLOTS:
    Q_INVOKABLE QDBusObjectPath CreateEngine (const QString &name);
    Q_INVOKABLE void Destroy ();

private :

    uint    m_id;
    QDBusConnection m_conn;
    QMap<QString, const QMetaObject *> m_engineMap;
    QLinkedList<EnginePointer> m_engineLList;
    IBusFactoryAdaptor	*m_factoryAdaptor;

    static EngineFactory	*m_factory;
};

};

#endif
