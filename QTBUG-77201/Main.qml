
import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 300
    height: 300
    visible: true

    Rectangle {
        id: parentItem
        width: 300; height: 300

        Rectangle {
            id: redRect
            width: 100; height: 100
            color: "red"
        }

        Rectangle {
            id: greenRect
            width: 100; height: 100
            x: 30; y: 30
            color: "green"
        }

        Rectangle {
            id: blueRect
            width: 100; height: 100
            x: 60; y: 60
            color: "blue"
        }

        Component.onCompleted: {
            // Move blueRect to index after redRect
            blueRect.stackAfter(redRect);
        }
    }
}

// import QtQuick 2.15
// import QtQuick.Window 2.15

// Window {
//     id: mainWindow
//     visible: true
//     width: 400
//     height: 400
//     title: "Stack Order Example"

//     Rectangle {
//         id: redRect
//         objectName: "red"
//         width: 200; height: 200
//         color: "red"
//         x: 50; y: 50
//     }

//     Rectangle {
//         id: blueRect
//         objectName: "blue"
//         width: 200; height: 200
//         color: "blue"
//         x: 100; y: 100
//     }
// }


// import QtQuick 2.15
// import QtQuick.Window 2.15

// Window {
//     visible: true
//     width: 300
//     height: 300
//     title: "stackAfter() Demo"

//     Rectangle {
//         id: redRect
//         width: 150
//         height: 150
//         color: "red"
//         anchors.centerIn: parent
//         z: 0  // initial stacking order
//     }

//     Rectangle {
//         id: blueRect
//         width: 100
//         height: 100
//         color: "blue"
//         anchors.centerIn: parent
//         z: 0
//     }

//     Component.onCompleted: {
//         // Move redRect behind blueRect using stackAfter
//         redRect.stackAfter(blueRect)
//         // NOTE: Visually, blue will now be on top of red
//     }
// }

