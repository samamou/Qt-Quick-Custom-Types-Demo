import QtQuick
import QtQuick.Controls
import com.myobject

import QtQuick.Layouts
import QtQuick.Controls.Universal

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("LivePose_test")

    DataModel {
        id: x
        Component.onCompleted:
        {
            console.log(JSON.stringify(x.config, null, 2));
        } 
    }


    Rectangle {
        id: sidebar
        width: parent.width * 0.3
        height: parent.height
        color: "lightgray"

        Column {
            anchors.fill: parent
            spacing: 20
            padding: 10


            Label {
                text: "Run LivePose"
                font.bold: true
                font.pointSize: 20
            }

            ColumnLayout {
                spacing: 10
                Label {
                    text: "Load config file"
                    font.bold: true
                }

                ComboBox {
                    id: loadFile
                    Layout.fillWidth: true
                    currentIndex: 0
                    // model and onCurrentTextChanged are commented out because they depend on your specific application logic
                    // model: loadSaveConfigFilesData.getConfigFiles()
                    // onCurrentTextChanged: {
                    //     loadSaveConfigFilesData.loadBackendSelection(loadFile.currentText)
                    // }
                }
            }

        ColumnLayout {
            spacing: 10
            Label {
                text: "parameters"
                font.bold: true
            }

            TextField {
                id: initialData
                placeholderText: "cam_id"
                text: x.mmpose_params.cam_id
                Layout.minimumWidth: 120
            }

            TextField {
                id: updatedCamId
                placeholderText: "Updated cam_id"
                text: x.mmpose_params.cam_id
                Layout.minimumWidth: 120
            }

            TextField {
                id: updatedEnableDetection
                placeholderText: "Updated enable_detection"
                text: x.mmpose_params.enable_detection
                Layout.minimumWidth: 120
            }
                        TextField {
                id: resolutionWidth
                placeholderText: "Resolution Width"
                text: x.camera_params.resolution.width
                Layout.minimumWidth: 120
            }

            TextField {
                id: resolutionHeight
                placeholderText: "Resolution Height"
                text: x.camera_params.resolution.height
                Layout.minimumWidth: 120
            }
        }
        }
        


    }

}
