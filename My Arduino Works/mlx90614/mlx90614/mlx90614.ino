//Sketch created by Raunak Kumar
#include <Wire.h>
#include <Adafruit_MLX90614.h>
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
void setup() {
  Serial.begin(9600);    
}
void loop() {
  long x;
  mlx.begin();        //Here the code gets compiled but the integer value of x isn't specifiied, I need the temperature measure by the sensor to be x.
  if(x<30){
      Serial.print("Temperature : ");
      Serial.print(mlx.readObjectTempC()); 
      Serial.println(" Celsius");
      
      Serial.println();
      delay(500);
    }
  else{
      Serial.print("No temperature recorded.");
    }
}
