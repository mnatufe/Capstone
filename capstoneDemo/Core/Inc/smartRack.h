#ifndef SMARTRACK_H
#define SMARTRACK_H

#include "main.h"
#include "cmsis_os.h"

typedef struct{
	float temp;
	uint32_t valid;
} tempData_t;

typedef uint8_t fanCommand_t;

uint32_t readTempData(float *temp);




#endif
