#define POT A0 //Definindo o Potênciometro
#define button0 9 //Definindo o botão do modo 0
#define button1 11 //Definindo o botão do modo 1
#define button2 12 //Definindo o botão que inicia o sistema
#define button3 13 //Definindo o botão que desabilita o sistema

int LEDS [] = {2,3,4,5,6,7,8,10}; //Definindo Vetor de Leds
int variacao; //Variavel que ira guardar o valor atual do potêncimetro
bool aux = 0; //Variavel auxiliar que irá armazanar valor lógico do botão que habilita o sistema
bool auxoff = 0; //Variavel auxiliar que irá armazanar valor lógico do botão que desabilita o sistema
bool aux_modo0 = 0; //Variavel auxiliar que irá armazanar valor lógico do botão que ativa o modo 0
bool aux_modo1 = 0; //Variavel auxiliar que irá armazanar valor lógico do botão que ativa o modo 1

void setup()
{
  pinMode(POT, INPUT); //Indicando o potênciometro como entrada
  pinMode(button0, INPUT_PULLUP); //Indicando o botão como entrada
  pinMode(button1, INPUT_PULLUP); //Indicando o botão como entrada
  pinMode(button2, INPUT_PULLUP); //Indicando o botão como entrada
  pinMode(button3, INPUT_PULLUP); //Indicando o botão como entrada

  for(int i=0; i<=7;i++){ //Laço for pra indicar que todos os leds são saídas
    pinMode(LEDS[i], OUTPUT);
  }
   for(int i=0; i<=7;i++){ //Laço for pra indicar que todos os leds inciaram apagados
    digitalWrite(LEDS[i], LOW);
  }
  Serial.begin(9600); //Indicando a frequencia da porta serial
}

