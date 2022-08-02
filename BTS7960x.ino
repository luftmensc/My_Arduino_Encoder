int R_PWM = 8;
int L_PWM = 9;
#define ENCA 2
#define ENCB 3
volatile float pos;
volatile int b;
void readEncoder();

unsigned long begin_time=0, last_time;

void setup() {
  
  pos = 0;
  Serial.begin(9600);
  pinMode(R_PWM, OUTPUT);
  pinMode(L_PWM, OUTPUT);
  pinMode(ENCA,INPUT);
  pinMode(ENCB,INPUT);
  attachInterrupt(digitalPinToInterrupt(ENCA),readEncoder,RISING);
}

void loop() {
  last_time=millis();
  
   analogWrite(R_PWM, 255);
   analogWrite(L_PWM, 0);
   
   if(last_time-begin_time>200){
    Serial.println((pos*180)/26410);
    begin_time=last_time;
   } 
}

void readEncoder(){
  b = digitalRead(ENCB);
  if(b){
    pos++;}
  else{
    pos--;
  }
}
