#define s1 2
#define s2 3
#define s3 4
#define s4 5
#define s5 6

#define mL 8
#define mR 9

int outs[5];
void readSensors();
void printouts();

void setup() {
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);
  pinMode(s5, INPUT);

  pinMode(mL, OUTPUT);
  pinMode(mR, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  readSensors();
  
  if (outs[1] == 1 && outs[3] == 1){
    digitalWrite(mR, HIGH);
    digitalWrite(mL, HIGH);
  }
  else if (outs[1] == 0){
    digitalWrite(mR, HIGH);
    digitalWrite(mL, LOW);
  }
  else if (outs[3] == 0){
    digitalWrite(mR, LOW);
    digitalWrite(mL, HIGH);
  }
  else {
    digitalWrite(mR, LOW);
    digitalWrite(mL, LOW);
  }
  
}

// this initiate the outs[]
void readSensors() {
  outs[0] = digitalRead(s1);
  outs[1] = digitalRead(s2);
  outs[2] = digitalRead(s3);
  outs[3] = digitalRead(s4);
  outs[4] = digitalRead(s5);
}

void printouts(){
  for (int i = 0; i < 5; i++){
    Serial.print(outs[i]);
    Serial.print(" ");
  }
  Serial.println();
}
