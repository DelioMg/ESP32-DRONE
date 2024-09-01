#include <WiFi.h>
#include <WiFiUdp.h>

// Configurações de Wi-Fi
const char* ssid = "drone_network";
const char* password = "drone_password";

// Configurações de UDP
WiFiUDP udp;
const char* remoteIp = "192.168.4.1"; // IP do drone
const unsigned int remoteUdpPort = 4210;

// Pinos dos joysticks
const int joystick1XPin = 34;
const int joystick1YPin = 35;
const int joystick2XPin = 32;
const int joystick2YPin = 33;

void setup() {
  Serial.begin(115200);

  // Conecta-se ao Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao Wi-Fi...");
  }
  Serial.println("Conectado ao Wi-Fi");

  // Inicia o UDP
  udp.begin(remoteUdpPort);
}

void loop() {
  // Lê os valores dos joysticks
  int joystick1X = analogRead(joystick1XPin);
  int joystick1Y = analogRead(joystick1YPin);
  int joystick2X = analogRead(joystick2XPin);
  int joystick2Y = analogRead(joystick2YPin);

  // Converte os valores dos joysticks para comandos de motor (0-255)
  int motor1Speed = map(joystick1Y, 0, 4095, 0, 255);
  int motor2Speed = map(joystick2Y, 0, 4095, 0, 255);
  int motor3Speed = map(joystick1X, 0, 4095, 0, 255);
  int motor4Speed = map(joystick2X, 0, 4095, 0, 255);

  // Envia os comandos via UDP
  char packetBuffer[50];
  sprintf(packetBuffer, "%d %d %d %d", motor1Speed, motor2Speed, motor3Speed, motor4Speed);
  udp.beginPacket(remoteIp, remoteUdpPort);
  udp.write(packetBuffer);
  udp.endPacket();

  delay(100); // Ajuste o atraso conforme necessário
}
