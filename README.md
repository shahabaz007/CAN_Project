# CAN-Based Body Control Module (BCM)

A comprehensive project to implement a **Body Control Module (BCM)** using the **Controller Area Network (CAN)** protocol. This project showcases how to manage various automotive systems like lighting and wipers control in a modular and efficient way.

**>> Problem :** Need for a reliable automotive BCM replica to monitor and control vehicle functions with real-time communication and error detection.

**>> Solution :** Developed a BCM replica using LPC2129 RidoLabz boards and CAN protocol, with a transmitter node managing driver inputs and controlling three receiver nodes.

**>> Implementation :** Demonstrated real-time data exchange, error detection, and multi-node communication for efficient and reliable vehicle electronics management.

## Hardware Requirements
**Microcontroller:**
  * LPC2129 (ARM7-based MCU by NXP)
  * CPU: 16/32-bit ARM7TDMI-S core running at up to 60 MHz.
  * On-chip Flash: 128 KB.
  * On-chip RAM: 16 KB.
  * 2 CAN controllers with acceptance filters.

**Development Board:**
   * RidoLabz LPC2129 Development Board.
   * Integrated LPC2129 microcontroller.
   * Onboard CAN transceivers.
   * GPIO headers for external connections.

**CAN Transceivers:**
* TJA1050 or equivalent for physical layer communication over CAN.

**Power Supply:**
* 5V regulated power supply for the microcontroller and CAN transceivers.

**Peripherals:**
* Switches: For simulating driver inputs (e.g., headlight, door lock, wipers).
* LEDs: Indicate system responses (e.g., lights, lock status).
* DC Motor: For simulating wiper control.

**CAN Bus:**
* Twisted-pair wiring to connect all nodes.

## Software Requirements

**Development Environment:**
* **Keil μVision IDE:**
* **Compiler:** ARM Compiler (RealView).
* **Debugger:** JTAG-based debugging for LPC2129.

**Programming Language:** Embedded C for all firmware development.

**CAN Protocol:**
* **Bitrate:**  Configurable, typically 125 kbps for automotive applications.
* **Message Format:** Standard 11-bit identifiers.

**Functionality:**

**->> Transmitter Node:**
* Reads driver inputs from GPIO (e.g., switches).
* Sends CAN messages to receiver nodes with relevant commands.

**->> Receiver Nodes:**
  * Lighting Node: Controls headlights and indicators.
  * Wiper Node: Controls wiper speed and position.
e machines to manage input/output processing for each node.
