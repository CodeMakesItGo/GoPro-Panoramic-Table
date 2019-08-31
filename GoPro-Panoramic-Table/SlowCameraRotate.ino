#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

/* preprocessor defines */
#define StepperOnCount 5        //5ms for high and low time on stepper motor so it won't get hot
#define WebClientCycle (100)    //100ms between web client service
#define WifiTimeout    (300000) //5 Minutes before turning off the Wifi

/* Set these to your desired credentials. */
const char *ssid = "GoProTable";
const char *password = "CodeMakesItGo";

ESP8266WebServer server(80);    //Wifi webserver
IPAddress ip;                   //Wifi IP address default = 192.168.4.1
String webSite;                 //Web site text
volatile int stepperDelay = 30; //1 RPM default
volatile bool highPowerMode = true; //High power mode keeps the stepper motor on
volatile bool clockwiseMode = true; //Clockwise \ counter-clockwise switch

int WebClientCycleCounter = 0;
int WifiTimeoutCounter = 0;

void handleHome() 
{
  if (server.hasArg("rpm"))
  {
    stepperDelay = (int)server.arg("rpm").toInt();
    WriteInt(sizeof(int), stepperDelay);
  }

  if (server.hasArg("hpm"))
  {
    highPowerMode = (((int)server.arg("hpm").toInt()) == 1);
    WriteInt(sizeof(int) * 2, highPowerMode);
  }

  if (server.hasArg("ccm"))
  {
    clockwiseMode = (((int)server.arg("ccm").toInt()) == 1);
    WriteInt(sizeof(int) * 3, clockwiseMode);
  }
  
  buildHomePage();
 
  server.send(200, "text/html", webSite);
}

void setup() 
{
   //Pin Setup
   pinMode(D1, OUTPUT);
   pinMode(D2, OUTPUT);
   pinMode(D3, OUTPUT);
   pinMode(D4, OUTPUT);
   digitalWrite(D1, LOW);
   digitalWrite(D2, LOW);
   digitalWrite(D3, LOW);
   digitalWrite(D4, LOW);

  //EEProm Startup
  EEPromInit();

  //Start Wireless
  WiFi.softAP(ssid, password);
  ip = WiFi.softAPIP();
  
  //enable GoProTable.local web address
  MDNS.begin("GoProTable");
  
  //Set web sites
  server.on("/", handleHome);
  server.begin();
}

void stepperLoop(int out)
{
  int loopCount = stepperDelay;
  
  for(int i = 0; i < loopCount;)
  {
    if(highPowerMode || i == 0)
    {
      digitalWrite(out, HIGH);
    }
    delay(StepperOnCount);
    i += StepperOnCount;
    WebClientCycleCounter += StepperOnCount;
    WifiTimeoutCounter += StepperOnCount;
    
    digitalWrite(out, LOW);
    if(i < loopCount)
    {
      delay(StepperOnCount);
      i += StepperOnCount;
      WebClientCycleCounter += StepperOnCount;
      WifiTimeoutCounter += StepperOnCount;
    }

    //Process the web client service
    if(WebClientCycleCounter > WebClientCycle)
    {
      WebClientCycleCounter = 0;
      server.handleClient();
    }

    //Turn Off Wifi
    if(WifiTimeoutCounter > WifiTimeout)
    {
      WifiTimeoutCounter = 0;
      WiFi.forceSleepBegin();
    }
  }
}

void loop() 
{
  if(clockwiseMode)
  {
    stepperLoop(D4);
    stepperLoop(D3);
    stepperLoop(D2);
    stepperLoop(D1);    
  }
  else
  {
    stepperLoop(D1);
    stepperLoop(D2);
    stepperLoop(D3);
    stepperLoop(D4);
  }
}




