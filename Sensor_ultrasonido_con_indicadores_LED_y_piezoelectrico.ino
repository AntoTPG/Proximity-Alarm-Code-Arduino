// Codigo programado por ANTONIO REQUENA QUESADA
int distancia = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  pinMode(11, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
  distancia = 0.01723 * readUltrasonicDistance(5, 3);
  Serial.println(distancia);
  if (distancia < 10) {
    digitalWrite(11, HIGH);
    tone(13, 570, 300); // play tone 60 (C5 = 523 Hz)
  } else {
    digitalWrite(11, LOW);
  }
  if (distancia > 10 && distancia <= 100) {
    digitalWrite(10, HIGH);
  } else {
    digitalWrite(10, LOW);
  }
  if (distancia > 100 && distancia <= 200) {
    digitalWrite(9, HIGH);
  } else {
    digitalWrite(9, LOW);
  }
  delay(10); 
}
