int analogPin = A0;
int snooze_button_pin = A5;
int speaker_pin = 9;  // GPIO pin for piezo speaker
int i=0;  // Counter variable for alarm playback iterations
int initial_reading=0;  // Analog input value, max 1023 for Uno
int confirmation_reading = 0;  // Another variable for analog input value, to avoid false positives
int repeat=0;  // Number of times an open circuit was detected
int alarm_enabled = 1;  // Variable to store whether alarm is in "snooze" mode
uint32_t wait_time= 1 * 10 * 60; //in seconds
int previous_state = 1;  // Variable to store the previously detected state of the snooze switch (open-0, closed-1)
int boot = 1;  // variable to handle certain code only once on boot, but after the setup() function
int snooze_toggled = 0;  // variable to check whether the snooze button was pressed in the previous iteration


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(speaker_pin,OUTPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
  int snooze_timer = 0;
  
  int snooze_analog_reading = analogRead(snooze_button_pin);

  if(snooze_analog_reading>650&&!snooze_toggled)
  {  
    if(previous_state == 0 && !boot)
      alarm_enabled = !(alarm_enabled);
    previous_state = 1;
    if(boot)
      boot = 0;
  }

  else if(snooze_analog_reading<50&&!snooze_toggled)
  {  
    if(previous_state == 1 && !boot)
      alarm_enabled = !(alarm_enabled);
    previous_state = 0;
    if(boot)
      boot = 0;
  }

  if(snooze_toggled==1)
  {  
    alarm_enabled  = 0;
    Serial.println("Broke handled");
  }

  if(alarm_enabled == 0)
  {
    for(snooze_timer=0;snooze_timer<wait_time;snooze_timer++)
    {
      delay(1000); 
      snooze_analog_reading = analogRead(snooze_button_pin);
      if(snooze_analog_reading>650 && previous_state == 0)
      {
        previous_state = 1;
        break;
      }
      else if(snooze_analog_reading<50 && previous_state == 1){
        previous_state = 0;
        break;
      }
    }

    snooze_timer = 0;
    alarm_enabled = 1;
    snooze_toggled = 0;
    
  }
  
  repeat=0;
  initial_reading = analogRead(analogPin);
  delay(100);
  Serial.println(initial_reading);


  if(initial_reading<800 && alarm_enabled)
  {
    while(repeat<4)
    {
      delay(50);
      initial_reading = analogRead(analogPin);
      if(initial_reading<800)
        repeat++;
      else
        break;
    }
  }


  if(repeat == 4)
  {
    Serial.println("ALARM");
    for(i=0;i<40;i++)
    {
      digitalWrite(speaker_pin,HIGH);
      delay(50);
      digitalWrite(speaker_pin,LOW);
      delay(50);
      digitalWrite(speaker_pin,HIGH);
      delay(50);
      digitalWrite(speaker_pin,LOW);
      delay(50);
      digitalWrite(speaker_pin,HIGH);
      delay(50);
      digitalWrite(speaker_pin,LOW);
      delay(50);    
      delay(400);

      initial_reading = analogRead(analogPin);

      delay(100);

      confirmation_reading = analogRead(analogPin);

      if(initial_reading>800 && confirmation_reading>800 && i>4)
        break; 

      snooze_analog_reading = analogRead(snooze_button_pin);

      if(snooze_analog_reading>650 && previous_state == 0)
      {
        previous_state = 1;
        snooze_toggled = 1;
      
        Serial.println("Alarms disabled");
        break;
      }

      else if(snooze_analog_reading<50 && previous_state == 1)
      {
        previous_state = 0;
        snooze_toggled = 1;
      
        Serial.println("Alarms disabled");
        break;
      }

    } //endfor
     
  }
  
  else
    Serial.println("NO ALARM"); 
  
  delay(100);
}
