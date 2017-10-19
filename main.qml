import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

/*
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    MouseArea {
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
    }

    Text {
        text: qsTr("Hello World")
        anchors.centerIn: parent
    }
}*/

Window {
    objectName:"rootObject";
    visible: true;
    width: 360;
    height: 360;
    title: qsTr("Hello World");

    Text{
        objectName:"textLabel";
        text:"Hello World";
        anchors.centerIn: parent;
        font.pixelSize: 26;
    }

   Button{
       anchors.right: parent.right;
       anchors.rightMargin: 4;
       anchors.bottom: parent.bottom;
       anchors.bottomMargin: 4;
       text:"quit";
       objectName: "quitButton";
   }
}
