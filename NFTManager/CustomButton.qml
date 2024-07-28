import QtQuick
import app.Global

Rectangle {
    id: root

    property string textContent: "placehoder"
    property int fontSize: Global.fontSize2
    property color textColor: Global.color_text1
    required property color idleColor
    required property color hoveredColor
    required property color clickedColor
    property bool textBold: false
    property int btnRadius: 0

    property bool btnDisabledWhen: false

    radius: btnRadius

    signal clicked()

    implicitWidth: 100
    implicitHeight: 50
    //color: btnDisabledWhen ? clickedColor : (mouseArea.containsPress ? clickedColor : (mouseArea.containsMouse ? hoveredColor : idleColor))
    color: if (btnDisabledWhen){
               return clickedColor
           } else if (mouseArea.containsPress) {
               return clickedColor
           } else if (mouseArea.containsMouse) {
               return hoveredColor
           } else {
               return idleColor
           }


    Text {
        text: textContent
        font.pixelSize: fontSize
        font.bold: textBold
        color: textColor
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
        elide: Text.ElideRight
        anchors {
            fill: parent
        }
    }

    MouseArea {
        id: mouseArea

        hoverEnabled: true
        anchors {
            fill: parent
        }
        onClicked: {
            root.clicked()
        }
    }

}
