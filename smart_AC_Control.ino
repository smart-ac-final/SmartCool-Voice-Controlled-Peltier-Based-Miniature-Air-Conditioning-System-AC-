#define BLYNK_TEMPLATE_ID "TMPL31B4jh5C2"
#define BLYNK_TEMPLATE_NAME "Google Assistent"
#define BLYNK_AUTH_TOKEN "gs0vnRmxRO8D0foPqY22sQikLBP0c_6L"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
#include <SoftwareSerial.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Tulsidas";
char pass[] = "123456787";

//---------------- DHT11 ----------------
#define DHTPIN D2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

//---------------- Peltier ----------------
#define PELTIER D7

//---------------- Bluetooth ----------------
#define BT_RX D5
#define BT_TX D8
SoftwareSerial BT(BT_RX, BT_TX);

//--------------- Temperature Limits ---------------
const float ON_TEMP = 30.0;
const float OFF_TEMP = 27.0;

bool autoMode = true;
bool peltierState = false;

//--------------- Blynk Control ----------------
BLYNK_WRITE(V1)
{
  int value = param.asInt();

  autoMode = false;

  if(value == 1)
    peltierState = true;
  else
    peltierState = false;
}

void setup()
{
  Serial.begin(9600);
  BT.begin(9600);

  pinMode(PELTIER, OUTPUT);
  digitalWrite(PELTIER, LOW);

  dht.begin();

  Blynk.begin(auth, ssid, pass);

  Serial.println("=================================");
  Serial.println(" SMART COOLING SYSTEM ");
  Serial.println(" Blynk + Bluetooth + Auto Mode ");
  Serial.println("=================================");
}

void loop()
{
  Blynk.run();

  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  if(isnan(temp) || isnan(hum))
  {
    Serial.println("DHT11 Error");
    delay(1000);
    return;
  }

  // Send data to Blynk
  Blynk.virtualWrite(V2, temp);
  Blynk.virtualWrite(V3, hum);

  // Bluetooth Commands
  if(BT.available())
  {
    char cmd = BT.read();

    switch(cmd)
    {
      case 'A':
        autoMode = true;
        break;

      case 'M':
        autoMode = false;
        break;

      case '1':
        autoMode = false;
        peltierState = true;
        break;

      case '0':
        autoMode = false;
        peltierState = false;
        break;
    }
  }

  // Automatic Control
  if(autoMode)
  {
    if(temp >= ON_TEMP)
      peltierState = true;

    if(temp <= OFF_TEMP)
      peltierState = false;
  }

  digitalWrite(PELTIER, peltierState);

  Serial.println("----------------------------");
  Serial.print("Temperature : ");
  Serial.print(temp);
  Serial.println(" C");

  Serial.print("Humidity    : ");
  Serial.print(hum);
  Serial.println(" %");

  Serial.print("Mode        : ");
  Serial.println(autoMode ? "AUTO" : "MANUAL");

  Serial.print("Peltier     : ");
  Serial.println(peltierState ? "ON" : "OFF");

  delay(2000);
}