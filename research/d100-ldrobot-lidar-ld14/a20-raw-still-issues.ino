

byte myIn8bitA, myIn8bitB;
short myIn16bit;
int myHeader, myVerlen, mySpeed, myStartAngle, myEndAngle, myTimeStamp, myCRC;

// should be an array but this is easier
int myData1,myQuality1, myData2,myQuality2, myData3,myQuality3, myData4,myQuality4, myData5,myQuality5, myData6,myQuality6;

void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);

}

void loop() {
  while (Serial1.available()){

    myIn8bitA = Serial1.read();
    if (myIn8bitA == 0x54) {
      //first byte: header
      myHeader = (int) myIn8bitA;  // who cares.
      Serial.println();
      Serial.print("Start: ");
      Serial.print(myIn8bitA, HEX);
      
      // 2nd byte length
      myIn8bitA = Serial1.read();
      myVerlen = (int) myIn8bitA;  // who cares
      Serial.print(" ");
      if (myIn8bitA <= 15 ){Serial.print(" ");} // add a space for single digit hex values
      Serial.print(myIn8bitA, HEX); 

      // 3rd and 4th bytes angular speed iof lidar
      myIn8bitA = Serial1.read();
      myIn8bitB = Serial1.read();
      mySpeed = myIn8bitB *256 + myIn8bitA;   // check the order of this
      Serial.print(" ");
      if (myIn8bitA <= 15 ){Serial.print(" ");} // add a space for single digit hex values
      Serial.print(myIn8bitA, HEX); 
      Serial.print(" ");
      if (myIn8bitB <= 15 ){Serial.print(" ");} // add a space for single digit hex values
      Serial.print(myIn8bitB, HEX); 

      // 5th and 6th bytes start angle
      myIn8bitA = Serial1.read();
      myIn8bitB = Serial1.read();
      myStartAngle = myIn8bitB *256 + myIn8bitA;   // check the order of this
      Serial.print(" ");
      if (myIn8bitA <= 15 ){Serial.print(" ");} // add a space for single digit hex values
      Serial.print(myIn8bitA, HEX); 
      Serial.print(" ");
      if (myIn8bitB <= 15 ){Serial.print(" ");} // add a space for single digit hex values
      Serial.print(myIn8bitB, HEX); 

      Serial.print(" ---"); 

      // 7th and 8th bytes Data1
      myIn8bitA = Serial1.read();
      myIn8bitB = Serial1.read();
      myData1 = myIn8bitB *256 + myIn8bitA;   // check the order of this
      Serial.print(" ");
      if (myIn8bitA <= 15 ){Serial.print(" ");} // add a space for single digit hex values
      Serial.print(myIn8bitA, HEX); 
      Serial.print(" ");
      if (myIn8bitB <= 15 ){Serial.print(" ");} // add a space for single digit hex values
      Serial.print(myIn8bitB, HEX); 

      // 9th byte Quality for data1
      myIn8bitA = Serial1.read();
      myQuality1 = (int) myIn8bitA;  // who cares
      Serial.print(" ");
      if (myIn8bitA <= 15 ){Serial.print(" ");} // add a space for single digit hex values
      Serial.print(myIn8bitA, HEX); 

      Serial.print(" |");   // data boundry marker

      // 10th and 11th bytes Data2
      myIn8bitA = Serial1.read();
      myIn8bitB = Serial1.read();
      myData2 = myIn8bitB *256 + myIn8bitA;   // check the order of this
      Serial.print(" ");
      if (myIn8bitA <= 15 ){Serial.print(" ");} // add a space for single digit hex values
      Serial.print(myIn8bitA, HEX); 
      Serial.print(" ");
      if (myIn8bitB <= 15 ){Serial.print(" ");} // add a space for single digit hex values
      Serial.print(myIn8bitB, HEX); 

      // 12th byte Quality for data2
      myIn8bitA = Serial1.read();
      myQuality2 = (int) myIn8bitA;  // who cares
      Serial.print(" ");
      if (myIn8bitA <= 15 ){Serial.print(" ");} // add a space for single digit hex values
      Serial.print(myIn8bitA, HEX); 

      Serial.print(" |");  // data boundry marker

      // 13th and 14th bytes Data3
      myIn8bitA = Serial1.read();
      myIn8bitB = Serial1.read();
      myData3 = myIn8bitB *256 + myIn8bitA;   // check the order of this
      Serial.print(" ");
      if (myIn8bitA <= 15 ){Serial.print(" ");} // add a space for single digit hex values
      Serial.print(myIn8bitA, HEX); 
      Serial.print(" ");
      if (myIn8bitB <= 15 ){Serial.print(" ");} // add a space for single digit hex values
      Serial.print(myIn8bitB, HEX); 

      // 15th byte Quality for data3
      myIn8bitA = Serial1.read();
      myQuality3 = (int) myIn8bitA;  // who cares
      Serial.print(" ");
      if (myIn8bitA <= 15 ){Serial.print(" ");} // add a space for single digit hex values
      Serial.print(myIn8bitA, HEX); 


     // Serial.print(" |");  // data boundry marker

      // the next few data points are not that useful for testing so print and discard
 
     int myLoop;
     int myMaxBytes = 9;    // in steps of 3 bytes
     for (myLoop = 0; myLoop < myMaxBytes; myLoop++) {
        if (myLoop % 3 == 0) { Serial.print(" |"); }    // data boundry marker
        myIn8bitA = Serial1.read();
        Serial.print(" --");
     }


     Serial.print(" |"); 






      // last -5 and last -4 bytes end-angle
      myIn8bitA = Serial1.read();
      myIn8bitB = Serial1.read();
      myEndAngle = myIn8bitB *256 + myIn8bitA;   // check the order of this
      Serial.print(" ");
      if (myIn8bitA <= 15 ){Serial.print(" ");} // add a space for single digit hex values
      Serial.print(myIn8bitA, HEX); 
      Serial.print(" ");
      if (myIn8bitB <= 15 ){Serial.print(" ");} // add a space for single digit hex values
      Serial.print(myIn8bitB, HEX); 





      // last -3 and last -2 bytes TimeStamp
      myIn8bitA = Serial1.read();
      myIn8bitB = Serial1.read();
      myTimeStamp = myIn8bitB *256 + myIn8bitA;   // check the order of this
      Serial.print(" ");
      if (myIn8bitA <= 15 ){Serial.print(" ");} // add a space for single digit hex values
      Serial.print(myIn8bitA, HEX); 
      Serial.print(" ");
      if (myIn8bitB <= 15 ){Serial.print(" ");} // add a space for single digit hex values
      Serial.print(myIn8bitB, HEX); 

      // last byte  myCRC
      myIn8bitA = Serial1.read();
      myCRC = (int) myIn8bitA;  // who cares
      Serial.print(" ");
      if (myIn8bitA <= 15 ){Serial.print(" ");} // add a space for single digit hex values
      Serial.print(myIn8bitA, HEX); 


     // if (Serial1.available()) {Serial1.read(); Serial.print(".1");}
     // if (Serial1.read()){Serial.print(".1");}

       // try to flush an extra values . If anything here then the previous ending values are wrong
/*
      for (myLoop = 0; myLoop < 30; myLoop++){
        myIn8bitA = 0x00;
        myIn8bitA = Serial1.read();
        if (myIn8bitA != 0x00){ Serial.print(".");}
      }
*/

      // ignore the rest for now.
      // summary of what we have so far
      Serial.println();
      Serial.println("Header:"+String(myHeader)+ ", VerLen:"+String(myVerlen)+ ", Speed:"+String(mySpeed)+ " degrees per second, Start Angle:"+String(myStartAngle) +" 100th of a degree, "   ); 
      Serial.println("Data1: "+String(myData1)+ " mm, Quality1: "+String(myQuality1) );   
      Serial.println("Data2: "+String(myData2)+ " mm, Quality2: "+String(myQuality2) );   
      Serial.println("Data3: "+String(myData3)+ " mm, Quality3: "+String(myQuality3) ); 
      Serial.println("End Angle:"+String(myEndAngle)+ " 100th of a degree, Time Stamp:"+String(myTimeStamp)+ " ms, CRC:"+String(myCRC) +" Check bit"   ); 

      //myEndAngle, myTimeStamp, myCRC;  

      Serial.println();
    }  // end if startbit

  }  // end while

}  // end loop