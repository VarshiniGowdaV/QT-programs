import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 300
    title: "ComboBox Popup Fix Example"

    ComboBox {
        anchors.centerIn: parent
        model: []  // Try with and without items to test the fix
    }
}
