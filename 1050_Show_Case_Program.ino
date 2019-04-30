/**
 * This program recieves input from a Processing.pde program via the Serial port on a computer
 * and then controls pins on the Arduino board based on that input.
 * Author: Jasdeep Singh
 * Date: April 8, 2019
 */



char numFaces; // This variable will hold the letter which will correspond to the number of faces detected in the Processing program.


// This method sets preliminary Arduino board information before entering a loop structure.
void setup() {
  
  // Setting the arduino pins 2-5 as outputs.
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  // Starting communication with the computers Serial Port at a baud rate of 115200.
  Serial.begin(115200);
 

  

}


// This method will run continously in a loop forever until the program is terminated by the user.
void loop() {


  // This if statement checks the Serial Port to see if there is something to read.
  if(Serial.available())
  {
    // Give the passed character to the variable numFaces
   numFaces = Serial.read();
  }


  // If numFaces is the character a, light up one row of LEDs to indicate one face being detected.
  if(numFaces == 'a')
  {
    // Setting pin 5 to +5V.
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
  }

  // If the value of numFaces is not a, but is c, light up two rows of LEDs to indicate two faces being detected.
  else if(numFaces == 'c')
  {
    // Setting pins 5 and 4 to +5V.
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
  }

  // If the value of numFaces is not a, or c, but d, light up three rows of LEDs to indicate three faces being detected.
  else if(numFaces == 'd')
  {

    // Setting pins 5,4, and 3 to +5V.
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(2, LOW);
  }

  // If the value of numFaces is not a,c, or d, but is e or w, light up all four rows of LEDs to indicate 4 or more faces being detected respectively.
  else if(numFaces == 'e' || h == 'w')
  {
    // Setting pins 2-5 to +5V.
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(2, HIGH);
  }

  // If the value of numFaces is none of the above but is b, do not light up any LEDs to indicate no faces being detected.
  else if(numFaces == 'b')
  {
    // Setting pins 2-5 to 0V.
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
  }

  // Delay the program by 10 milliseconds.
  delay(10);

 
}
