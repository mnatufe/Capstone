#include "smartRack.h"

uint32_t readTempData(float *temp){
	uint8_t data[2];

	if(HAL_I2C_Mem_Read(&hi2c1, //Read data from temp sensor via i2c
			TEMPSENSOR_ADDR,
			TEMPSENSOR_TEMP_REG,
			I2C_MEMADD_SIZE_8BIT,
			data,
			2,
			100) != HAL_OK){
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
