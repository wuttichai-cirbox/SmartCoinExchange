#include <Arduino.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(PC12, PC11);  // RX, TX (BV20)
SoftwareSerial mySerial2(PB4, PB3);   // RX, TX (UCAE)
#define LED_STS     PC4
#define CTRL_PWB    PC10        // PW Bill(BV20)
#define CTRL_PWC    PB5         // PW Coin(UCAE)
#define CTRL_PWCD1  PA6         // PW Coin Dispensor(Mini Hopper1)
#define CTRL_PWCD2  PA7         // PW Coin Dispensor(Mini Hopper2)
#define LED_QR      PC5
#define STS_COIN    PB0
#define STS_BILL    PB1
#define STS_CDIS    PB2
#define NBM_RST     PA12
#define NBP_RST     PA8
#define SW_IN       PA15        //Setting Switch
#define DGTL_IN     PD2         // Prox Sensor

int buttonState = 0;
int buttonState2 = 0;
int incomingByte = 0;


void setup() {

  Serial1.begin(9600);    // NB-IoT
  Serial2.begin(9600);    // Mini HOPPER1
  Serial3.begin(9600);    // Debug
  Serial4.begin(9600);    // Mini HOPPER2
  // Software Serial 
  mySerial.begin(9600);   // Bill Acceptor
  mySerial2.begin(9600);  // Coin Acceptor
  
  pinMode(SW_IN,INPUT);
  pinMode(DGTL_IN,INPUT);
  pinMode(LED_STS,OUTPUT);
  pinMode(CTRL_PWB,OUTPUT);
  pinMode(CTRL_PWC,OUTPUT);
  pinMode(CTRL_PWCD1,OUTPUT);
  pinMode(CTRL_PWCD2,OUTPUT);
  pinMode(LED_QR,OUTPUT);
  pinMode(STS_COIN,OUTPUT);
  pinMode(STS_BILL,OUTPUT);
  pinMode(STS_CDIS,OUTPUT);
  pinMode(NBM_RST,OUTPUT);
  pinMode(NBP_RST,OUTPUT);
  
  delay(500);
  Serial1.println("NB-iot_Initial");
  Serial2.println("Hopper1_Initial");
  Serial3.println("DBG_Initial");
  Serial4.println("Hopper2_Initial");
  mySerial.println("BV20_Initial");
  mySerial2.println("UCAE_Initial");


}

void loop() {
  buttonState = digitalRead(SW_IN);
  buttonState2 = digitalRead(DGTL_IN);
  digitalWrite(CTRL_PWCD2,HIGH);
  digitalWrite(LED_QR,HIGH);
  if (Serial2.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial2.read();

    // say what you got:
    Serial1.print("I received2: ");
    Serial1.println(incomingByte);
  }
  if (Serial3.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial3.read();

    // say what you got:
    Serial1.print("I received3: ");
    Serial1.println(incomingByte);
  }
  if (Serial4.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial4.read();

    // say what you got:
    Serial1.print("I received4: ");
    Serial1.println(incomingByte);
  }
  
  if (buttonState == LOW) {
    Serial1.println("Setting true");
    Serial2.println("Setting true");
    Serial3.println("Setting true");
    Serial4.println("Setting true");
    
  } 
  else if(buttonState2 == LOW) {
    Serial1.println("ProxSen true");
    Serial2.println("ProxSen true");
    Serial3.println("ProxSen true");
    Serial4.println("ProxSen true");
    
  }
  
  
}