#include <APR33A3.h>

APR33A3 audio1(4,5,6,7,16,17);

void setup(){
}

void loop(){
  audio1.recordAudio(0);
  delay(10000);      //10 Second Recording
    audio1.stopRecord();          //Stop the recording
    delay(2000);
  audio1.playAudioTillBusy(0);  //Play the recorded audio

  
  audio1.recordAudio(1);
  delay(10000);      //10 Second Recording
    audio1.stopRecord();          //Stop the recording
    delay(2000);
  audio1.playAudioTillBusy(1);  //Play the recorded audio


  audio1.recordAudio(2);
  delay(10000);      //10 Second Recording
    audio1.stopRecord();          //Stop the recording
    delay(2000);
  audio1.playAudioTillBusy(2);  //Play the recorded audio


  audio1.recordAudio(3);
  delay(10000);      //10 Second Recording
    audio1.stopRecord();          //Stop the recording
    delay(2000);
  audio1.playAudioTillBusy(3);  //Play the recorded audio

}
