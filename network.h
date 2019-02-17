#include <WiFi.h>;
#include <AWS_IOT.h>;

AWS_IOT aws_iot;
int status = WL_IDLE_STATUS;

void connectToWifi(char* ssid, char* password) {
	Serial.print("Connecting to ");
	Serial.println(ssid);

	WiFi.begin(ssid, password);

	while (WiFi.status() != WL_CONNECTED) {
		delay(500);
		Serial.print(".");
	}

	if(aws_iot.connect(AWS_HOST_ADDRESS, AWS_CLIENT_ID) == 0) {
	    Serial.println("Connected to AWS");
	    delay(1000);
	} else {
	    Serial.println("AWS connection failed, Check the HOST Address");
	}
}

int sendData(const char * data) {
  char payload[sizeof(data)/sizeof(char*)];

  sprintf(payload, data);
  
    if (aws_iot.publish(AWS_TOPIC_NAME, payload) == 0) {        
        Serial.print("Publish Message:");
        Serial.println(data);
    } else {
        Serial.println("Publish failed");
    }
}
