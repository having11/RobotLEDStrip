#include "WPILib.h"

#define I2C_SLAVE_ADR 0x08 // ADXL345 I2C device address


/* The I2C color codes are as follows:
'r' = Set to red, 'g' = Set to green, 'b' = Set to blue, 'u' = Rainbow, 'c' = Rainbow cycle,
'h' = Chase, 'o' = Off

'r' = 114, 'g' = 103, 'b' = 98, 'u' = 117, 'c' = 99, 'h' = 104, 'o' = 111, 't' = 116, 'p' = 112

'o' -> 'r' -> 'g' -> 'b' -> 'u' -> 'c' -> 'h' -> 't' -> 'p' -> ...
*/

int pixelPosition = 0;

I2C *I2Channel;
I2Channel = new I2C(I2C::kOnboard, I2C_SLAVE_ADR);

relay.turnOn()

if(button1.pressed()){
	if(pixelPosition == 8){
		pixelPosition = 0;
	}
	else{
		pixelPosition += 1
	}
}

if(button2.pressed){
	if(pixelPosition == 0){
		pixelPosition = 8;
	}
	else{
		pixelPosition -= 1;
	}
}
	
switch(pixelPosition()){
	case 0:
		I2CWrite(111);
		break;
	case 1:
		I2CWrite(114);
		break;
	case 2:
		I2CWrite(103);
		break;
	case 3:
		I2CWrite(98);
		break;
	case 4:
		I2CWrite(117);
		break;
	case 5:
		I2CWrite(99);
		break;
	case 6:
		I2CWrite(104);
		break;
	case 7:
		I2CWrite(116);
		break;
	case 8:
		I2CWrite(112);
		break;
}

void I2CWrite(data){
	I2Channel->Write(I2C_SLAVE_ADR, data);
}
