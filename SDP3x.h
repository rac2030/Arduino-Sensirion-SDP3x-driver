#ifndef SDP3X_H
	#define SDP3X_H

	// convert two 8 bit values to one word
	#define BIU16(data, start) (((uint16_t)(data)[start]) << 8 | ((data)[start + 1]))

	// data length of result from I2C
	#define COMMAND_DATA_LENGTH 2
	#define RESULT_DATA_LENGTH 6

	// SDP3x sensor I2C address
	// The adress can be overwritten by defining SDP3x_I2C_ADDRESS in your sketch directly
	#ifndef SDP3x_I2C_ADDRESS
		#define SDP3x_I2C_ADDRESS 0x21
	#endif

	// triggered mode with 50ms conversion time
	typedef enum {
	   SDP_MEASUREMENT_COMMAND_0 = 0x36,
	   SDP_MEASUREMENT_COMMAND_1 = 0x2F
	} SDP3xCommands;

	class SDP3xClass
	{
	  public:
	  	uint8_t readSensor(uint8_t* readData, uint8_t size);
	  	float getPressureDiff(void);
	  	float getTemperature(void);
	};

	extern SDP3xClass SDP3x;

#endif


