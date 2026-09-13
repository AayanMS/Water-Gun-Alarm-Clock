#include <Arduino.h>

const int PUMP_PIN = 23;

void setup() {
  pinMode(PUMP_PIN, OUTPUT);
  digitalWrite(PUMP_PIN, LOW); // Ensure the pump is off initially

  Serial.begin(115200);
  delay(200);
}

void loop() { 
  if (Serial.available() > 0) {
    char input = Serial.read();
    if (input == ' ') {  // Space bar pressed
      
      Serial.println("Pump ON");
      //set time here in seconds for how long you want to sleep
      for (int i = 0; i < 28800; i++) { 
        delay(1000); // Wait for 1 second
        Serial.print("Time elapsed:  ");
        Serial.print(i + 1);
      }// Pump runs for 8 hours
        digitalWrite(PUMP_PIN, HIGH);
        delay(1000);
      
      digitalWrite(PUMP_PIN, LOW);
      Serial.println("Pump OFF");
    }
  }
}