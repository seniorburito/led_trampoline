const int inPin = 35;
const int outPin = 53;

int jumpleverState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(inPin, INPUT);
  pinMode(outPin, OUTPUT);
  digitalWrite(outPin, HIGH);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(outPin, HIGH);
  jumpleverState = digitalRead(inPin);
  Serial.print(" lever = ");
  Serial.println(jumpleverState);

  delay(2);
}
