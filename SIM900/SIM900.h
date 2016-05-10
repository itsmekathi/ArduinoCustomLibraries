#ifndef _SIM900_H
#define _SIM900_H
#include "Arduino.h"
#include <SoftwareSerial.h>

#define SERIALTIMEOUT 2000
#define PHONESIZE 13
#define MAXMSGLEN 100
#define OUTMESSAGE_SIZE 100

class SIM900 : public SoftwareSerial {
public:
  SIM900(int rxpin,int txpin);
  void SendSMS();
  void SendSMS(char * cellnumber,char * outmsg);
  void DeleteAllSMS();
  void Reset();
  void EndSMS();
  void StartSMS();
  int ReadLine();
  void Verbose(boolean var1);
  boolean Verbose();
  void Sender(char * var1);
  char * Sender();
  void Rcpt(char * var1);
  char * Rcpt();
  void Message(char * var1);
  char * Message();
  void Boot();

  void Call(char * cellNumber);
  void CallHangup();
  byte GetCallStatus();
  void AnswerCall();
  void DisconnectLine();



  boolean verbose;
  char sendernumber[PHONESIZE + 1];
  char rcpt[PHONESIZE + 1];
  char outmessage[100];
  
protected:
  unsigned long lastrec;
  
};

#endif