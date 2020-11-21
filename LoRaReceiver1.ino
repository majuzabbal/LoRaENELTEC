#include "../../libraries/SPI/src/SPI.h"
#include <LoRa.h>

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

  Serial.println("LoRa Receiver");

  if (!LoRa.begin(915E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.print("Received packet '");

    // read packet
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    }

    // print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
  }
}
