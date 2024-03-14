#pragma once

#include <QVector2D>
#include <QtQml>

#include <compare>

struct Void_backend
{
  Q_GADGET

public:
  bool operator==(const Void_backend& other) const noexcept = default;
};

struct Mmpose_params
{
  Q_GADGET
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
};

struct Posenet_params
{
  Q_GADGET
  Q_PROPERTY(QString base_model MEMBER base_model)
  Q_PROPERTY(int device_id MEMBER device_id)
  Q_PROPERTY(bool draw_bounding_boxes MEMBER draw_bounding_boxes)
  Q_PROPERTY(bool draw_skeleton_edges MEMBER draw_skeleton_edges)
  Q_PROPERTY(QSize input_resolution MEMBER input_resolution)
  Q_PROPERTY(float min_keypoint_confidence MEMBER min_keypoint_confidence)
  Q_PROPERTY(float min_pose_confidence MEMBER min_pose_confidence)
  Q_PROPERTY(bool multi_pose_detection MEMBER multi_pose_detection)
  Q_PROPERTY(int output_stride MEMBER output_stride)

public:
  QString base_model;
  int device_id = 0;
  bool draw_bounding_boxes = false;
  bool draw_skeleton_edges = false;
  QSize input_resolution = {0, 0};
  float min_keypoint_confidence = 0.0f;
  float min_pose_confidence = 0.0f;
  bool multi_pose_detection = false;
  int output_stride = 0;

  bool operator==(const Posenet_params& other) const noexcept = default;
};

struct Trt_params
{
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

struct Mediapipe_params
{
  Q_GADGET
  Q_PROPERTY(bool detect_faces MEMBER detect_faces)
  Q_PROPERTY(bool detect_face_meshs MEMBER detect_face_meshs)
  Q_PROPERTY(bool detect_hands MEMBER detect_hands)
  Q_PROPERTY(bool detect_poses MEMBER detect_poses)
  Q_PROPERTY(bool detect_holistic MEMBER detect_holistic)
  Q_PROPERTY(bool use_gpu MEMBER use_gpu)
  Q_PROPERTY(float min_detection_confidence MEMBER min_detection_confidence)

public:
  bool detect_faces = false;
  bool detect_face_meshs = false;
  bool detect_hands = false;
  bool detect_poses = false;
  bool detect_holistic = false;
  bool use_gpu = false;
  float min_detection_confidence = 0.0f;

  bool operator==(const Mediapipe_params& other) const noexcept = default;
};

// pose_backends array of type variant
struct Pose_backend
{
  Q_GADGET
  Q_PROPERTY(QString name MEMBER name)
  Q_PROPERTY(QVariant params MEMBER params)

public:
  QString name;
  QVariant params; // either of the three types

  bool operator==(const Pose_backend& other) const noexcept = default;
};

// camera parameters
struct Camera_params
{
  Q_GADGET
  Q_PROPERTY(QSize resolution MEMBER resolution)
  Q_PROPERTY(int framerate MEMBER framerate)
  Q_PROPERTY(bool flip MEMBER flip)
  Q_PROPERTY(int rotate MEMBER rotate)
  Q_PROPERTY(bool align_frames MEMBER align_frames)
  Q_PROPERTY(int id MEMBER id)
  Q_PROPERTY(QString api MEMBER api)

public:
  QSize resolution = {0, 0};
  int framerate = 0;
  bool flip = false;
  int rotate = 0;
  bool align_frames = false;
  int id = 0;
  QString api;

  bool operator==(const Camera_params& other) const noexcept = default;
};

struct DistortionCoefficients
{
  Q_GADGET
  Q_PROPERTY(QVector<float> coeffs MEMBER coeffs)

public:
  QVector<float> coeffs; // Stores the distortion coefficients

  bool operator==(const DistortionCoefficients& other) const noexcept = default;
};

struct Cameras
{
  Q_GADGET
  Q_PROPERTY(QVector<QString> input_paths MEMBER input_paths)
  Q_PROPERTY(bool flip_camera MEMBER flip_camera)
  Q_PROPERTY(QVariantMap params MEMBER params)
  Q_PROPERTY(QVariantMap intrinsics MEMBER intrinsics)
  Q_PROPERTY(QVariantMap distortion_coeffs MEMBER distortion_coeffs)
  Q_PROPERTY(QVariantMap extrinsics MEMBER extrinsics)

public:
  QVector<QString> input_paths;
  bool flip_camera = false;
  QVariantMap params;
  QVariantMap intrinsics;
  QVariantMap distortion_coeffs;
  QVariantMap extrinsics;

  bool operator==(const Cameras& other) const noexcept = default;
};

// Pair of points
struct PointPair
{
  Q_GADGET
  Q_PROPERTY(QVector2D point1 MEMBER point1)
  Q_PROPERTY(QVector2D point2 MEMBER point2)

public:
  QVector2D point1;
  QVector2D point2;

