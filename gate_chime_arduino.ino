int analogPin = A0;
int spk = 9;  // GPIO pin for piezo speaker
int i=0;  // Counter variable for alarm playback iterations
int val=0;  // Analog input value, max 1023 for Uno
int val1 = 0;  // Another variable for analog input value, to avoid false positives
int repeat=0;  // Number of times an open circuit was detected
int alarm_enabled = 1;  // Variable to store whether alarm is in "snooze" mode
uint32_t wait_time= 1 * 10 * 60; //in seconds
int analog_state = 1;
int boot = 1;
int broke = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(spk,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int ctr = 0;
  
  int vals = analogRead(A5);
  if(vals>650&&!broke)
  {
    if(analog_state == 0 && !boot)
      alarm_enabled = !(alarm_enabled);
    analog_state = 1;
    if(boot)
      boot = 0;
  }
  else if(vals<50&&!broke)
  {
    if(analog_state == 1 && !boot)
        alarm_enabled = !(alarm_enabled);
    analog_state = 0;
    if(boot)
      boot = 0;
  }

  if(broke==1){
    alarm_enabled  = 0;
    Serial.println("Broke handled");
  }
  if(alarm_enabled == 0)
  {
    for(ctr=0;ctr<wait_time;ctr++)
    {
      delay(1000); 
      vals = analogRead(A5);
      if(vals>650 && analog_state == 0){
        analog_state = 1;
        break;
      }
      else if(vals<50 && analog_state == 1){
        analog_state = 0;
        break;
      }
     }  
     ctr = 0;
     alarm_enabled = 1;
     broke = 0;
  }
  
  repeat=0;
  val = analogRead(analogPin);
  delay(100);
  Serial.println(val);
  if(val<800 && alarm_enabled)
  {
   while(repeat<4)
   {
    delay(50);
    val = analogRead(analogPin);
    if(val<800)
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
    digitalWrite(spk,HIGH);
    delay(50);
    digitalWrite(spk,LOW);
    delay(50);
    digitalWrite(spk,HIGH);
    delay(50);
    digitalWrite(spk,LOW);
    delay(50);
    digitalWrite(spk,HIGH);
    delay(50);
    digitalWrite(spk,LOW);
    delay(50);
  
    delay(400);
    val = analogRead(analogPin);
    delay(100);
    val1 = analogRead(analogPin);
    if(val>800 && val1>800 && i>4)
      break; 

    vals = analogRead(A5);
      if(vals>650 && analog_state == 0){
        analog_state = 1;
        broke = 1;
        Serial.println("Broke");
        break;
      }
      else if(vals<50 && analog_state == 1){
        analog_state = 0;
        broke = 1;
        Serial.println("Broke");
        break;
      }
     }
     
    }
  
  else
    Serial.println("NO ALARM"); 
  //Serial.println("Switch");
  //Serial.println(analogRead(A5));
  delay(100);
}
