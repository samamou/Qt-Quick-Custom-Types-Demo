#pragma once

#include <QtQml>
#include <compare>
#include <QVector2D> 


struct Mmpose_params{
    Q_GADGET

    Q_PROPERTY(QString name MEMBER name) // Declares a QString property named "foo" with a member variable "foo"
    Q_PROPERTY(int params MEMBER params) // Declares an int property named "bar" with a member variable "bar"

    Q_PROPERTY(QString cam_id MEMBER cam_id)
    Q_PROPERTY(int enable_detection MEMBER enable_detection)
    Q_PROPERTY(QString det_config MEMBER det_config)
    Q_PROPERTY(QString det_checkpoint MEMBER det_checkpoint)
    Q_PROPERTY(int enable_human_pose MEMBER enable_human_pose)
    Q_PROPERTY(int enable_animal_pose MEMBER enable_animal_pose)
    Q_PROPERTY(int enable_hand_pose MEMBER enable_hand_pose)
    Q_PROPERTY(QString human_pose_config MEMBER human_pose_config)
    Q_PROPERTY(QString human_pose_checkpoint MEMBER human_pose_checkpoint)
    Q_PROPERTY(QVector<int> human_det_ids MEMBER human_det_ids)
    Q_PROPERTY(QString animal_pose_config MEMBER animal_pose_config)
    Q_PROPERTY(QString animal_pose_checkpoint MEMBER animal_pose_checkpoint)
    Q_PROPERTY(QVector<int> animal_det_ids MEMBER animal_det_ids)
    Q_PROPERTY(QString hand_pose_config MEMBER hand_pose_config)
    Q_PROPERTY(QString hand_pose_checkpoint MEMBER hand_pose_checkpoint)
    Q_PROPERTY(QVector<int> hand_det_ids MEMBER hand_det_ids)
    Q_PROPERTY(QString device MEMBER device)
    Q_PROPERTY(double det_score_thr MEMBER det_score_thr)
    Q_PROPERTY(double kpt_thr MEMBER kpt_thr)
    Q_PROPERTY(int vis_mode MEMBER vis_mode)
    Q_PROPERTY(bool sunglasses MEMBER sunglasses)
    Q_PROPERTY(bool bugeye MEMBER bugeye)
    Q_PROPERTY(QVariant out_video_file MEMBER out_video_file)
    Q_PROPERTY(int out_video_fps MEMBER out_video_fps)
    Q_PROPERTY(int buffer_size MEMBER buffer_size)
    Q_PROPERTY(int inference_fps MEMBER inference_fps)
    Q_PROPERTY(int display_delay MEMBER display_delay)
    Q_PROPERTY(bool synchronous_mode MEMBER synchronous_mode)

public:
    QString name = "Hell8o"; // Default value for the "foo" property
    int params = 123; // Default value for the "bar" property

    QString cam_id;
    int enable_detection = 0;
    QString det_config;
    QString det_checkpoint;
    int enable_human_pose = 0;
    int enable_animal_pose = 0;
    int enable_hand_pose = 0;
    QString human_pose_config;
    QString human_pose_checkpoint;
    QVector<int> human_det_ids;
    QString animal_pose_config;
    QString animal_pose_checkpoint;
    QVector<int> animal_det_ids;
    QString hand_pose_config;
    QString hand_pose_checkpoint;
    QVector<int> hand_det_ids;
    QString device;
    double det_score_thr = 0.0;
    double kpt_thr = 0.0;
    int vis_mode = 0;
    bool sunglasses = false;
    bool bugeye = false;
    QVariant out_video_file;
    int out_video_fps = 0;
    int buffer_size = 0;
    int inference_fps = 0;
    int display_delay = 0;
    bool synchronous_mode = false;


    bool operator==(const Mmpose_params& other) const noexcept = default;

    bool operator<(const Mmpose_params& other) {
        // Implement less-than comparison
        // For example, compare just the 'name' and 'params' members
        return std::tie(name, params) < std::tie(other.name, other.params);
    }
};

