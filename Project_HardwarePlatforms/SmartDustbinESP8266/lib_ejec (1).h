#include <ESP8266WiFi.h>
#include <strings_en.h>
#include <WiFiManager.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>

#include <Ticker.h>
//#define pinLedWifi  D4
const int pinLedWifi  = 4;

Ticker ticker_wifi;

void parpadeoLedWifi();
void MyWiFiConnect();
void printMessageWiFi();


void parpadeoLedWifi(){
  //cambiar de estado el LED
  byte estado = digitalRead(pinLedWifi);
  digitalWrite(pinLedWifi, !estado);  
}

void printMessageWiFi(){
  Serial.println("\n**************************************");
  Serial.print("Conectado a la red Wifi: ");
  Serial.println(WiFi.SSID());
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
  Serial.print("macAdress: ");
  Serial.println(WiFi.macAddress());
  Serial.println("****************************************");
  
}

void MyWiFiConnect(){
	Serial.begin(115200);//115200
  //Modo del pin
  pinMode(pinLedWifi, OUTPUT);
  //empezamos el temporizador que hara parpadear el LED
  ticker_wifi.attach(0.2, parpadeoLedWifi);

  //creamos una instancia d ela clase WiFiManager
  WiFiManager wifiManager;

  //descomentar para resetear configuracion
  //wifiManager.resetSettings();

  //creamos AP y portal cautivo y comprobamos si se establece la conexion
  if(!wifiManager.autoConnect("EJEC_ESP8266")){
    Serial.println("Fallo en la conexion (timeout)");
    ESP.reset();
    delay(1000);
  }

  printMessageWiFi();
  //eliminamos el temporizador
  ticker_wifi.detach();

  //apagamos el led
  digitalWrite(pinLedWifi, HIGH); //apagamos el LED
  
 
}
