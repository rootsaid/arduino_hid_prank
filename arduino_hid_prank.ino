//HID or Human Interface Devices are Devices that takes input from human and pass it on to the device connected to it. 
//HID devices includes keyboard, joystick, mouse, touch pad, graphic tablet etc. 
//There is a Library available in arduino which enables MKR1000 to acts as a keyboard and send keystrokes to PC. 
//Here, we will be using an Arduino Board, Arduino MKR1000 to integrate wireless network connectivity and perform HID Pranks
//http://bit.ly/arduino-hid --Here you will find so many videos; software as well as hardware level.
//Support us by subscribing the channel.... Happy Pranking........

#include <SPI.h>
#include <WiFi101.h>
#include <Keyboard.h>

char ssid[] = "ESSID"; 
char pass[] = "Password";
int keyIndex = 0;      
int ledpin = 6;
bool val = true;

int status = WL_IDLE_STATUS;
WiFiServer server(80);

void setup() {
  Serial.begin(9600);  
  Keyboard.begin();  
  Serial.print("Start Serial ");
  pinMode(ledpin, OUTPUT); 
  Serial.print("WiFi101 shield: ");
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("NOT PRESENT");
    return; // don't continue
  }
  Serial.println("DETECTED");
  
  while ( status != WL_CONNECTED) {
    digitalWrite(ledpin, LOW);
    Serial.print("Attempting to connect to Network named: ");
    Serial.println(ssid);                
    digitalWrite(ledpin, HIGH);
    status = WiFi.begin(ssid, pass);
    delay(10000);
  }
  server.begin();                          
  printWifiStatus();                      
  digitalWrite(ledpin, HIGH);
}
void loop() {
  WiFiClient client = server.available();  

  if (client) {                           
    Serial.println("new client");       
    String currentLine = "";              
    while (client.connected()) 
    {       
      if (client.available()) 
      {           
        char c = client.read();          
        Serial.write(c);                 
        if (c == '\n') 
        {                 

            if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
            client.print("www.rootsaid.com<br>");
            client.print("https://www.youtube.com/c/rootsaid<br>");
            client.print("<br>");
            client.print("<h1>Windows<br>");
            client.print("<br>");
            client.print("<h1>Click <a href=\"/WT\">here</a> Ghost Message <br>");
            client.print("Click <a href=\"/L\">here</a> To Lock Computer<br>");
            client.print("Click <a href=\"/WL\">here</a> To Logout<br>");
            client.print("Click <a href=\"/WS\">here</a> To Shutdown<br>");
            client.print("Click <a href=\"/WW\">here</a> To Change Wallpaper (Coming Soon...)<br>");
            client.print("Click <a href=\"/WRS\">here</a> Launch Reverse Shell (Coming Soon...)<br>");

            client.print("<br>");
            client.print("Linux<br>");
            client.print("<br>");
            client.print("Click <a href=\"/KT1\">here</a> Ghost Message <br>");
            client.print("Click <a href=\"/KT2\">here</a> Ghost Message - Doomed <br>");
            client.print("Click <a href=\"/L\">here</a> To Lock<br>");
            client.print("Click <a href=\"/KL\">here</a> To Logout<br>");
            client.print("Click <a href=\"/KPD\">here</a> To Shutdown<br>");
            client.print("Click <a href=\"/KR\">here</a> To Reboot<br>");
            client.print("Click <a href=\"/HV\">here</a> Play Scary Video<br>");
            client.print("Click <a href=\"/ES1\">here</a> Execute Series 1<br>");
            client.print("Click <a href=\"/ES2\">here</a> Execute Series 2<br>");
            client.print("Click <a href=\"/RS\">here</a> Rotate Monitor<br></h1>");
            client.println();
            break;
          }
          else {   
            currentLine = "";
          }
        }
        else if (c != '\r') {   
          currentLine += c;   
        }


//Windows
        
        if (currentLine.endsWith("GET /WT")) {
          winTest();         
        }
        else if (currentLine.endsWith("GET /L")) {
          lockDevice();         
        }
        else if (currentLine.endsWith("GET /WL")) {
          winLogoff();         
        }
        else if (currentLine.endsWith("GET /WS")) {
          shutdownDevice();         
        }
//Linux
        else if (currentLine.endsWith("GET /KT1")) 
        {
          linuxMessage1();       
        }

        else if (currentLine.endsWith("GET /KT2")) 
        {
          linuxMessage2();       
        }
        else if (currentLine.endsWith("GET /KPD")) 
        {
          linuxPoweroff();   
        }
        else if (currentLine.endsWith("GET /KL")) 
        {
          linuxLogout();   
        }
        else if (currentLine.endsWith("GET /KR")) 
        {
          linuxReboot();   
        }
        else if (currentLine.endsWith("GET /RS")) 
        {
          linuxRotate();   
        }
        else if (currentLine.endsWith("GET /HV")) 
        {
          horrorVideo();   
        }

         else if (currentLine.endsWith("GET /ES1")) 
        {
          executeSeries1();   
        }
         else if (currentLine.endsWith("GET /ES2")) 
        {
          executeSeries2();   
        }
      }
    }

    client.stop();
    Serial.println("client disonnected");
  }
}


