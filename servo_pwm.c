/*
Atenilton Júnior
*/

#include "pico/stdlib.h" //Padrão
#include "servo.h"      // Inclui as funções do módulo servo

int main() {
    uart_config();    // Configura UART
    servo_config();  // Habilita a configuração do servo
    movimentos();   // Realiza os primeiros movimentos fixos do servo

    while (true) { servo_movimento_periodico(); }
    return 0;  // Este ponto nunca será alcançado
}