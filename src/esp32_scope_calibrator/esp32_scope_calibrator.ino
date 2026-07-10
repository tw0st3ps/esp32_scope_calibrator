/*
  ESP32 Oscilloscope Calibration Signal (Updated for ESP32 Arduino Core v3.x)
  Generates a 1 kHz square wave with a 50% duty cycle on Pin 18.
*/

// Define the output pin (GPIO 18, can be changed if needed)
const int OSCI_PIN = 18;

// PWM Configuration
const int FREQUENCY = 1000;    // 1000 Hz = 1 kHz
const int RESOLUTION = 8;      // 8-bit resolution (values from 0 to 255)

// 50% of 255 corresponds to ~127 for a perfectly symmetrical square wave
const int DUTY_CYCLE = 127; 

void setup() {
  // New API command starting from Core version 3.0:
  // Directly binds the pin to the frequency and resolution. Channels are managed automatically.
  ledcAttach(OSCI_PIN, FREQUENCY, RESOLUTION);
  
  // Start generating the signal with 50% duty cycle
  ledcWrite(OSCI_PIN, DUTY_CYCLE);
}

void loop() {
  // The loop remains empty. The hardware timer handles signal generation autonomously.
}