import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import app.Global
import app.Controller
import QtCharts

Window {
    id: root
    width: Global.appWidth
    height: Global.appHeight
    visible: true
    title: qsTr("NFTManager")
    opacity: 1

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

            ///////////// TAB BAR BUTTONS BEGIN ///////////////
            TabBar {
                id: tabBar
                width: parent.width
                height: parent.height

                CustomTabButton {
                    stackLayoutItem: stackLayout
                    selfIndex: 0
                    name: "TCP & UDP count"
                }

                CustomTabButton {
                    stackLayoutItem: stackLayout
                    selfIndex: 1
                    name: "Block all incoming packets"
                }

                CustomTabButton {
                    stackLayoutItem: stackLayout
                    selfIndex: 2
                    name: "Reset NFTables"
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

            ///////////// TAB BAR BUTTONS END ///////////////
        }

        ////////////////// TABS WINDOWS BEGIN //////////////
        StackLayout {
            id: stackLayout
            height: root.height - Global.selectionBarHeight
            anchors {
                left: parent.left
                right: parent.right
            } // Feature Windows below are index'ed one by one as they are listed (first is 0, then 1, then 2 etc.)

            FeatureWindow { // FIRST TAB (1)
                id: feature1

                Text{
                    id: titleF1
                    text: "TCP and UDP packets listener, counts incoming packets in certain period of time."
                    font.pixelSize: Global.fontSize5
                    height: 100
                    font.bold: true
                    color: Global.color_text1
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                    elide: Text.ElideRight
                    anchors {
                        top: parent.top
                        left: parent.left
                        right: parent.right
                        topMargin: 25
                        leftMargin: 50
                        rightMargin: 50
                        //horizontalCenter: parent.horizontalCenter
                    }
                }
                Item {
                    anchors {
                        top: titleF1.bottom
                        left: parent.left
                        right: parent.right
                        bottom: parent.bottom
                    }
                    Item {
                        anchors {
                            left: parent.left
                            right: parent.horizontalCenter
                            top: parent.top
                            bottom: parent.bottom
                        }

                        CustomButton{
                            id: listenBtnF1
                            width: 300
                            height: 150
                            anchors {
                                horizontalCenter: parent.horizontalCenter
                                verticalCenter: parent.verticalCenter

                            }
                            textContent: "Listen for 10 seconds"
                            textContentWhenDisabled: "Listening..."
                            textBold: true
                            fontSize: Global.fontSize3
                            btnRadius: 25
                            idleColor: Global.color_theme2
                            hoveredColor: Global.color_theme1
                            //clickedColor: Global.color_bg2
                            clickedColor: Global.color_bg2
                            clickedHoveredColor: Global.color_bg2
                            btnDisabledWhen: Controller.listening
                            onClicked: Controller.updateTcpUdpCount()
                        }
                    }

                    ChartView {
                        id: chartF1
                        title: "Recorded incoming packets (TCP & UDP)"
                        legend.alignment: Qt.AlignBottom
                        antialiasing: true
                        width: 400
                        height: 400
                        anchors {
                            left: parent.horizontalCenter
                            right: parent.right
                            top: parent.top
                            bottom: parent.bottom
                            margins: 50
                        }

                        PieSeries {
                            id: pieSeriesF1
                            PieSlice { label: "TCP: " + Controller.inTcpCount; value: Controller.inTcpCount }
                            PieSlice { label: "UDP: " + Controller.inUdpCount; value: Controller.inUdpCount }
                        }
                    }
                }

            }

            FeatureWindow { // SECOND TAB (2)
                id: feature2
                Text{
                    id: titleF2
                    text: "Block all incoming packets (inet)."
                    font.pixelSize: Global.fontSize5
                    height: 100
                    font.bold: true
                    color: Global.color_text1
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                    elide: Text.ElideRight
                    anchors {
                        top: parent.top
                        left: parent.left
                        right: parent.right
                        topMargin: 25
                        leftMargin: 50
                        rightMargin: 50
                        //horizontalCenter: parent.horizontalCenter
                    }
                }

                CustomButton {
                    id: btnF2
                    anchors {
                        top: titleF2.bottom
                        bottom: parent.bottom
                        left: parent.left
                        right: parent.right
                        margins: 100
                    }

                    textContent: "Drop all incoming packets"
                    textContentWhenDisabled: "Accept all incoming packets"
                    fontSize: Global.fontSize5
                    textColor: Global.color_text1
                    idleColor: Global.color_btnOn
                    hoveredColor: Qt.darker(Global.color_btnOn)
                    clickedColor: Global.color_btnOff
                    clickedHoveredColor: Qt.darker(Global.color_btnOff)
                    textBold: true
                    btnRadius: 25

                    btnDisabledWhen: Controller.blockedAllInPackets

                    onClicked: Controller.toogleBlockAllPackets()
                }
            }

            FeatureWindow { // THIRD TAB (3)
                id: feature3
                Text{
                    id: titleF3
                    text: "Reset NFTables (/etc/nftables.conf) to default configuration."
                    font.pixelSize: Global.fontSize5
                    height: 100
                    font.bold: true
                    color: Global.color_text1
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                    elide: Text.ElideRight
                    anchors {
                        top: parent.top
                        left: parent.left
                        right: parent.right
                        topMargin: 25
                        leftMargin: 50
                        rightMargin: 50
                        //horizontalCenter: parent.horizontalCenter
                    }
                }

                CustomButton {
                    id: btnF3
                    anchors {
                        top: titleF3.bottom
                        bottom: parent.bottom
                        left: parent.left
                        right: parent.right
                        margins: 100
                    }

                    textContent: "Reset"
                    fontSize: Global.fontSize5
                    textColor: Global.color_text1
                    idleColor: Global.color_theme2
                    hoveredColor: Global.color_theme1
                    clickedColor: Global.color_bg1 // not working
                    clickedHoveredColor: Global.color_bg2 // not working

                    textBold: true
                    btnRadius: 25

                    onClicked: Controller.resetNFT()
                }
            }


            FeatureWindow { // FOURTH TAB (4)
                id: feature4

            }

            FeatureWindow { // FIFTH TAB (5)
                id: feature5

            }

            FeatureWindow { // SIXTH TAB (6)
                id: feature6

            }

            FeatureWindow { // SEVENTH TAB (7)
                id: feature7

            }
        }
        ////////////////// TABS WINDOWS END //////////////////
    }
}
