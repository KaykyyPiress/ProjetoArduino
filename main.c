#include <LiquidCrystal.h>


///////////////////////////////////////////////////////////////////////////
//variaveis do arduino
char buffer[50];
int sequencia[10];
int botaoVerde = 3; // sim
int botaovermelho = 2; // não
int botaoInicia = 8; 
int ledVermelh = 10;
int ledVerd = 9;
int buzzer = 13;
///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////
LiquidCrystal lcd_1(12, 11, 7, 6, 5, 4);
///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////
//perguntas do jogo
String perguntas[] = {
  "o ceu e azul?", 
  "bolacha?",
  "Banana e amarela?",
  "Progamamos em Pyton?",
  "Foi facil fazer?",
  "Java é bom?",
  "Mandou bem?",
  "Gol?",
};
//respostas do jogo
const bool respostas[8] = {true, true, true, false, false,true,false,false};
///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
void setup() {

    lcd_1.begin(16, 2); 
    lcd_1.setCursor(0, 0); 
    lcd_1.print("Aperte o botao ");
    lcd_1.setCursor(0,1);
    lcd_1.print("para iniciar");

    pinMode(ledVermelh, OUTPUT);
    pinMode(ledVerd, OUTPUT);
    pinMode(botaoVerde, INPUT);
    pinMode(botaovermelho, INPUT);
    pinMode(botaoInicia, INPUT);
    pinMode(buzzer, OUTPUT);
    
    Serial.begin(9600);
    randomSeed(analogRead(0)); 
}
///////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////
//sequencia gerada nesta função
void sequenciaJogo() {
    //gera numeros aleatorios entre 0 e 1
    for (int i = 0; i < 3; i++) {
        sequencia[i] = random(2); // 0 para vermelho, 1 para verde
    }
}
///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////
//mostra a sequencia no visor do lcd
void mostraSequencia() {

    for (int i = 0; i < 3; i++) {
        //verifica se o botão de inicio foi acionado
        if (digitalRead(botaoInicia) == HIGH){
            return;
        }
        //limpa o lcd
        lcd_1.clear();  
        //printa no lcd a mensagem
        lcd_1.print("Memorize os leds");

        //printa no serial a sequencia para teste e ascende os leds para memorizar
        if (sequencia[i] == 0) {
            ledVermelho();
            Serial.println("Vermelho");
        } 
        
        else if (sequencia[i] == 1) {
            ledVerde();
            Serial.println("Verde");
        }
        delay(300);
    }
}
///////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
// Função para rolar texto no LCD
void scrollTexto(String texto, int delayScroll) {
    int tamanhoTexto = texto.length();

    // Se o texto é menor ou igual a 16 caracteres, não precisa rolar
    if (tamanhoTexto <= 16) {
        lcd_1.print(texto);
    } else {
        // Faz o texto rolar para a esquerda
        for (int i = 0; i < tamanhoTexto - 15; i++) {
            lcd_1.clear();
            lcd_1.setCursor(0, 0); // Início da linha superior
            lcd_1.print(texto.substring(i, i + 16)); // Mostra 16 caracteres por vez
            delay(delayScroll); // Define a velocidade do scroll
        }
    }
}
///////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////
//verifica a respota do jogador e compara com a certa
bool respJogador(){

    for (int i = 0; i < 3; i++){

        bool respCorreta = false;

        //limpa o lcd
        lcd_1.clear();
        //printa no lcd a mensagem e atualiza os acertos conforme estejam certos
        lcd_1.print("Acertos: ");
        lcd_1.print(i);

        //verifica a resposta ao apertar cada botão
        while(!respCorreta){

            //verifica o botão de inicio
            if (digitalRead(botaoInicia) == HIGH){
                return false;
            }

            //verifica o botão de led verde
            if (digitalRead(botaoVerde) == HIGH){
                ledVerde();
                if(sequencia[i] == 1){
                    respCorreta = true;
                } else {
                    return false;
                }
            }

            //verifica o botão de led vermelho
            else if(digitalRead(botaovermelho) == HIGH){
                ledVermelho();
                if(sequencia[i] == 0){
                    respCorreta = true;
                } else {
                    return false;
                }
            }
        }
        delay(300); 
    }
    return true; 
}
//fim da função de comparação de respostas
///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////
//Função para verificar o resultado do jogos
void resultado(){

    //verifica se a resposta do jogador esta correta
    if(respJogador()){
        lcd_1.clear();
        lcd_1.print("Acertou!");
        //emite som de vitoria
        somV(); 
        //executa função das perguntas caso acerte as sequencias dos leds
        jogoDasPerguntas();
    }

    //caso erre a resposta imprime mensagem que errou
    else{
        lcd_1.clear();
        lcd_1.print("Errou :(");
        //emite som de derrota
        somD();
    } 
}
//fim da função de verificar a resposta do jogo
///////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////
//função do jogo da memoria
void jgMemoria(){

    String stringGerando  = "Gerando sequencia...";
    //limpa o lcd e mostra a mensagem 
    lcd_1.clear();
    scrollTexto(stringGerando, 200);
    //executa a função para gerar a sequencia
    sequenciaJogo();
    delay(1000);
    
    //executa a função para mostrar a sequencia
    mostraSequencia();
    
    //executa a função que verifica o resultado do jogador 
    resultado();
    delay(2000);

    //apresenta mensagem para iniciar novamente o jogo
    lcd_1.clear();
    lcd_1.print("Aperte o botao");
    lcd_1.setCursor(0, 1);
    lcd_1.print("para iniciar");
}
//Função do jogo da memoria
///////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////////////
//sons e leds das perguntas e respostas
void somV(){
    tone(buzzer, 1000, 200); 
    delay(250);             
    tone(buzzer, 1200, 200); 
    delay(250);             
    tone(buzzer, 1400, 200); 
    delay(250);             
    noTone(buzzer); 
}

void somD(){
    tone(buzzer, 500, 300); 
    delay(350);             
    tone(buzzer, 400, 300); 
    delay(350);             
    tone(buzzer, 300, 300);
    delay(350);             
    noTone(buzzer);   
}

void ledVerde(){
    digitalWrite(ledVerd, HIGH);
    delay(500);
    digitalWrite(ledVerd, LOW);
}

void ledVermelho(){
    digitalWrite(ledVermelh, HIGH);
    delay(500);
    digitalWrite(ledVermelh, LOW);
}
// fim das funções de sons e leds 
//////////////////////////////////////////////////////////////////////////////

