/*
 *CAPITULO IV: PERIFERICOS ESPECIALES
 *DEBER 4.2: MANEJ0 DE INTERRUPCIONES
 *OBJETIVO: ACTIVAR JUEGO DE LEDS POR MEDIO DE LA INTERRUPCION 0 Y LA SELECCION DEL NUMERO DE VECES QUE QUERRAMOS JUGAR SE HARA CON LA OTRA INTERRUPCION 1
 *NOMBRE: RAFAEL FARINANGO
 */

const int leds[6] = {13,12,11,10,9,8};
volatile int on = 0;
int cont = 0;
int a = 0;
boolean bandera = false;


void setup() {
  Serial.begin(9600);
  Serial.println("INICIO DEL SISTEMA");
  for(int i=0; i<6 ;i++){
    pinMode(leds[i],OUTPUT);
  }
  attachInterrupt(0,activacion,RISING);    //interupcion 0 se habilita
  attachInterrupt(1,contador,RISING);
}


void loop() {

}


void activacion(){
  cont++;
  //Serial.println(cont);
  if(cont == 1){
    Serial.println("Ingrese el numero de veces a jugar:");
  }
  else if (cont == 2){
    bandera = true;
    //Serial.println("Inicio del juego");
    luces();
  }
  else{
    Serial.println("Fin del juego :) ");
    on = 0;
    cont = 0;
    bandera = false;
  }
}


void contador(){
  if(cont == 1){
  on++;
  Serial.println(String("Juega ")+String(on)+String(" veces"));
  }
}


void luces(){
  if(bandera == true){
    for(int i=0; i<on; i++){
      for(int j=0; j<6; j++){
        digitalWrite(leds[j],HIGH);
        delay(30000);
        digitalWrite(leds[j],LOW);
        delay(30000);
      }
    }
  }
}
