import QtQuick
import app.Global
import app.IpBlockController

Rectangle {
    id: root

    property string textContent: ""
    property string textContentWhenDisabled: ""
    property int fontSize: Global.fontSize2
    property color textColor: Global.color_text1
    required property color idleColor
    required property color hoveredColor
    required property color clickedColor
    required property color clickedHoveredColor
    property bool textBold: false
    property int btnRadius: 0

    property bool btnDisabledWhen: false

    radius: btnRadius

    signal clicked()

    implicitWidth: 100
    implicitHeight: 50
    //color: btnDisabledWhen ? clickedColor : (mouseArea.containsPress ? clickedColor : (mouseArea.containsMouse ? hoveredColor : idleColor))
    color: if (btnDisabledWhen && mouseArea.containsMouse) { // Button activated and mouse hovered
               return clickedHoveredColor
           } else if (btnDisabledWhen) {
               return clickedColor
           } else if (!btnDisabledWhen && mouseArea.containsMouse) {
               return hoveredColor
           } else {
               return idleColor
           }


    Text {
        text: if (btnDisabledWhen){
                  return textContentWhenDisabled
              } else {
                  return textContent
              }

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
