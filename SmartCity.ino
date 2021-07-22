// C++ code
//
//#################### GAS SENSOR VARIABLES #############
int gasSensorPin = A1;
int gasPiezo = 8;
int GREEN_LED = 4;
int BLUE_LED = 5;
int YELLOW_LED = 6;
int RED_LED = 7;

//#################### STATS VARIABLES #############
int hours = 0;
int minutes = 0;
int seconds = 0;

int previousSeconds = 0;
int previousMinutes = 0;
int previousHours = 0;



void setup(){
  Serial.begin(9600);
  
  //initializing time
  hours = getHours();
  minutes = getMinutes();
  seconds = getSeconds();
  
  previousHours = hours;
  previousMinutes = minutes;
  previousSeconds = seconds;
}

void loop()
{
  int gas = analogRead(gasSensorPin);
  
  gas = map(gas, 300, 750, 0, 100);
  //Serial.print("Smog Levels: ");
  //Serial.println(gas);
  checkGas(gas);
  
  
  
  checkTime();
  
  Serial.println(seconds);
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



//########################## UTILS ##########################
int getHours(){
  String hours = hours + __TIME__[0] + __TIME__[1];
  return hours.toInt();
}

int getMinutes(){
  String hours = hours + __TIME__[3] + __TIME__[4];
  return hours.toInt();
}

int getSeconds(){
  String hours = hours + __TIME__[6] + __TIME__[7];
  return hours.toInt();
}

void checkTime(){
  int localSeconds = millis()/1000 ;
  int localMinutes = ( millis()/1000 ) / 60;
  int localHours = ( ( millis()/1000 ) / 60 ) / 60;
  
  if(previousSeconds != localSeconds){
    previousSeconds = localSeconds;
  	seconds+=1;
    if(seconds >= 60){
    	seconds = 0;
    }
  }
  
  if(previousMinutes != localMinutes){
    previousMinutes = localMinutes;
  	minutes+=1;
    if(minutes >= 60){
    	minutes = 0;
    }
  }
  
  if(previousHours != localHours){
    previousHours = localHours;
  	hours+=1;
    if(hours == 24){
    	hours = 0;
    }
  }
  
  
}

/**
* This method should write to an SD card,
* but TinkerCad does not have such module.
* Instead i just print to screen the log.
*/
String writeLog(){
  int seconds = millis()/1000;
  Serial.println(seconds);
}





