#include <Arduino.h>

int LDR = 7;

int LED1 = 10;
int LED2 = 11;
int LED3 = 12;
int LED4 = 13;
int LED_ldr = 8;

int IR1 = 2;
int IR2 = 3;
int IR3 = 4;
int IR4 = 5;

unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;
unsigned long previousMillis3 = 0;
unsigned long previousMillis4 = 0;

const long interval = 3000;

void setup() {

      pinMode(IR1,INPUT);
      pinMode(IR2,INPUT);
      pinMode(IR3,INPUT);
      pinMode(IR4,INPUT);
      pinMode(LDR,INPUT);

      pinMode(LED1,OUTPUT); 
      pinMode(LED2,OUTPUT);
      pinMode(LED3,OUTPUT);
      pinMode(LED4,OUTPUT);

      pinMode(LED_ldr,OUTPUT);
}


void loop() {
    
    int statusIR1 = digitalRead (IR1);
    int statusIR2 = digitalRead (IR2);
    int statusIR3 = digitalRead (IR3);
    int statusIR4 = digitalRead (IR4);
    int statusLDR = digitalRead (LDR);
    unsigned long currentMillis = millis();


    if(statusLDR){

        digitalWrite(LED_ldr,HIGH);

        if(!statusIR1){
            previousMillis1 = currentMillis;
        }
        if(previousMillis1 + interval >= currentMillis){
            digitalWrite(LED1, HIGH);
        }
        else{
            digitalWrite(LED1, LOW);
        }

        if(!statusIR2){
            previousMillis2 = currentMillis;
        }
        if(previousMillis2 + interval >= currentMillis){
            digitalWrite(LED2, HIGH);
        }
        else{
            digitalWrite(LED2, LOW);
        }

        if(!statusIR3){
            previousMillis3 = currentMillis;
        }
        if(previousMillis3 + interval >= currentMillis){
            digitalWrite(LED3, HIGH);
        }
        else{
            digitalWrite(LED3, LOW);
        }

        if(!statusIR4){
            previousMillis4 = currentMillis;
        }
        if(previousMillis4 + interval >= currentMillis){
            digitalWrite(LED4, HIGH);
        }
        else{
            digitalWrite(LED4, LOW);
        }
    } 
    else{
        digitalWrite(LED_ldr,LOW);
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, LOW);
        digitalWrite(LED4, LOW);
    }
        
}
