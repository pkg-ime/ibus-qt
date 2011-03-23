#include <Qt>
#include <QtDebug>
#include <QDBusMessage>
#include <QCoreApplication>
#include <QDBusArgument>
#include <QList>
#include <QMetaType>
#include "qibusserializable.h"
#include "qibustext.h"
#include "qibusbus.h"
#include "qibusattribute.h"

#include <iostream>

using namespace IBus;

class App : QCoreApplication {
public:
    App (int &argc, char **argv ) : QCoreApplication (argc, argv) {
    }
};

int main (int argc, char **argv)
{
    App app(argc, argv);
    Bus bus;
    SerializablePointer p = new Serializable ();
    p = bus.ping (p);

    bus.createInputContext ("Test");
    QCoreApplication::exec ();


#if 0
    qDBusRegisterMetaType<SerializablePointer>();

    QDBusArgument arg;

    {
        SerializablePointer p;
        p = new Serializable ();

        QVariant v = qVariantFromValue (p);
        QDBusVariant dv (v);
        SerializablePointer p1 = v.value<SerializablePointer>();
        arg << p;
    }


    App app(argc, argv);
    Connection connection (QString ("unix:path=/tmp/ibus-liudl/ibus-unix-0"));

    org::freedesktop::IBus bus (QString ("org.freedesktop.IBus"),
                  QString ("/org/freedesktop/IBus"),
                  connection.getConnection ());


    SerializablePointer p = /* (Serializable *) */ new Attribute();
    QVariant v = qVariantFromValue (p);

	std::cout << v.toInt();

    QDBusPendingReply<QDBusVariant> ret = bus.Ping (qDBusVariantFromSerializable (p));

    SerializablePointer p1 = qDBusVariantToSerializable (ret);
#endif
#if 0




    Serializable *obj1, *obj2;
    QDBusArgument arg;

    obj1 = new Serializable ();

    Serializable::serializeObject (obj1, arg);
    delete obj1;

    QVariant a = QVariant::fromValue(arg);


    QDBusArgument argout = ret.argumentAt<0>().variant().value<QDBusArgument>();

    Serializable::deserializeObject (obj2, argout);
#endif

    return 0;
}
