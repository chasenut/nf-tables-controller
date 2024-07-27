import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import app.Global

Window {
    id: root
    width: Global.appWidth
    height: Global.appHeight
    visible: true
    title: qsTr("NFTManager")

    color: Global.color_bg1
    minimumWidth: Global.appMinWidth
    minimumHeight: Global.appMinHeight

    Column {

        anchors {
            top: parent.top
            bottom: parent.bottom
            left: parent.left
            right: parent.right
        }

        Rectangle {
            id: selectionBar
            height: Global.selectionBarHeight
            color: Global.color_bg2
            anchors {
                left: parent.left
                right: parent.right
            }

            TabBar {
                id: tabBar
                width: parent.width
                height: parent.height

                CustomTabButton {
                    stackLayoutItem: stackLayout
                    selfIndex: 0
                    name: "Feature1"
                }

                CustomTabButton {
                    stackLayoutItem: stackLayout
                    selfIndex: 1
                    name: "Feature2"
                }

                CustomTabButton {
                    stackLayoutItem: stackLayout
                    selfIndex: 2
                    name: "Feature3"
                }

                CustomTabButton {
                    stackLayoutItem: stackLayout
                    selfIndex: 3
                    name: "Feature4"
                }

                CustomTabButton {
                    stackLayoutItem: stackLayout
                    selfIndex: 4
                    name: "Feature5"
                }

                CustomTabButton {
                    stackLayoutItem: stackLayout
                    selfIndex: 5
                    name: "Feature6"
                }

                CustomTabButton {
                    stackLayoutItem: stackLayout
                    selfIndex: 6
                    name: "Feature7"
                }
            }
        }

        StackLayout {
            id: stackLayout
            anchors {
                top: selectionBar.bottom
                left: parent.left
                right: parent.right
            }

            Item {
                Rectangle {
                    width: parent.width
                    height: parent.height
                    Text {
                        text: "Home"
                        anchors {
                            centerIn: parent
                        }
                        font.pixelSize: 30
                    }
                }
            }

            Item {
                Rectangle {
                    width: parent.width
                    height: parent.height
                    Text {
                        text: "Dupa"
                        anchors {
                            centerIn: parent
                        }
                        font.pixelSize: 30
                    }
                }
            }

            Item {
                Rectangle {
                    width: parent.width
                    height: parent.height
                    Text {
                        text: "Settings"
                        anchors {
                            centerIn: parent
                        }
                        font.pixelSize: 30
                    }
                }
            }

        }
    }
}
