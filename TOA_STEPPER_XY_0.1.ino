// Define pin connections 
const int x_dir_pin = 55;
const int x_step_pin = 54;
const int y_dir_pin = 61;
const int y_step_pin = 60;

const int nx_lim_pin = 63;
const int px_lim_pin = 59;
const int ny_lim_pin = 65;
const int py_lim_pin = 66;

const int nx_pin = 42;
const int px_pin = 64;
const int ny_pin = 40;
const int py_pin = 44;

  int px = 0;
  int nx = 0;
  int py = 0;
  int ny = 0;
  int nxLim = 0;
  int pxLim = 0;
  int nyLim = 0;
  int pyLim = 0;
    
void setup()
{
  // Declare pins
  
  //output to drivers
  pinMode(x_step_pin, OUTPUT);
  pinMode(x_dir_pin, OUTPUT);
  pinMode(y_step_pin, OUTPUT);
  pinMode(y_dir_pin, OUTPUT);
  //limit switches
  pinMode(nx_lim_pin, INPUT);
  pinMode(px_lim_pin, INPUT);
  pinMode(ny_lim_pin, INPUT);
  pinMode(py_lim_pin, INPUT);
  //directional inputs
  pinMode(nx_pin, INPUT);
  pinMode(px_pin, INPUT);
  pinMode(ny_pin, INPUT);
  pinMode(py_pin, INPUT);

}
void loop()
{
  
 px = digitalRead(px_pin);
 nx = digitalRead(nx_pin);
 py = digitalRead(py_pin);
 ny = digitalRead(ny_pin);
 
 pxLim = digitalRead(px_lim_pin);
 nxLim = digitalRead(nx_lim_pin);
 pyLim = digitalRead(py_lim_pin);
 nyLim = digitalRead(ny_lim_pin);

//Check if +x is pressed, check if limit switch is pressed, Spin motor if limit isn't hit
  for(int i = 0; px == HIGH && pxLim == LOW; px = digitalRead(px_pin)){
    


  // Set motor direction +x (clockwise spin)
  digitalWrite(x_dir_pin, HIGH);
 

    //Spin Motor
    digitalWrite(x_step_pin, HIGH);
    delayMicroseconds(2000);
    digitalWrite(x_step_pin, LOW);
    delayMicroseconds(2000);
    
    //read limit switch 
    pxLim = digitalRead(nx_lim_pin);
     
  }
  

 //Check if -x is pressed, check if limit switch is pressed, Spin motor if limit isn't hit
  for(int i = 0; nx == HIGH && nxLim == LOW; nx = digitalRead(nx_pin)){
    


  // Set motor direction -x (counterclockwise spin)
  digitalWrite(x_dir_pin, LOW);
 

    //Spin Motor
    digitalWrite(x_step_pin, HIGH);
    delayMicroseconds(2000);
    digitalWrite(x_step_pin, LOW);
    delayMicroseconds(2000);
    
    //read limit switch 
    nxLim = digitalRead(nx_lim_pin);
     
  }
  //Check if +y is pressed, check if limit switch is pressed, Spin motor if limit isn't hit
  for(int i = 0; py == HIGH && pyLim == LOW; py = digitalRead(py_pin)){
    


  // Set motor direction +y (clockwise spin)
  digitalWrite(y_dir_pin, HIGH);
 

    //Spin Motor
    digitalWrite(y_step_pin, HIGH);
    delayMicroseconds(2000);
    digitalWrite(y_step_pin, LOW);
    delayMicroseconds(2000);
    
    //read limit switch 
    pyLim = digitalRead(ny_lim_pin);
     
  }
  

 //Check if -y is pressed, check if limit switch is pressed, Spin motor if limit isn't hit
  for(int i = 0; ny == HIGH && nyLim == LOW; ny = digitalRead(ny_pin)){
    


  // Set motor direction -y (counterclockwise spin)
  digitalWrite(y_dir_pin, LOW);
 

    //Spin Motor
    digitalWrite(y_step_pin, HIGH);
    delayMicroseconds(2000);
    digitalWrite(y_step_pin, LOW);
    delayMicroseconds(2000);
    
    //read limit switch 
    nyLim = digitalRead(ny_lim_pin);
     
  }}
