// Define pin for LDR
const int inputPin = A0; 

// Define pin for HCSR-04
const int echoPin = 10;
const int triggerPin = 9;

// Define booleans
bool night;
bool carFront;

void setup() {
  
  pinMode(inputPin, INPUT);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
}

void loop() {

  night = isNight();
  carFront = isCarFront();

  Serial.print("Night: ");Serial.println(night);
  Serial.print("carFront: ");Serial.println(carFront);

  delay(1000);

}

bool isCarFront() {

  if (getDistance() < 15) {
    return true;
  }
  return false;

}

float getDistance() {

  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  float duration = pulseIn(echoPin, HIGH);
  return (duration*.0343)/2;
  
}


bool isNight() {
  
  if (analogRead(inputPin) < 200) {
    return true;
  } 
  return false;
}
