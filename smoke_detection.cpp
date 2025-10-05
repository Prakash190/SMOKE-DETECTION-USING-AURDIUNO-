// Smoke Detection System using MQ-2 Sensor

// Pin definitions
const int mq2Pin = A0;       // Analog pin for MQ-2 sensor
const int ledPin = 13;       // LED pin
const int buzzerPin = 12;    // Buzzer pin

// Threshold value for smoke detection
int smokeThreshold = 300;    // Adjust this according to your sensor calibration

void setup() {
  Serial.begin(9600);        // Initialize serial communication
  pinMode(ledPin, OUTPUT);   // Set LED as output
  pinMode(buzzerPin, OUTPUT);// Set Buzzer as output
}

void loop() {
  int smokeValue = analogRead(mq2Pin); // Read analog value from MQ-2
  Serial.print("Smoke Value: ");
  Serial.println(smokeValue);

  if(smokeValue > smokeThreshold) {
    // Smoke detected
    digitalWrite(ledPin, HIGH);   // Turn LED ON
    digitalWrite(buzzerPin, HIGH);// Turn Buzzer ON
    Serial.println("Warning! Smoke Detected!");
  } else {
    // No smoke
    digitalWrite(ledPin, LOW);    // Turn LED OFF
    digitalWrite(buzzerPin, LOW); // Turn Buzzer OFF
  }

  delay(1000); // Wait 1 second before next reading
}
