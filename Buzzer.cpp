#include "Buzzer.h"

Buzzer::Buzzer(QObject *parent) :
    QObject(parent),
    BuzzerRun("/sys/class/pwm-sunxi/pwm1/run"),
    BuzzerDutyPercent("/sys/class/pwm-sunxi/pwm1/duty_percent"),
    BuzzerPeriod("/sys/class/pwm-sunxi/pwm1/period")
{
}

void Buzzer::enableBuzzer()
{
    QFile file(BuzzerRun);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    out << "1";

    // optional, as QFile destructor will already do it:
    file.close();
}

void Buzzer::disableBuzzer()
{
    QFile file(BuzzerRun);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    out << "0";

    // optional, as QFile destructor will already do it:
    file.close();
}

void Buzzer::setFrequency(unsigned int Hertz)
{
    QFile file(BuzzerPeriod);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);

    out << QString::number(Hertz) << "hz";

    // optional, as QFile destructor will already do it:
    file.close();
}

void Buzzer::delay( int millisecondsToWait )
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}

void Buzzer::test()
{
    setFrequency(1500);
    enableBuzzer();
    delay(150);
    setFrequency(2000);
    delay(150);
    disableBuzzer();

    delay(1000);

    setFrequency(2000);
    enableBuzzer();
    delay(150);
    setFrequency(1500);
    delay(150);
    //setFrequency(1000);
    //delay(50);
    disableBuzzer();
}

/*
void Buzzer::brightness()
{
    QFile file(BuzzerPeriod);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);

    out << QString::number(Hertz) << "hz";

    // optional, as QFile destructor will already do it:
    file.close();
}*/
