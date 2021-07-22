// C++ code
//
//#################### GAS SENSOR VARIABLES #############
int gasSensorPin = A1;
int gasPiezo = 8;
int GREEN_LED = 4;
int BLUE_LED = 5;
int YELLOW_LED = 6;
int RED_LED = 7;




void setup(){
  Serial.begin(9600);
}

void loop()
{
  int gas = analogRead(gasSensorPin);
  
  gas = map(gas, 300, 750, 0, 100);
  //Serial.print("Smog Levels: ");
  //Serial.println(gas);
  checkGas(gas);
  
  
  delay(250);
  
}

void checkGas(int value){
  if(value > 80){
  	tone(gasPiezo, 460); // play tone 59 (B4 = 494 Hz)
    delay(1000);
  }
  noTone(gasPiezo);
  
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(BLUE_LED, value >= 30 ? HIGH : LOW);
  digitalWrite(YELLOW_LED, value >= 50 ? HIGH : LOW);
  digitalWrite(RED_LED, value >= 80 ? HIGH : LOW);
}

void checkCarPass(){
  int carSensor = analogRead(A2);
  //Serial.print("Sensor: ");
  //Serial.println(sensor);
  
  /** 	if the value is greater than 0
  		it means that a car has passed.
  */
  if(carSensor > 0){
  	
  }
}
