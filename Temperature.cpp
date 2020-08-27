
#include "Temperature.h"

using namespace dermair;

Temperature::Temperature() :
    m_type(INVALID),
    m_value(0.0f)
{
    //
}

Temperature::Temperature(Type type, float value) :
    m_type(type),
    m_value(value)
{
    //
}

Temperature::~Temperature()
{
    //
}

bool
Temperature::isValid()
{
    return m_type == Type::VALID ? true : false;
}

void
Temperature::validate()
{
    m_type = Type::VALID;
}

float
Temperature::getValue()
{
    return m_value;
}

void
Temperature::setValue(float value)
{
    m_value = value;
}
