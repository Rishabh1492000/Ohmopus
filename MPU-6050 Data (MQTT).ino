#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

Adafruit_MPU6050 mpu;

char out[128];

  StaticJsonDocument<200> doc;


 
const char* ssid = "Shunya Ekai";
const char* password = "SES@01622";
const char* mqttServer = "supro.shunyaekai.tech";
const int mqttPort = 1883;
//const char* mqttUser = "mqtt username";
//const char* mqttPassword = "mqtt password";
// 
WiFiClient espClient;
PubSubClient client(espClient);
 
void setup() {
 
Serial.begin(115200);

//  StaticJsonDocument<200> doc;

//  doc["sensor"] = "gps";
//  doc["time"] = 1351824120;

    

WiFi.begin(ssid, password);
 
while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.println("Connecting to WiFi..");
}
 
Serial.println("Connected to the WiFi network");
 
client.setServer(mqttServer, mqttPort);
 
while (!client.connected()) {
Serial.println("Connecting to MQTT...");
 
if (client.connect("ESP32Client" )) {
 
Serial.println("connected");
 
} else {
 
Serial.print("failed with state ");
Serial.print(client.state());
delay(2000);
 
}

}

//client.publish("esp32/esp32test", "Hello from ESP32learning 10");
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  
//   serializeJsonPretty(doc, out);

}
 
void loop() {

    sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

    doc["gyroscope X"] = g.gyro.x;
  doc["gyroscope Y"] = g.gyro.y;
  doc["gyroscope Z"] = g.gyro.z;

     serializeJsonPretty(doc, out);
//  
//  client.publish("esp32/esp32test", "Hello from ESP32learning 10");
//  delay(2000);
  client.publish("esp32/esp32test", out);
  delay(2000);
client.loop();
}
