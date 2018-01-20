#pragma once

#include "json_serialization.h"
#include <rpos/core/pose.h>
#include <rpos/core/geometry.h>
#include <rpos/core/home_description.h>
#include <rpos/system/util/log.h>
#include <rpos/core/diagnosis_info.h>
#include <rpos/message/message.h>
#include <rpos/message/subscription.h>
#include <rpos/message/base_messages.h>
#include <rpos/message/imu_messages.h>
#include <rpos/core/rpos_core_config.h>
#include <rpos/core/door_description.h>

namespace rpos { namespace system { namespace serialization { namespace json {

    template <>
	struct RPOS_CORE_API Serializer < core::Pose >
    {
        static Json::Value serialize(const core::Pose& v);
        static core::Pose deserialize(const Json::Value& v);
    };

    template <>
    struct RPOS_CORE_API Serializer < core::Location >
    {
        static Json::Value serialize(const core::Location& v);
        static core::Location deserialize(const Json::Value& v);
    };

    template <>
	struct RPOS_CORE_API Serializer < core::RectangleF >
    {
        static Json::Value serialize(const core::RectangleF& v);
        static core::RectangleF deserialize(const Json::Value& v);
    };

    template <>
	struct RPOS_CORE_API Serializer < core::Vector2i >
    {
        static Json::Value serialize(const core::Vector2i& v);
        static core::Vector2i deserialize(const Json::Value& v);
    };

    template <>
	struct RPOS_CORE_API Serializer < core::Vector3i >
    {
        static Json::Value serialize(const core::Vector3i& v);
        static core::Vector3i deserialize(const Json::Value& v);
    };

    template <>
	struct RPOS_CORE_API Serializer < core::Vector4i >
    {
        static Json::Value serialize(const core::Vector4i& v);
        static core::Vector4i deserialize(const Json::Value& v);
    };

    template <>
	struct RPOS_CORE_API Serializer < core::Vector2f >
    {
        static Json::Value serialize(const core::Vector2f& v);
        static core::Vector2f deserialize(const Json::Value& v);
    };

    template <>
	struct RPOS_CORE_API Serializer < core::Vector3f >
    {
        static Json::Value serialize(const core::Vector3f& v);
        static core::Vector3f deserialize(const Json::Value& v);
    };

    template <>
	struct RPOS_CORE_API Serializer < core::Vector4f >
    {
        static Json::Value serialize(const core::Vector4f& v);
        static core::Vector4f deserialize(const Json::Value& v);
    };

    template <>
	struct RPOS_CORE_API Serializer < core::DiagnosisInfoScanData >
    {
        static Json::Value serialize(const core::DiagnosisInfoScanData& v);
        static core::DiagnosisInfoScanData deserialize(const Json::Value& v);
    };

    template <>
	struct RPOS_CORE_API Serializer < core::DiagnosisInfoLidarScan >
    {
        static Json::Value serialize(const core::DiagnosisInfoLidarScan& v);
        static core::DiagnosisInfoLidarScan deserialize(const Json::Value& v);
    };

    template <>
	struct RPOS_CORE_API Serializer < core::DiagnosisInfoDepthCameraScan >
    {
        static Json::Value serialize(const core::DiagnosisInfoDepthCameraScan& v);
        static core::DiagnosisInfoDepthCameraScan deserialize(const Json::Value& v);
    };

    template <>
	struct RPOS_CORE_API Serializer < core::DiagnosisInfoSensor >
    {
        static Json::Value serialize(const core::DiagnosisInfoSensor& v);
        static core::DiagnosisInfoSensor deserialize(const Json::Value& v);
    };

	template <>
	struct RPOS_CORE_API Serializer < message::SubscriptionQos >
	{
		static Json::Value serialize(const message::SubscriptionQos& v);
		static message::SubscriptionQos deserialize(const Json::Value& v);
	};

	template <>
	struct RPOS_CORE_API Serializer < message::SubscriptionOptions >
	{
		static Json::Value serialize(const message::SubscriptionOptions& v);
		static message::SubscriptionOptions deserialize(const Json::Value& v);
	};

	template < class PayloadT >
	struct RPOS_CORE_API Serializer < message::Message<PayloadT> >
	{
		static Json::Value serialize(const message::Message<PayloadT>& v)
		{
			Json::Value output;

			output["timestamp"] = json::serialize(v.timestamp);
			output["payload"] = json::serialize(v.payload);

			return output;
		}

		static message::Message<PayloadT> deserialize(const Json::Value& v)
		{
			message::Message<PayloadT> message;

			message.timestamp = json::deserialize<message::message_timestamp_t>(v["timestamp"]);
			message.payload = json::deserialize<PayloadT>(v["payload"]);

			return message;
		}
	};

	template <>
	struct RPOS_CORE_API Serializer < message::base::MovementEstimation> {
		static Json::Value serialize(const message::base::MovementEstimation& v);
		static message::base::MovementEstimation deserialize(const Json::Value& v);
	};

	template <>
	struct RPOS_CORE_API Serializer < message::imu::ImuAllSensorData > {
		static Json::Value serialize(const message::imu::ImuAllSensorData& v);
		static message::imu::ImuAllSensorData deserialize(const Json::Value& v);
	};

    template <>
    struct RPOS_CORE_API Serializer < core::HomeDesc > {
        static Json::Value serialize(const core::HomeDesc& v);
        static core::HomeDesc deserialize(const Json::Value& v);
    };

    template <>
    struct RPOS_CORE_API Serializer < core::DoorDesc > {
        static Json::Value serialize(const core::DoorDesc& v);
        static core::DoorDesc deserialize(const Json::Value& v);
    };

	template <>
	struct RPOS_CORE_API Serializer < rpos::system::util::diagnosis::LogData > {
		static Json::Value serialize(const rpos::system::util::diagnosis::LogData& v);
		static rpos::system::util::diagnosis::LogData deserialize(const Json::Value& v);
	};

} } } }
