import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    anchors.fill: parent
    property string title: "Dapp Manager"
    Text {
        text: "Installed DAPPs:"
        x: 20
        y: 20
    }
    //GridView {/*TODO*/}
    Rectangle {anchors.fill: parent; color: "#ff00ff"}
}
