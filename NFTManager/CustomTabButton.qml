import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import app.Global

TabButton {
    id: root
    required property Item stackLayoutItem
    required property int selfIndex
    required property string name
    text: name

    contentItem: Text{
        text: parent.text
        color: Global.color_text1
        font.pixelSize: stackLayoutItem.currentIndex === parent.selfIndex ? Global.fontSize2 : Global.fontSize1
        font.bold: stackLayoutItem.currentIndex === parent.selfIndex ? true : false
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }
    background: Rectangle {
        color: stackLayoutItem.currentIndex === parent.selfIndex ? Global.color_bg1 : Global.color_bg2
    }
    height: parent.height
    anchors {
        top: parent.top
        bottom: parent.bottom
    }
    onClicked: stackLayoutItem.currentIndex = selfIndex
}
