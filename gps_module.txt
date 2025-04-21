// ESP32 has multiple hardware serial ports
// Use Serial1 for GPS, assign pins accordingly
#define RXD2 16  // GPIO16 as RX pin
#define TXD2 17  // GPIO17 as TX pin

void setup() {
  // Start the built-in Serial for communication with PC
  Serial.begin(115200);  
  // Start Serial1 for communication with GPS
  Serial1.begin(9600, SERIAL_8N1, RXD2, TXD2);  // 9600 baud, 8 data bits, 1 stop bit, no parity
}

void loop() {
  // Read from GPS and write to Serial monitor
  while (Serial1.available() > 0) {
    // Read the byte from GPS
    byte gpsData = Serial1.read();
    // Write the GPS data to the Serial monitor
    Serial.write(gpsData);
  }
}
