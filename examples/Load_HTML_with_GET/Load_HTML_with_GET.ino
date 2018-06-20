/*
 * Simple Web Server with GET Requests
 *
 * A simple web server controllable with the URL on your IOT2000
 *
 * Created by Dominik Reichl
 */
#include <IOT2000.h>

//Enter a MAC address and IP address for your controller below
//The IP address will be dependent on your local network
byte mac[] = { 
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,200,1);

//Initialize the Ethernet server library
//with the IP address and port you want to use 
//(port 80 is default for HTTP)
EthernetClientIOT ECIOT;
EthernetServer server(80);
getRequest gr;

void setup() {
  userLEDSketchRunning();
  //Open serial communications
  Serial.begin(9600);

  //Start the Ethernet connection and the server
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("Server is at ");
  Serial.println(Ethernet.localIP());
}

void loop() {
  //Listen for incoming clients
  EthernetClient client = server.available();
  if (client) {
    Serial.println("New client");
    //An http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
				//Get the string
        gr.getString(c);
        
        //If you've gotten to the end of the line (received a newline
        //character) and the line is blank, the http request has ended,
        //so you can send a reply
        if (c == '\n' && currentLineIsBlank) {
          //Send a standard http response header
          ECIOT.standardHttpResponseHeader(client);
          //Load the file
          ECIOT.loadHTML("/sketch/full_example.html",client);
  
          break;
        }
        if (c == '\n') {
          //Start a new line
          currentLineIsBlank = true;
        } 
        else if (c != '\r') {
          //Got a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    //Give the web browser time to receive the data
    delay(1);
    //Close the connection:
    client.stop();
    Serial.println("Client disonnected");
    Serial.println();
		
		//Check for string
		if(gr.checkString("?on")){
        digitalWrite(13, HIGH);
        Serial.println("Led On");
    }
    if(gr.checkString("?off")){
        digitalWrite(13, LOW);
        Serial.println("Led Off");
    }
		//Clear string for next read
    gr.resetString();
  }
}

