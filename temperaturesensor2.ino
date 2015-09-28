int tmp102Address = 0x48;

void setup(){
  Serial.begin(9600);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  digitalWrite(D2,HIGH);
  digitalWrite(D3,HIGH);
  digitalWrite(D4,HIGH);
  Wire.begin();
}

void loop(){

  float celsius = getTemperature();
  //Serial.print("Celsius: ");
  //Serial.println(celsius);


  float fahrenheit = (1.8 * celsius) + 32;  
  //Serial.print("Fahrenheit: ");
  Serial.println(fahrenheit);

  delay(2000); //just here to slow down the output. You can remove this
  if (fahrenheit >= 79)
    {
      digitalWrite(D2, LOW);
      digitalWrite(D3, HIGH);
      digitalWrite(D4, HIGH);
      //Serial.println("Its hot!");
  }
  if ((fahrenheit < 79) && (fahrenheit >= 75)){
        digitalWrite(D2, LOW);
        digitalWrite(D3, LOW);
        digitalWrite(D4, HIGH);
        //Serial.println("Its warm");
  }
  if ((fahrenheit < 75) && (fahrenheit >= 70)){
        digitalWrite(D2, HIGH);
        digitalWrite(D3, LOW);
        digitalWrite(D4, HIGH);
        //Serial.println("Its perfect");
  }
  if ((fahrenheit < 70) && (fahrenheit >= 65)){
        digitalWrite(D2, HIGH);
        digitalWrite(D3, LOW);
        digitalWrite(D4, LOW);
        //Serial.println("Its a little chill");
  }
  if (fahrenheit < 65){
        digitalWrite(D2, HIGH);
        digitalWrite(D3, HIGH);
        digitalWrite(D4, LOW);
        //Serial.println("Its cold!");
  }
}

float getTemperature(){
  Wire.requestFrom(tmp102Address,2); 

  byte MSB = Wire.read();
  byte LSB = Wire.read();

  //it's a 12bit int, using two's compliment for negative
  int TemperatureSum = ((MSB << 8) | LSB) >> 4; 

  float celsius = TemperatureSum*0.0625;
  return celsius;
}
