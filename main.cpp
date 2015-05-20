#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "Buzzer.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    Buzzer theBuzzer;

    QQmlContext *ctxt = engine.rootContext();
    ctxt->setContextProperty("Buzzer", &theBuzzer);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
