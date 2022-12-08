int LOW_BAT_WARING_timer;
int cont;
float lectura_ADC;
float tension_bateria;
bool LOW_BAT_WARING;
int LOW_BAT_WARING_cont;
#define buzzer A2

void setup() {
  Serial.print("hello world");
  LOW_BAT_WARING_timer = 5000;
  digitalWrite (buzzer,HIGH);
  delay(1000);
  digitalWrite (buzzer,LOW);
  Serial.print ("config done");
}

void loop() {
  delay(1000);
  cont=micros();
  if (millis() == LOW_BAT_WARING_timer)LOW_BAT_WARING_timer += 1000; 
    // Leer entrada analógica
    lectura_ADC = analogRead(A6);
    tension_bateria = (22.8/5) * lectura_ADC * (5/1023);
      if (tension_bateria < 21 && LOW_BAT_WARING == false) {
      LOW_BAT_WARING_cont++;
      }
      if (LOW_BAT_WARING_cont > 30)LOW_BAT_WARING = true;
      if (LOW_BAT_WARING == true) {
        digitalWrite (buzzer,HIGH);
        if (millis() == LOW_BAT_WARING_timer);{
          Serial.println("low bat ");
          Serial.print(tension_bateria);
        }
      }
    else LOW_BAT_WARING_cont = 0;
  Serial.println(micros()-cont);
}