void printWifiStatus() 
{

  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
 
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
 
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
  // print where to go in a browser:
  Serial.print("To see this page in action, open a browser to http://");
  Serial.println(ip);
}


void winTest()
{     Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press('r');
      Keyboard.releaseAll();
      Keyboard.write(KEY_RETURN);     
      delay(500);
      Keyboard.println("notepad");
      delay(2000);
      Keyboard.write(KEY_RETURN);
      delay(1000);
      Keyboard.println("HID Test For Windows");
}
void changeWallpaper()
{
//Coming Soon
}
void lockDevice()
{
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press('l');
      Keyboard.releaseAll();
      delay(50);
}
void winLogoff()
{
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press('r');
      Keyboard.releaseAll();
      Keyboard.write(KEY_RETURN);     
      delay(500);
      Keyboard.println("shutdown -l");
      delay(50);
      Keyboard.write(KEY_RETURN);
      Keyboard.releaseAll();
      delay(1000);
}

void shutdownDevice()
{

      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press('r');
      Keyboard.releaseAll();
      Keyboard.write(KEY_RETURN);     
      delay(500);
      Keyboard.println("shutdown -t 0 -f -s");
      delay(50);
      Keyboard.write(KEY_RETURN);
      Keyboard.releaseAll();
      delay(1000);
}

void linuxMessage1()
{
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press('t');
      Keyboard.releaseAll();
      delay(1000);
      
      Keyboard.println(" I am the GHOST OF DATA PAST!!!   ");
      delay(2000);
      Keyboard.println("Ghost of Files That You Deleted for No Reason!!!   ");
      delay(2000);
      Keyboard.println(" Why Did You Delete ME??    ");
      delay(2000);
      Keyboard.println(" I will HAUNT You This PC for What You Have Done!!!!!! ");
      delay(4000);
      Keyboard.write(KEY_RETURN);
      Keyboard.println("exit");
      Keyboard.write(KEY_RETURN);

}

void linuxMessage2()
{
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press('t');
      Keyboard.releaseAll();
      delay(500);
      Keyboard.println(" You Really Thought You can Save this PC..... ");
      delay(2000);
      Keyboard.println(" with a Reboot??  ");
      delay(2000);
      Keyboard.println("There is no Escape!!! ");
      delay(2000);
      Keyboard.println("Your PC is Doomed Forever ...... ");
      delay(4000);
      Keyboard.write(KEY_RETURN);
      Keyboard.println("exit");
      Keyboard.write(KEY_RETURN);
}

void linuxPoweroff()
{
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press('t');
      Keyboard.releaseAll();
      delay(1000);
      Keyboard.println("poweroff");
      delay(50);
      Keyboard.write(KEY_RETURN);
}
void linuxReboot()
{
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press('t');
      Keyboard.releaseAll();
      delay(1000);
      Keyboard.println("reboot");
      delay(50);
      Keyboard.write(KEY_RETURN);
}
void linuxLogout()
{
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press('t');
      Keyboard.releaseAll();
      delay(1000);
      Keyboard.println("gnome-session-quit");
      delay(100);
      Keyboard.write(KEY_RETURN);
      delay(50);
      Keyboard.write(KEY_RETURN);
}
void linuxRotate()
{
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press('t');
      Keyboard.releaseAll();
      delay(1000);
      Keyboard.println("gnome-terminal --geometry=0x0+0+0 & exit");
      delay(50);
      Keyboard.write(KEY_RETURN);
      delay(500);
      Keyboard.println("xrandr -o inverted");
      Keyboard.write(KEY_RETURN);
      delay(50);
}

void horrorVideo()
{
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press('t');
      Keyboard.releaseAll();
      delay(1000);
      Keyboard.println("gnome-terminal --geometry=0x0+0+0 & exit");
      delay(50);
      Keyboard.write(KEY_RETURN);
      delay(500);
      Keyboard.println("google-chrome https://youtu.be/rwgEHs2JK2w?t=25");
      delay(50);
      Keyboard.write(KEY_RETURN);
      delay(50);
}

void launchTerminal()
{
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press('t');
      Keyboard.releaseAll();
      delay(1000);
}

void executeSeries1()
{
  launchTerminal();
  delay(5000);  
  linuxMessage1();
  delay(5000);
  lockDevice(); 
  delay(5000);
  
}

void executeSeries2()
{

  linuxMessage2();
  horrorVideo();
  delay(8000);
  linuxRotate();
  delay(2000);
  Keyboard.println("xrandr -o normal");
  Keyboard.write(KEY_RETURN);
  delay(4000);
  Keyboard.println("xrandr -o inverted");
  Keyboard.write(KEY_RETURN);
  delay(2000);
  Keyboard.println("xrandr -o normal");
  Keyboard.write(KEY_RETURN);
  delay(4000);
  Keyboard.println("xrandr -o inverted");
  Keyboard.write(KEY_RETURN);
}
