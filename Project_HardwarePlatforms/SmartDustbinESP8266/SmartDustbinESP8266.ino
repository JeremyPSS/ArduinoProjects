#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>

#include "lib_ejec.h"



//servidor web
String protocol = "http://";
String host = "tachobasurainteligente.000webhostapp.com";
String resource = "/prueba_recibe.php";
int port=80;
String url = protocol + host + resource;


int contar = 0;

int numMax = 3; //this can be delete, it's just for test

int idtacho =0;

Serial.println(httpCode); //Print HTTP return code
Serial.println(respuesta); //print resquest response paylod



void setup() {
  MyWiFiConnect();
  
}

void loop() {
   method1();
   delay(5000);
}

/*Metodo para conectar con https*/
void method2(){
WiFiClient client;
  if(!client.connect(host,port)){ //se intenta conectar al servidor web
    Serial.println("Fallo al conectar");
    client.stop();
    return;
  }

  contar = random(0,1);
    
  String postData = "device_label="+String(contar)+"&temperature="+String(temp)+"&humidity=" + String(hume); //is the data to send
    
  
  client.print(String("POST ")+url+" HTTP/1.0\r\n"+
    "Host: " + host + "\r\n"+
    "Accept: *" +"/"+"*\r\n" +
    "Content-Length: " + postData.length() + "\r\n"+
    "Content-Type: application/w-www-form-urlencoded\r\n" +
    "\r\n" + postData);

  Serial.println("\nDatos enviados:(contar:" + String(contar)+")"+"\n");
  Serial.println("*********INICIA RESPUESTA**********");

  int nl=0;
  int code=-1;
  String respuesta="";
  
  while(client.connected())
  {
    if(client.available())
    {
      String line = client.readStringUntil('\n'); //prueba con \r
      nl++;
      if(nl==1)
      {
        int ini=line.indexOf(" ");
        int fin=line.indexOf(" ",ini +1);
        Serial.println("code = " + line.substring(ini+1, fin));
        code = line.substring(init+1, fin).toInt()M;;
      }else if(nl>1000){
        Serial.println(String(nl) + " *** " + line);
        respuesta = respuesta +line;
      }else{
        if(line.indexOf("Repuest") !=-1){
          nl=999;
        }
      }
    }
  }
  Serial.println("codigo= " + String(code));
  Serial.println("respuesta= " + respuesta);
  Serial.println("**********FIN RESPUESTA********");
  client.stop();

  //IdTacho: 5, contar: 1, fecha: 2022-08-13 18:02:03
    int ini=respuesta.indexOf(":");//busca los dos puntos
    int fin=respuesta.indexOf(",",ini+1);//busca la coma a partir de los dos puntos
    idtacho = respuesta.substring(ini+1,fin).toInt(); //obtiene el 5 de las posiciones anteriores

}

/*Metodo para conectar con http*/
void method1(){
  if(numMax>3){
    HTTPClient http;
    http.begin(url);
    http.addHeader("Content-Type", "application/x-wwww-form-urlencoded"; //Is the header where we indicate the content
  
    contar = random(0,1);
    
    String postData = "device_label="+String(contar)+"&temperature="+String(temp)+"&humidity=" + String(hume); //is the data to send
    
    int httpCode = http.POST(postData); //Send the resquest | we send the data
    String respuesta = http.getString(); //Get the response payload
    Serial.println(httpCode); //Print HTTP return code
    Serial.println(respuesta); //print resquest response paylod
  
    
    //IdTacho: 5, contar: 1, fecha: 2022-08-13 18:02:03
    int ini=respuesta.indexOf(":");//busca los dos puntos
    int fin=respuesta.indexOf(",",ini+1);//busca la coma a partir de los dos puntos
    idtacho = respuesta.substring(ini+1,fin).toInt(); //obtiene el 5 de las posiciones anteriores
    
    
    http.end(); //close conexcion

    numMax++;
    

    
  } 

}
