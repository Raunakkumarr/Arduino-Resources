//********ACCELEROMETER***********
//********Coded by Raunak Kumar***
const int xout = A0; //Defines Arduino Pin For Xout
const int yout = A1; //Defines Arduino Pin For Yout
const int zout = A2; //Defines Arduino Pin For Zoutint out1 = 0;       
int out1 = 0;   //Defines Output Pin1
int sout1 = 0;  //Scale output1 as Desired  
int out2 = 0;   //Defines Output Pin2 
int sout2= 0;   //Scale output2 as Desired
int out3 = 0;   //Defines Output Pin3
int sout3= 0;   //Scale output3 as Desired

void setup() 
{
   Serial.begin(9600);  //Starts Serial
}
void loop() 
  {

  analogReference(EXTERNAL);

  out1 = analogRead(xout);           

  sout1 = map(out1, 0, 1023, 0, 255); 

  delay(2);                    

  out2 = analogRead(yout);           

  sout2 = map(out2, 0, 1023, 0, 255);

  delay(2);                

  out3 = analogRead(zout);           

  sout3 = map(out3, 0, 1023, 0, 255); 

  Serial.print("X = " );                      

  Serial.print(out1);     

  Serial.print("\t output1 = ");     

  Serial.println(sout1);  

  Serial.print("Y = " );                      

  Serial.print(out2);     

  Serial.print("\t output2 = ");     

  Serial.println(sout2);  

  Serial.print("Z = " );                      

  Serial.print(out3);     

  Serial.print("\t output3 = ");     

  Serial.println(sout3);  

  delay(3000);                    

}
