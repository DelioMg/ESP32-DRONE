# ESP32-Drone

![ESP32-Drone](https://github.com/username/esp32-drone/assets/esp32-drone-banner.jpg)

## Descrição

O ESP32-Drone é um projeto DIY (faça você mesmo) que utiliza um ESP32 para controlar um mini drone. O objetivo deste projeto é criar um drone simples e acessível que possa ser controlado por outro ESP32 configurado como um controle remoto com dois joysticks analógicos.

## Componentes do Projeto

- **Microcontrolador:** ESP32
- **Motores:** 4 motores 716 com hélices de 55mm
- **Bateria:** Bateria Li-Po adequada para o ESP32 e os motores
- **Transistores:** 4 transistores BC548 para controlar a alimentação dos motores
- **Controle:** Outro ESP32 com dois joysticks analógicos e uma bateria

## Diagrama de Circuito

![Diagrama de Circuito](https://github.com/username/esp32-drone/assets/esp32-drone-circuit.jpg)

## Funcionalidades

- **Controle de Voo:** O ESP32 principal controla os quatro motores do drone para permitir voo estável.
- **Comunicação Sem Fio:** Utiliza a capacidade de Wi-Fi do ESP32 para a transmissão de sinal entre o drone e o controle remoto.
- **Controle Remoto:** Um ESP32 configurado com dois joysticks analógicos para enviar comandos de voo ao drone.

## Instruções de Montagem

1. **Montagem do Drone:**
   - Conecte os quatro motores 716 ao ESP32 através dos transistores BC548.
   - Conecte a bateria ao ESP32 e aos motores, garantindo que a alimentação seja adequada.
   - Fixe as hélices de 55mm nos motores.

2. **Montagem do Controle Remoto:**
   - Conecte dois joysticks analógicos ao segundo ESP32.
   - Conecte a bateria ao ESP32 do controle remoto.

3. **Configuração de Software:**
   - Faça o download e configure o ambiente de desenvolvimento para ESP32 Arduino IDE.
   - Carregue o código para o ESP32 do drone e para o ESP32 do controle remoto.

## Como Usar

1. Ligue o drone e o controle remoto.
2. Utilize os joysticks no controle remoto para enviar comandos ao drone.
3. Experimente diferentes manobras e aproveite o voo do seu mini drone.

## Contribuições

Contribuições são bem-vindas! Sinta-se à vontade para abrir issues e enviar pull requests.

## Licença

Este projeto é licenciado sob a [MIT License](LICENSE).
