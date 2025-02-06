#include "Constants.hpp"
#include "lemlib/chassis/trackingWheel.hpp"
#include "main.h"  // IWYU pragma: keep

// left motor group
pros::MotorGroup left_motor_group({MOTOR_PORT_LEFT_A, MOTOR_PORT_LEFT_B,
                                   MOTOR_PORT_LEFT_C},
                                  pros::MotorGears::green);
// right motor group
pros::MotorGroup right_motor_group({MOTOR_PORT_RIGHT_A, MOTOR_PORT_RIGHT_B,
                                    MOTOR_PORT_RIGHT_C},
                                   pros::MotorGears::green);

// drivetrain settings
lemlib::Drivetrain lemdrivetrain(
    &left_motor_group,           // left motor group
    &right_motor_group,          // right motor group
    15.25,                       // 10 inch track width
    lemlib::Omniwheel::NEW_325,  // using new 4" omnis
    480,                         // drivetrain rpm is 360
    8                            // horizontal drift is 2 (for now)
);

// imu
pros::Imu imu(SENSOR_PORT_IMU);
// // horizontal tracking wheel encoder
// pros::Rotation horizontal_encoder(20);
// // vertical tracking wheel encoder
// pros::adi::Encoder vertical_encoder('C', 'D', true);
// horizontal tracking wheel
// lemlib::TrackingWheel horizontal_tracking_wheel(&horizontal_encoder,
//                                                 lemlib::Omniwheel::NEW_275,
//                                                 -5.75);
// // vertical tracking wheel
// lemlib::TrackingWheel vertical_tracking_wheel(&vertical_encoder,
//                                               lemlib::Omniwheel::NEW_275, -2.5);

// odometry settings
lemlib::OdomSensors sensors(
    nullptr,  // vertical tracking wheel 1, set to null
    nullptr,  // vertical tracking wheel 2, set to nullptr as we are using IMEs
    nullptr,  // horizontal tracking wheel 1
    nullptr,  // horizontal tracking wheel 2, set to nullptr as we don't have a second one
    &imu  // inertial sensor
);

// lateral PID controller
lemlib::ControllerSettings lateral_controller(
    25,   // proportional gain (kP)
    0,    // integral gain (kI)
    3,    // derivative gain (kD)
    0,    // anti windup
    1,    // small error range, in inches
    100,  // small error range timeout, in milliseconds
    3,    // large error range, in inches
    500,  // large error range timeout, in milliseconds
    20    // maximum acceleration (slew)
);

// angular PID controller
lemlib::ControllerSettings angular_controller(
    5,    // proportional gain (kP)
    0,    // integral gain (kI)
    20,   // derivative gain (kD)
    0,    // anti windup
    1,    // small error range, in inches
    100,  // small error range timeout, in milliseconds
    3,    // large error range, in inches
    500,  // large error range timeout, in milliseconds
    0     // maximum acceleration (slew)
);
// create the chassis
lemlib::Chassis chassis(lemdrivetrain,       // drivetrain settings
                        lateral_controller,  // lateral PID settings
                        angular_controller,  // angular PID settings
                        sensors              // odometry sensors
);
