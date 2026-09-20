const int clockpin = 4;//shift register clock
const int latchpin = 3;//output register clock
const int datapin = 2;//input

void setup()
{
	pinMode(clockpin,OUTPUT);
  	pinMode(latchpin,OUTPUT);
  	pinMode(datapin,OUTPUT);
}

void updateLights(byte reg2,byte reg1)
{
	digitalWrite(latchpin , LOW);
	shiftOut(datapin,clockpin,MSBFIRST,reg2);
  	shiftOut(datapin,clockpin,MSBFIRST,reg1);
  	digitalWrite(latchpin,HIGH);
}

void loop()
{
	updateLights(B00001001,B00100100);//Red reg2: E W  Green reg1: N S 
  	delay(10000);
  	
  	updateLights(B00011011,B00010010);//Red with Orange reg2: E  W  Orange reg1: N  S  
  	delay(5000);
  
  	updateLights(B00100100,B00001001);//Green reg2: E  W  Red reg1: N  S
   	delay(10000);
  
  	updateLights(B00010010,B00011011);//Orange reg2: E  W red with Orange reg1: N  S
   	delay(5000);
}
