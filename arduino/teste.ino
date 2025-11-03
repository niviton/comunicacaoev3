// enviador_distancia_simples_softserial.ino
// Arduino (qualquer modelo) -> EV3 via pinos 2 (RX) e 3 (TX)
// Envia {"distancia":123} a cada 250 ms

#include <SoftwareSerial.h>

const byte RX_PIN = 2; // pino que recebe dados do EV3 (não usado aqui)
const byte TX_PIN = 3; // pino que envia dados para o EV3
const unsigned long INTERVALO_MS = 250;
const int VALOR_HIPOTETICO = 123;

SoftwareSerial ev3Serial(RX_PIN, TX_PIN); // RX, TX
unsigned long ultimoEnvio = 0;

void setup() {
  Serial.begin(115200);       // para debug via USB
  ev3Serial.begin(115200);    // comunicação com o EV3

  Serial.println("Arduino pronto — enviando JSON para o EV3");
}

void loop() {
  unsigned long agora = millis();
  if (agora - ultimoEnvio >= INTERVALO_MS) {
    ultimoEnvio = agora;

    // Envia JSON
    ev3Serial.print("{\"distancia\":");
    ev3Serial.print(VALOR_HIPOTETICO);
    ev3Serial.print("}\n");

    // Debug no serial monitor
    Serial.print("Enviado -> {\"distancia\":");
    Serial.print(VALOR_HIPOTETICO);
    Serial.println("}");
  }

  delay(1);
}
