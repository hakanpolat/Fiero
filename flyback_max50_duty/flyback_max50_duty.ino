

int data_read = A0;
int pwm_pin = 5;
float duty_cycle = 0;
//float degisken = 0;
float inputValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pwm_pin,OUTPUT);
  //TCCR0B = TCCR0B & B11111000 | B00000010;    // set timer 0 divisor to     8 for PWM frequency of  7812.50 Hz D13 bacagı için
  // TCCR2B = TCCR2B & B11111000 | B00000010;    // set timer 2 divisor to     8 for PWM frequency of  3921.16 Hz D9 bacagı için
TCCR0B = TCCR0B & B11111000 | B00000001;
}



void loop(){

   inputValue = analogRead(data_read);
   analogWrite(pwm_pin, inputValue/8);
   duty_cycle = (inputValue / 1024 *100)/2;
   Serial.print("Duty Cycle = ");
   Serial.println(duty_cycle);
}

