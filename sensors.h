#include <OneWire.h>
#include <DallasTemperature.h>
#include <DHT.h>

OneWire leatherWire(LEATHER_TEMP_PIN);
OneWire weatherWire(WEATHER_TEMP_PIN);

// Pass our oneWire reference to Dallas Temperature sensor   Передаем ссылку oneWire на датчик температуры в Далласе
DallasTemperature leatherSensor(&leatherWire);
DallasTemperature weatherSensor(&weatherWire);

DHT dht(DHT_PIN, DHT_TYPE);

void initSensors() {
	leatherSensor.begin();
	weatherSensor.begin();
	dht.begin();
}

String getSensorsData() {
	leatherSensor.requestTemperatures();
	weatherSensor.requestTemperatures();


	float leatherTemp = leatherSensor.getTempCByIndex(0);
	float weatherTemp = weatherSensor.getTempCByIndex(0);
	float humidity = dht.readHumidity();
	float dhtTemp = dht.readTemperature();

	return String(leatherTemp)+"|"+String(weatherTemp)+"|"+String(dhtTemp)+"|"+String(humidity);
}
