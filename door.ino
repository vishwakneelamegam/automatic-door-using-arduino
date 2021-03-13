#define m1 2
#define m2 3
#define irSensor 4
#define weightSensor 5

int flag = 0;
int delayTime = 1500;

void rotateClockwise(){
  digitalWrite(m1,HIGH);
  digitalWrite(m2,LOW);
}

void rotateAntiClockwise(){
  digitalWrite(m1,LOW);
  digitalWrite(m2,HIGH);
}

void stopRotating(){
  digitalWrite(m1,LOW);
  digitalWrite(m2,LOW);
}

void setup() {
  //Serial.begin(9600);
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(irSensor,INPUT);
  pinMode(weightSensor,INPUT);
}

void loop() {
  //Serial.println(digitalRead(weightSensor));
  if(digitalRead(irSensor) == HIGH && flag == 0){
      rotateClockwise();
      delay(delayTime);
      stopRotating();
      flag = 1;
    }
  if(digitalRead(irSensor) == LOW && flag == 1){
    rotateAntiClockwise();
    delay(delayTime);
    stopRotating();
    flag = 0;
    }
}
