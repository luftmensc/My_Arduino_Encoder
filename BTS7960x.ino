int R_PWM = 8;
int L_PWM = 9;
#define ENCA 2 // YELLOW
#define ENCB 3// WHITE
volatile float pos;
//static int ar[2];
volatile int b;
void readEncoder();

unsigned long begin_time=0, last_time;

void setup() {
  // put your setup code here, to run once:
  pos = 0;
  Serial.begin(9600);
  pinMode(R_PWM, OUTPUT);
  pinMode(L_PWM, OUTPUT);
  pinMode(ENCA,INPUT);
  pinMode(ENCB,INPUT);
  attachInterrupt(digitalPinToInterrupt(ENCA),readEncoder,RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  last_time=millis();
  
   analogWrite(R_PWM, 250);
   analogWrite(L_PWM, 0);
   
   if(last_time-begin_time>100){
    Serial.println((pos*180)/26410);
    begin_time=last_time;
   }
   

 
  
}

void readEncoder(){
  //Serial.println(pos);
  b = digitalRead(ENCB);
  if(b){
    pos+=1;}
  else{
    pos-=1;
  }
  //Serial.println(pos);
}
