
#include "AntaresESPHTTP.h"
#include "DHT.h"
#define DHTPIN D5
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);

#define SERVER "http://platform.antares.id"
#define PORT "8080"
#define ACCESSKEY "your_antares_access_key"
#define WIFISSID "your_wifi_name"
#define PASSWORD "your_wifi_password"

String projectName = "your_antares_application_name";
String deviceName = "your_antares_device_name";

Antares antares(ACCESSKEY,SERVER,PORT);

void setup() {
    Serial.begin(115200);
    pinMode(D5,INPUT); 
    antares.setDebug(true);
    antares.wifiConnection(WIFISSID,PASSWORD);
}

void loop() {

   String suhu = String(dht.readTemperature());
   String lembab = String(dht.readHumidity());
   String pot = String(analogRead(A0));
   
   int sizeData = 3;
   String dataName[sizeData],dataValue[sizeData];
   dataName[0]= "Suhu";
   dataName[1]= "Lembab";
   dataName[2]= "Pot";

   dataValue[0]= suhu;
   dataValue[1]= lembab;
   dataValue[2]= pot;

   Serial.println(antares.storeData(projectName, deviceName, dataName, dataValue,sizeData));
   delay(10000);
   
} 