import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15

ApplicationWindow
{
    visible: true
    width: 400
    height: 200
    title: qsTr("Qt 6 Bug Reproduction")
Button
{
    id: myButton
    text: "button"
    enabled: false

    ToolTip.text: "some text"
    ToolTip.visible: hovered

    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        enabled: myButton.enabled
        onEntered: console.log("ENTERED!")
    }
}
}
