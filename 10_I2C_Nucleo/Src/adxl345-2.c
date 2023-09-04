#include "adxl345-2.h"


char data;
 uint8_t data_rec[6];

void aadxl_read_address(uint8_t reg)
 {
	 II2C1_byteRead(DEVICE_ADDR, reg, &data);

 }
void aadxl_write (uint8_t reg, char value)
 {
	 char data[1];
	 data[0] = value;

	 II2C1_burstWrite(DEVICE_ADDR, reg, 1, data);

 }
void aadxl_read_values(uint8_t reg)
{
	II2C1_burstRead(DEVICE_ADDR, reg, 6,(char *) data_rec);
}

void aadxl_init(void)
{
	//enable i2c
	II2C1_init();
	//read  the DEVID. this should return 0XE5
	aadxl_read_address(DEVID_R);
	//Set data format range to +-4g
	aadxl_write(DATA_FORMAT_R, FOUR_G);
	//reset all bits
	aadxl_write(POWER_CONTROL_R, RESET);
	// configure power control  mesure bit
	aadxl_write(POWER_CONTROL_R, SET_MEASURE_B);
}
