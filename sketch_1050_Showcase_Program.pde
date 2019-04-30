import gab.opencv.*;     // Importing the openCV library
import processing.video.*;   // Importing the processing library 
import java.awt.Rectangle;    // Importing the Rectangle Library
import processing.serial.*;

// Declaring an object on type Serial.
Serial myPort;

// Declaring an object of type OpenCV
OpenCV opencv;

// Initializing a rectangle array called faces
Rectangle[] faces;

// Initializing a Capture object named video.
Capture video;


// This method sets the initial object parameters for the program
void setup() 
{
  // Initializing video pixel width and height
  size(640,480);
  
  // Setting the String portName to the 5th Serial port used on the computer. (Change to coincide with the Serial port you are using).
  String portName = Serial.list()[5];
  
  // Setting myPort to the above Serial port at a baud rate of 115200.
  myPort = new Serial(this, portName, 115200);
  
  // Setting the video object to this programs video input at the same screen resolution as above.
  video =  new Capture(this, 640, 480);
  
  // Setting the opencv object to parameters exisiting within this programs video input.
  opencv = new OpenCV(this, video);
  
  // Loading the front face detection alogirthm
  opencv.loadCascade(OpenCV.CASCADE_FRONTALFACE); 
  
  // Starting the video.
  video.start();
  
}

  
void draw() 
{
  // Setting initial video background to black.
  background(0);

// If a new video is available read in that video.
 if(video.available())
 {
    video.read();
 }

    // Recieving an image input from the video input.
    opencv.loadImage(video);
   
   // Creating a new image that is from the video feed.
    image(video, 0, 0);
    noFill();
    
    // Sets the rectangle colour to green.
    stroke(0,255, 0);
    
    // Sets the width of the lines drawn.
    strokeWeight(3);
    
    // Filling the array of rectangled equal to faces detected.
    Rectangle[] faces = opencv.detect();
  
    int a = faces.length;
    println(a + " This is the amount of faces ");
    
   
    
    // Draws a rectangle on every face detected
    for(int i = 0; i < faces.length; i++)
    {
      println(faces[i].x + "," + faces[i].y);
      rect(faces[i].x, faces[i].y, faces[i].width, faces[i].height);
      
    }
    
 
 // This series of if-else-if statements sends a letter across the Serial Port to an arduino program that lights up LEDs corresponding to how many faces are detected.
   if(a == 1)
  {
    myPort.write('a');
    
  }
  else if(a == 2)
  {
    myPort.write('c');
  }
  else if(a == 3)
  {
    myPort.write('d');
  }
  else if(a == 4)
  {
    myPort.write('e');
  }
  else if(a>4)
  {
     myPort.write('w');
  }
  else
  {
    myPort.write('b');
  }

   

}

// This method reads in video input from the webcam.
void captureEvent(Capture video)
{
  
  video.read();
  
}
