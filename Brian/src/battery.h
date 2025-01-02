#ifndef BATTERY_H
#define BATTERY_H

#include <QObject>
#include <QString>

class Battery : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int percentage READ percentage WRITE setPercentage NOTIFY percentageChanged)
    Q_PROPERTY(QString color READ color NOTIFY colorChanged)

public:
    explicit Battery(QObject *parent = nullptr);

    int percentage() const;
    void setPercentage(int newPercentage);

    QString color() const;

public slots:
    void increase();
    void decrease();
    void setBatteryLevel(int level);

signals:
    void percentageChanged();
    void colorChanged();

private:
    int m_percentage;
    QString m_color;

    void updateColor();
};

#endif // BATTERY_H
