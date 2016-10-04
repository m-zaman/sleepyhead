/*
 *  Simple HTTP get webclient test
 */
 
#include <ESP8266WiFi.h>
#include <ArduinoJson.h>
#include <string>

const char* ssid     = "CalVisitor";
const char* password = "";
 
const char* host = "sleepyhead.herokuapp.com";
 
void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(115200);
  delay(100);
 
  // We start by connecting to a WiFi network
 
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
 
int value = 0;
 
void loop() {
  delay(5000);
  ++value;
 
  Serial.print("connecting to ");
  Serial.println(host);

  // Send request and get a result.
  // Here I use a shortcut to get it in a string stream ...
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  
  // We now create a URI for the request
  String url = "/file.txt";
  Serial.print("Requesting URL: ");
  Serial.println(url);

  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  delay(500);

  String line = "";
  // Read all the lines of the reply from server and print them to Serial
  while(client.available()){
    line = client.readStringUntil('\r');
    //Serial.println("H");
    Serial.println(line);
    // Serial.println("B");
    
  }
  line.trim();
  Serial.println(line);
  if (line.equals("f")) {
  digitalWrite(13, HIGH);  // turn the LED on (HIGH is the voltage level)    }
    if (line.equals("t")) {
  digitalWrite(13, LOW);   // turn the LED off by making the voltage LOW
    }
  delay(5000);
  
  Serial.println("closing connection");
}
