#ifdef SD_WRITE

#include <SPI.h>
#include <SD.h>

File myFile;

bool setupSD() {
  return SD.begin(4);
}

bool writeSD() {
  myFile = SD.open("test.txt", FILE_WRITE);
  if (myFile) {
    myFile.println("testing 1, 2, 3.");
    myFile.close();
  } else {
    Serial.println("error opening test.txt");
  }
}
#endif