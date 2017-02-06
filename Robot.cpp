#include "WPILib.h"

#define I2C_SLAVE_ADR 0x08 // ADXL345 I2C device address


/* The I2C color codes are as follows:
'r' = Set to red, 'g' = Set to green, 'b' = Set to blue, 'u' = Rainbow, 'c' = Rainbow cycle,
'h' = Chase, 'o' = Off

'r' = 0x72, 'g' = 0x67, 'b' = 0x62, 'u' = 0x75, 'c' = 0x63, 'h' = 0x68, 'o' = 0x6F

'o' -> 'r' -> 'g' -> 'b' -> 'u' -> 'c' -> 'h' -> ...
*/

int pixelPosition = 0;

I2C *I2Channel;
I2Channel = new I2C(I2C::kOnboard, I2C_SLAVE_ADR);


if(button1.pressed()){
	if(pixelPosition > 6){
		pixelPosition = 0;
	}
	else{
		pixelPosition += 1
	}
}

if(button2.pressed){
	if(pixelPosition<1){
		pixelPosition = 6;
	}
	else{
		pixelPosition -= 1;
	}
}
	
switch(pixelPosition()){
	case 0:
		I2CWrite(0x6F);
		break;
	case 1:
		I2CWrite(0x72);
		break;
	case 2:
		I2CWrite(0x67);
		break;
	case 3:
		I2CWrite(0x62);
		break;
	case 4:
		I2CWrite(0x75);
		break;
	case 5:
		I2CWrite(0x63);
		break;
	case 6:
		I2CWrite(0x68);
		break;
}

void I2CWrite(data){
	I2Channel->Write(I2C_SLAVE_ADR, data);
}