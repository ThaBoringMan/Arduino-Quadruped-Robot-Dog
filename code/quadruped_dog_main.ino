/*----BANKAI----*/

#include <Wire.h>
#include "config.h"
#include "functions.h"


// Replace with your network credentials
const char* ssid = "piku";
const char* password = "123401234";



void setup() {
  Serial.begin(115200);
  pwm.begin();
  pwm.setPWMFreq(SERVO_FREQ);
  delay(10);
  seat();
  delay(20);

  moveServoSmoothly(CAM_SERVO_PIN, 90);
  delay(20);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected. IP address: ");
  Serial.println(WiFi.localIP());

  // Setup server routes
  server.on("/command", handleCommandRequest);

  // Start server
  server.begin();
  Serial.println("HTTP server started");
  if (!MDNS.begin("bankai")) {  // 👈 sets the device hostname to bankai.local
  Serial.println("Error starting mDNS");
  return;
}
Serial.println("mDNS responder started. Access at http://bankai.local");

}


void loop() {
  server.handleClient();
  static String inputString = "";

  while (Serial.available()) {
    char inChar = (char)Serial.read();

    if (inChar == '\n' || inChar == '\r') {
      if (inputString.length() > 0) {
        handleCommand(inputString);
        inputString = "";
      }
    } else {
      inputString += inChar;
    }
  }
}
