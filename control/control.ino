
float ref_voltage=2.5; // Do not forget, Ardinocan read up to 5.2 Vansd will scale the values read upto 5.2 V
float V_ref; //will be up to 1024

int data_read = A0;
int pwm_pin = 5;
float D = 0;
float feedback = 0; // will be up to 1024

void setup() {
  Serial.begin(9600);
  pinMode(pwm_pin,OUTPUT);
  //TCCR0B = TCCR0B & B11111000 | B00000010;    // set timer 0 divisor to     8 for PWM frequency of  7812.50 Hz D13 bacagı için
  // TCCR2B = TCCR2B & B11111000 | B00000010;    // set timer 2 divisor to     8 for PWM frequency of  3921.16 Hz D9 bacagı için
TCCR0B = TCCR0B & B11111000 | B00000001;

V_ref= ref_voltage/5.2*1024;// this isthe analog correspondence of reference set voltage above

}



void loop(){

   feedback = analogRead(data_read);
   
  if (feedback<V_ref){
    D++;
    }

    else {
      D--;
      }

  if (D>=100) D=100;
  else if (D<=0) D=0;
   
   analogWrite(pwm_pin, D);
   
   Serial.print("Duty Cycle = ");
   Serial.println(D);

   delay(100);
}

