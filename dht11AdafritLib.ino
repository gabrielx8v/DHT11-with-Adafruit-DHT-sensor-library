#include <DHT.h>
 
#define DHTPIN A1 // define o pino de dados
#define DHTTYPE DHT11 // define qual versão do dht está sendo usada.
 
DHT dht(DHTPIN, DHTTYPE);

void setup() 
{
  Serial.begin(9600);
  Serial.println("DHT11 test!");
  dht.begin();
}
 
void loop() 
{
  // faz a leitura de humidade e temperatura e armazena respectivamente nas variaveis h e t.
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  // testa se retorno é valido, caso contrário algum erro ocorreu.
  if (isnan(t) || isnan(h)) 
  {
    Serial.println("falha para ler o DHT11");
  } 
  else
  {
    // caso o retorno for valido exibe as informações na tela
    Serial.print("Umidade: ");
    Serial.print(h);
    Serial.println(" %");
    Serial.print("Temperatura: ");
    Serial.print(t);
    Serial.println(" C");

  }
  // aguarda 3 segundos ate a proxima leitura.
  delay(3000);
}
