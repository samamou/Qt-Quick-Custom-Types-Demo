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
            x.pose_backend.name = "posenet";
            x.posenet_params.base_model = "resnet50";
            x.posenet_params.device_id = 0;
            x.posenet_params.draw_bounding_boxes = false;
            x.posenet_params.draw_skeleton_edges = true;
            x.posenet_params.input_resolution = Qt.size(250, 250);
            x.posenet_params.min_keypoint_confidence = 0.1;
            x.posenet_params.min_pose_confidence = 0.15;
            x.posenet_params.multi_pose_detection = true;
            x.posenet_params.output_stride = 32;
            x.pose_backend.params = x.posenet_params;

            // Set up cameras
            x.camera_params.resolution = Qt.size(640, 480);
            x.camera_params.framerate = 30;
            x.camera_params.flip = false;
            x.camera_params.rotate = 0;
            x.config.cameras.input_paths = ["/dev/video0"];
            x.config.cameras.params = { "/dev/video0" :  x.camera_params };

            // Set up dimmaps
        
            // Set up filters
            x.skeletons.two_dimensional = true;
            x.skeletons.three_dimensional = false;
            x.skeletons.min_pose_completeness = 0.5;
            x.filters.skeletons = x.skeletons;
            x.config.filters = { "skeletons": x.skeletons };


            // Set up outputs    
            x.osc_output.destinations = { "localhost": 9000 };
            x.config.outputs = { "osc": x.osc_output };

            // Print the final configuration
            // console.log(JSON.stringify(x.config, null, 2));
            
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
                id: backendSelector
                Layout.fillWidth: true
                model: ["PoseNet", "Mmpose", "Mediapipe", "Trt" , "Void"] // Add other backends as needed
                currentIndex: 0

                    onCurrentIndexChanged: {
                        switch (currentIndex) {
                            case 0: // PoseNet
                                x.pose_backend.name = "posenet";
                                x.posenet_params.base_model = "resnet50";
                                x.posenet_params.device_id = 0;
                                x.posenet_params.draw_bounding_boxes = false;
                                x.posenet_params.draw_skeleton_edges = true;
                                x.posenet_params.input_resolution = Qt.size(250, 250);
                                x.posenet_params.min_keypoint_confidence = 0.1;
                                x.posenet_params.min_pose_confidence = 0.15;
                                x.posenet_params.multi_pose_detection = true;
                                x.posenet_params.output_stride = 32;
                                x.pose_backend.params = x.posenet_params;
                                break;
                            case 1: // Mmpose
                                x.pose_backend.name = "mmpose";
                                x.mmpose_params.cam_id = "0";
                                x.mmpose_params.enable_detection = 1;
                                x.mmpose_params.det_config = "external/mmpose/demo/mmdetection_cfg/ssdlite_mobilenetv2_scratch_600e_coco.py";
                                x.mmpose_params.det_checkpoint = "https://download.openmmlab.com/mmdetection/v2.0/ssd/ssdlite_mobilenetv2_scratch_600e_coco/ssdlite_mobilenetv2_scratch_600e_coco_20210629_110627-974d9307.pth";
                                x.mmpose_params.enable_human_pose = 1;
                                x.mmpose_params.enable_animal_pose = 0;
                                x.mmpose_params.enable_hand_pose = 0;
                                x.mmpose_params.human_pose_config = "external/mmpose/configs/wholebody/2d_kpt_sview_rgb_img/topdown_heatmap/coco-wholebody/vipnas_res50_coco_wholebody_256x192_dark.py";
                                x.mmpose_params.human_pose_checkpoint = "https://download.openmmlab.com/mmpose/top_down/vipnas/vipnas_res50_wholebody_256x192_dark-67c0ce35_20211112.pth";
                                x.mmpose_params.human_det_ids = [1];
                                x.mmpose_params.animal_pose_config = "external/mmpose/configs/animal/2d_kpt_sview_rgb_img/topdown_heatmap/animalpose/hrnet_w32_animalpose_256x256.py";
                                x.mmpose_params.animal_pose_checkpoint = "https://download.openmmlab.com/mmpose/animal/hrnet/hrnet_w32_animalpose_256x256-1aa7f075_20210426.pth";
                                x.mmpose_params.animal_det_ids = [16,17,18,19,20];
                                x.mmpose_params.hand_pose_config = "external/mmpose/configs/hand/2d_kpt_sview_rgb_img/topdown_heatmap/onehand10k/res50_onehand10k_256x256.py";
                                x.mmpose_params.hand_pose_checkpoint = "https://download.openmmlab.com/mmpose/top_down/resnet/res50_onehand10k_256x256-e67998f6_20200813.pth";
                                x.mmpose_params.hand_det_ids = [1];
                                x.mmpose_params.device = "cuda:0";
                                x.mmpose_params.det_score_thr = 0.5;
                                x.mmpose_params.kpt_thr = 0.3;
                                x.mmpose_params.vis_mode = 2;
                                x.mmpose_params.sunglasses = false;   
                                x.pose_backend.params = x.mmpose_params;
                                break;
                            case 2: // Mediapipe
                                x.pose_backend.name = "mediapipe";
                                x.mediapipe_params.detect_faces = false;
                                x.mediapipe_params.detect_face_meshs = false;
                                x.mediapipe_params.detect_hands = true;
                                x.mediapipe_params.detect_poses = false;
                                x.mediapipe_params.detect_holistic = false;
                                x.mediapipe_params.use_gpu = true;
                                x.mediapipe_params.min_detection_confidence = 0.5;
                                x.pose_backend.params = x.mediapipe_params;
                                break;
                            case 3: // Trt
                                x.pose_backend.name = "trt";
                                x.trt_params.optimize = false;
                                x.trt_params.keypoint_dataset = "HAND_21";
                                x.trt_params.model_path = "hand_pose_resnet18_att_244_244_trt.pth";
                                x.trt_params.model_optimized = "hand_pose_resnet18_att_244_244_trt.engine";
                                x.trt_params.model_weights = "hand_pose_resnet18_att_244_244.pth";
                                x.trt_params.model_desc = "hand_pose.json";
                                x.trt_params.model_height = 244;
                                x.trt_params.model_width = 244;
                                x.trt_params.min_pose_confidence = 0.15;
                                x.pose_backend.params = x.trt_params;
                                break;
                            case 4: // Void
                                x.pose_backend.name = "void";
                                x.pose_backend.params = x.void_backend;
                        }
                        x.config.pose_backends = [x.pose_backend];
                    }
                }

                TextField {
                    id: inputPathField
                    placeholderText: "Enter camera path"
                    Layout.preferredWidth: 150
                    onTextChanged: {
                        x.config.cameras.input_paths = [inputPathField.text];
                    }
                }

            CheckBox {
                id: skeletonTypeCheckbox
                text: "2D Skeleton"
                checked: x.skeletons.two_dimensional
                onCheckedChanged: {
                    x.skeletons.two_dimensional = checked;
                    x.skeletons.three_dimensional = !checked;
                    x.skeletons.min_pose_completeness = 0.5;
                    x.filters.skeletons = x.skeletons;
                    x.config.filters = { "skeletons": x.skeletons };

                    x.osc_output.destinations = { "localhost": 9000 };
                    x.config.outputs = { "osc": x.osc_output };
                }
            }
                    
            Label {
                text: "Output"
                font.bold: true
            }

            RowLayout {
                TextField {
                    id: destinationField
                    placeholderText: "Destination"
                    Layout.preferredWidth: 100
                }

                TextField {
                    id: portField
                    placeholderText: "Port"
                    Layout.preferredWidth: 50
                }

            }

            Button {    
                text: "Save"
                onClicked: {
                    console.log(JSON.stringify(x.config, null, 2));
                }
            }

        }
        }

    }

}
