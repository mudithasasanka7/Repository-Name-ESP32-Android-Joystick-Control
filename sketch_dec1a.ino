#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <ESP32Servo.h>

// Create Servo objects
Servo servo1;
Servo servo2;

// Define Servo Pins
const int servo1Pin = 25;
const int servo2Pin = 26;

// Define servo angles
int servo1Angle = 90; // Initial position for servo1
int servo2Angle = 90; // Initial position for servo2

// Initialize Server
AsyncWebServer server(80);

void setup() {
  // Start Serial Communication
  Serial.begin(115200);

  // Configure ESP32 as Access Point
  WiFi.softAP("ESP32_AP", "12345678");
  Serial.println("Access Point started!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());

  // Attach servos
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);

  // Move Servos to default position
  servo1.write(servo1Angle);
  servo2.write(servo2Angle);
  Serial.println("Servos initialized to default position (90°).");

  // Setup server routes
  server.on("/command", HTTP_GET, [](AsyncWebServerRequest *request) {
    if (request->hasParam("move")) {
      String move = request->getParam("move")->value();
      bool success = handleMovement(move);
      if (success) {
        request->send(200, "text/plain", "Command executed: " + move);
      } else {
        request->send(400, "text/plain", "Invalid command: " + move);
      }
    } else {
      request->send(400, "text/plain", "Missing 'move' parameter.");
    }
  });

  // Start server
  server.begin();
  Serial.println("Server started, waiting for commands...");
}

void loop() {
  // Nothing required in the loop
}

// Function to handle servo movement
bool handleMovement(String move) {
  if (move == "UP") {
    if (servo1Angle + 90 <= 180) {
      servo1Angle += 90;
      servo1.write(servo1Angle);
      Serial.println("Servo1 moved UP to " + String(servo1Angle) + "°.");
      return true;
    }
  } else if (move == "DOWN") {
    if (servo1Angle - 90 >= 0) {
      servo1Angle -= 90;
      servo1.write(servo1Angle);
      Serial.println("Servo1 moved DOWN to " + String(servo1Angle) + "°.");
      return true;
    }
  } else if (move == "LEFT") {
    if (servo2Angle - 90 >= 0) {
      servo2Angle -= 90;
      servo2.write(servo2Angle);
      Serial.println("Servo2 moved LEFT to " + String(servo2Angle) + "°.");
      return true;
    }
  } else if (move == "RIGHT") {
    if (servo2Angle + 90 <= 180) {
      servo2Angle += 90;
      servo2.write(servo2Angle);
      Serial.println("Servo2 moved RIGHT to " + String(servo2Angle) + "°.");
      return true;
    }
  }
  // Invalid movement or out of range
  Serial.println("Invalid or out-of-range command: " + move);
  return false;
}