  bool operator==(const PointPair& other) const noexcept = default;
};

// dimmaps
struct Pose2DToFloor
{
  Q_GADGET
  Q_PROPERTY(QMap<QString, QVector<PointPair>> pairs_per_camera MEMBER pairs_per_camera)

public:
  QMap<QString, QVector<PointPair>> pairs_per_camera;
  bool operator==(const Pose2DToFloor& other) const noexcept = default;
};

struct Dimmaps
{
  Q_GADGET
  Q_PROPERTY(Pose2DToFloor pose2d_to_floor MEMBER pose2d_to_floor)

public:
  Pose2DToFloor pose2d_to_floor;

  bool operator==(const Dimmaps& other) const noexcept = default;
};

// skeleton obj
struct SkeletonFilters
{
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

struct HubsFilter // hubs will shutdown? no longer necessary?
{
  Q_GADGET

public:
  bool operator==(const HubsFilter& other) const noexcept = default;
};

struct Position2DFilter
{
  Q_GADGET
  Q_PROPERTY(QMap<QString, QVector<PointPair>> pairs_per_camera MEMBER pairs_per_camera)

public:
  QMap<QString, QVector<PointPair>> pairs_per_camera;

  bool operator==(const Position2DFilter& other) const noexcept = default;
};

struct CameraCalibration
{
  Q_GADGET
  Q_PROPERTY(QVector<float> Kmats MEMBER Kmats)
  Q_PROPERTY(QVector<float> Rtmats MEMBER Rtmats)

public:
  QVector<float> Kmats;
  QVector<float> Rtmats;

  bool operator==(const CameraCalibration& other) const noexcept = default;
};

struct PositionFilter
{
  Q_GADGET
  Q_PROPERTY(QMap<QString, CameraCalibration> calibrations MEMBER calibrations)
  Q_PROPERTY(bool use_pyrealsense2 MEMBER use_pyrealsense2)

public:
  QMap<QString, CameraCalibration> calibrations;
  bool use_pyrealsense2 = false;

  bool operator==(const PositionFilter& other) const noexcept = default;
};

struct ArmUpFilter
{
  Q_GADGET

public:
  bool operator==(const ArmUpFilter& other) const noexcept = default;
};

struct TriangulateFilter
{
  Q_GADGET
  Q_PROPERTY(QMap<QString, CameraCalibration> calibration MEMBER calibration)
  Q_PROPERTY(QMap<QString, DistortionCoefficients> dist_coeffs MEMBER dist_coeffs)
  Q_PROPERTY(QSize res MEMBER res)

public:
  QMap<QString, CameraCalibration> calibration;
  QMap<QString, DistortionCoefficients> dist_coeffs;
  QSize res = {0, 0};

  bool operator==(const TriangulateFilter& other) const noexcept = default;
};

struct Filters
{
  Q_GADGET
  Q_PROPERTY(SkeletonFilters skeletons MEMBER skeletons)
  Q_PROPERTY(HubsFilter hubs MEMBER hubs)
  Q_PROPERTY(Position2DFilter position2d MEMBER position2d)
  Q_PROPERTY(PositionFilter position MEMBER position)
  Q_PROPERTY(ArmUpFilter armup MEMBER armup)
  Q_PROPERTY(TriangulateFilter triangulate MEMBER triangulate)

public:
  SkeletonFilters skeletons;
  HubsFilter hubs;
  Position2DFilter position2d;
  PositionFilter position;
  ArmUpFilter armup;
  TriangulateFilter triangulate;

  bool operator==(const Filters& other) const noexcept = default;
};

// osc output obj
struct OscOutput
{
  Q_GADGET
  Q_PROPERTY(QMap<QString, int> destinations MEMBER destinations)

public:
  QMap<QString, int> destinations;

  bool operator==(const OscOutput& other) const noexcept = default;
};

struct Ssl
//TODO : create a struct where key_path & cert_path can be wither bool or String
{
  Q_GADGET
  Q_PROPERTY(QString cert_path MEMBER cert_path)
  Q_PROPERTY(QString key_path MEMBER key_path)

public:
  QString cert_path;
  QString key_path;

  bool operator==(const Ssl& other) const noexcept = default;
};

struct WebSocketOutput
{
  Q_GADGET
  Q_PROPERTY(QString host MEMBER host)
  Q_PROPERTY(int port MEMBER port)
  Q_PROPERTY(Ssl ssl MEMBER ssl)
  Q_PROPERTY(int nb_messages_per_second MEMBER nb_messages_per_second)

public:
  QString host;
  int port = 9000;
  Ssl ssl;
  int nb_messages_per_second = 0;

  bool operator==(const WebSocketOutput& other) const noexcept = default;
};

struct JsonOutput
{
  Q_GADGET
  Q_PROPERTY(QString path MEMBER path)
  Q_PROPERTY(QString header MEMBER header)
  Q_PROPERTY(QString footer MEMBER footer)

public:
  QString path;
  QString header;
  QString footer;

