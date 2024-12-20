#include "Battery.h"

Battery::Battery(QObject *parent)
    : QObject(parent), m_percentage(100), m_color("#50C828")
{
    updateColor();
}

int Battery::percentage() const
{
    return m_percentage;
}

void Battery::setPercentage(int newPercentage)
{
    if (m_percentage != newPercentage) {
        m_percentage = newPercentage;
        updateColor();
        emit percentageChanged();
    }
}

QString Battery::color() const
{
    return m_color;
}

void Battery::increase()
{
    if (m_percentage < 100) {
        setPercentage(m_percentage + 1);
    }
}

void Battery::decrease()
{
    if (m_percentage > 0) {
        setPercentage(m_percentage - 1);
    }
}

void Battery::setBatteryLevel(int level)
{
    if (level >= 0 && level <= 100) {
        setPercentage(level);
    }
}

void Battery::updateColor()
{
    if (m_percentage <= 5) {
        m_color = "#D84440";
    } else if (m_percentage <= 20) {
        m_color = "#EA821E";
    } else if (m_percentage <= 45) {
        m_color = "#F9C502";
    } else {
        m_color = "#50C828";
    }

    emit colorChanged();
}
