// SIM900 library
// Version 1.0
#include <SIM900.h>


// Constructor function
SIM900::SIM900(int rxpin,int txpin):
SoftwareSerial(rxpin,txpin)
{
 verbose=false;
}

int SIM900::ReadLine(){
  static int pos=0;
  char nc;
  while (this->available()){
    nc=this->read();
    if (nc == '\n' or (pos > MAXMSGLEN) or ((millis()> lastrec + SERIALTIMEOUT)and (pos > 0)) ){
      nc='\0';
      lastrec=millis();
      inmessage[pos]=nc;
     pos=0;
     if (verbose) Serial.println(inmessage);
      return 1;
    }
    else if (nc=='\r') {
    }
    else{
      inmessage[pos++]=nc;
      lastrec=millis();
    }
  }
  return 0;
}
///////////////////////////////////////////////////////////////////////////////
/* SMS Functions */

void SIM900::StartSMS(){
  this->println("AT+CMGF=1"); // set SMS mode to text
  delay(200);
  this->ReadLine();
  this->print("AT+CMGS=");

  this->print(char(34)); // ASCII equivalent of "
  Serial.print(rcpt);
  this->print(rcpt);

  this->println(char(34));  // ASCII equivalent of "

  delay(500); // give the module some thinking time
  this->ReadLine();

}

void SIM900::EndSMS(){
  this->print(char(26));  // ASCII equivalent of Ctrl-Z
  Serial.println();

  //delay(5 * 1000); // the SMS module needs time to return to OK status
}

void SIM900::SendSMS(){
  if (verbose) Serial.println(rcpt);
  if (verbose) Serial.println(outmessage);
  this->StartSMS();
  Serial.print(outmessage);
  this->print(outmessage);
  this->EndSMS();
  delay(500);
  this->ReadLine();
}

void SIM900::DeleteAllSMS(){
  this->println("AT+CMGD=1,4"); // delete all SMS
  delay(200);
  this->ReadLine();
}


/////////////////////////////////////////////////////////////////////////////////////

void SIM900::Reset(){
  this->println("AT+CFUN=1,1"); // Reset Modem
  delay(200);
  this->ReadLine();
}


boolean SIM900::Verbose(){
	return verbose;
}

void SIM900::Verbose(boolean var1){
	verbose=var1;
}

char * SIM900::Sender(){
	return sendernumber;
}


char * SIM900::Rcpt(){
	return rcpt;
}

char * SIM900::Message(){
	return inmessage;
}


void SIM900::Sender(char * var1){
	sprintf(sendernumber,"%s",var1);
}


void SIM900::Rcpt(char * var1){
	sprintf(rcpt,"%s",var1);
}

void SIM900::Message(char * var1){
	sprintf(outmessage,"%s",var1);
}

void SIM900::Boot(){
  int counter=0;
  while(counter++ < 15){
    if (verbose) Serial.print(".");
    delay(1000);
  }
  if (verbose) Serial.println();
  
}
///////////////////////////////////////////////////////////////////////
//////////////////// Call functions //////////////////////////////////

void SIM900:Call(char * cellNumber)
{
	// Function to initiate a call to the cellNumber
	// 
	Serial.println(cellNumber);
}

void SIM900:CallHangup()
{
	// function written to hangup call
	// Implements the AT+CHUP function
	Serial.println();
}

byte SIM900:GetCallStatus()
{
	// will return a particular byte if the call is active or disconnected
	// Implements the AT+CLCC functions

}

void SIM900:AnswerCall()
{
	// Will implement the call answering function
	// Implements the ATA logic
}

void SIM900:DisconnectLine()
{
	// Implements the ATH functionallity
}