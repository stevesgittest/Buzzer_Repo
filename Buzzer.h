#ifndef BUZZER_H
#define BUZZER_H

#include <QObject>
#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QTime>

class Buzzer : public QObject
{
    Q_OBJECT
public:
    explicit Buzzer(QObject *parent = 0);

private:
    const QString BuzzerRun;
    const QString BuzzerDutyPercent;
    const QString BuzzerPeriod;

    void delay( int millisecondsToWait );

signals:

public slots:

    void enableBuzzer();
    void disableBuzzer();
    void setFrequency(unsigned int Hertz);

    void test();


};

#endif // BUZZER_H
