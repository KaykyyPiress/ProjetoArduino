# Projeto Arduino

##  O projeto consiste em um jogo de memorização e de perguntas.

  Este programa foi desenvolvido em C++ e para ser usado com Arduino. 

  Instruções para uso do programa:

   ### 1- Monte o circuito conforme a imagem abaixo, para melhor funcionalidade do programa.
    
   ### ![Imagem do circuito do programa](https://github.com/user-attachments/assets/a22987d6-fb36-41fb-93b4-ca88be058b6a)

   ### 2- Copie o codigo ou baixe o arquivo main.c que esta no repositorio.

   ### 3- Abra o Arduino e execute o codigo do programa para iniciar o jogo.


## Como é o jogo e como jogar:

   ###  Quando se inicia o jogo, ele exibe uma mensagem no LCD uma mensagem para pressionar o botão de inicio para começar.
   ###   (Botão de inicio é o isolado do lado esquerdo)
      
  ###    ![Imagem do Inicio do jogo](https://github.com/user-attachments/assets/1b5e1bb4-d3fd-439f-8eeb-4bb163e409d0)

   ###  Após iniciar o jogo, ele começa com o jogo da memoria, onde os leds irão piscar 10 vezes e que o jogador deverá
  ###  memorizar e apertar os botões conforme a sequência. 

   ###   (Botão para o led verde esta no lado direito, e botão do led vermelho esta do lado direito, no centro da segunda protoboard).
      
   ###  A cada acerto a quantidade de acertos no LCD irá aumentar.

   ###   ![Imagem do visor com a quantidade de acertos](https://github.com/user-attachments/assets/da743b77-3a69-4398-9019-d97857b031a7)

  ###   Caso erre a sequência o jogo irá parar e exibirá a mensagem para iniciar novamente. Caso acerte a sequência, o
  ###  jogador ira passar para a proxima fase que é a de perguntas. 
    
  ###   Está fase é composta de 5 perguntas, onde o jogador não poderá errar nenhuma resposta. Caso erre alguma
  ###  o jogo sera reiniciado.

   ###   ![Imagem da pergunta no visor LCD](https://github.com/user-attachments/assets/6c49bb75-2db6-468e-b90a-36572ec9e785)

   ###  Se a resposta estiver correta, irá emitir um som e a mensagem no visor LCD
     
   ###   ![Acertou a pergunta](https://github.com/user-attachments/assets/09a99896-3e74-48f2-b698-f993ae37f45d)

   ###  Se a resposta estiver incorreta, irá emitir um som e a mensagem no visor LCD
   ###   ![Errou a pergunta](https://github.com/user-attachments/assets/e3b83236-1293-4c1e-8f86-ee02f27e5319)

   ###  O jogador terá direito de pular uma unica pergunta (Esgotar o tempo e não responder), que a mesma será exibida
   ### ao final das demais perguntas.

   ###   ![Imagem do tempo no visor do LCD](https://github.com/user-attachments/assets/798d0dfa-c4f9-426d-8690-5761c99aa1a9)
      
   ###   ![Pulou pergunta](https://github.com/user-attachments/assets/67003a53-1d15-4d36-9d42-7a837aa6ff8a)
      
   ###   Após iniciado o jogo de perguntas, uma pergunta vai aparecer no LCD
   ###   ![imagem_com_pergunta_no_lcd](https://github.com/user-attachments/assets/8e772cea-3800-481a-8e36-4bd8e79c88db)

   ###   O jogador pode reponder sim ou não utilizando os botões dos leds
   ###   ![botoes_sim_e_nao](https://github.com/user-attachments/assets/310a6ae0-34cf-4714-816a-10801e66620d)

   ###   Depois de selecionar se sim ou não, no LCD irá aparecer um "*" na opção selecionada juntamente com o tempo restante
   ###   ![imagem_com_sim_selecionado](https://github.com/user-attachments/assets/f1763273-c206-4e45-aad2-805ac1d700d1)

   ###   ![imagem_com_nao_selecionado](https://github.com/user-attachments/assets/1707f5d5-2551-47a3-bf76-90ede00dc345)

   ###   Após o tempo acabar, irá aparecer no LCD se acertou ou errou a pergunta
   ###   ![imagem_acertou](https://github.com/user-attachments/assets/68fa1586-0760-4a79-a47d-ff5c816fd115)

   ###   Assim que acertar todas as cinco perguntas, o usuário irá para a pergunta final
   ###   ![imagem_pergunta_final](https://github.com/user-attachments/assets/d6440070-aa36-4a42-8db7-93e4a3543d6c)

   ###   Caso o usuário acerto a pergunta final, ele mostra que o usuário venceu no LCD
   ###   ![imagem_voce_venceu](https://github.com/user-attachments/assets/99d89366-48cd-4a1b-b284-6a589726cd9f)

   ###   No monitor serial aparece também a sequencia dos leds e as perguntas
   ###   ![imagem_monitorSerial](https://github.com/user-attachments/assets/e6080040-7144-4198-a6d3-5c5da0630a39)

    

      

