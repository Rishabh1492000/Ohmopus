
#include "HomeSpan.h"         // HomeSpan sketches always begin by including the HomeSpan library
#include "LED.h"
void setup() {                // Your HomeSpan code should be placed within the standard Arduino setup() function
 
  Serial.begin(115200);       // Start a serial connection so you can receive HomeSpan diagnostics and control the device using HomeSpan's Command-Line Interface (CLI)
  homeSpan.setPairingCode("11122333");
  homeSpan.begin(Category::Lighting,"HomeSpan LightBulb");   // initializes a HomeSpan device named "HomeSpan Lightbulb" with Category set to Lighting

  new SpanAccessory();                              // Begin by creating a new Accessory using SpanAccessory(), no arguments needed

    new Service::AccessoryInformation();            // HAP requires every Accessory to implement an AccessoryInformation Service
  
      new Characteristic::Identify();               // Create the required Identify Characteristic                                                      

    new LED(4);

  new SpanAccessory();                              // Begin by creating a new Accessory using SpanAccessory(), no arguments needed

    new Service::AccessoryInformation();            // HAP requires every Accessory to implement an AccessoryInformation Service
  
      new Characteristic::Identify();               // Create the required Identify Characteristic                                                      

    new LED(5);
    
} 

void loop(){  
  homeSpan.poll();         // run HomeSpan!
} 
