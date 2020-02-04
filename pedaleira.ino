//Código desenvolvido por Glauber Santos Monteiro 
// baseado em pesquisas de arduino e documentações sobre midi - código beta.

byte powerled = 13; // led do power (ligado  - on)

void setup() {
   // set up the LCD's number of columns and rows: 
  //lcd.begin(16, 2);
  // Print a message to the LCD.

  Serial.begin(31250); // baud rate deve está igual aos sofwares conversores midi como o s2mi ou o hairless midiserial, como também virtualizar o canal midi (midi yoke)
   pinMode(powerled,OUTPUT); // saída para o pino 13 led
   pinMode(7,INPUT);  // pino digital deve declarar - entrada do botão - foothihat 
   pinMode(8,INPUT);  // pino digital deve declarar - entrada do botão - foothihat 
   pinMode(9,INPUT);  // pino digital deve declarar - entrada do botão - foothihat 
   pinMode(10,INPUT);  // pino digital deve declarar - entrada do botão - foothihat 
   
        
  }

  
void loop() {
  
    byte botao1 = digitalRead(7); // leitura da porta digital 7 - pedal digital
    if (botao1 == 1)  { // ativa o botão q seleciona o efeito
      
      noteOn(0x90, 57, 40);// função para emitir o efeito 
      botao1 = digitalRead(7);// variavel recebe a porta digital 7 do arduino

   }
       byte botao2 = digitalRead(8); // leitura da porta digital 7 - pedal digital
    if (botao2 == 1)  { // ativa o botão q seleciona o efeito
      
      noteOn(0x90, 58, 40);// função para emitir o efeito 
      botao2 = digitalRead(8);// variavel recebe a porta digital 7 do arduino

     
   }

       byte botao3 = digitalRead(9); // leitura da porta digital 7 - pedal digital
    if (botao3 == 1)  { // ativa o botão q seleciona o efeito
      
      noteOn(0x90, 59, 40);// função para emitir o efeito 
      botao3 = digitalRead(9);// variavel recebe a porta digital 7 do arduino 
   }

       byte botao4 = digitalRead(10); // leitura da porta digital 7 - pedal digital
    if (botao4 == 1)  { // ativa o botão q seleciona o efeito
      
      noteOn(0x90, 60, 40);// função para emitir o efeito 
      botao4 = digitalRead(10);// variavel recebe a porta digital 7 do arduino

   }

 } // fim void loop
 
 byte noteOn(byte cmd, byte pitch, byte velocity) { // função que exibe o canal midi, a nota e a dinamica(velocity) ao tocar o piezo
 
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}
/*obs: não deixar os fios se tocarem na parte eletrônica, pois é propício a erros de notas vazadas e outros, a cor verde e dourada 
 do resistor de 1M, o fio fica conectado para o lado da porta analog in*/
