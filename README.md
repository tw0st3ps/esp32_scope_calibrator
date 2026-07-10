# ESP32 Scope Calibrator 🛠️

A simple yet precise workbench utility. This project leverages the ESP32's built-in Hardware PWM generator (LEDC) to output a highly stable **1 kHz square wave with a 50% duty cycle**. It is ideal for frequency compensation and probe calibration on portable or benchtop oscilloscopes.

## Features
* **Precise 1 kHz Frequency**: Perfectly matches the industry standard for probe compensation.
* **Hardware-Driven**: The signal is generated completely at the hardware timer level. The `loop()` function remains completely empty, ensuring an entirely jitter-free output signal.
* **Compatible with ESP32 Arduino Core v3.x**: Uses the modern, simplified `ledcAttach` API.

## Hardware Setup

Connecting your oscilloscope is straightforward:

1. **GND**: Connect your probe's ground clip to any **GND pin** on the ESP32.
2. **Signal**: Connect the probe tip to **GPIO 18** (Pin 18) on the ESP32.

> ⚠️ **Important:** Without a shared ground (GND) connection, your oscilloscope will only display signal noise!

## Software & Installation

1. Ensure you have the **Arduino IDE** installed.
2. Add the ESP32 board manager URL and install the `esp32` platform (tested with version 3.0+).
3. Open the sketch located in the `/src/esp32_scope_calibrator` directory.
4. Select your specific ESP32 board under *Tools -> Board*.
5. Click **Upload**.

## Calibrating Your Probe

Use a non-conductive (plastic) adjustment tool to turn the trimmer capacitor on your probe until the square wave edges appear perfectly square on your display:

* **Rounded corners:** Under-compensated (turn the trimmer clockwise).
* **Overshoot / Spikes:** Over-compensated (turn the trimmer counter-clockwise).
* **Perfectly flat top & bottom:** Optimally calibrated!