// import QtQuick 2.15
// import QtQuick.Controls 2.15
// import QtQuick.Window 2.15

//     Button {
//             text: "button"
//             enabled: false

//             ToolTip.text: "some text"
//             ToolTip.visible: hovered

//             MouseArea {
//                 anchors.fill: parent
//                 hoverEnabled: true
//                 onEntered: console.log("ENTERED!")
//             }
//         }



// fixed_hover_example.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 200
    title: "Fixed Hover Example (Qt 6)"

    Button {
        id: myButton
        text: "Disabled"
        anchors.centerIn: parent
        enabled: false  // ✅ Same disabled state

        ToolTip.text: "Some tooltip"
        ToolTip.visible: hovered

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true

            // ✅ FIX: Disable MouseArea when button is disabled
            enabled: parent.enabled

            onEntered: console.log("✅ Hover triggered")
        }
    }
}
