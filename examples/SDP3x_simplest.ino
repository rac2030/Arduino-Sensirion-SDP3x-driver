#include "SDP3x.h"

// Setup routine runs once when you press reset
void setup() {
	// Initialize serial console
	Serial.begin(9600);
	// Initialize I2C communication
	Wire.begin();
}

// the loop routine runs over and over again forever
void loop() {
	// Simply print raw value, this can be viewed in the serial plotter
	Serial.print(SDP3x.GetPressureDiff());
	// delay for a 100ms until the next sensor reading
	delay(100);
}