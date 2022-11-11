
#include <ESP8266WiFi.h>
#include <Servo.h>

Servo servo;

/*********conexion****/
String ssid     = "Red_PrietoConza";
String password = "torbi2020gato";

byte cont = 0;
byte max_intentos = 50;

void setup() {
  // Inicia Serial
  Serial.begin(115200);
  Serial.println("\n");

  // Conexión WIFI
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED and cont < max_intentos) { //Cuenta hasta 50 si no se puede conectar lo cancela
    cont++;
    delay(500);
    Serial.print(".");
  }

Serial.println("");

  if (cont < max_intentos) {  //Si se conectó      
      Serial.println("********************************************");
      Serial.print("Conectado a la red WiFi: ");
      Serial.println(WiFi.SSID());
      Serial.print("IP: ");
      Serial.println(WiFi.localIP());
      Serial.print("macAdress: ");
      Serial.println(WiFi.macAddress());
      Serial.println("*********************************************");
  }
  else { //No se conectó
      Serial.println("------------------------------------");
      Serial.println("Error de conexion");
      Serial.println("------------------------------------");
  }
  /*********************************************************SERVO*********************************/
   
    servo.attach(5); //D1
    servo.write(0);

    delay(2000);
   
}

void loop() {
    servo.write(90);

    delay(1000);

    servo.write(0);

    delay(1000);

}
