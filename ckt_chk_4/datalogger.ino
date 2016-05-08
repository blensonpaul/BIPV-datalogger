/*
  SD card datalogger
 This example shows how to log data
 to an SD card using the SD library.
 The circuit:
 * analog sensors on analog ins 0, 1, and 2
 * SD card attached to SPI bus as follows:
 ** MOSI - pin D11
 ** MISO - pin D12
 ** CLK - pin D13
 ** CS - pin D4
 */


 
void datalogger(unsigned int time_stamp_n, int mux_ch, float voltage_V , float current_mA){
   // make a string for assembling the data to log:
  String dataString = "";

   dataString = dataString +String(time_stamp_n)+ ","+ "Ch_" + String(mux_ch) + "," + String(voltage_V) + "," + String(current_mA);
  
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("datalog.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();

  }
  // if the file isn't open, pop up an error:
  else {
return;
  }

}
