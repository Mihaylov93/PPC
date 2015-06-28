/*
0 - zero humidity
900 - In water, max value
*/

#define moisture_input 0 //Analog Input
#define divider_top 2
#define divider_bottom 3

int SoilMoisture(){
  int reading;

  // drive a current through the divider in one direction
  digitalWrite(divider_top,HIGH);
  digitalWrite(divider_bottom,LOW);
  
  delay(1000); // wait a moment for capacitance effects to settle

  reading=analogRead(moisture_input);

  // reverse the current
  digitalWrite(divider_top,LOW);
  digitalWrite(divider_bottom,HIGH);

  delay(1000);// give as much time in 'reverse as in 'forward'

  // stop the current
  digitalWrite(divider_bottom,LOW);

  return reading;

}

void setup() {
  // set driver pins to outputs
  pinMode(divider_top,OUTPUT);
  pinMode(divider_bottom,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.print(F("Soil Humidity: "));
  Serial.print (1023 - SoilMoisture()+ "\n");

}
