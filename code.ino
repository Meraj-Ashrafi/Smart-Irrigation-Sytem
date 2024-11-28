#define BLYNK_TEMPLATE_ID "TMPL3v3Pe2I0n"
#define BLYNK_TEMPLATE_NAME "Smart Irrigation System"
#define BLYNK_AUTH_TOKEN "l2yXzH5HUAyOPFG4bFXAvrtmAGyfem5S"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Replace with your network credentials
const char* ssid = "OPPO F21 PRO";
const char* password = "1se8takhai";

// Blynk template and authentication


// Pin where the sensor is connected
#define SOIL_MOISTURE_PIN A0
#define led D4
int moistureThreshold = 500;
bool irrigationAlertSent = false; // Flag to track if notification was already sent

void setup() {
  // Start serial communication
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to WiFi");


  // Initialize Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password);
}

void loop() {
  // Read soil moisture value
  int sensorValue = analogRead(SOIL_MOISTURE_PIN);
  
  // Print sensor value to Serial Monitor
  Serial.print("Soil Moisture Value: ");
  Serial.println(sensorValue);

  // Send soil moisture value to Blynk
  Blynk.virtualWrite(V0, sensorValue);  // For Gauge

  if (sensorValue > moistureThreshold) {
    // Soil is dry - turn on LED and trigger notification on V2
    Serial.println("Soil is dry - LED ON");
    if (!irrigationAlertSent) {
      digitalWrite(led, HIGH);
      Blynk.logEvent("alert");
      irrigationAlertSent = true; // Mark notification as sent
    }
  } else {
    // Soil is moist - turn off LED
    digitalWrite(led, LOW);
    Serial.println("Soil is moist - LED OFF");
    irrigationAlertSent = false; // Reset notification flag
  }
  

  // Run Blynk
  Blynk.run();

  // Delay before next reading
  delay(2000);
}