// struct Size {
//     Q_GADGET
//     Q_PROPERTY(int width MEMBER width)
//     Q_PROPERTY(int height MEMBER height)

// public:
//     int width = 0;
//     int height = 0;

//     bool operator==(const QSize& other) const noexcept = default;

// };

//params object 
struct Posenet_params {
    Q_GADGET
    Q_PROPERTY(QString base_model MEMBER base_model)
    Q_PROPERTY(int device_id MEMBER device_id)
    Q_PROPERTY(bool draw_bounding_boxes MEMBER draw_bounding_boxes)
    Q_PROPERTY(bool draw_skeleton_edges MEMBER draw_skeleton_edges)
    Q_PROPERTY(QVector<QSize> input_resolution MEMBER input_resolution)
    Q_PROPERTY(float min_keypoint_confidence MEMBER min_keypoint_confidence)
    Q_PROPERTY(float min_pose_confidence MEMBER min_pose_confidence)
    Q_PROPERTY(bool multi_pose_detection MEMBER multi_pose_detection)
    Q_PROPERTY(int output_stride MEMBER output_stride)

public:
    QString base_model;
    int device_id =0;
    bool draw_bounding_boxes = false;
    bool draw_skeleton_edges = false;
    QVector<QSize> input_resolution = {{0, 0}};
    float min_keypoint_confidence = 0.0f;
    float min_pose_confidence = 0.0f;
    bool multi_pose_detection = false;
    int output_stride = 0;

    bool operator==(const Posenet_params& other) const noexcept = default;
};

struct Trt_params {
    Q_GADGET
    Q_PROPERTY(bool optimize MEMBER optimize)
    Q_PROPERTY(QString keypoint_dataset MEMBER keypoint_dataset)
    Q_PROPERTY(QString model_path MEMBER model_path)
    Q_PROPERTY(QString model_optimized MEMBER model_optimized)
    Q_PROPERTY(QString model_weights MEMBER model_weights)
    Q_PROPERTY(QString model_desc MEMBER model_desc)
    Q_PROPERTY(int model_height MEMBER model_height)
    Q_PROPERTY(int model_width MEMBER model_width)
    Q_PROPERTY(float min_pose_confidence MEMBER min_pose_confidence)

public:
    bool optimize = false;
    QString keypoint_dataset;
    QString model_path;
    QString model_optimized;
    QString model_weights;
    QString model_desc;
    int model_height = 0;
    int model_width = 0;
    float min_pose_confidence = 0.0f;

    bool operator==(const Trt_params& other) const noexcept = default;
};


//pose_backends array of type variant
struct Pose_backend {
    Q_GADGET
    Q_PROPERTY(QString name MEMBER name)
    Q_PROPERTY(QVariant params MEMBER params)

public:
    QString name;
    QVariant params; //either of the three types

    bool operator==(const Pose_backend& other) const noexcept = default;
};

//camera parameters
struct Camera_params {
    Q_GADGET
    Q_PROPERTY(QSize resolution MEMBER resolution)
    Q_PROPERTY(int framerate MEMBER framerate)
    Q_PROPERTY(bool flip MEMBER flip)
    Q_PROPERTY(int rotate MEMBER rotate)

public:
    QSize resolution = {300, 400};
    int framerate = 0;
    bool flip = false;
    int rotate = 0;

    bool operator==(const Camera_params& other) const noexcept = default;
};

struct Cameras {
    Q_GADGET
    Q_PROPERTY(QVector<QString> input_paths MEMBER input_paths)
    Q_PROPERTY(bool flip_camera MEMBER flip_camera)
    Q_PROPERTY(QMap<QString, Camera_params> params MEMBER params)
    Q_PROPERTY(QMap<QString, QString> intrinsics MEMBER intrinsics)

public:
    QVector<QString> input_paths;
    bool flip_camera = false;
    QMap<QString, Camera_params> params;
    QMap<QString, QString> intrinsics; //idk what the structure is here

