import QtQuick
import QtQuick.Controls
import com.myobject

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    DataModel {
        id: x
        Component.onCompleted:
        {
            console.log(data);
            data.foo = "hiiii";
            console.log(data);
            console.log(JSON.stringify(data));
        }
        
    }
        TextArea {
        id: consoleOutput
        width: parent.width
        height: parent.height / 2
        readOnly: true
        text: "Initial data: " + x.data.foo + "\n"

        Component.onCompleted: {
            x.data.foo = "hiiii";
            text += "Updated data: " + x.data.foo + "\n";
        }
    }
}
