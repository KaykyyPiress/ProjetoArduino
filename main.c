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


///////////////////////////////////////////////////////////////////////////
// Função para a fase de perguntas
void jogoDasPerguntas() {

    //limpa o lcd e exibe a mensagem
    lcd_1.clear();
    lcd_1.print("Perguntinhas");
    delay(2500);

    //variavel para vezes que jogador pode pular
    int qtdePulos = 1; 


    int qtdePerguntas[5];

    for (int i = 0; i < 5; i++) {

        int indPergunta;
        bool repetida;


        do {
            repetida = false;
            //gera um numero aleatoria entre 0 e 7
            indPergunta = random(8); 

            //percorre a lista de perguntas com base no indice que cair
            for (int j = 0; j < i; j++) {
                //verifica se a pergunta esta sendo repetida
                if (qtdePerguntas[j] == indPergunta) {
                    repetida = true;
                    break;
                }
            }
        } while (repetida);
        qtdePerguntas[i] = indPergunta;


        //exibe no lcd a pergunta a ser feita por 3 segundos
        lcd_1.clear();
        scrollTexto(perguntas[indPergunta], 300);
        Serial.print("Pergunta: ");
        Serial.println(perguntas[indPergunta]);
        delay(3000);
        lcd_1.clear();

        // Aguarda resposta 
        bool respPergunta = false;
        bool respJogador = false;

        //conta o tempo para a resposta do jogador
        for (int tempo = 9; tempo > -1; tempo--) { 
        	
            //mostra o contador do tempo    
        	lcd_1.setCursor(5,0);
            lcd_1.print("tempo: ");
          	lcd_1.setCursor(12,0);
            lcd_1.print(tempo);
            lcd_1.setCursor(3,1);
            lcd_1.print("Sim");
            lcd_1.setCursor(10,1);
            lcd_1.print("Nao");

            
            if (tempo <= 4) {
                tone(buzzer, 1000); // Emite som de contagem regressiva
            }

            if (digitalRead(botaoInicia) == HIGH) {
                return; // Sai do jogo
            }
            //verifica a resposta do jogador se for sim
            if (digitalRead(botaoVerde) == HIGH) {
                respJogador = true;
                respPergunta = true;
                lcd_1.setCursor(2,1);
                lcd_1.print("*");
                noTone(buzzer);
                delay(200);
                
                
            }
            //verifica se a resposta do jogador foi não 
            else if (digitalRead(botaovermelho) == HIGH) {
                respJogador = false;
                respPergunta = true;
                lcd_1.setCursor(9,1);
                lcd_1.print("*");
                noTone(buzzer);
                delay(200);
                
            }
            delay(1000); // Espera 1 segundo
        }
        noTone(buzzer); // Para o som


        // Se o tempo acabar pula a questão e subtrai as vezes possiveis de pulo
        if (!respPergunta) {
            if (qtdePulos > 0) {
              
				String pulouPerg = "Pulou a pergunta";
                qtdePulos--;
              	lcd_1.clear();
                scrollTexto(pulouPerg,350);
                tone(buzzer, 500, 500);
                delay(1000);
                continue; // Vai para a próxima pergunta

            } 
            //caso não tenha mais pulos para o jogo
            else {
              
              	String pulouPerg = "Sem pulos restantes";
                lcd_1.clear();
                scrollTexto(pulouPerg,350);
                tone(buzzer, 200, 500);
                delay(1000);
                return; // Sai do jogo
            }
        }

        // Verifica resposta do jogador se esta correta ou não
        if (respJogador == respostas[indPergunta]) {
            lcd_1.clear();
            lcd_1.print("Correto!");
            somV(); // Emite som de vitória
            delay(500);
        } else {
            lcd_1.clear();
            lcd_1.print("Errado!");
            somD(); // Emite som de derrota
            delay(1000);
            return; // Sai do jogo
        }
    }

    // Pergunta final
    ultimaPergunta();
}
///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////
//executa a pergunta final do jogo
void ultimaPergunta() {

    //exibe no lcd a mensagem de ultima pergunta
    lcd_1.clear();
    lcd_1.print("Pergunta Final");
    delay(2000);


    //ultima pergunta e respostas
    String pergunta = "Arduino e um microcontrolador?";
    bool respUltPergunta = true;

    //exibe a perfunta final 
    lcd_1.clear();
    scrollTexto(pergunta, 300);
    Serial.print("Pergunta Final: ");
    Serial.println(pergunta);
    delay(3000);
    lcd_1.clear();
    
    bool respPerguntaUlt = false;
    bool respJogadorUlt = false;

    for (int tempo = 9; tempo > -1; tempo--) { 
        	
        //exibe o tempo e a resposta do jogador
        lcd_1.setCursor(5,0);
        lcd_1.print("tempo: ");
        lcd_1.setCursor(12,0);
        lcd_1.print(tempo);
        lcd_1.setCursor(3,1);
        lcd_1.print("Sim");
        lcd_1.setCursor(10,1);
        lcd_1.print("Nao");
        

        //contagem regressiva
        if (tempo <= 4) {
            tone(buzzer, 1000); 
        }
        //volta o jogo
        if (digitalRead(botaoInicia) == HIGH) {
            return; 
        }

        //verifica se a resposta do jogador foi sim
        if (digitalRead(botaoVerde) == HIGH) {
            respJogadorUlt = true;
            respPerguntaUlt = true;
            lcd_1.setCursor(2,1);
            lcd_1.print("*");
            noTone(buzzer);
            
            
        } 
        //verifica se a resposta do jogador foi não
        else if (digitalRead(botaovermelho) == HIGH) {
            respJogadorUlt = false;
            respPerguntaUlt = true;
            lcd_1.setCursor(9,1);
            lcd_1.print("*");
            noTone(buzzer);
            
        }
        delay(1000);
    }

    //caso jogador não responda exibe o tempo esgotado e finaliza o jogo
    if (!respPerguntaUlt) {
        lcd_1.clear();
        lcd_1.print("Tempo esgotado");  
        tone(buzzer, 200, 500);
        Serial.println("Tempo esgotado na pergunta final.");
        delay(1000);
        return; // Sai do jogo
    }

    //emite a mensagem de vitoria se responder tudo certo
    if (respJogadorUlt == respUltPergunta) {
        lcd_1.clear();
        lcd_1.print("Voce Venceu!");
        somV(); //Emite o som de vitória do jogo
        Serial.println("Jogador Venceu!");
    } 
    //exibe a mensagem de derrota caso erre
    else {
        lcd_1.clear();
        lcd_1.print("Errado!");
        somD(); //Emite o som de derrota do jogo
        Serial.println("Resposta Incorreta na Pergunta Final!");
        delay(1000);
    }
}
///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////
//inicia o jogo
void loop() {
    if (digitalRead(botaoInicia) == HIGH) {
        jgMemoria();
    }
}
///////////////////////////////////////////////////////////////////////////
