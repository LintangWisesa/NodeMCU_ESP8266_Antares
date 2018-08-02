#

![antares](https://2.bp.blogspot.com/-mjZdSSb6uQI/W2KAgLTs9CI/AAAAAAAAETQ/MQsIGRDj_Y0-sIxB8XKyk_mz-g8okX-KwCLcBGAs/s400/Logo_Antares.png)

![simplinnovation](https://4.bp.blogspot.com/-f7YxPyqHAzY/WJ6VnkvE0SI/AAAAAAAADTQ/0tDQPTrVrtMAFT-q-1-3ktUQT5Il9FGdQCLcB/s350/simpLINnovation1a.png)

# ESP8266 NodeMCU & Antares

### **[Antares](https://antares.id/id/index.html)** offers an IoT platform specifically designed for any Internet of Things (IoT) projects. The platform is developed by Telkom Indonesia to support the integration of data from sensors and actuators on the internet. 

### This article will present a step by step example how to upload analog value of a potentiometer & DHT11 (temperature & humidity sensor) from ESP8266 NodeMCU to Antares IoT platform. Watch video below (or [click here](https://www.youtube.com/watch?v=Et821NVJNpk)) for its demonstration, then follow these instructions to start building your project with ESP8266 NodeMCU & Antares.

[![Video ESP8266 NodeMCU & Antares](https://img.youtube.com/vi/Et821NVJNpk/0.jpg)](https://www.youtube.com/watch?v=Et821NVJNpk)

#

### **1. What You Need** :gift:
To build this project, you need the following items:
- 1 ESP8266 NodeMCU board
- 1 breadboard
- 1 potentiometer
- 1 DHT11 sensor
- some jumper wires
- Arduino IDE ([download here](https://www.arduino.cc/en/Main/Software))
- Antares ESP8266 library ([download here](https://github.com/antaresdocumentation/antares-esp8266-http))

#

### **2. Schematics** :wrench::hammer:

Gather your parts then follow the schematics below.

![simplinnovation](https://4.bp.blogspot.com/-f7YxPyqHAzY/WJ6VnkvE0SI/AAAAAAAADTQ/0tDQPTrVrtMAFT-q-1-3ktUQT5Il9FGdQCLcB/s350/simpLINnovation1a.png)

#

### **3. Antares Setup** :heart:

- __Create Antares Application & Device__

  Signup/login to [Antares](https://antares.id/id/index.html) then go to __*Applications*__ menu, and click _**+Add Application_** button to create a project. Fill out the forms then click __*+Add Device*__ button to create your virtual device on Antares.

  > __*Please remember your application & device name, we'll use it later!*__
  
  ![antares application](https://1.bp.blogspot.com/--Mq83ylGf1M/W2KIF4xd3SI/AAAAAAAAETc/u3TDSzL8vZsaN6JuJCAr4z2RF7xv-XulwCLcBGAs/s1600/1.png)

- __Get Antares Access Key__

  Now go to your Antares *Account*, grab your access key, and you're __Done!__

  ![antares access key](https://3.bp.blogspot.com/-C6A84xr4yHA/W2KJzaB4c8I/AAAAAAAAETo/XTcu7ZEgk4glHeSpho3AGH9-qXPpPl2CACLcBGAs/s1600/2.png)

#

### **4. Arduino Sketch** :clipboard:

- First you need to install ESP8266 platform on Arduino IDE, follow these instructions: [click here](https://github.com/esp8266/Arduino). 
- Install manually Antares library for ESP8266 ([download here](https://github.com/antaresdocumentation/antares-esp8266-http)). Download, extract & copy its files to _**C:\\...\Documents\Arduino\libraries**_. In my case, I have to deactivate _WiFiClient library_ from *Antares library*. Simply open __*AntaresESPHTTP.h*__ file, then delete/comment this line:
  ```c++
  // #include <WiFiClient.h> 
  ```
- Open your Arduino IDE, then copy sketch below to your Arduino IDE. Make sure you have chosen the right option for **_Board_** and **_Port_** under **_Tools_** menu, then upload to your NodeMCU board.

  ```c++  
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

    Serial.println(antares.storeData(projectName, deviceName, dataName, dataValue, sizeData));
    delay(10000);
  } 
  ```

#

### **5. Have Fun!** :joy:
Now you can monitor your potentiometer & DHT11 sensor value every 10 seconds on Antares dashboard. You can also create some widgets under __Widgets__ menu to visualize the data. For more information about Antares, read its full documentation: [click here](https://antares.id/id/docs.html).

![antares dashboard](https://2.bp.blogspot.com/-UHdiZYRH42U/W2KLLke3l5I/AAAAAAAAET0/gHDYsJhJpsYIRb_CtwK47hkVWEvNe0dQwCLcBGAs/s1600/3.png)

#

#### Lintang Wisesa :love_letter: _lintangwisesa@ymail.com_

[Facebook](https://www.facebook.com/lintangbagus) | 
[Twitter](https://twitter.com/Lintang_Wisesa) |
[Google+](https://plus.google.com/u/0/+LintangWisesa1) |
[Youtube](https://www.youtube.com/user/lintangbagus) | 
:octocat: [GitHub](https://github.com/LintangWisesa) |
[Hackster](https://www.hackster.io/lintangwisesa)

