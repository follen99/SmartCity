// C++ code
//
//#################### GAS SENSOR VARIABLES #############
int gasSensorPin = A1;
int gasPiezo = 8;
int GREEN_LED = 4;
int BLUE_LED = 5;
int YELLOW_LED = 6;
int RED_LED = 7;
int temperaturePin = A0;

//#################### STATS VARIABLES #############

//cars
long passedCars = 0;
long lastLog = millis();
long LOG_INTERVAL = 2000;

long hourMillis = 3600000;
long lastHourMillis = 0;
long lastHourPassedCars = 0;

long maximumCarsPerHour = 5;

//stoplight
int redLight = 10;
int greenLight = 9;


void setup(){
  Serial.begin(9600);
  lastHourMillis = millis();
  
  initLeds();	//init stoplightLeds
}

void loop()
{
  
 
  checkGas();
  
  checkCarPass();
  
  Serial.println(getTemperature());
  
  delay(250);
  
}

void checkGas(){
  int value = getAirQuality();
  
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
    if(millis() - lastLog > LOG_INTERVAL){

      if(millis() - lastHourMillis < hourMillis){
        lastHourPassedCars +=1;		//adding a car

        if(lastHourPassedCars > maximumCarsPerHour){
          //block the lane
          digitalWrite(redLight, HIGH);
          digitalWrite(greenLight, LOW);
        }else{
          initLeds();
        }
      }else{
        lastHourMillis = millis();
        lastHourPassedCars = 0;
        initLeds();
      }
      
      lastLog = millis();
      
      passedCars +=1;
      writeLog("A car passed");
    }
    
  }
}



//########################## UTILS #########################


/**
* This method should write to an SD card,
* but TinkerCad does not have such module.
* Instead i just print to screen the log.
*/
String writeLog(String action){
  
    
  Serial.print("{");
  
  //the timestamp of the event
  Serial.print("\"Timestamp\" : \"");
  Serial.print(millis());
  
  //the action that triggered the log
  Serial.print("\"; \"Action\" : \"");
  Serial.print(action);
  
  //the amount of cars that passed till this moment
  Serial.print("\"; \"passedCars\" : \"");
  Serial.print(passedCars);
  
  //the amount of cars that passed in the last hour
  Serial.print("\"; \"passedCarsLastHour\" : \"");
  Serial.print(lastHourPassedCars);
  
  //the air quality at this point in time
  Serial.print("\"; \"airQuality\" : \"");
  Serial.print(getAirQuality());
  Serial.print("%");

  //the air temperature 
  Serial.print("\"; \"airTemperature\" : \"");
  Serial.print(getTemperature());

  Serial.println("\"}");
  
}

int getAirQuality(){
  int gas = analogRead(gasSensorPin);
  return map(gas, 300, 750, 0, 100);
}

int getTemperature(){
  return map(((analogRead(temperaturePin) - 20) * 3.04), 0, 1023, -40, 125);
}

void initLeds(){
  digitalWrite(redLight, LOW);		//stoplight
  digitalWrite(greenLight, HIGH);	//stoplight
}




