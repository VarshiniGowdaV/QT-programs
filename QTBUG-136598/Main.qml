

import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15
Button {
       text: "button"
       enabled: false

       ToolTip.text: "some text"
       ToolTip.visible: hovered

       MouseArea {
           anchors.fill: parent
           hoverEnabled: true
           onEntered: console.log("ENTERED!")
       }
   }

// import QtQuick 2.15
// import QtQuick.Controls 2.15
// import QtQuick.Window 2.15

// ApplicationWindow {
//     width: 400
//     height: 300
//     visible: true
//     title: "Button Hover Bug Workaround"

//     Button {
//         id: myButton
//         text: "Disabled Button"
//         anchors.centerIn: parent
//         enabled: false  // Simulate disabled state

//         ToolTip.text: "some text"
//         ToolTip.visible: hovered && enabled  // <-- Prevent tooltip when disabled

//         MouseArea {
//             anchors.fill: parent
//             hoverEnabled: true
//             enabled: parent.enabled           // <-- Prevent hover events when disabled
//             onEntered: console.log("ENTERED!")  // <-- Will not trigger when disabled
//         }
//     }
// }


