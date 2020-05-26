
int Status= 12; //Pin D6
int sensor = 13; //Pin D7
int state = 0 ;
void setup() {
  // put your setup code here, to run once:

  pinMode(sensor, INPUT);   // declare sensor as input
  pinMode(Status, OUTPUT);  // declare LED as output
  
}

void loop() {
  // put your main code here, to run repeatedly:


   state = digitalRead(sensor);
    if(state == HIGH) {
      digitalWrite (Status, HIGH);
      Serial.println("Motion detected!");
      delay(300);
    }
    else {
      digitalWrite (Status, LOW);
      Serial.println("Motion absent!");
      delay(300);
      }
}
