// Copyright (c) Sandeep Mistry. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

// Import libraries (EddystoneBeacon depends on SPI)
#include <SPI.h>
#include <EddystoneBeacon.h>

// define pins (varies per shield/board), required, but are hard coded or ignored for some boards like those in the nrf5x core
//
//   Adafruit Bluefruit LE   10, 2, 9
//   Blend                    9, 8, UNUSED
//   Blend Micro              6, 7, 4
//   RBL BLE Shield           9, 8, UNUSED

#define EDDYSTONE_BEACON_REQ   6
#define EDDYSTONE_BEACON_RDY   7
#define EDDYSTONE_BEACON_RST   4

EddystoneBeacon eddystoneBeacon = EddystoneBeacon(EDDYSTONE_BEACON_REQ, EDDYSTONE_BEACON_RDY, EDDYSTONE_BEACON_RST);

void setup() {
  Serial.begin(9600);

  delay(1000);

  eddystoneBeacon.begin(-18, "http://www.example.com"); // power, URI

  Serial.println(F("Eddystone URL Beacon"));
}

void loop() {
  eddystoneBeacon.loop();
}
