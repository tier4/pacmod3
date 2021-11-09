// Copyright (c) 2019 AutonomouStuff, LLC
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include <pacmod3_dbc3_ros_api.h>
#include <autogen/pacmod3.h>

#include <vector>
#include <string>
#include <memory>


namespace pacmod3
{

std::shared_ptr<void> Dbc3Api::ParseSystemRptBool(const can_msgs::Frame& can_msg)
{
  std::shared_ptr<pm_msgs::SystemRptBool> new_msg( new pm_msgs::SystemRptBool() );

  HORN_RPT_t parsed_rpt;
  Unpack_HORN_RPT_pacmod3(&parsed_rpt, static_cast<const uint8_t*>(&can_msg.data[0]), static_cast<uint8_t>(can_msg.dlc));

  new_msg->enabled = parsed_rpt.ENABLED;
  new_msg->override_active = parsed_rpt.OVERRIDE_ACTIVE;
  new_msg->command_output_fault = parsed_rpt.COMMAND_OUTPUT_FAULT;
  new_msg->input_output_fault = parsed_rpt.INPUT_OUTPUT_FAULT;
  new_msg->output_reported_fault = parsed_rpt.OUTPUT_REPORTED_FAULT;
  new_msg->pacmod_fault = parsed_rpt.PACMOD_FAULT;
  new_msg->vehicle_fault = parsed_rpt.VEHICLE_FAULT;

  // dbc3 has no command_timeout field
  new_msg->command_timeout = 0;
  new_msg->manual_input = parsed_rpt.MANUAL_INPUT;
  new_msg->command = parsed_rpt.COMMANDED_VALUE;
  new_msg->output = parsed_rpt.OUTPUT_VALUE;

  return new_msg;
}

// void Pacmod3TxMsgParser::fillSystemRptInt(
//     const std::shared_ptr<Pacmod3TxMsg>& parser_class,
//     pm_msgs::SystemRptInt * new_msg,
//     const std::string& frame_id)
// {
//   auto dc_parser = std::dynamic_pointer_cast<SystemRptIntMsg>(parser_class);

//   new_msg->enabled = dc_parser->enabled;
//   new_msg->override_active = dc_parser->override_active;
//   new_msg->command_output_fault = dc_parser->command_output_fault;
//   new_msg->input_output_fault = dc_parser->input_output_fault;
//   new_msg->output_reported_fault = dc_parser->output_reported_fault;
//   new_msg->pacmod_fault = dc_parser->pacmod_fault;
//   new_msg->vehicle_fault = dc_parser->vehicle_fault;

//   new_msg->manual_input = dc_parser->manual_input;
//   new_msg->command = dc_parser->command;
//   new_msg->output = dc_parser->output;

//   new_msg->header.frame_id = frame_id;
//   new_msg->header.stamp = ros::Time::now();
// }

// void Pacmod3TxMsgParser::fillSystemRptFloat(
//     const std::shared_ptr<Pacmod3TxMsg>& parser_class,
//     pm_msgs::SystemRptFloat * new_msg,
//     const std::string& frame_id)
// {
//   auto dc_parser = std::dynamic_pointer_cast<SystemRptFloatMsg>(parser_class);

//   new_msg->enabled = dc_parser->enabled;
//   new_msg->override_active = dc_parser->override_active;
//   new_msg->command_output_fault = dc_parser->command_output_fault;
//   new_msg->input_output_fault = dc_parser->input_output_fault;
//   new_msg->output_reported_fault = dc_parser->output_reported_fault;
//   new_msg->pacmod_fault = dc_parser->pacmod_fault;
//   new_msg->vehicle_fault = dc_parser->vehicle_fault;

//   new_msg->manual_input = dc_parser->manual_input;
//   new_msg->command = dc_parser->command;
//   new_msg->output = dc_parser->output;

//   new_msg->header.frame_id = frame_id;
//   new_msg->header.stamp = ros::Time::now();
// }

// void Pacmod3TxMsgParser::fillGlobalRpt(
//     const std::shared_ptr<Pacmod3TxMsg>& parser_class,
//     pm_msgs::GlobalRpt * new_msg,
//     const std::string& frame_id)
// {
//   auto dc_parser = std::dynamic_pointer_cast<GlobalRptMsg>(parser_class);

//   new_msg->enabled = dc_parser->enabled;
//   new_msg->override_active = dc_parser->override_active;
//   new_msg->pacmod_sys_fault_active = dc_parser->fault_active;
//   new_msg->config_fault_active = dc_parser->config_fault_active;
//   new_msg->user_can_timeout = dc_parser->user_can_timeout;
//   new_msg->steering_can_timeout = dc_parser->steering_can_timeout;
//   new_msg->brake_can_timeout = dc_parser->brake_can_timeout;
//   new_msg->subsystem_can_timeout = dc_parser->subsystem_can_timeout;
//   new_msg->vehicle_can_timeout = dc_parser->vehicle_can_timeout;
//   new_msg->user_can_read_errors = dc_parser->user_can_read_errors;

//   new_msg->header.frame_id = frame_id;
//   new_msg->header.stamp = ros::Time::now();
// }

// void Pacmod3TxMsgParser::fillComponentRpt(
//     const std::shared_ptr<Pacmod3TxMsg>& parser_class,
//     pm_msgs::ComponentRpt * new_msg,
//     const std::string& frame_id)
// {
//   auto dc_parser = std::dynamic_pointer_cast<ComponentRptMsg>(parser_class);

//   new_msg->component_type = dc_parser->component_type;
//   new_msg->counter = dc_parser->counter;
//   new_msg->complement = dc_parser->complement;
//   new_msg->config_fault = dc_parser->config_fault;

//   new_msg->header.frame_id = frame_id;
//   new_msg->header.stamp = ros::Time::now();
// }

// void Pacmod3TxMsgParser::fillAccelAuxRpt(
//     const std::shared_ptr<Pacmod3TxMsg>& parser_class,
//     pm_msgs::AccelAuxRpt * new_msg,
//     const std::string& frame_id)
// {
//   auto dc_parser = std::dynamic_pointer_cast<AccelAuxRptMsg>(parser_class);

//   new_msg->operator_interaction = dc_parser->operator_interaction;
//   new_msg->operator_interaction_avail = dc_parser->operator_interaction_avail;

//   new_msg->header.frame_id = frame_id;
//   new_msg->header.stamp = ros::Time::now();
// }

// void Pacmod3TxMsgParser::fillBrakeAuxRpt(
//     const std::shared_ptr<Pacmod3TxMsg>& parser_class,
//     pm_msgs::BrakeAuxRpt * new_msg,
//     const std::string& frame_id)
// {
//   auto dc_parser = std::dynamic_pointer_cast<BrakeAuxRptMsg>(parser_class);

//   new_msg->brake_pressure = dc_parser->raw_brake_pressure;
//   new_msg->operator_interaction = dc_parser->operator_interaction;
//   new_msg->brake_on_off = dc_parser->brake_on_off;
//   new_msg->operator_interaction_avail = dc_parser->operator_interaction_avail;
//   new_msg->brake_on_off_avail = dc_parser->brake_on_off_avail;

//   new_msg->header.frame_id = frame_id;
//   new_msg->header.stamp = ros::Time::now();
// }

// void Pacmod3TxMsgParser::fillDateTimeRpt(
//     const std::shared_ptr<Pacmod3TxMsg>& parser_class,
//     pm_msgs::DateTimeRpt * new_msg,
//     const std::string& frame_id)
// {
//   auto dc_parser = std::dynamic_pointer_cast<DateTimeRptMsg>(parser_class);

//   new_msg->year = dc_parser->year;
//   new_msg->month = dc_parser->month;
//   new_msg->day = dc_parser->day;
//   new_msg->hour = dc_parser->hour;
//   new_msg->minute = dc_parser->minute;
//   new_msg->second = dc_parser->second;

//   new_msg->header.frame_id = frame_id;
//   new_msg->header.stamp = ros::Time::now();
// }

// void Pacmod3TxMsgParser::fillDetectedObjectRpt(
//     const std::shared_ptr<Pacmod3TxMsg>& parser_class,
//     pm_msgs::DetectedObjectRpt * new_msg,
//     const std::string& frame_id)
// {
//   auto dc_parser = std::dynamic_pointer_cast<DetectedObjectRptMsg>(parser_class);

//   new_msg->front_object_distance_low_res = dc_parser->front_object_distance_low_res;
//   new_msg->front_object_distance_high_res = dc_parser->front_object_distance_high_res;

//   new_msg->header.frame_id = frame_id;
//   new_msg->header.stamp = ros::Time::now();
// }
// void Pacmod3TxMsgParser::fillDoorRpt(
//     const std::shared_ptr<Pacmod3TxMsg>& parser_class,
//     pm_msgs::DoorRpt * new_msg,
//     const std::string& frame_id)
// {
//   auto dc_parser = std::dynamic_pointer_cast<DoorRptMsg>(parser_class);

//   new_msg->driver_door_open = dc_parser->driver_door_open;
//   new_msg->driver_door_open_avail = dc_parser->driver_door_open_avail;
//   new_msg->passenger_door_open = dc_parser->passenger_door_open;
//   new_msg->passenger_door_open_avail = dc_parser->passenger_door_open_avail;
//   new_msg->rear_driver_door_open = dc_parser->rear_driver_door_open;
//   new_msg->rear_driver_door_open_avail = dc_parser->rear_driver_door_open_avail;
//   new_msg->rear_passenger_door_open = dc_parser->rear_passenger_door_open;
//   new_msg->rear_passenger_door_open_avail = dc_parser->rear_passenger_door_open_avail;
//   new_msg->hood_open = dc_parser->hood_open;
//   new_msg->hood_open_avail = dc_parser->hood_open_avail;
//   new_msg->trunk_open = dc_parser->trunk_open;
//   new_msg->trunk_open_avail = dc_parser->trunk_open_avail;
//   new_msg->fuel_door_open = dc_parser->fuel_door_open;
//   new_msg->fuel_door_open_avail = dc_parser->fuel_door_open_avail;

//   new_msg->header.frame_id = frame_id;
//   new_msg->header.stamp = ros::Time::now();
// }

// void Pacmod3TxMsgParser::fillEngineRpt(
//     const std::shared_ptr<Pacmod3TxMsg>& parser_class,
//     pm_msgs::EngineRpt * new_msg,
//     const std::string& frame_id)
// {
//   auto dc_parser = std::dynamic_pointer_cast<EngineRptMsg>(parser_class);

//   new_msg->engine_speed = dc_parser->engine_speed;
//   new_msg->engine_torque = dc_parser->engine_torque;
//   new_msg->engine_coolant_temp = dc_parser->engine_coolant_temp;
//   new_msg->engine_speed_avail = dc_parser->engine_speed_avail;
//   new_msg->engine_torque_avail = dc_parser->engine_torque_avail;
//   new_msg->engine_coolant_temp_avail = dc_parser->engine_coolant_temp_avail;

//   new_msg->header.frame_id = frame_id;
//   new_msg->header.stamp = ros::Time::now();
// }

// void Pacmod3TxMsgParser::fillHeadlightAuxRpt(
//     const std::shared_ptr<Pacmod3TxMsg>& parser_class,
//     pm_msgs::HeadlightAuxRpt * new_msg,
//     const std::string& frame_id)
// {
//   auto dc_parser = std::dynamic_pointer_cast<HeadlightAuxRptMsg>(parser_class);

//   new_msg->headlights_on = dc_parser->headlights_on;
//   new_msg->headlights_on_bright = dc_parser->headlights_on_bright;
//   new_msg->fog_lights_on = dc_parser->fog_lights_on;
//   new_msg->headlights_mode = dc_parser->headlights_mode;
//   new_msg->headlights_on_avail = dc_parser->headlights_on_avail;
//   new_msg->headlights_on_bright_avail = dc_parser->headlights_on_bright_avail;
//   new_msg->fog_lights_on_avail = dc_parser->fog_lights_on_avail;
//   new_msg->headlights_mode_avail = dc_parser->headlights_mode_avail;

//   new_msg->header.frame_id = frame_id;
//   new_msg->header.stamp = ros::Time::now();
// }

// void Pacmod3TxMsgParser::fillInteriorLightsRpt(
//     const std::shared_ptr<Pacmod3TxMsg>& parser_class,
//     pm_msgs::InteriorLightsRpt * new_msg,
//     const std::string& frame_id)
// {
//   auto dc_parser = std::dynamic_pointer_cast<InteriorLightsRptMsg>(parser_class);

//   new_msg->front_dome_lights_on = dc_parser->front_dome_lights_on;
//   new_msg->front_dome_lights_on_avail = dc_parser->front_dome_lights_on_avail;
//   new_msg->rear_dome_lights_on = dc_parser->rear_dome_lights_on;
//   new_msg->rear_dome_lights_on_avail = dc_parser->rear_dome_lights_on_avail;
//   new_msg->mood_lights_on = dc_parser->mood_lights_on;
//   new_msg->mood_lights_on_avail = dc_parser->mood_lights_on_avail;
//   new_msg->dim_level = dc_parser->dim_level;
//   new_msg->dim_level_avail = dc_parser->dim_level_avail;

//   new_msg->header.frame_id = frame_id;
//   new_msg->header.stamp = ros::Time::now();
// }

// void Pacmod3TxMsgParser::fillLatLonHeadingRpt(
//     const std::shared_ptr<Pacmod3TxMsg>& parser_class,
//     pm_msgs::LatLonHeadingRpt * new_msg,
//     const std::string& frame_id)
// {
//   auto dc_parser = std::dynamic_pointer_cast<LatLonHeadingRptMsg>(parser_class);

//   new_msg->latitude_degrees = dc_parser->latitude_degrees;
//   new_msg->latitude_minutes = dc_parser->latitude_minutes;
//   new_msg->latitude_seconds = dc_parser->latitude_seconds;
//   new_msg->longitude_degrees = dc_parser->longitude_degrees;
//   new_msg->longitude_minutes = dc_parser->longitude_minutes;
//   new_msg->longitude_seconds = dc_parser->longitude_seconds;
//   new_msg->heading = dc_parser->heading;

//   new_msg->header.frame_id = frame_id;
//   new_msg->header.stamp = ros::Time::now();
// }

// void Pacmod3TxMsgParser::fillMotorRpt1(
//     const std::shared_ptr<Pacmod3TxMsg>& parser_class,
//     pm_msgs::MotorRpt1 * new_msg,
//     const std::string& frame_id)
// {
//   auto dc_parser = std::dynamic_pointer_cast<MotorRpt1Msg>(parser_class);

//   new_msg->current = dc_parser->current;
//   new_msg->position = dc_parser->position;

//   new_msg->header.frame_id = frame_id;
//   new_msg->header.stamp = ros::Time::now();
// }

// void Pacmod3TxMsgParser::fillMotorRpt2(
//     const std::shared_ptr<Pacmod3TxMsg>& parser_class,
//     pm_msgs::MotorRpt2 * new_msg,
//     const std::string& frame_id)
// {
//   auto dc_parser = std::dynamic_pointer_cast<MotorRpt2Msg>(parser_class);

//   new_msg->encoder_temp = dc_parser->encoder_temp;
//   new_msg->motor_temp = dc_parser->motor_temp;
//   new_msg->angular_speed = dc_parser->velocity;

//   new_msg->header.frame_id = frame_id;
//   new_msg->header.stamp = ros::Time::now();
// }

// void Pacmod3TxMsgParser::fillMotorRpt3(
//     const std::shared_ptr<Pacmod3TxMsg>& parser_class,
//     pm_msgs::MotorRpt3 * new_msg,
//     const std::string& frame_id)
// {
//   auto dc_parser = std::dynamic_pointer_cast<MotorRpt3Msg>(parser_class);

//   new_msg->torque_output = dc_parser->torque_output;
//   new_msg->torque_input = dc_parser->torque_input;

//   new_msg->header.frame_id = frame_id;
//   new_msg->header.stamp = ros::Time::now();
// }

// void Pacmod3TxMsgParser::fillOccupancyRpt(
//     const std::shared_ptr<Pacmod3TxMsg>& parser_class,
//     pm_msgs::OccupancyRpt * new_msg,
//     const std::string& frame_id)
// {
//   auto dc_parser = std::dynamic_pointer_cast<OccupancyRptMsg>(parser_class);

//   new_msg->driver_seat_occupied = dc_parser->driver_seat_occupied;
//   new_msg->driver_seat_occupied_avail = dc_parser->driver_seat_occupied_avail;
//   new_msg->passenger_seat_occupied = dc_parser->passenger_seat_occupied;
//   new_msg->passenger_seat_occupied_avail = dc_parser->passenger_seat_occupied_avail;
//   new_msg->rear_seat_occupied = dc_parser->rear_seat_occupied;
//   new_msg->rear_seat_occupied_avail = dc_parser->rear_seat_occupied_avail;
//   new_msg->driver_seatbelt_buckled = dc_parser->driver_seatbelt_buckled;
//   new_msg->driver_seatbelt_buckled_avail = dc_parser->driver_seatbelt_buckled_avail;
//   new_msg->passenger_seatbelt_buckled = dc_parser->passenger_seatbelt_buckled;
//   new_msg->passenger_seatbelt_buckled_avail = dc_parser->passenger_seatbelt_buckled_avail;
//   new_msg->driver_rear_seatbelt_buckled = dc_parser->rear_seatbelt_buckled;
//   new_msg->driver_rear_seatbelt_buckled_avail = dc_parser->rear_seatbelt_buckled_avail;

//   new_msg->header.frame_id = frame_id;
//   new_msg->header.stamp = ros::Time::now();
// }

// void Pacmod3TxMsgParser::fillRearLightsRpt(
//     const std::shared_ptr<Pacmod3TxMsg>& parser_class,
//     pm_msgs::RearLightsRpt * new_msg,
//     const std::string& frame_id)
// {
//   auto dc_parser = std::dynamic_pointer_cast<RearLightsRptMsg>(parser_class);

//   new_msg->brake_lights_on = dc_parser->brake_lights_on;
//   new_msg->brake_lights_on_avail = dc_parser->brake_lights_on_avail;
//   new_msg->reverse_lights_on = dc_parser->reverse_lights_on;
//   new_msg->reverse_lights_on_avail = dc_parser->reverse_lights_on_avail;

//   new_msg->header.frame_id = frame_id;
//   new_msg->header.stamp = ros::Time::now();
// }

// void Pacmod3TxMsgParser::fillShiftAuxRpt(
//     const std::shared_ptr<Pacmod3TxMsg>& parser_class,
//     pm_msgs::ShiftAuxRpt * new_msg,
//     const std::string& frame_id)
// {
//   auto dc_parser = std::dynamic_pointer_cast<ShiftAuxRptMsg>(parser_class);

//   new_msg->between_gears = dc_parser->between_gears;
//   new_msg->stay_in_neutral_mode = dc_parser->stay_in_neutral_mode;
//   new_msg->brake_interlock_active = dc_parser->brake_interlock_active;
//   new_msg->speed_interlock_active = dc_parser->speed_interlock_active;
//   new_msg->between_gears_avail = dc_parser->between_gears_avail;
//   new_msg->stay_in_neutral_mode_avail = dc_parser->stay_in_neutral_mode_avail;
//   new_msg->brake_interlock_active_avail = dc_parser->brake_interlock_active_avail;
//   new_msg->speed_interlock_active_avail = dc_parser->speed_interlock_active_avail;
//   new_msg->gear_number_avail = dc_parser->gear_number_avail;
//   new_msg->gear_number = dc_parser->gear_number;

//   new_msg->header.frame_id = frame_id;
//   new_msg->header.stamp = ros::Time::now();
// }

// void Pacmod3TxMsgParser::fillSteeringAuxRpt(
//     const std::shared_ptr<Pacmod3TxMsg>& parser_class,
//     pm_msgs::SteeringAuxRpt * new_msg,
//     const std::string& frame_id)
// {
//   auto dc_parser = std::dynamic_pointer_cast<SteeringAuxRptMsg>(parser_class);

//   new_msg->steering_torque = dc_parser->raw_torque;
//   new_msg->rotation_rate = dc_parser->rotation_rate;
//   new_msg->operator_interaction = dc_parser->operator_interaction;
//   new_msg->steering_torque_avail = dc_parser->raw_torque_avail;
//   new_msg->rotation_rate_avail = dc_parser->rotation_rate_avail;
//   new_msg->operator_interaction_avail = dc_parser->operator_interaction_avail;

//   new_msg->header.frame_id = frame_id;
//   new_msg->header.stamp = ros::Time::now();
// }

// void Pacmod3TxMsgParser::fillTurnAuxRpt(
//     const std::shared_ptr<Pacmod3TxMsg>& parser_class,
//     pm_msgs::TurnAuxRpt * new_msg,
//     const std::string& frame_id)
// {
//   auto dc_parser = std::dynamic_pointer_cast<TurnAuxRptMsg>(parser_class);

//   new_msg->driver_blinker_bulb_on = dc_parser->driver_blinker_bulb_on;
//   new_msg->passenger_blinker_bulb_on = dc_parser->passenger_blinker_bulb_on;
//   new_msg->driver_blinker_bulb_on_avail = dc_parser->driver_blinker_bulb_on_avail;
//   new_msg->passenger_blinker_bulb_on_avail = dc_parser->passenger_blinker_bulb_on_avail;

//   new_msg->header.frame_id = frame_id;
//   new_msg->header.stamp = ros::Time::now();
// }

// void Pacmod3TxMsgParser::fillVehicleDynamicsRpt(
//     const std::shared_ptr<Pacmod3TxMsg>& parser_class,
//     pm_msgs::VehicleDynamicsRpt * new_msg,
//     const std::string& frame_id)
// {
//   auto dc_parser = std::dynamic_pointer_cast<VehicleDynamicsRptMsg>(parser_class);

//   new_msg->veh_g_forces = dc_parser->g_forces;

//   new_msg->header.frame_id = frame_id;
//   new_msg->header.stamp = ros::Time::now();
// }

// void Pacmod3TxMsgParser::fillVehicleSpeedRpt(
//     const std::shared_ptr<Pacmod3TxMsg>& parser_class,
//     pm_msgs::VehicleSpeedRpt * new_msg,
//     const std::string& frame_id)
// {
//   auto dc_parser = std::dynamic_pointer_cast<VehicleSpeedRptMsg>(parser_class);

//   new_msg->vehicle_speed = dc_parser->vehicle_speed;
//   new_msg->vehicle_speed_valid = dc_parser->vehicle_speed_valid;

//   new_msg->header.frame_id = frame_id;
//   new_msg->header.stamp = ros::Time::now();
// }

// void Pacmod3TxMsgParser::fillVinRpt(
//     const std::shared_ptr<Pacmod3TxMsg>& parser_class,
//     pm_msgs::VinRpt * new_msg,
//     const std::string& frame_id)
// {
//   auto dc_parser = std::dynamic_pointer_cast<VinRptMsg>(parser_class);

//   new_msg->mfg_code = dc_parser->mfg_code;
//   new_msg->mfg = dc_parser->mfg;
//   new_msg->model_year_code = dc_parser->model_year_code;
//   new_msg->model_year = dc_parser->model_year;
//   new_msg->serial = dc_parser->serial;

//   new_msg->header.frame_id = frame_id;
//   new_msg->header.stamp = ros::Time::now();
// }

// void Pacmod3TxMsgParser::fillWheelSpeedRpt(
//     const std::shared_ptr<Pacmod3TxMsg>& parser_class,
//     pm_msgs::WheelSpeedRpt * new_msg,
//     const std::string& frame_id)
// {
//   auto dc_parser = std::dynamic_pointer_cast<WheelSpeedRptMsg>(parser_class);

//   new_msg->front_left_wheel_speed = dc_parser->front_left_wheel_speed;
//   new_msg->front_right_wheel_speed = dc_parser->front_right_wheel_speed;
//   new_msg->rear_left_wheel_speed = dc_parser->rear_left_wheel_speed;
//   new_msg->rear_right_wheel_speed = dc_parser->rear_right_wheel_speed;

//   new_msg->header.frame_id = frame_id;
//   new_msg->header.stamp = ros::Time::now();
// }

// void Pacmod3TxMsgParser::fillWiperAuxRpt(
//     const std::shared_ptr<Pacmod3TxMsg>& parser_class,
//     pm_msgs::WiperAuxRpt * new_msg,
//     const std::string& frame_id)
// {
//   auto dc_parser = std::dynamic_pointer_cast<WiperAuxRptMsg>(parser_class);

//   new_msg->front_wiping = dc_parser->front_wiping;
//   new_msg->front_spraying = dc_parser->front_spraying;
//   new_msg->rear_wiping = dc_parser->rear_wiping;
//   new_msg->rear_spraying = dc_parser->rear_spraying;
//   new_msg->spray_near_empty = dc_parser->spray_near_empty;
//   new_msg->spray_empty = dc_parser->spray_empty;
//   new_msg->front_wiping_avail = dc_parser->front_wiping_avail;
//   new_msg->front_spraying_avail = dc_parser->front_spraying_avail;
//   new_msg->rear_wiping_avail = dc_parser->rear_wiping_avail;
//   new_msg->rear_spraying_avail = dc_parser->rear_spraying_avail;
//   new_msg->spray_near_empty_avail = dc_parser->spray_near_empty_avail;
//   new_msg->spray_empty_avail = dc_parser->spray_empty_avail;

//   new_msg->header.frame_id = frame_id;
//   new_msg->header.stamp = ros::Time::now();
// }

// void Pacmod3TxMsgParser::fillYawRateRpt(
//     const std::shared_ptr<Pacmod3TxMsg>& parser_class,
//     pm_msgs::YawRateRpt * new_msg,
//     const std::string& frame_id)
// {
//   auto dc_parser = std::dynamic_pointer_cast<YawRateRptMsg>(parser_class);

//   new_msg->yaw_rate = dc_parser->yaw_rate;

//   new_msg->header.frame_id = frame_id;
//   new_msg->header.stamp = ros::Time::now();
// }

// Command messages

can_msgs::Frame Dbc3Api::EncodeSystemCmdBool(const pm_msgs::SystemCmdBool& msg)
{
  can_msgs::Frame packed_frame;

  HORN_CMD_t unpacked_cmd;
  unpacked_cmd.ENABLE = msg.enable;
  unpacked_cmd.IGNORE_OVERRIDES = msg.ignore_overrides;
  unpacked_cmd.CLEAR_OVERRIDE = msg.clear_override;
  unpacked_cmd.HORN_CMD = msg.command;

  uint8_t unused_ide;
  Pack_HORN_CMD_pacmod3(&unpacked_cmd, static_cast<uint8_t*>(&packed_frame.data[0]), static_cast<uint8_t*>(&packed_frame.dlc), &unused_ide);

  return packed_frame;
}


}  // namespace pacmod3

