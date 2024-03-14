import QtQuick
import QtQuick.Controls
import com.myobject

import QtQuick.Layouts
import QtQuick.Controls.Universal

Window {
    width: 640
    height: 750
    visible: true
    title: qsTr("LivePose_test")

    DataModel {
        id: x
        Component.onCompleted:
        {
            // Set pose_backend as backend
            x.pose_backend.name = "PoseNet";
            x.posenet_params.base_model = "resnet50";
            x.posenet_params.device_id = 0;
            x.posenet_params.draw_bounding_boxes = false;
            x.posenet_params.draw_skeleton_edges = true;
            x.posenet_params.input_resolution = [250, 250];
            x.posenet_params.min_keypoint_confidence = 0.1;
            x.posenet_params.min_pose_confidence = 0.15;
            x.posenet_params.multi_pose_detection = true;
            x.posenet_params.output_stride = 32;
            x.pose_backend.params = x.posenet_params;
            x.config.pose_backends = [ x.pose_backend ];

            // Set up cameras
            x.camera_params.resolution = [640, 480];
            x.camera_params.framerate = 30;
            x.camera_params.flip = false;
            x.camera_params.rotate = 0;
            x.config.cameras.input_paths = ["/dev/video0"];
            x.config.cameras.params = { "/dev/video0" :  x.camera_params };

            // Set up dimmaps
        
            // Set up filters
        
            // Set up outputs
            x.osc_output.destinations["localhost"] = 9000;
            x.config.outputs.osc = [ x.osc_output ];

            // Print the final configuration
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

            ComboBox {
                id: backendSelector
                model: x.config.pose_backends
                Layout.fillWidth: true
                currentIndex: 0

                onCurrentIndexChanged: {
                    model.text("Selected backend: " + model[currentIndex].name);                
            }
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
