#include "drivers.h"

extern int counter;

int (util_get_LSB)(uint16_t val, uint8_t *lsb)
{
	if (!lsb)
		return 1;
	*lsb = val & 0xFF;
	return 0;
}

int (util_get_MSB)(uint16_t val, uint8_t *msb)
{
	if (!msb)
		return 1;
	*msb = (val & 0xFF00) >> 8;
	return 0;
}

int (util_sys_inb)(int port, uint8_t *value)
{
	if (!value)
		return -1;
	
	uint32_t res;
	int retv = sys_inb(port, &res);
#ifdef LAB3
	counter++;
#endif
	*value = (uint8_t)res;
	return retv;
}