# Projeto Arduino

  O projeto consiste em um jogo de memorização e de perguntas.

  Este programa foi desenvolvido em C++ e para ser usado com Arduino. 

  Instruções para uso do programa:

    1- Monte o circuito conforme a imagem abaixo, para melhor funcionalidade do programa.
    
      ![Imagem do circuito do programa](https://github.com/user-attachments/assets/a22987d6-fb36-41fb-93b4-ca88be058b6a)

    2- Copie o codigo ou baixe o arquivo main.c que esta no repositorio.

    3- Abra o Arduino e execute o codigo do programa para iniciar o jogo.


Como é o jogo e como jogar o mesmo:

     Quando se inicia o jogo, ele exibe uma mensagem no LCD uma mensagem para pressionar o botão de inicio para começar.
      (Botão de inicio é o isolado do lado esquerdo)
      
      ![Imagem do Inicio do jogo](https://github.com/user-attachments/assets/1b5e1bb4-d3fd-439f-8eeb-4bb163e409d0)

     Após iniciar o jogo, ele começa com o jogo da memoria, onde os leds irão piscar 10 vezes e que o jogador deverá
    memorizar e apertar os botões conforme a sequência. 

      (Botão para o led verde esta no lado direito, e botão do led vermelho esta do lado direito, no centro da segunda protoboard).
      
     A cada acerto a quantidade no LCD irá aumentar.

      ![Imagem do visor com a quantidade de acertos](https://github.com/user-attachments/assets/da743b77-3a69-4398-9019-d97857b031a7)

     Caso erre a sequência o jogo irá parar e exibirá a mensagem para iniciar novamente. Caso acerte a sequência, o
    jogador ira passar para a proxima fase que é a de perguntas. 
    
     Está fase é composta de 5 perguntas, onde o jogador não poderá errar nenhuma resposta. Caso erre alguma
    o jogo sera reiniciado.

      ![Imagem da pergunta no visor LCD](https://github.com/user-attachments/assets/6c49bb75-2db6-468e-b90a-36572ec9e785)

     Se a resposta estiver correta, irá emitir um som e a mensagem no visor LCD
     
      ![Acertou a pergunta](https://github.com/user-attachments/assets/09a99896-3e74-48f2-b698-f993ae37f45d)

     Se a resposta estiver incorreta, irá emitir um som e a mensagem no visor LCD
      ![Errou a pergunta](https://github.com/user-attachments/assets/e3b83236-1293-4c1e-8f86-ee02f27e5319)

     O jogador terá direito de pular uma unica pergunta (Esgotar o tempo e não responder), que a mesma será exibida
    ao final das demais perguntas.

      ![Imagem do tempo no visor do LCD](https://github.com/user-attachments/assets/798d0dfa-c4f9-426d-8690-5761c99aa1a9)
      
      ![Pulou pergunta](https://github.com/user-attachments/assets/67003a53-1d15-4d36-9d42-7a837aa6ff8a)

      

