#ifndef SENSORS_DTO_H
#define SENSORS_DTO_H

#include <Arduino.h>
#include <ArduinoJson.h>

class SensorsDto {
  private:
    float temperature;
    float humidity;
    bool isGasDetected;
    int gasLevel;
    bool isMotionDetected;

  public:
    SensorsDto() {
      temperature = 0.0;
      humidity = 0.0;
      isGasDetected = false;
      gasLevel = 0;
      isMotionDetected = false;
    }

    void setTemperature(float temp) {
      temperature = temp;
    }

    void setHumidity(float hum) {
      humidity = hum;
    }

    void setIsGasDetected(bool gasDetected) {
      isGasDetected = gasDetected;
    }

    void setGasLevel(int level) {
      gasLevel = level;
    }

    void setIsMotionDetected(bool motionDetected) {
      isMotionDetected = motionDetected;
    }

    String toJson() {
      JsonDocument doc;
      doc["temperature"] = temperature;
      doc["humidity"] = humidity;
      doc["isGasDetected"] = isGasDetected;
      doc["gasLevel"] = gasLevel;
      doc["isMotionDetected"] = isMotionDetected;
      
      String jsonString;
      serializeJson(doc, jsonString);
      return jsonString;
  }
};

#endif
