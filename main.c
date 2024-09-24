#include <LiquidCrystal.h>

char buffer[50];
int sequencia[10];
int botaoVerde = 3; // sim
int botaovermelho = 2; // não
int botaoInicia = 8; 
int ledVermelho = 10;
int ledVerde = 9;
int buzzer = 13;

LiquidCrystal lcd_1(12, 11, 7, 6, 5, 4);

void setup() {
    lcd_1.begin(16, 2); 
    lcd_1.print("  Aperte o botao para iniciar");
    pinMode(ledVermelho, OUTPUT);
    pinMode(ledVerde, OUTPUT);
    pinMode(botaoVerde, INPUT);
    pinMode(2, INPUT);
    pinMode(botaoInicia, INPUT);
    pinMode(buzzer, OUTPUT);
    
    Serial.begin(9600);
    randomSeed(analogRead(0)); 
}