#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "IoT_LV323";
const char* password = "@dm1nLV323";

WebServer server(80);

const int ledPin = 2;
bool ledState = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  
  // Conexión WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando al WiFi...");
  }
  Serial.println("Conectado al WiFi");
  
  // Definición de rutas del servidor web
  server.on("/", handleRoot);
  server.on("/on", handleOn);
  server.on("/off", handleOff);
  
  server.begin();
  Serial.println("Servidor HTTP iniciado");
}

void loop() {
  server.handleClient();
}

void handleRoot() {
  server.send(200, "text/html", "<h1>Control de LED</h1><p><a href=\"/on\"><button>Encender</button></a>&nbsp;<a href=\"/off\"><button>Apagar</button></a></p>");
}

void handleOff() {
  digitalWrite(ledPin, HIGH);
  ledState = HIGH;
  server.send(200, "text/html", "<h1>LED Encendido</h1><p><a href=\"/\">Regresar</a></p>");
}

void handleOn() {
  digitalWrite(ledPin, LOW);
  ledState = LOW;
  server.send(200, "text/html", "<h1>LED Apagado</h1><p><a href=\"/\">Regresar</a></p>");
}
