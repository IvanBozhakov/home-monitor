#ifndef MQ2_SENSOR_H
#define MQ2_SENSOR_H

#include <Arduino.h>

class MQ2Sensor {
  
  uint8_t digitalPin;
    uint8_t analogPin;
    
  public:
    MQ2Sensor(uint8_t dpin, uint8_t apin)
        : digitalPin(dpin), analogPin(apin) {}
    
    void begin() {
        pinMode(digitalPin, INPUT);
        pinMode(analogPin, INPUT);
        Serial.print("Wait for the MQ2 to warm up");
        delay(20000);
    }
    
    bool isGasDetected() {
       int gasState = digitalRead(digitalPin);
       return gasState == LOW;
    }

    int level() {
       return analogRead(analogPin);
    }
};

#endif 
