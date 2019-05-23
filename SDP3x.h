#ifndef SDP3X_H
	#define SDP3X_H

	// convert two 8 bit values to one word
	#define BIU16(data, start) (((uint16_t)(data)[start]) << 8 | ((data)[start + 1]))

	// data length of result from I2C
	#define COMMAND_DATA_LENGTH 2
	#define RESULT_DATA_LENGTH 9

	#define DEFAULT_SDP3X_I2C_ADDRESS  0x21
	#define DEFAULT_SDP8XX_I2C_ADDRESS 0x25

	// triggered mode with 50ms conversion time
	typedef enum {
	   SDP_MEASUREMENT_COMMAND_0 = 0x36,
	   SDP_MEASUREMENT_COMMAND_1 = 0x2F
	} SDP3xCommands;

	class SDP3xClass
	{
	  public:
	  	SDP3xClass() : mI2CAddress(DEFAULT_SDP3X_I2C_ADDRESS) {}
	  	void setI2CAddress(uint8_t i2cAddress);

	  	uint8_t readSensor(uint8_t* readData, uint8_t size);
	  	float getPressureDiff(void);
	  	float getTemperature(void);

	  private:
	  	uint8_t mI2CAddress;
	};

	extern SDP3xClass SDP3x;

#endif


