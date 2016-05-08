void current_read(){

//this works fine with the inbuilt ADC of arduino.
//analog voltage read
// analog pin A5,A61 is used for input


float sum1 = 0; //
float sum2 = 0; //
volt1 =0;
float volt2 =0;
current =0;
for(int i=0;i<sample;i++)
{
sum1+=analogRead(A5); //read the voltage from the divider circuit
sum2+=analogRead(A6); //read the ammeter
}
sum1=sum1/sample;
volt1=volt_div_factor*sum1*volt_ref/1024; //0-5 is divided into 0-1024
sum2=sum2/sample;
volt2=sum2*4.24/1024; //4.24 is ref voltage wrt current measure.
current=2*5.85*volt2; //mA measure equation

}
