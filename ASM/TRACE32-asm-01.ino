/* 
 *  my15-TRACE32.ino
 *  By @rocksetta aka
 *  Jeremy Ellis
 *  Use at your own Risk! 
 *  
 *  *  This example at https://github.com/hpssjellis/my-examples-for-the-arduino-portentaH7/blob/master/my15-TRACE32.ino
 *  
 *  My resources and links about Assembly languages at https://github.com/hpssjellis/my-examples-for-the-arduino-portentaH7/tree/master/ASM
 *  
 *  1. Download TRACE32 from https://www.lauterbach.com/frames.html?download_demo.html 
 *  Scroll down the long page until you see Arduino Pro 
 *  Download and unzip then create a shortcut of the bin--> windows64-->t32marm.exe file to your desktop. 
 *  If you use Ubuntu Linux pre download qt5 with this command
 *  sudo apt-get install qt5-default
 *  as always with Linux expect port permissions issues.
 *  
 * 2. Pro Arduino Tutorial https://www.arduino.cc/pro/tutorials/portenta-h7/por-ard-trace32
 * 
 * 3. Get Your Portenta SN from the Arduino IDE, Tools-->Board Info (plug in Portenta a select port )
 * 
 * 4. Lisense either now or later at https://www.lauterbach.com/frames.html?register_arduino.php
 * 
 * Read your replied email for a lisense code.
 * 
 * 5. Put the following Thread debug lines in your code, compile and install as usual
 * 
 * 6. Make sure your regular Arduino IDE File --> Preeferences --> Show verbose output during: 
 * set with a check for both  compilation and upload
 * 
 * 7. Find your TEMP build folder and open it in a window to look at the files.
 * note AppData is a hidden part of windows, so best to copy the link from the arduino output. 
 * 
 * 8. Load TRACE32
 * 
 * 9. Portenta H7 Demos--> T32ThreadDebug --> FILE (use the above link and choose the .elf file)
 * 
 * 10. Load Debug symbols (Do not flash as it looks for the wrong .bin file)
 * 
 * 11. reset protenta (Single click)
 * 
 * 12. Insert License data and save if asked
 * 
 * 13. On the terminal line labelled B:: type go loop
 * 
 * 14. Right click to set breakpoint. Then keep clicking "GO" 
 *     or, set myDebug = true if you know where the issue is in your code.
 *     This breaks your code from the arduino IDE as well
 *         
 * 
 * 15. In the Var --> Watch window type myLoop to see it changing
 * 
 * 16. Right click the Term.View window to clear it.
 * 
 * 17. Window --> Store Window (Somewhere easy to find to load next time.)
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */


///////////////////// Start: Add thesse lines to your code //////////////////////////////


#include <ThreadDebug.h>

USBSerial              SerialUSB1(false, "DebugPort");
UsbDebugCommInterface  debugComm(&SerialUSB1);
ThreadDebug            threadDebug(&debugComm, DEBUG_NO_BREAK_IN_SETUP);
//ThreadDebug            threadDebug(&debugComm, DEBUG_BREAK_IN_SETUP);



///////////////////// End: Add thesse lines to your code //////////////////////////////


//bool myDebug = false; // set to true to insert breakpoint.(stops your code there) 
int myLoop = 0;

unsigned int myA = 0;
unsigned int myB = 0;


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LEDB, OUTPUT);
  Serial.begin(115200);
  myA = 5;

}

// the loop function runs over and over again forever
void loop() {
   debugBreak();           // debug breakpoint 
  myLoop += 1;
 // myA++;
  //myB = 4;
 // myA += myB; 
  
 // asm("ldr r0, =myA \n ldr r1, =111 \n add r0, r1 \n  ");
asm(
    "ldr r0, =(myA)  \n\t"
    "ldr r1, =111  \n\t"
    "add r1, r0    \n\t" 
      :"=r" (myB)
   );








 
  
  digitalWrite(LEDB, LOW);              // turn the Portenta Blue LED on 
  Serial.println("Hi from Portenta");
  Serial.println("Loop #: "+ String(myLoop));
  Serial.println("myA #: "+ String(myA) + ", myB #: "+ String(myB));
  delay(100);                           // wait a bit 
  digitalWrite(LEDB, HIGH);             // turn the Portenta Blue LED off 
  delay(100);                           // wait a bit 
  Serial.println("Bye from Portenta");
  Serial.println();

}
