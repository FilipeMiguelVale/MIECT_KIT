
/* Create a WiFi access point and provide a web server on it. */

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#define ledR 5
#define ledG 4



/* Set these to your desired credentials. */
const char *ssid = "IOT KIT";     //Change your Network name here
const char *password = "";        //Change your Password here

IPAddress local_IP(192,168,1,1);  //Change your local ip here
IPAddress gateway(192,168,1,10);
IPAddress subnet(255,255,255,0);

String webPage = "";              //webpage content
String inputString = "";          // a String to hold incoming data
bool stringComplete = false;      // whether the string is complete

ESP8266WebServer server(80);

int serial;
//function to read the serial data
void serialEvent() {
  while (serial = Serial.available()) {
    char inChar = (char)Serial.read();
    // if the number or chars to read is more than 1 we add the char to the sting, if not we assume that the string is complete
    serial>1 ? inputString += inChar : stringComplete = true;
  }
  if (stringComplete) {
    String option = inputString;
    Serial.println();
    if(option == "help"){
       Serial.println("To know your board ip write IP");
       Serial.println("To Know the number of devices connected Write NUM");
     }else{ 
      if(option == "IP"){
        Serial.printf("%s IP address = ", ssid);
        Serial.println(WiFi.softAPIP());
      }if(option == "NUM")
        Serial.printf("Stations connected to %s = %d\n", ssid,WiFi.softAPgetStationNum());
     }
     inputString = "";
     stringComplete = false;
   }        
}

void setup() {
  //Website HTML Code
  webPage += "<html>";
  webPage +="<head>";
  webPage += "<meta name=\"viewport\" content=\"initial-scale=1, maximum-scale=1\">";
  webPage +="<style>";
  webPage +=".content {";
  webPage +="  //max-width: 50px;";
  webPage +="  margin: auto;";
  webPage +="  background: white;";
  webPage +=" font-size: 2.5vw; ";
  webPage +="  padding: 10px; }";
  webPage +=".button {";
  webPage +="  background-color: #4CAF50;"; /* Green */
  webPage +="  border: none;";
  webPage +="  color: white;";
  webPage +="  padding: 16px 32px;";
  webPage +="  text-align: center;";
  webPage +="  text-decoration: none;";
  webPage +="  display: inline-block;";
  webPage +="  font-size: 16px;";
  webPage +="  margin: 4px 2px;";
  webPage +=" -webkit-transition-duration: 0.4s; ";/* Safari */
  webPage +="  transition-duration: 0.4s;";
  webPage +="  cursor: pointer; }";
  webPage +=".button1 {";
  webPage +="  background-color: white; ";
  webPage +="  color: black; ";
  webPage +="  border: 2px solid #000000 ;}";
  webPage +=" .button1:hover {";
  webPage +="   background-color: #000000;";
  webPage +="   color: white; }";
  webPage +=" .button2 {";
  webPage +=" background-color: white; ";
  webPage +="  color: black; ";
  webPage +="  border: 2px solid #4CAF50;}";
  webPage +=" .button2:hover {";
  webPage +="   background-color: #4CAF50;";
  webPage +="   color: white;}";
  webPage +=" </style>";
  webPage +=" </head>";
  webPage +=" <body>";
  webPage +=" <div class=\"content\">";
  webPage +="<h1>IOT KIT Web Server</h1>";
  webPage +="<h2>Led Vermelho <a href=\"socket1On\"><button class=\"button button2\">ON</button></a>&nbsp;<a href=\"socket1Off\"><button class=\"button button1\">OFF</button></a></h2>";
  webPage +="<h2>Led Verde <a href=\"socket2On\"><button class=\"button button2\">ON</button></a>&nbsp;<a href=\"socket2Off\"><button class=\"button button1\">OFF</button></a></h2></div>";
  webPage +=" </body>";
  webPage +=" </html>";

  // preparing GPIOs   
  pinMode(ledR, OUTPUT);   
  digitalWrite(ledR, HIGH);   
  pinMode(ledG, OUTPUT);   
  digitalWrite(ledG, HIGH);      
  delay(500);   
	Serial.begin(115200);
	Serial.println();
	Serial.println("Configuring access point...");     

  Serial.printf("Setting %s configuration ... ", ssid);
  Serial.println(WiFi.softAPConfig(local_IP, gateway, subnet) ? "Ready" : "Failed!");

  Serial.printf("Setting %s ... ", ssid);
  Serial.println(WiFi.softAP(ssid) ? "Ready" : "Failed!");

  Serial.printf("%s IP address = ", ssid);
  Serial.println(WiFi.softAPIP());

	server.on("/", [](){     
      server.send(200, "text/html", webPage);   }
      );   
  server.on("/socket1On", [](){     
    server.send(200, "text/html", webPage);     
    digitalWrite(ledR, HIGH);
    Serial.println("ledR ON");      
       });   
  server.on("/socket1Off", [](){     
     server.send(200, "text/html", webPage);     
     digitalWrite(ledR, LOW); 
     Serial.println("ledR OFF");     
         });
  server.on("/socket2On", [](){     
    server.send(200, "text/html", webPage);     
    digitalWrite(ledG, HIGH);
    Serial.println("ledG ON");      
       });   
  server.on("/socket2Off", [](){     
    server.send(200, "text/html", webPage);     
    digitalWrite(ledG, LOW); 
    Serial.println("ledG OFF");     
       });       
  server.begin();   
  Serial.println("HTTP server started"); }   

void loop() {
	server.handleClient();
  serialEvent();
  
}
