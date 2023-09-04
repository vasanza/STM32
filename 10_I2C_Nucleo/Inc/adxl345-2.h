
#ifndef ADXL345_2_H_
#define ADXL345_2_H_

#include <II2C.h>
#include <stdint.h>

#define DEVID_R				(0x00)
#define DEVICE_ADDR			(0x53)
#define DATA_FORMAT_R		(0x31)
#define POWER_CONTROL_R		(0x2D)
#define DATA_START_ADDR		(0x32)

#define FOUR_G				(0x01)
#define RESET				(0x00)
#define SET_MEASURE_B		(0x08)


void aadxl_init(void);
void aadxl_read_values(uint8_t reg);
void aadxl_write(uint8_t reg, char value);
void aadxl_read_address(uint8_t reg);










#endif /* ADXL345_2_H_ */
