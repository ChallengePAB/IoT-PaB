#include <WiFi.h>
#include <HTTPClient.h>
#include <DHT.h> 

#define DHTPIN 15    
#define DHTTYPE DHT22 
DHT dht(DHTPIN, DHTTYPE);

const char* ssid = "Wokwi-GUEST";
const char* password = "";

String serverName = "https://site-pab.onrender.com/api/clima/update";

unsigned long ultimaLeitura = 0;
const unsigned long intervalo = 10000; 

void setup() {
  Serial.begin(115200);
  Serial.println("\n=== IOT: ESP32 + DHT22 -> Render ===");

  // Inicializa o sensor DHT
  dht.begin();

  // Conexão WiFi
  Serial.print("Conectando ao WiFi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\n✅ WiFi conectado!");
}

void loop() {
  unsigned long agora = millis();

  if (agora - ultimaLeitura >= intervalo) {
    ultimaLeitura = agora;

    float temperatura = dht.readTemperature();
    float umidade = dht.readHumidity();

    if (isnan(temperatura) || isnan(umidade)) {
      Serial.println("❌ Falha ao ler do sensor DHT!");
      return; // Tenta novamente no próximo ciclo
    }


    String json = "{\"temperatura\": " + String(temperatura, 1) +
                  ", \"umidade\": " + String(umidade, 1) + "}";

    Serial.println("\n====================");
    Serial.print("Enviando leitura REAL para: ");
    Serial.println(serverName);
    Serial.println("Dados: " + json);

    if (WiFi.status() == WL_CONNECTED) {
      HTTPClient http;
      http.begin(serverName.c_str());
      http.addHeader("Content-Type", "application/json");

      int codigo = http.POST(json);

      if (codigo > 0) {
        Serial.print("✅ Sucesso! Código HTTP: ");
        Serial.println(codigo);
        String resposta = http.getString(); 
        Serial.println("Resposta: " + resposta);
      } else {
        Serial.print("❌ Erro no envio HTTP: ");
        Serial.println(http.errorToString(codigo).c_str());
      }
      http.end();
    } else {
      Serial.println("⚠️ WiFi desconectado");
    }
  }
}