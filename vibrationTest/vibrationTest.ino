//defines the pin connections
int GroundPin= A0;
int sensePin= 1;
int LEDpin= 8;

//defines normal and threshold voltage levels
int normalReading= 0;
int threshold= 40;

//sets GroundPin and LEDPin as output pins, with GroundPin being set to LOW
void setup()
{
  pinMode(GroundPin, OUTPUT);
  digitalWrite(GroundPin, LOW);
  pinMode(LEDpin, OUTPUT);
  normalReading = calibrate();
  Serial.begin(9600); 
}

//if the reading is higher than the threshold value, then the LED is turned on
void loop()
{
  int reading= analogRead(sensePin);
  if (reading > normalReading + threshold){
    digitalWrite(LEDpin, HIGH);
  }
  else{
    digitalWrite(LEDpin, LOW);
  }
  Serial.print(reading);
  Serial.print("\n");
}

//this function returns the average reading of the sensePin when no large vibration is detected
int calibrate()
{
  int n= 100;
  long total=0;
  for (int i=0; i<n; i++) {
    total= total + analogRead(sensePin);
    delay(1);
  }
  return total/n;
}
