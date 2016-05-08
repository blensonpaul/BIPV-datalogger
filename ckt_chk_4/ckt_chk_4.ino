// Analog 005 set to outputs, then control multiplexer using port manipulation
// removing the need of serial communication
// time stamp added


#include <SPI.h>
#include <SD.h>

int mux_start= 01;// to use the selected channels for operation,use 01,02 format
int mux_end= 13;//mux_end+1
unsigned int delay_time = 1000 * 60 * 1; //1 min delay
int sample=1; //number of samples to read
float volt_ref = 5;//measured from the vrefpin of arduino.4.02859, 3.98, 4.24
int volt_div_factor = 4;

const int chipSelect = 4; //SD card CS D4

//Global current , voltage variables
float volt1 =0;
float current =0;

unsigned int time_stamp=0;

void setup()
{

  pinMode(A5, INPUT); //initialize pin A0 as input
  pinMode(A6, INPUT); //initialize pin A1 as input
  DDRC=   DDRC | B011111; // set PORTC (analog A4-A0) to outputs
 
  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    // don't do anything more:
    return;
  }


}
 
void loop()
{
  //select first MUX lines one by one
//int mux_sel;

      for (int mux_sel = mux_start; mux_sel < mux_end; mux_sel++) {
      PORTC = mux_sel;
      delay(100);//small wait after selecting mux
      current_read();
      //voltage_read();
      datalogger(time_stamp, mux_sel, volt1, current);

      } //for loop

delay(delay_time); //wait for some time after measureing all the channels
      //mux_sel = mux_start;
      time_stamp++ ;

}//loop
