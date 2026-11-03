//11/03/2026   wrist test


#include <Dynamixel2Arduino.h>  // Library for communicating with DYNAMIXEL motors

// Define serial communication ports
#define DXL_SERIAL   Serial3   // Hardware serial port for OpenCR <-> AX-18A communication
#define DEBUG_SERIAL Serial    // USB serial port for PC <-> OpenCR debugging

const int DXL_DIR_PIN = 84;    // Direction control pin for DYNAMIXEL half-duplex communication

// DYNAMIXEL motor communication settings
const uint8_t DXL_ID = 1;                      // Motor ID
const float DXL_PROTOCOL_VERSION = 1.0;        // AX-18A uses DYNAMIXEL Protocol 1.0
const uint32_t DXL_BAUDRATE = 1000000;         // Communication baud rate: 1 Mbps

// Create DYNAMIXEL controller instance
Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);

void setup()
{
  // PC <-> OpenCR
  // Initialize USB serial communication for debugging
  DEBUG_SERIAL.begin(115200);

  delay(2000);  // Allow time for serial communication to initialize

  // Indicate that the program has started
  DEBUG_SERIAL.println("===== PROGRAM START =====");

  // OpenCR <-> AX-18A
  // Initialize motor communication using the specified baud rate and protocol
  dxl.begin(DXL_BAUDRATE);
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);

  DEBUG_SERIAL.println("Dynamixel port initialized");

  // Ping
  // Check whether the motor with the specified ID responds
  if (dxl.ping(DXL_ID))
  {
    DEBUG_SERIAL.println("Ping OK");
  }
  else
  {
    DEBUG_SERIAL.println("Ping FAILED");
    return;  // Exit setup if communication fails
  }

  // Position mode
  // Disable motor torque before changing the operating mode
  dxl.torqueOff(DXL_ID);

  // Configure the motor for position control (Joint Mode)
  if (dxl.setOperatingMode(DXL_ID, OP_POSITION))
  {
    DEBUG_SERIAL.println("Position mode OK");
  }
  else
  {
    DEBUG_SERIAL.println("Position mode FAILED");
    return;  // Exit setup if mode configuration fails
  }

  // Torque ON
  // Enable motor torque to allow position commands to move the motor
  if (dxl.torqueOn(DXL_ID))
  {
    DEBUG_SERIAL.println("Torque ON OK");
  }
  else
  {
    DEBUG_SERIAL.println("Torque ON FAILED");
    return;  // Exit setup if torque cannot be enabled
  }

  // Read and display the motor's initial position in degrees
  DEBUG_SERIAL.print("Current position = ");
  DEBUG_SERIAL.println(
    dxl.getPresentPosition(DXL_ID, UNIT_DEGREE)
  );

  DEBUG_SERIAL.println("Setup finished");
}

void loop()
{
  
  // this part is tester its not acurate when motor moving in high speed
  // Read the motor's current position in raw encoder units
  // DEBUG_SERIAL.print("Actual RAW = ");
  // DEBUG_SERIAL.println(
  //   dxl.getPresentPosition(DXL_ID)
  // );

  // Read the motor's current position in degrees
  // DEBUG_SERIAL.print("Actual Degree = ");
  // DEBUG_SERIAL.println(
  //   dxl.getPresentPosition(DXL_ID, UNIT_DEGREE)
  // );




  // Command the motor to move to position 380 (RAW units)
  DEBUG_SERIAL.println("Go to RAW 380");

  // Send the target position command
  // Returns true (1) if the command is successfully transmitted
  bool result = dxl.setGoalPosition(DXL_ID, 380);

  // Display whether the position command was successfully sent
  DEBUG_SERIAL.print("Command result = ");
  DEBUG_SERIAL.println(result);

  // Wait 500 ms before sending the next position command
  delay(500);

  // Read and display the actual position after commanding RAW 380
  // DEBUG_SERIAL.print("Actual RAW = ");
  // DEBUG_SERIAL.println(
  //   dxl.getPresentPosition(DXL_ID)
  // );

  // DEBUG_SERIAL.print("Actual Degree = ");
  // DEBUG_SERIAL.println(
  //   dxl.getPresentPosition(DXL_ID, UNIT_DEGREE)
  // );


  // Command the motor to move to position 40 (RAW units)
  DEBUG_SERIAL.println("Go to RAW 40");

  // Send the second target position command
  result = dxl.setGoalPosition(DXL_ID, 40);

  // Display whether the second position command was successfully sent
  DEBUG_SERIAL.print("Command result = ");
  DEBUG_SERIAL.println(result);

  // Wait 500 ms before repeating the movement sequence
  delay(500);

  // Read and display the actual position after commanding RAW 40
  // DEBUG_SERIAL.print("Actual RAW = ");
  // DEBUG_SERIAL.println(
  //   dxl.getPresentPosition(DXL_ID)
  // );

  // DEBUG_SERIAL.print("Actual Degree = ");
  // DEBUG_SERIAL.println(
  //   dxl.getPresentPosition(DXL_ID, UNIT_DEGREE)
  // );
}
