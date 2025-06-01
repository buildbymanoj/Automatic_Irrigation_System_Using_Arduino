const int soilSensorPin = A0;
const int relayPin = 7;
const int redLedPin = 12;
const int greenLedPin = 13;
const int buzzerPin = 8;

// Threshold values for moisture levels
const int lowThreshold = 300;
const int mediumThreshold = 600;

void setup() {
  pinMode(relayPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  digitalWrite(relayPin, LOW);
  digitalWrite(redLedPin, LOW);
  digitalWrite(greenLedPin, LOW);
  digitalWrite(buzzerPin, LOW);

  Serial.begin(9600);
}

void loop() {
  int moistureValue = analogRead(soilSensorPin);
  Serial.print("Soil Moisture Value: ");
  Serial.println(moistureValue);

  if (moistureValue < lowThreshold) {
    // Low moisture - water needed
    digitalWrite(relayPin, HIGH);    // Pump ON
    digitalWrite(redLedPin, HIGH);   // Red LED ON
    digitalWrite(greenLedPin, LOW);  // Green LED OFF
    digitalWrite(buzzerPin, HIGH);   // Buzzer ON
  }
  else if (moistureValue >= lowThreshold && moistureValue <= mediumThreshold) {
    // Medium moisture - caution
    digitalWrite(relayPin, LOW);     // Pump OFF
    digitalWrite(redLedPin, LOW);    // Red LED OFF
    digitalWrite(greenLedPin, HIGH); // Green LED ON
    digitalWrite(buzzerPin, LOW);    // Buzzer OFF
  }
  else {
    // High moisture - safe
    digitalWrite(relayPin, LOW);     // Pump OFF
    digitalWrite(redLedPin, LOW);    // Red LED OFF
    digitalWrite(greenLedPin, HIGH); // Green LED ON
    digitalWrite(buzzerPin, LOW);    // Buzzer OFF
  }

  delay(1000);
}
