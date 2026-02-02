// Define pin for LDR
const int inputPin = A0; 

// Define booleans
bool night;

void setup() {
  
  pinMode(inputPin, INPUT);
}

void loop() {

  night = isNight();
}

bool isNight() {
  
  if (analogRead(inputPin) < 200) {
    return true;
  } 
  return false;

}
