
#include <ESP8266WiFi.h>

WiFiServer server(80);

void setup()
{
  Serial.begin(9600);
  WiFi.disconnect();
  delay(3000);
   WiFi.begin("wifi","1234567890");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);

  }
  Serial.println("IP is - ");
  Serial.println((WiFi.localIP().toString()));
 // Serial.println((WiFi.gatewayIP().toString().c_str()));
  server.begin();

}


void loop()
{

    WiFiClient client = server.available();
    if (!client) { return; }
    while(!client.available()){  delay(1); }
    client.flush();
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println(analogRead(A0));
    client.println("</html>");
    client.stop();
    delay(1);

}
