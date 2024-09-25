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

void loop(){
    lcd_1.scrollDisplayLeft();
    delay(200);


    //quando botão inicia for precionado vai chamar as funções
    if(digitalRead(botaoInicia) == HIGH){
        mostrarSequencia();
    }
}

void gerarSequencia() {
    for (int i = 0; i < 3; i++) {
        sequencia[i] = random(2); // 0  vermelho, 1  verde
    }
}

void mostrarSequencia(){
    for(int i = 0; i < 3; i++){
        if(digitalRead(botaoInicia) = HIGH){
            return;
        }
        lcd_1.clear();
        lcd_1.print("Memorize os leds");

        if(sequencia[i] == 0){
            digitalWrite(ledVermelho, HIGH);]
            delay(500);
            digitalWrite(ledVermelho, LOW);
        }
        else if (sequencia[i] == 1){
            digitalWrite(ledVerde, HIGH);]
            delay(500);
            digitalWrite(ledVerde, LOW);
        }
        delay(300);
    }
}


