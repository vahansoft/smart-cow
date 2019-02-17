#include <SD.h>;

void initSDCard() {
  // Initialize SD card
  SD.begin(SD_PIN);

  if(!SD.begin(SD_PIN)) {
    Serial.println("Card Mount Failed");
    return;
  }
  uint8_t cardType = SD.cardType();
  
  if(cardType == CARD_NONE) {
    Serial.println("No SD card attached");
    return;
  }
  
  Serial.println("Initializing SD card...");
  
  if (!SD.begin(SD_PIN)) {
    Serial.println("ERROR - SD card initialization failed!");
    return;    // init failed
  }
}

void writeInFile(const char * path, const char * message) {
  Serial.printf("Appending to file: %s\n", path);
 
  File file = SD.open(path, FILE_APPEND);
  
  if(!file) {
    file = SD.open(path, FILE_WRITE);
  }

  if (!file) {
    Serial.println("Failed to open file for appending");
    return;
  }

  if(file.print(message)) {
    Serial.println("Message appended");
  } else {
    Serial.println("Append failed");
  }
  file.close();
}
