#include <WiFi.h>
#include <WiFiUdp.h>

// Configurações de Wi-Fi
const char* ssid = "drone_network";
const char* password = "drone_password";

// Configurações de UDP
WiFiUDP udp;
const unsigned int localUdpPort = 4210;

// Pinos dos motores
const int motor1Pin = 16;
const int motor2Pin = 17;
const int motor3Pin = 18;
const int motor4Pin = 19;

// Variáveis para armazenar comandos
int motor1Speed = 0;
int motor2Speed = 0;
int motor3Speed = 0;
int motor4Speed = 0;

void setup() {
  Serial.begin(115200);
  
  // Inicializa os pinos dos motores como saídas
  pinMode(motor1Pin, OUTPUT);
  pinMode(motor2Pin, OUTPUT);
  pinMode(motor3Pin, OUTPUT);
  pinMode(motor4Pin, OUTPUT);

  // Conecta-se ao Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao Wi-Fi...");
  }
  Serial.println("Conectado ao Wi-Fi");

  // Inicia o UDP
  udp.begin(localUdpPort);
  Serial.printf("Agora escutando na porta UDP %d\n", localUdpPort);
}

void loop() {
  // Verifica se há dados disponíveis no buffer UDP
  int packetSize = udp.parsePacket();
  if (packetSize) {
    char incomingPacket[255];
    int len = udp.read(incomingPacket, 255);
    if (len > 0) {
      incomingPacket[len] = '\0';
    }

    // Converte os dados recebidos para velocidades dos motores
    sscanf(incomingPacket, "%d %d %d %d", &motor1Speed, &motor2Speed, &motor3Speed, &motor4Speed);

    // Define a velocidade dos motores
    analogWrite(motor1Pin, motor1Speed);
    analogWrite(motor2Pin, motor2Speed);
    analogWrite(motor3Pin, motor3Speed);
    analogWrite(motor4Pin, motor4Speed);
  }
}