  bool operator==(const JsonOutput& other) const noexcept = default;
};

struct LibmapperOutput
{
  Q_GADGET

public:
  bool operator==(const LibmapperOutput& other) const noexcept = default;
};

struct RosbagOutput
{
  Q_GADGET
  Q_PROPERTY(QString channels MEMBER channels)
  Q_PROPERTY(bool compress MEMBER compress)
  Q_PROPERTY(QString path MEMBER path)
  Q_PROPERTY(int rosbag_version MEMBER rosbag_version)
  Q_PROPERTY(int chunk_duration MEMBER chunk_duration)

public:
  QString channels;
  bool compress = false;
  QString path;
  int rosbag_version = 0;
  int chunk_duration = 0;

  bool operator==(const RosbagOutput& other) const noexcept = default;
};

struct Outputs
{
  Q_GADGET
  Q_PROPERTY(QList<OscOutput> osc MEMBER osc)
  Q_PROPERTY(QList<WebSocketOutput> websocket MEMBER websocket)
  Q_PROPERTY(QList<JsonOutput> json MEMBER json)
  Q_PROPERTY(QList<RosbagOutput> rosbag MEMBER rosbag)
  Q_PROPERTY(QList<LibmapperOutput> libmapper MEMBER libmapper)

public:
  QList<OscOutput> osc;
  QList<WebSocketOutput> websocket;
  QList<JsonOutput> json;
  QList<RosbagOutput> rosbag;
  QList<LibmapperOutput> libmapper;

  bool operator==(const Outputs& other) const noexcept = default;
};

// represents the entire config file obj
struct Config
{
  Q_GADGET
  Q_PROPERTY(QList<Pose_backend> pose_backends MEMBER pose_backends)
  Q_PROPERTY(Cameras cameras MEMBER cameras)
  Q_PROPERTY(QVariantMap filters MEMBER filters)
  Q_PROPERTY(Outputs outputs MEMBER outputs)

public:
  QList<Pose_backend> pose_backends;
  Cameras cameras;
  QVariantMap filters;
  Outputs outputs;

  bool operator==(const Config& other) const noexcept = default;
};

struct DataModel : public QObject
{
  Q_OBJECT // Macro to enable Qt's meta-object system for this class
  Q_PROPERTY(Void_backend void_backend MEMBER void_backend)
  Q_PROPERTY(Mmpose_params mmpose_params MEMBER mmpose_params)
  Q_PROPERTY(Posenet_params posenet_params MEMBER posenet_params)
  Q_PROPERTY(Trt_params trt_params MEMBER trt_params)
  Q_PROPERTY(Mediapipe_params mediapipe_params MEMBER mediapipe_params)
  Q_PROPERTY(Pose_backend pose_backend MEMBER pose_backend)

  //camera properties
  Q_PROPERTY(Camera_params camera_params MEMBER camera_params)
  Q_PROPERTY(Cameras cameras MEMBER cameras)

  //dimmap properties
  Q_PROPERTY(Pose2DToFloor pose2d_to_floor MEMBER pose2d_to_floor)
  Q_PROPERTY(Dimmaps dimmaps MEMBER dimmaps)

  //Filters properties
  Q_PROPERTY(SkeletonFilters skeletons MEMBER skeletons)
  Q_PROPERTY(HubsFilter hubs MEMBER hubs)
  Q_PROPERTY(Position2DFilter position2d MEMBER position2d)
  Q_PROPERTY(PositionFilter position MEMBER position)
  Q_PROPERTY(ArmUpFilter armup MEMBER armup)
  Q_PROPERTY(TriangulateFilter triangulate MEMBER triangulate)
  Q_PROPERTY(Filters filters MEMBER filters)

  //Output properties
  Q_PROPERTY(OscOutput osc_output MEMBER osc_output)
  Q_PROPERTY(WebSocketOutput websocket_output MEMBER websocket_output)
  Q_PROPERTY(JsonOutput json_output MEMBER json_output)
  Q_PROPERTY(RosbagOutput rosbag_output MEMBER rosbag_output)
  Q_PROPERTY(LibmapperOutput libmapper_output MEMBER libmapper_output)
  Q_PROPERTY(Outputs outputs MEMBER outputs)

  Q_PROPERTY(Config config MEMBER config)

public:
  Mmpose_params mmpose_params; // Instance of Mmpose_params
  Void_backend void_backend;
  Posenet_params posenet_params;
  Trt_params trt_params;
  Mediapipe_params mediapipe_params;
  Pose_backend pose_backend;

  //camera properties
  Camera_params camera_params;
  Cameras cameras;

  //dimmap properties
  Dimmaps dimmaps;
  Pose2DToFloor pose2d_to_floor;

  //Filters properties
  SkeletonFilters skeletons;
  HubsFilter hubs;
  Position2DFilter position2d;
  PositionFilter position;
  ArmUpFilter armup;
  TriangulateFilter triangulate;
  Filters filters;

  //Output properties
  OscOutput osc_output;
  WebSocketOutput websocket_output;
  JsonOutput json_output;
  RosbagOutput rosbag_output;
  LibmapperOutput libmapper_output;
  Outputs outputs;

  Config config;
};
