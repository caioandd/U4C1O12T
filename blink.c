#include <stdio.h>
#include "pico/stdlib.h"

const uint led_pin_red = 13;

void ponto(){
  gpio_put(led_pin_red,true);
  sleep_ms(200);//LED aceso por 200ms
  gpio_put(led_pin_red,false);
  sleep_ms(125);//LED apagado por 125ms
}
void traco(){
  gpio_put(led_pin_red,true);
  sleep_ms(800);//LED aceso por 800ms
  gpio_put(led_pin_red,false);
  sleep_ms(125);//LED apagado por 125ms
}
void tmed(){
  sleep_ms(125);//125+125=250 -> intervalo entre letras
}
void tfinal(){
  sleep_ms(2875);//125+2875=3000 -> intervalo para reinício do sinal SOS
}
void palavra(){
    ponto();ponto();ponto();tmed();//S
    traco();traco();traco();tmed();//O
    ponto();ponto();ponto();tfinal();//S
}

int main(){
  gpio_init(led_pin_red);
  gpio_set_dir(led_pin_red, GPIO_OUT);
  palavra();
  while (true){
    palavra();
  }
  return 0;
}