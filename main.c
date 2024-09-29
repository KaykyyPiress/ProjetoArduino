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

const String perguntas[6] = {
  "Java e legal?", 
  "Python e legal?",
  "Banana e amarela?",
  "A placa e Arduino?",
  "Foi facil fazer?",
};
const bool respostas[5] = {false, true, true, true, false};

void setup() {
    lcd_1.begin(16, 2); 
    lcd_1.setCursor(2, 0); 
    lcd_1.print("Aperte o botao para iniciar");
    pinMode(ledVermelho, OUTPUT);
    pinMode(ledVerde, OUTPUT);
    pinMode(botaoVerde, INPUT);
    pinMode(2, INPUT);
    pinMode(botaoInicia, INPUT);
    pinMode(buzzer, OUTPUT);
    
    Serial.begin(9600);
    randomSeed(analogRead(0)); 
}


void gerarSequencia() {
    for (int i = 0; i < 3; i++) {
        sequencia[i] = random(2); // 0 para vermelho, 1 para verde
    }
}

void mostrarSequencia() {
    for (int i = 0; i < 3; i++) {
        if (digitalRead(botaoInicia) == HIGH){
            return;
        }
        lcd_1.clear();  
        lcd_1.print("Memorize os leds");

        if (sequencia[i] == 0) {
            acenderledVermelho();
            Serial.println("Vermelho");
        } else if (sequencia[i] == 1) {
            acenderledVerde();
            Serial.println("Verde");

        }
        delay(300);
    }
}

bool respostaJogador(){
    for (int i = 0; i < 3; i++){
        bool respostaCorreta = false;

        lcd_1.clear();
        lcd_1.print("Acertos: ");
        lcd_1.print(i);

        while(!respostaCorreta){
            if (digitalRead(botaoInicia) == HIGH){
                return false;
            }

            if (digitalRead(botaoVerde) == HIGH){
                acenderledVerde();

                if(sequencia[i] == 1){
                    respostaCorreta = true;
                } else{
                    return false;
                }
            }
            else if(digitalRead(botaovermelho) == HIGH){
                acenderledVermelho();

                if(sequencia[i] == 0){
                    respostaCorreta = true;
                } else{
                    return false;
                }
            }
        }
        delay(300); 
    }
    return true; 
}

void verificarResultado(){
    if(digitalRead(botaoInicia) == HIGH){
        return;
    }

    if(respostaJogador()){
        lcd_1.clear();
        lcd_1.print("Acertou!");
        somVitoria(); 
    }
    else{
        lcd_1.clear();
        lcd_1.print("Errou :(");
        somDerrota();
    } 
}

void jogoMemoria(){
    lcd_1.clear();
    lcd_1.print("Gerando sequencia...");
    gerarSequencia();
    delay(1000);
    lcd_1.clear();
    lcd_1.print("Mostrando sequencia");
    mostrarSequencia();
    lcd_1.clear();
    lcd_1.print("Sua vez...");
    verificarResultado();
    delay(2000);
    lcd_1.clear();
    lcd_1.print("Aperte o botao");
    lcd_1.setCursor(0, 1);
    lcd_1.print("para iniciar");
}

void somVitoria(){
    tone(buzzer, 1000, 200); 
    delay(250);             
    tone(buzzer, 1200, 200); 
    delay(250);             
    tone(buzzer, 1400, 200); 
    delay(250);             
    noTone(buzzer); 
}

void somDerrota(){
    tone(buzzer, 500, 300); 
    delay(350);             
    tone(buzzer, 400, 300); 
    delay(350);             
    tone(buzzer, 300, 300);
    delay(350);             
    noTone(buzzer);   
}

void acenderledVerde(){
    digitalWrite(ledVerde, HIGH);
    delay(500);
    digitalWrite(ledVerde, LOW);
}

void acenderledVermelho(){
    digitalWrite(ledVermelho, HIGH);
    delay(500);
    digitalWrite(ledVermelho, LOW);
}

void loop(){

    if(digitalRead(botaoInicia) == HIGH){
  	   jogoMemoria();
  }
}