    bool operator==(const Cameras& other) const noexcept = default;
};

//Pair of points
struct PointPair {
    Q_GADGET
    Q_PROPERTY(QVector2D point1 MEMBER point1)
    Q_PROPERTY(QVector2D point2 MEMBER point2)

public:
    QVector2D point1;
    QVector2D point2;

    bool operator==(const PointPair& other) const noexcept = default;
};

//dimmaps 
struct Pose2DToFloor {
    Q_GADGET
    Q_PROPERTY(QMap<QString, QVector<PointPair>> pairs_per_camera MEMBER pairs_per_camera)

public:
    QMap<QString, QVector<PointPair>> pairs_per_camera;
    bool operator==(const Pose2DToFloor& other) const noexcept = default;
};

struct Dimmaps {
    Q_GADGET
    Q_PROPERTY(Pose2DToFloor pose2d_to_floor MEMBER pose2d_to_floor)

public:
    Pose2DToFloor pose2d_to_floor;

    bool operator==(const Dimmaps& other) const noexcept = default; 
};

//skeleton obj
struct SkeletonFilters {
    Q_GADGET
    Q_PROPERTY(bool two_dimensional MEMBER two_dimensional)
    Q_PROPERTY(bool three_dimensional MEMBER three_dimensional)
    Q_PROPERTY(float min_pose_completeness MEMBER min_pose_completeness)

public:
    bool two_dimensional = false;
    bool three_dimensional = false;
    float min_pose_completeness = 0.0f;

    bool operator==(const SkeletonFilters& other) const noexcept = default;
};

struct Filters {
    Q_GADGET
    Q_PROPERTY(SkeletonFilters skeletons MEMBER skeletons)

public:
    SkeletonFilters skeletons;

    bool operator==(const Filters& other) const noexcept = default;
};

//osc output obj
struct OscOutput {
    Q_GADGET
    Q_PROPERTY(QMap<QString, int> destinations MEMBER destinations)

public:
    QMap<QString, int> destinations;

    bool operator==(const OscOutput& other) const noexcept = default;
};

//represents the entire config file obj
struct Config {
    Q_GADGET
    Q_PROPERTY(QVector<Posenet_params> pose_backends MEMBER pose_backends)
    Q_PROPERTY(QMap<QString, Camera_params> cameras MEMBER cameras)
    Q_PROPERTY(SkeletonFilters filters MEMBER filters)
    Q_PROPERTY(OscOutput outputs MEMBER outputs)

public:
    QVector<Posenet_params> pose_backends;
    QMap<QString, Camera_params> cameras;
    SkeletonFilters filters;
    OscOutput outputs;

    bool operator==(const Config& other) const noexcept = default;
};

struct DataModel : public QObject
{
    Q_OBJECT // Macro to enable Qt's meta-object system for this class
    Q_PROPERTY(Mmpose_params mmpose_params MEMBER mmpose_params) // Declares a property named "mmpose_params" with a member variable "data"
    Q_PROPERTY(Posenet_params posenet_params MEMBER posenet_params)
    Q_PROPERTY(Trt_params trt_params MEMBER trt_params)
    Q_PROPERTY(Pose_backend pose_backend MEMBER pose_backend)
    Q_PROPERTY(Camera_params camera_params MEMBER camera_params)
    Q_PROPERTY(Cameras cameras MEMBER cameras)
    Q_PROPERTY(Dimmaps dimmaps MEMBER dimmaps)
    Q_PROPERTY(Filters filters MEMBER filters)
    Q_PROPERTY(OscOutput osc_output MEMBER osc_output)
    Q_PROPERTY(Config config MEMBER config)

public:
    Mmpose_params mmpose_params; // Instance of Mmpose_params
    Posenet_params posenet_params;
    Trt_params trt_params;
    Pose_backend pose_backend;
    Camera_params camera_params;
    Cameras cameras;
    Dimmaps dimmaps;
    Filters filters;
    OscOutput osc_output;
    Config config;
};
