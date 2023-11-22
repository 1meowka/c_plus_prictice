#include <WiFi.h>

char ssid[] = "ASOIU";  
char pass[] = "kaf.asoiu.48";
int status = WL_IDLE_STATUS; 

void setup() {
  Serial.begin(9600);	

  status = WiFi.begin(ssid, pass);
  if (status != WL_CONNECTED) {
    Serial.println("Не удалось подключиться к WiFi");
  }

  Serial.print("Подключение к:");
  printWiFiData();

}

void loop() {
  delay(10000);
  printWiFiData();
}

void printWiFiData() {

  while(Serial.available())
  {
    IPAddress ip = WiFi.localIP(); 
    
    Serial.print("Локальный IP адрес: ");
    Serial.println(ip);

    Serial.print("Host name(www.google.com): ");
    String MyHostName = Serial.readString();
    int pingResult = WiFi.ping(MyHostName, 5);

    Serial.print("Ping Result: ");
    if (pingResult >= 0) 
    {
      Serial.print("Done, time = ");
      Serial.print(pingResult);
      Serial.println(" ms ");
    }
    else 
    {
      Serial.print("Error");
    }
  }

} 
