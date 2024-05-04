#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

// // Use pins 2 and 3 to communicate with DFPlayer Mini
// static const uint8_t PIN_MP3_TX = 13; // D7
// static const uint8_t PIN_MP3_RX = 12; // D6
SoftwareSerial softwareSerial(3, 2);
// Create the Player object
DFRobotDFPlayerMini player;

void setup() {

  Serial.begin(9600);
  softwareSerial.begin(9600);
  Serial.println();
  if (player.begin(softwareSerial, true, false)) {
    Serial.println("OK");

    // Set volume to maximum (0 to 30).
    player.volume(20);  //30 is very loud
  } else {
    Serial.println("Connecting to DFPlayer Mini failed!");
  }
  pinMode(4, INPUT);
  // Serial.print("player.readFileCounts");
  // Serial.print(player.readFileCounts());
  // Serial.print("   ");
  // Serial.print("player.readCurrentFileNumber");
  // Serial.print(player.readCurrentFileNumber());
  // Serial.print("   ");
  // Serial.print("player.readFileCountsInFolder");
  // Serial.print(player.readFileCountsInFolder(1));
  // Serial.print("   ");
  // Serial.print("player.");
  // Serial.print(player.);
  // Serial.print("   ");
  // Serial.print("player.readFileCounts");
  // Serial.print(player.readFileCounts());
  // Serial.print("   ");
  // Serial.print("player.readCurrentFileNumber");
  // Serial.print(player.readCurrentFileNumber());
  // Serial.print("   ");
  // Serial.print("player.readFileCountsInFolder");
  // Serial.print(player.readFileCountsInFolder(2));
  // Serial.print("   ");
  // Serial.print("player.readFolderCounts()");
  // Serial.print(player.readFolderCounts());
  // Serial.print("   ");

  // Serial.println(player.readState());                //read mp3 state
  // Serial.println(player.readVolume());               //read current volume
  // Serial.println(player.readEQ());                   //read EQ setting
  // Serial.println(player.readFileCounts());           //read all file counts in SD card
  // Serial.println(player.readCurrentFileNumber());    //read current play file number
  // Serial.println(player.readFileCountsInFolder(00));  //read file counts in folder SD:/03
}

bool fake = true;
int incomingByte = 0;
void loop() {
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    // say what you got:
    if (incomingByte != 10 && incomingByte != 13) {
      Serial.print("I received: ");
      Serial.println(incomingByte, DEC);
    }
  }

  // delay(3000);
  // player.playFolder(3, 1);
  // Serial.println("folder 1");
  // delay(3000);
  // delay(10000);

  bool value = digitalRead(4);
  if (value==true && fake==true) {
    Serial.println("play");
    fake=false;
    player.playFolder(01, 1);
  }

  if (incomingByte == 57) {
    player.pause();
    Serial.println("57");
  }
  if (incomingByte == 56) {
    Serial.println("56");
    player.reset();
  }
  if (incomingByte == 55) {
    Serial.println("55");
    player.stop();
  }
  if (incomingByte == 54) {
    Serial.println("54");
    player.sleep();
  }
  if (incomingByte == 53) {
    Serial.println("53");
    player.volume(0);
  }
  if (incomingByte == 52) {
    Serial.println("52");
    fake = true;
  }
  // player.start()


  delay(500);
  // // player.playFolder(00, 1);
  // delay(9000);
  // player.playFolder(3, 2);
  // Serial.println("folder 2");
  // delay(3000);
  // player.playFolder(3, 3);
  // Serial.println("folder 3");
  // delay(3000);
  // player.playFolder(3, 4);
  // Serial.println("folder 4");
  // delay(3000);
  // // // player.play(2);
  // player.stop();
}