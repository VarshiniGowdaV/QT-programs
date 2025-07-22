import QtQuick 2.15
import QtQuick.Controls 2.15 as T

T.Control {
    id: control
    property alias model: comboModel
    property alias popupVisible: popup.visible
    property int highlightedIndex: -1

    signal activated(int index)

    width: 200
    height: 40

    ListModel {
        id: comboModel
        // Uncomment below items to test with model entries
        // ListElement { text: "Option 1" }
        // ListElement { text: "Option 2" }
    }

    T.Popup {
        id: popup
        y: control.height
        width: control.width
        height: Math.min(contentItem.implicitHeight, control.Window.height - topMargin - bottomMargin)
        topMargin: 6
        bottomMargin: 6
        palette: control.palette

        // ✅ FIX: Don't show popup if model is empty
        visible: control.delegateModel.count > 0 && control.popupVisible

        contentItem: ListView {
            id: popupListView
            clip: true
            implicitHeight: contentHeight
            model: control.delegateModel
            currentIndex: control.highlightedIndex
            highlightMoveDuration: 0

            delegate: Item {
                width: parent.width
                height: 40

                Text {
                    anchors.centerIn: parent
                    text: model.text
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        control.highlightedIndex = index
                        control.activated(index)
                        popup.close()
                    }
                }
            }

            T.ScrollIndicator.vertical: T.ScrollIndicator {}
        }

        background: Rectangle {
            color: control.palette.window
        }
    }

    // Your visible ComboBox area (can be customized)
    Rectangle {
        anchors.fill: parent
        color: "#f0f0f0"
        border.color: "#888"
        radius: 4

        Text {
            anchors.centerIn: parent
            text: comboModel.count > 0 && highlightedIndex >= 0
                  ? comboModel.get(highlightedIndex).text
                  : "Select an option"
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                popup.open()
            }
        }
    }

    // Hidden internal model used by the popup
    ListModel {
        id: delegateModel
        Component.onCompleted: {
            for (var i = 0; i < comboModel.count; ++i)
                delegateModel.append({ text: comboModel.get(i).text })
        }
    }

    property alias delegateModel: delegateModel
}