void loop()
{
  int valor_button2 = digitalRead(button2); //Leitura do valor do botao que habilita o sistema
  int valor_button3 = digitalRead(button3); //Leitura do valor do botao que habilita o sistema
  if (valor_button2 == 1){ //Condição logica para guardar na variavel auxiliar o valor logico do botão quando o mesmo for precionado
    aux = 1;
  }
  if (valor_button3 == 1){ //Condição logica para guardar na variavel auxiliar o valor logico do botão quando o mesmo for precionado
    auxoff = 1;
  }
  
  while(aux == 1 && auxoff == 0){
    int valor_button = digitalRead(button0); //Leitura do botao do modo 0
    int valor_button1 = digitalRead(button1); //Leitura do botao do modo 1
    if (valor_button == 1){ //Condição logica para guardar na variavel auxiliar o valor logico do botão quando o mesmo for precionado
    aux_modo0 = 1;
  }
     if (valor_button1 == 1){ //Condição logica para guardar na variavel auxiliar o valor logico do botão quando o mesmo for precionado
    aux_modo1 = 1;
  }
     
    while(aux_modo0 == 1 && aux_modo1 == 0){
      int valor_POT = analogRead(POT);
      int valor_button1 = digitalRead(button1); ////Botao do modo 1
      int valor_button3 = digitalRead(button3); //Leitura do valor do botao que habilita o sistema
      int variacao = map(valor_POT,0,1023,0,180); //Utilizando a função map para transformar a faixa de valor do potenciomento 0-1023 para
      //uma faixa menor, entre 0-180, que será os valores de variação do ângulo.
      
       if (valor_button1 == 1){ //Condição para atribuir valor lógico 1 a auxiliar do modo 1.
        aux_modo1 = 1;
    }
       
      if(variacao < 45){ //Condição para os ângulos de 0º a 45º
        digitalWrite(LEDS[0], LOW);
        digitalWrite(LEDS[1], LOW);
        digitalWrite(LEDS[2], LOW);
        digitalWrite(LEDS[3], HIGH);
        digitalWrite(LEDS[4], LOW);
        digitalWrite(LEDS[5], LOW);
        digitalWrite(LEDS[6], LOW);
        digitalWrite(LEDS[7], LOW);
      }else{   
          if(variacao >= 45 && variacao < 90){ //Condição para os ângulos de 45º a 89º
            digitalWrite(LEDS[0], LOW);
            digitalWrite(LEDS[1], LOW);
            digitalWrite(LEDS[2], HIGH);
            digitalWrite(LEDS[3], LOW);
            digitalWrite(LEDS[4], HIGH);
            digitalWrite(LEDS[5], LOW);
            digitalWrite(LEDS[6], LOW);
            digitalWrite(LEDS[7], LOW);
          }else{
            if(variacao >= 90 && variacao < 135){ //Condição para os ângulos de 90º a 134º
              digitalWrite(LEDS[0], HIGH);
              digitalWrite(LEDS[1], LOW);
              digitalWrite(LEDS[2], LOW);
              digitalWrite(LEDS[3], LOW);
              digitalWrite(LEDS[4], LOW);
              digitalWrite(LEDS[5], LOW);
              digitalWrite(LEDS[6], LOW);
              digitalWrite(LEDS[7], HIGH);
            }else{
              if(variacao >= 135 && variacao < 180){ //Condição para os ângulos de 135º a 179º
                digitalWrite(LEDS[0], LOW);
                digitalWrite(LEDS[1], HIGH);
                digitalWrite(LEDS[2], LOW);
                digitalWrite(LEDS[3], LOW);
                digitalWrite(LEDS[4], LOW);
                digitalWrite(LEDS[5], HIGH);
                digitalWrite(LEDS[6], LOW);
                digitalWrite(LEDS[7], LOW);
              }else{
                if(variacao >= 180){//Condição para o ângulo de 180º
                  digitalWrite(LEDS[1], LOW);
                  digitalWrite(LEDS[2], LOW);
                  digitalWrite(LEDS[3], LOW);
                  digitalWrite(LEDS[4], LOW);
                  digitalWrite(LEDS[5], LOW);
                  digitalWrite(LEDS[6], HIGH);
                  digitalWrite(LEDS[7], LOW);
                }
        } //Fim else
       } //Fim else
      }//Fim else
     }//Fim else 
        if (valor_button3 == 1){ //Condição para quando o botao de desabilitação do sistema for ativado.
          aux_modo0 = 0;
          aux_modo1 = 0;
          auxoff = 0;
          for(int i=0; i<=7;i++){ //Laço for pra indicar que todos os leds inciaram apagados
              digitalWrite(LEDS[i], LOW);
          }
      }
    }//Fim While aux modo 0
    aux_modo0 = 0; //Zerando a variavel auxiliar após sair do loop do modo 0.
    
    while(aux_modo1 == 1 && aux_modo0 == 0){
      int valor_POT = analogRead(POT);
      int valor_button1 = digitalRead(button0); ////Botao do modo 1
      int valor_button3 = digitalRead(button3); //Leitura do valor do botao que habilita o sistema
      int variacao = map(valor_POT,0,1023,-90,90);
      
       if (valor_button == 1){
        aux_modo0 = 1;
    }
      
      if(variacao < -80){
        digitalWrite(LEDS[0], LOW);
        digitalWrite(LEDS[1], LOW);
        digitalWrite(LEDS[2], LOW);
        digitalWrite(LEDS[3], LOW);
        digitalWrite(LEDS[4], LOW);
        digitalWrite(LEDS[5], LOW);
        digitalWrite(LEDS[6], LOW);
        digitalWrite(LEDS[7], HIGH);
      }else{   
          if(variacao >= -80 && variacao < -50){
            digitalWrite(LEDS[0], LOW);
            digitalWrite(LEDS[1], LOW);
            digitalWrite(LEDS[2], LOW);
            digitalWrite(LEDS[3], LOW);
            digitalWrite(LEDS[4], HIGH);
            digitalWrite(LEDS[5], HIGH);
            digitalWrite(LEDS[6], LOW);
            digitalWrite(LEDS[7], LOW);
          }else{
            if(variacao >= -50 && variacao < 0){
              digitalWrite(LEDS[0], LOW);
              digitalWrite(LEDS[1], LOW);
              digitalWrite(LEDS[2], LOW);
              digitalWrite(LEDS[3], HIGH);
              digitalWrite(LEDS[4], LOW);
              digitalWrite(LEDS[5], LOW);
              digitalWrite(LEDS[6], HIGH);
              digitalWrite(LEDS[7], LOW);
            }else{
              if(variacao >= 0 && variacao < 45){
                digitalWrite(LEDS[0], LOW);
                digitalWrite(LEDS[1], HIGH);
                digitalWrite(LEDS[2], HIGH);
                digitalWrite(LEDS[3], LOW);
                digitalWrite(LEDS[4], LOW);
                digitalWrite(LEDS[5], LOW);
                digitalWrite(LEDS[6], LOW);
                digitalWrite(LEDS[7], LOW);
              }else{
                if(variacao >= 45){
                  digitalWrite(LEDS[0], HIGH);
                  digitalWrite(LEDS[1], LOW);
                  digitalWrite(LEDS[2], LOW);
                  digitalWrite(LEDS[3], LOW);
                  digitalWrite(LEDS[4], LOW);
                  digitalWrite(LEDS[5], LOW);
                  digitalWrite(LEDS[6], LOW);
                  digitalWrite(LEDS[7], LOW);
                }
        } //Fim else
       } //Fim else
      }//Fim else
     }//Fim else
      if (valor_button3 == 1){
          aux_modo0 = 0;
          aux_modo1 = 0;
          auxoff = 0;
          for(int i=0; i<=7;i++){ //Laço for pra indicar que todos os leds inciaram apagados
              digitalWrite(LEDS[i], LOW);
          }
      }
    }//Fim do modo 1
    aux_modo1 = 0;
  }//Fim while aux 1
}//Fim Loop
