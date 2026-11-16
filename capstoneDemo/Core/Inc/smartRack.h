#ifndef SMARTRACK_H
#define SMARTRACK_H

#include "main.h"
#include "cmsis_os.h"

typedef uint8_t fanCommand_t;

#define TEMPSENSOR_ADDR (0x48 << 1)
#define TEMPSENSOR_TEMP_REG 0x00

extern osMutexId_t i2cMutexHandle;
extern I2C_HandleTypeDef hi2c1;


typedef struct{
	float temp;
	uint32_t valid;
} tempData_t;



uint32_t readTempData(float *temp);




#endif
