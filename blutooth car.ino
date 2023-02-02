#include <SoftwareSerial.h>
SoftwareSerial EEBlue(10, 11); // RX | TX
int ledpin=13; // led on D13 will show blink on / off
int BluetoothData; // the data given from Computer
void setup()
{
 
  Serial.begin(9600);
  EEBlue.begin(9600);  //Default Baud for comm, it may be different for your Module.  
  Serial.println("The bluetooth gates are open.\n Connect to HC-05 from any other bluetooth device with 1234 as pairing key!.");
  EEBlue.println("Bluetooth On please press 1 or 0 blink LED ..");
  pinMode(ledpin,OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
   if (EEBlue.available()){
BluetoothData=EEBlue.read();
   if(BluetoothData=='F'){   // if number 1 pressed ....
   digitalWrite(ledpin,1);
   EEBlue.println("LED  On D13 ON ! ");
   }
  if (BluetoothData=='B'){// if number 0 pressed ....
  digitalWrite(ledpin,0);
   EEBlue.println("LED  On D13 Off ! ");
  }
}
delay(100);// prepare for next data ...
}
// void loop()
// {
 
//   // Feed any data from bluetooth to Terminal.
//   if (EEBlue.available())
//     Serial.write(EEBlue.read());
 
//   // Feed all data from termial to bluetooth
//   if (Serial.available())
//     EEBlue.write(Serial.read());
// }
