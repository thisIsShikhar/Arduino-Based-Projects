    //agrohi.net
    
    import processing.serial.*;    
    Serial myPort;    
    String data="" ;  
    PFont  myFont;    
      
    void setup(){  
      size(1366,900); // size of processing window  
      background(0);// setting background color to black  
      myPort = new Serial(this, "/dev/ttyACM0(Arduino/Genuino Uno)", 9600);  
      myPort.bufferUntil('\n');  
    }  
      
    void draw(){  
      background(0);  
      textAlign(CENTER);  
      fill(255);  
      text(data,820,400);  
      textSize(100);  
      fill(#4B5DCE);  
      text("              Distance :        cm",450,400);  
      noFill();  
      stroke(#4B5DCE);  
    }  
      
    void serialEvent(Serial myPort){  
       data=myPort.readStringUntil('\n');  
    }  
