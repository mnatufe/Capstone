#include "smartRack.h"

#define TEMPSENSOR_TEMP_REG 0x00

extern I2C_HandleTypeDef hi2c1;


uint32_t readTempData(float *temp){
	uint8_t data[2];

	// Wait for I2C mutex
	if (osMutexAcquire(i2cMutexHandle, osWaitForever) != osOK) {
		return 0;
	}

	HAL_StatusTypeDef status= HAL_I2C_Master_Receive(&hi2c1, //Read data from temp sensor via i2c
			TEMPSENSOR_ADDR,
			data,
			2,
			100);

	// Release I2C mutex
	osMutexRelease(i2cMutexHandle);

	// Check communication status
	if (status != HAL_OK) {
	    return 0;
	}
	//combine received bytes
	int16_t rawData = (int16_t)((data[0] << 8) | data[1]);

	//convert temp data
	int16_t tempConv = rawData >> 4;

	//store converted temp to temperature register address
	*temp = tempConv * 0.0625f;

	return 1;
}
