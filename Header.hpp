#pragma once

#include <QtQml>
#include <compare>



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
    QString name = "Hello"; // Default value for the "foo" property
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

    
    bool operator==(const Mmpose_params& other) const
    {
        // Implement equality comparison
        // For example, compare just the 'name' and 'params' members
        return name == other.name && params == other.params;
    }

    bool operator<(const Mmpose_params& other) const
    {
        // Implement less-than comparison
        // For example, compare just the 'name' and 'params' members
        return std::tie(name, params) < std::tie(other.name, other.params);
    }
};

struct Size {
    Q_GADGET
    Q_PROPERTY(int width MEMBER width)
    Q_PROPERTY(int height MEMBER height)

public:
    int width = 0;
    int height = 0;
};

//params object 
struct Posenet_params {
    QString base_model;
    int device_id =0;
    bool draw_bounding_boxes = false;
    bool draw_skeleton_edges = false;
    QVector<Size> input_resolution = {{0, 0}};
    float min_keypoint_confidence = 0.0f;
    float min_pose_confidence = 0.0f;
    bool multi_pose_detection = false;
    int output_stride = 0;
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
};


//pose_backends array of type variant
struct Pose_backend {
    QString name;
    QVariant params; //either of the three types
};

//camera parameters
struct Camera_params {
    Size resolution = {0, 0};
    int framerate = 0;
    bool flip = false;
    int rotate = 0;
};

struct Cameras {
    QVector<QString> input_paths;
    bool flip_camera = false;
    QMap<QString, Camera_params> params;
    QMap<QString, QString> intrinsics; //idk what the structure is here
};

//dimmaps 
struct Pose2DToFloor {
    QMap<QString, QVector<QVector<float>>> pairs_per_camera;
};

struct Dimmaps {
    Pose2DToFloor pose2d_to_floor;
};

//skeleton obj
struct SkeletonFilters {
    bool two_dimensional = false;
    bool three_dimensional = false;
    float min_pose_completeness = 0.0f;
};

struct Filters {
    SkeletonFilters skeletons;
};

//osc output obj
struct OscOutput {
    QMap<QString, int> destinations;
};

//represents the entire config file obj
struct Config {
    QVector<Posenet_params> pose_backends;
    QMap<QString, Camera_params> cameras;
    SkeletonFilters filters;
    OscOutput outputs;
};

struct DataModel : public QObject
{
    Q_OBJECT // Macro to enable Qt's meta-object system for this class

    Q_PROPERTY(Mmpose_params data MEMBER data) // Declares a property named "data" with a member variable "data" of type MyObject

public:
    Mmpose_params data; // Instance of Mmpose_params

    Q_INVOKABLE QString toJson() // Declares a invokable method named "toJson" that returns a QString
    {
        /// magic
        QJsonObject json;
        json["name"] = data.name;
        json["params"] = data.params;
        // Add the rest of the properties...

        QJsonDocument doc(json);
        return QString(doc.toJson(QJsonDocument::Compact));
    }

    Q_INVOKABLE void fromJson(const QString& jsonString)
    {
        QJsonDocument doc = QJsonDocument::fromJson(jsonString.toUtf8());
        QJsonObject json = doc.object();

        data.name = json["name"].toString();
        data.params = json["params"].toInt();
        // Parse the rest of the properties...
    }
};
