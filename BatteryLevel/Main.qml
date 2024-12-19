import QtQuick
import QtQuick.Controls 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Battery Level")

    // Lock window size
    minimumWidth: width
    minimumHeight: height
    maximumWidth: width
    maximumHeight: height

    Component.onCompleted: {
        slider.value = batteryWidget.battery.percentage
    }

    Item {
        anchors.fill: parent
        focus: true

        BatteryWidget {
            id: batteryWidget
            anchors.centerIn: parent
            onPercentageChanged: slider.value = batteryWidget.percentage
        }

        Slider {
            id: slider
            width: 200
            from: 0
            to: 100
            stepSize: 1
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter
            anchors.verticalCenterOffset: 30
            onValueChanged: batteryWidget.battery.setBatteryLevel(Math.round(slider.value))
        }

        Text {
            anchors.centerIn: slider
            anchors.verticalCenterOffset: -100
            font.pixelSize: 18
            text: "U = Increase\nD = Decrease"
        }

        Keys.onPressed: (event) => {
                            if (event.key === Qt.Key_U) {
                                batteryWidget.battery.increase()
                            } else if (event.key === Qt.Key_D) {
                                batteryWidget.battery.decrease()
                            }
                        }
    }
}
