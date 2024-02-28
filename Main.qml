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
            data.name = "hiiii";
            data.cam_id = "new cam_id"; // Set the "cam_id" property
            data.enable_detection = 1; // Set the "enable_detection" property
            console.log(data);
            console.log(JSON.stringify(data));
        }
        
    }
        TextArea {
        id: consoleOutput
        width: parent.width
        height: parent.height / 2
        readOnly: true
        text: "Initial data: " + x.data.name + "\n"

        Component.onCompleted: {
            x.data.name = "hiiii";
            x.data.cam_id = "new cam_id"; // Set the "cam_id" property
            x.data.enable_detection = 1; // Set the "enable_detection" property
            text += "Updated data: " + x.data.name + "\n";
            text += "Updated cam_id: " + x.data.cam_id + "\n";
            text += "Updated enable_detection: " + x.data.enable_detection + "\n";
        }
    }
}
