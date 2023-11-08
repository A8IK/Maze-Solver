//active

#define VCC2 3 //define pin 3 as VCC2
#define VCC3 9 //define pin 9 as VCC3

#define echoPinf A1
#define trigPinf A0

#define echoPinl A3 
#define trigPinl A2

#define echoPinr A5
#define trigPinr A4

int sonarf,sonarl,sonarr;

//Motor Control
int enA = 10;
int in1 = 5;
int in2 = 4;
// Motor B connections
int enB = 11;
int in3 = 8;
int in4 = 7;

int rightspeed=80;
int leftspeed=80;

// defines variables
long duration; 
int distance; 

void setup() {
  pinMode(VCC2, OUTPUT); //define a digital pin as output
  digitalWrite(VCC2, HIGH); //set the above pin as HIGH so it acts as 5V
  pinMode(VCC3, OUTPUT); //define a digital pin as output
  digitalWrite(VCC3, HIGH); //set the above pin as HIGH so it acts as 5V


  pinMode(trigPinf, OUTPUT); 
  pinMode(echoPinf, INPUT); 

  pinMode(trigPinl, OUTPUT); 
  pinMode(echoPinl, INPUT); 

    pinMode(trigPinr, OUTPUT); 
  pinMode(echoPinr, INPUT); 

  
  Serial.begin(9600);

}
void loop() {

  sonarf = sonarF();
  sonarl= sonarL();
  sonarr = sonarR();
  
  Serial.print("Forward: ");Serial.print(sonarf);Serial.print(" cm   ");Serial.print("Left: ");Serial.print(sonarl);Serial.print(" cm   ");Serial.print("Right: ");Serial.print(sonarr);Serial.println(" cm   ");
  

  motorF();

  if(sonarf<25 && sonarf>1 ){
    motorO();

    
    if(sonarr>sonarl){
      motorR();
    } else if(sonarl>sonarr){
      motorL();
    }
    
  }
  sonarf = sonarF();
  sonarl= sonarL();
  
  
  if(sonarl<5){
  analogWrite(enA, 80);
  analogWrite(enB, 80);
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(50);
  }
  sonarr = sonarR();
  if(sonarr<5){
  analogWrite(enA, 80);
  analogWrite(enB, 80);
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(50);
  }
//sonarf = sonarF();
//   if(sonarf=1){
//      analogWrite(enA, 80);
//    analogWrite(enB, 80);
//  
//  digitalWrite(in1, HIGH);
//  digitalWrite(in2, LOW);
//  digitalWrite(in3, HIGH);
//  digitalWrite(in4, LOW);
//   }


}
  //motorF();
  //speedControl();
 

void motorF(){
  analogWrite(enA, 80);
  analogWrite(enB, 80);
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

}
void motorR(){
  analogWrite(enA, rightspeed);
  analogWrite(enB, leftspeed);
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(100);
  
}
void motorfpwm(){
  analogWrite(enA, rightspeed);
  analogWrite(enB, leftspeed);
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(80);
  
}
void motorL(){
  analogWrite(enA, rightspeed);
  analogWrite(enB, leftspeed);
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  
  delay(80);
  
}
void motorO(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, HIGH);
  
}

void speedControl() {
  // Turn on motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  
  // Accelerate from zero to maximum speed
  for (int i = 0; i < 256; i++) {
    analogWrite(enA, i);
    analogWrite(enB, i);
    delay(20);
  }
}
int sonarF(){
  digitalWrite(trigPinf, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinf, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinf, LOW);
  duration = pulseIn(echoPinf, HIGH);
  distance = duration * 0.034 / 2;
  return distance;
}

int sonarL(){
  digitalWrite(trigPinl, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinl, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinl, LOW);
  duration = pulseIn(echoPinl, HIGH);
  distance = duration * 0.034 / 2;
  return distance;
}

int sonarR(){
  digitalWrite(trigPinr, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinr, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinr, LOW);
  duration = pulseIn(echoPinr, HIGH);
  distance = duration * 0.034 / 2;
  return distance;
}

