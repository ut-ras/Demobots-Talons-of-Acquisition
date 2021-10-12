// Define pin connections 
const int dirPin = 2;
const int stepPin = 3;
const int nxLimPin = 8;
const int pxLimPin = 9;
const int nxPin = 10;
const int pxPin = 11;
  int px = 0;
  int nx = 0;
  int nxLim = 0;
  int pxLim = 0;
void setup()
{
  // Declare pins
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  
  pinMode(nxLimPin, INPUT);
  pinMode(pxLimPin, INPUT);
  pinMode(nxPin, INPUT);
  pinMode(pxPin, INPUT);


}
void loop()
{
  
 px = digitalRead(pxPin);
 nx = digitalRead(nxPin);
 pxLim = digitalRead(pxLimPin);
 nxLim = digitalRead(nxLimPin);

//Check if +x is pressed, check if limit switch is pressed, Spin motor if limit isn't hit
  for(int i = 0; px == HIGH && pxLim == LOW; px = digitalRead(pxPin)){
    


  // Set motor direction +x (clockwise spin)
  digitalWrite(dirPin, HIGH);
 

    //Spin Motor
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(2000);
    
    //read limit switch 
    pxLim = digitalRead(pxLimPin);
     
  }
  

 //Check if -x is pressed, check if limit switch is pressed, Spin motor if limit isn't hit
  for(int i = 0; nx == HIGH && nxLim == LOW; nx = digitalRead(nxPin)){
    


  // Set motor direction -x (counterclockwise spin)
  digitalWrite(dirPin, LOW);
 

    //Spin Motor
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(2000);
    
    //read limit switch 
    nxLim = digitalRead(nxLimPin);
     
  }}
