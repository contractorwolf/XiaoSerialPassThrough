const String projectName = "SERIAL PASS THROUGH";



void setup() {
  // put your setup code here, to run once:
  // begin serial comms with IDE and SIM7600
  Serial.begin(9600);// serial from arduino ide
  Serial.setTimeout(250);
  
  Serial1.begin(115200);//serial to SIM7600 cellular board
  Serial1.setTimeout(250);

  Serial.print(projectName);
  Serial.println(" started");  
}

void loop() {
  // put your main code here, to run repeatedly:
  checkForIDEMessages();
  checkForSIM7600Messages() ;
}

void checkForSIM7600Messages() {
  if (Serial1.available() > 0) {
    String messageFromSIM7600 = Serial1.readString();
    //remove incoming end \r\n from the message
    messageFromSIM7600.trim();
    Serial.println(messageFromSIM7600);
    //Serial.println(messageFromSIM7600.length());
  }
}


// for test communication via arduino serial, use if you plan on controlling/communicating with phone via 
// the arduino IDE or other serial communication tools (FOR TESTING OR DEV NOT REQUIRED FOR OPERATION)
void checkForIDEMessages() {
  // ------------------------------------------
  if (Serial.available() > 0)
  {
    String incoming = Serial.readString();
    incoming.trim();

    Serial.print("incoming:");
    Serial.println(incoming);      
	
    Serial1.println(incoming);
    // end if    
  }
  // ------------------------------------------ 
}