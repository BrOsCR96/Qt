import QtQuick
import QtQuick.Controls 2.15
import CustomComponents 1.0

Item {
    width: 200
    height: 400

    Battery {
        id: battery
    }

    property alias battery: battery
    readonly property var percentage: battery.percentage

    Rectangle {
        width: 150
        height: 350
        anchors.centerIn: parent
        anchors.horizontalCenterOffset: 50
        color: "white"
        border.color: "black"
        border.width: 12
        radius: 12
        opacity: 50

        Rectangle {
            width: 60
            height: 25
            anchors.top: parent.top
            anchors.topMargin: -20
            anchors.horizontalCenter: parent.horizontalCenter
            color: "black"
            radius: 6
        }

        Rectangle {
            width: 110
            height: (parent.height - 36) * (battery.percentage / 100)
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 18
            anchors.horizontalCenter: parent.horizontalCenter
            color: battery.color
            radius: 8

            Behavior on height { NumberAnimation { duration: 300 } }
            Behavior on color { ColorAnimation { duration: 200 } }
        }
    }
}
