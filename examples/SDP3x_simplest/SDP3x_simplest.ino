#include <Wire.h>

#include "SDP3x.h"

// Setup routine runs once when you press reset
void setup() {
	// Initialize serial console
	Serial.begin(9600);
	// Initialize I2C communication
	Wire.begin();

	// To set a different I2C address, uncomment the line below
	// SDP3x.setI2CAddress(0x25);
}

// the loop routine runs over and over again forever
void loop() {
	// Simply print raw value, this can be viewed in the serial plotter
	Serial.print("Pressure difference: ");
	Serial.println(SDP3x.getPressureDiff());
	// delay for a 100ms until the next sensor reading
	delay(100);
	Serial.print("Temperature: ");
	Serial.println(SDP3x.getTemperature());
	// delay for a 100ms until the next sensor reading
	delay(100);
}