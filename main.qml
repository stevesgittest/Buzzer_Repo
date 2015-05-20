import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Buzzer")


    Button {
        id: button1
        x: 38
        y: 38
        text: qsTr("Buzzer on")

        onClicked: {
            Buzzer.enableBuzzer();
        }
    }

    Button {
        id: button2
        x: 152
        y: 38
        text: qsTr("Buzzer off")

        onClicked: {
            Buzzer.disableBuzzer()
        }
    }

    Slider {
        id: frequencySlider
        x: 313
        y: 38
        width: 28
        height: 385
        stepSize: 1
        value: 1
        minimumValue: 1
        maximumValue: 2000
        orientation: Qt.Vertical

//        onValueChanged: {
//            Buzzer.setFrequency(value);
//            frequencyLabel.text = value;
//        }
    }

    Label {
        id: frequencyLabel
        x: 419
        y: 210
        font.pixelSize: 24
        text: "1"
    }

    Button {
        id: test
        x: 109
        y: 149
        text: qsTr("Test")

        onClicked: {
            Buzzer.test()
        }
    }
}
