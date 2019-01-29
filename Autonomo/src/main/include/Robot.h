/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>
#
#include <frc/Joystick.h>
#include <frc/Spark.h>
#include <PWMSpeedController.h>
#include <frc/TimedRobot.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/smartdashboard/SendableChooser.h>

class Robot : public frc::TimedRobot {
  frc::Spark m_leftMotor{0};
  frc::Spark m_rightMotor{1};
  frc::Spark m_trigger{2};
  frc::DifferentialDrive m_robotDrive{m_leftMotor, m_rightMotor};
  frc::Joystick m_stick{0};
  frc::Spark m_button{3};
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

 private:
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;
};
