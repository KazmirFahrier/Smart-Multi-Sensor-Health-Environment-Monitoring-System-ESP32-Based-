#define MQ2pin 8 // Update this pin number if necessary according to your ESP32 setup

int sensorValue;  //variable to store sensor value

void setup() {
  Serial.begin(115200); // ESP32 supports higher baud rates, set to 115200 for faster serial communication
  pinMode(MQ2pin, INPUT); // Define MQ2pin as input
  Serial.println("MQ2 warming up!");
  delay(20000); // allow the MQ2 to warm up
}

void loop() {
  sensorValue = digitalRead(MQ2pin); // read digital output pin
  Serial.print("Digital Output: ");
  Serial.print(sensorValue);
  
  // Determine the status
  if (sensorValue) {
    Serial.println("  |  Smoke: -");
  } else {
    Serial.println("  |  Smoke: Detected!");
  }
  
  delay(2000); // wait 2s for next reading
}
