#include "../../libraries/SPI/src/SPI.h"
#include <LoRa.h>

int counter = 0;

#define LORA_SCK         19
#define LORA_MOSI        12
#define LORA_MISO        34
#define LORA_DIO012      23
#define LORA_RST         13
#define LORA_SS          05

void setup() {
  LoRa.setPins(LORA_SS, LORA_RST, LORA_DIO012);
  SPI.begin(LORA_SCK, LORA_MISO, LORA_MOSI);
  Serial.begin(115200);
  while (!Serial);

  Serial.println("LoRa Sender");

  if (!LoRa.begin(915E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  Serial.print("Sending packet: ");
  Serial.println(counter);

  // send packet
  LoRa.beginPacket();
  LoRa.print("hello ENELTEC");
  LoRa.print(counter);
  LoRa.endPacket();

  counter++;

  delay(5000);
}
