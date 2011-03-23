#include "qibusattribute.h"

namespace IBus {

IBUS_DECLARE_SERIALIZABLE(Attribute, IBusAttribute);

bool
Attribute::serialize (QDBusArgument &argument)
{
    if (!Serializable::serialize (argument)) {
        return false;
    }

    argument << m_type;
    argument << m_value;
    argument << m_start;
    argument << m_end;

    return true;
}

bool
Attribute::deserialize (const QDBusArgument &argument)
{
    if (!Serializable::deserialize (argument)) {
        return false;
    }

    argument >> m_type;
    argument >> m_value;
    argument >> m_start;
    argument >> m_end;

    return true;
}

};
