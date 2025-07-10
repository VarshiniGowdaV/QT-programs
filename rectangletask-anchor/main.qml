import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle
    {
        id:rect
        width: 200
        height: 100
        color: "red"
    }
    Rectangle
    {
        id:rect1
        width: 200
        height: 100
        color: "blue"
        anchors.left:rect.right
        anchors.top:rect.bottom
    }
    Rectangle
    {
        id:rect2
        width: 200
        height: 100
        color: "green"
        anchors.left:rect1.right
        anchors.top:rect1.bottom
    }
    Rectangle
    {
        id:rect3
        width: 200
        height: 100
        color: "purple"
        anchors.left:rect2.right
        anchors.top:rect2.bottom
    }
    Rectangle
    {
        id:rect4
        width: 200
        height: 100
        color: "pink"
        anchors.left:rect3.right
        anchors.top:rect3.bottom
    }
    Rectangle
    {
        id:rect5
        width: 200
        height: 100
        color: "black"
        anchors.left:rect4.right
        anchors.top:rect4.bottom
    }
    Rectangle
    {
        id:rect6
        width: 200
        height: 100
        color: "brown"
        anchors.left:rect5.right
        anchors.top:rect5.bottom
    }
    Rectangle
    {
        id:rect7
        width: 200
        height: 100
        color: "yellow"
        anchors.left:rect6.right
        anchors.top:rect6.bottom
    }
    Rectangle
    {
        id:rect8
        width: 200
        height: 100
        color: "orange"
        anchors.left:rect7.right
        anchors.top:rect7.bottom
    }
}
