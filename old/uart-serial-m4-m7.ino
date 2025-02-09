
/*
 * File my13_uart_m4_m7_print.ino for grabbing the Serial1 or _UART_ print from the M4 or M7 cores
 *
 * Note: Other Arduino must be a 3Volt arduino!
 * GND Portenta to GND other Arduino 
 * TX Portenta to RX other Arduino
 * RX Portenta to TX other Arduino
 *
 * On Portenta H7 https://content.arduino.cc/assets/Pinout-PortentaH7_latest.png  
 * On Nano 33 BLE https://content.arduino.cc/assets/Pinout-NANOble_latest.png
 * On Nano 33 IOT https://content.arduino.cc/assets/Pinout-NANO33IoT_latest.png
 *
 *
 * You could just purchase a TTL USB cable with the three connections
 * 
 * The Portenta M7 Core Serial.println("Hi");  // works fine
 * The Portenta M7 Core Serial1.println("Hi"); // prints out as Serial1
 * 
 * The Portenta M4 Core Serial.println("Hi");  // prints out as Serial1
 * The Portenta M4 Core Serial1.println("Hi"); // prints out as Serial1
 * 
 * Easier to just use   _UART1_.println("Hi"); // from Both M4 and M7 prints to Serial1 on the UX,TX,GND pins
 * 
 * 
 * The Portenta also sends crash information out on the UART TX and RX pins.
 * This program allows you to load a running serial1 monitor on another 3.3V Arduino board
 * I use the program putty to monitor it (radio button serial, find com port and speed 115200)
 * use DOS or CMD command "mode" to find the correct port
 * 
 * But you could also just use the regual serial monitor on the correct port
 * 
 * 
 * 
 * 
 */




 #if  defined (CORE_CM7)  ||  defined (CORE_CM4) // the PortentaH7


#ifdef CORE_CM7  // Start M7 specific complete sketch
void setup() {
  bootM4();
  _UART1_.begin(115200);
}

void loop(){
 
  _UART1_.println("Hello from M7");
  delay(3000); 
  
}

#endif   // all the M7 core stuff


#ifdef CORE_CM4  // Start M4 core specific sketch

void setup() {
  _UART1_.begin(115200);
}

void loop(){
 
  _UART1_.println("Hello from M4");
  delay(2000); 
  
}

#endif   // all the M4 core stuff



#else    // some 3.3V non-portenta Arduino such as the Nano 33 BLE or Nano 33 IOT or SeeduinoXIAO

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  Serial1.begin(115200);
  
  //while(!Serial.available()){} // I don't like this but useful today.
  //Serial.println("Hello from the other Arduino");
  digitalWrite(LED_BUILTIN, HIGH);  // flash on-board LED no matter grounding
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH);
}

void loop() {

  if (Serial1.available()) {     // If anything comes in Serial1 (pins 0 & 1)
    Serial.write(Serial1.read());   // read it and send it out Serial (USB)
  }
  
  
} 



#endif









/*
 * lets crash the Portenta !
 * 
 * long comment the above code and uncomment the below code
 * 
 */


/* 

void setup() {
}

void loop() {
  analogWrite(A5,128);
} 

*/
