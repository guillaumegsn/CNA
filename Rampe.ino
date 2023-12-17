#include <Arduino.h>

#define Broche_STR 4
#define Broche_DAT 3
#define Broche_CLK 5
#define Freq 8000 //Frequence en Hz
 
char Data1 = 0xFF; //Donnée a envyée 7F
char Data2 = 0xFF; //Donnée a envyée 
float TechDemi = ((1./(float)Freq)*1000000.)/2.; //Calcul de la temporisation pour avoir Fclk = 8kHZ car Fclk = 64kHz est impossible

void setup() {

    pinMode(Broche_STR, OUTPUT);
    pinMode(Broche_DAT, OUTPUT);
    pinMode(Broche_CLK, OUTPUT);    
    
}

void loop() {
    //Envoi_Octet(Data1);
    Envoi_Octet(Data1);
    if (Data1 < 0xFF)
      Data1 ++ ;
    else 
      Data1 = 0;

    //delay(10);
    
}

void Envoi_Octet (char OCTET){
    for (int i = 8; i > 0; i--){
        digitalWrite(Broche_DAT, (OCTET & (1 >> (i-1))));
        if (i == 1){
            digitalWrite(Broche_STR, 1);
        }
        delayMicroseconds(1);
        digitalWrite(Broche_CLK, 1);
        delayMicroseconds(1);
        digitalWrite(Broche_CLK, 0); 
    }
    delayMicroseconds(1);
    digitalWrite(Broche_DAT, 0);
    digitalWrite(Broche_STR, 0);
    delayMicroseconds(1);
}
