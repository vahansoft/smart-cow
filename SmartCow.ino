#include "config.h";
#include "network.h";
#include "storage.h";
#include "sensors.h";

int lastTick = 0;

void setup() {
	// Start serial communication for debugging
  Serial.begin(115200);

  connectToWifi(WIFI_SSID, WIFI_PASSWORD);

  initSDCard();

  initSensors();
}

void loop() {
	String data = getSensorsData();
	Serial.println(data);
  
//  writeInFile("./data.txt", data.c_str());

  sendData(data.c_str());

  if (millis() - lastTick > 10000) {
    lastTick = millis();

//    sendCollectedData(readFromFile("./data.txt"));
//
//    trushFile("./data.txt");
  }
}
