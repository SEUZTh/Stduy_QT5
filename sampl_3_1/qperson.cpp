#include "qperson.h"

QPerson::QPerson(QString name, QObject *parent)
    : QObject{parent}
{
    m_name = name;
}

unsigned int QPerson::age()
{
    return m_age;
}

/**
 * @brief QPerson::setAge
 * @param value
 * @note
 * 1. emit signal
 * 2. update m_age
 */
void QPerson::setAge(unsigned int value)
{
    m_age = value;
    emit(ageChanged(m_age));
}

/**
 * @brief QPerson::incAge
 * @note
 * 1. emit signal
 * 2. update m_age
 */
void QPerson::incAge()
{
    m_age++;
    emit(ageChanged(m_age));
}
