#include "servo.h"  // Biblioteca para controle do servo motor
#include "hardware/pwm.h"  // Biblioteca para controle de PWM
#include "pico/stdlib.h"  // Biblioteca padrão da Raspberry Pi Pico
#include <stdio.h>  // Biblioteca para funções de entrada e saída

// Variáveis globais
uint slice_num;  // Variável para armazenar o número do slice PWM
uint channel;  // Variável para armazenar o canal PWM

void uart_config() {  // Função para configurar a UART
  uart_init(uart0, 115200);  // Inicializa a UART com baud rate de 115200
  gpio_set_function(false, GPIO_FUNC_UART);  // Configura o GPIO 0 como UART
  gpio_set_function(true, GPIO_FUNC_UART);  // Configura o GPIO 1 como UART
}

uint16_t calcula_pulso(uint16_t angulo) {  // Calcula o pulso PWM com base no ângulo
    return 500 + (angulo * (2400 - 500) / 180);  // Retorna o valor do pulso correspondente ao ângulo
}

void posicao(uint16_t pulse_us) {  // Define a posição do servo com base no pulso
    uint16_t level = (pulse_us * TOP) / 20000;  // Calcula o nível PWM baseado no pulso
    pwm_set_chan_level(slice_num, channel, level);  // Define o nível do canal PWM
}

void servo_config() {  // Configura o servo para operar com PWM
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);  // Configura o pino do servo como PWM
    slice_num = pwm_gpio_to_slice_num(SERVO_PIN);  // Obtém o slice correspondente ao pino
    channel = pwm_gpio_to_channel(SERVO_PIN);  // Obtém o canal correspondente ao pino

    pwm_config config = pwm_get_default_config();  // Obtém a configuração padrão do PWM
    pwm_config_set_clkdiv(&config, CLOCK_DIVIDER);  // Define o divisor de clock
    pwm_config_set_wrap(&config, TOP);  // Define o valor de contagem máximo
    pwm_init(slice_num, &config, true);  // Inicializa o PWM com a configuração definida
}

void movimentos() {  // Realiza movimentos predefinidos com o servo
    uart_puts(uart0, "Posição: 180°\r\n");  // Envia mensagem via UART
    posicao(calcula_pulso(0));  // Move o servo para 180°
    sleep_ms(5000);  // Aguarda 5 segundos

    uart_puts(uart0, "Posição: 90°\r\n");  // Envia mensagem via UART
    posicao(calcula_pulso(90));  // Move o servo para 90°
    sleep_ms(5000);  // Aguarda 5 segundos

    uart_puts(uart0, "Posição: 0°\r\n");  // Envia mensagem via UART
    posicao(calcula_pulso(180));  // Move o servo para 0°
    sleep_ms(5000);  // Aguarda 5 segundos

    uart_puts(uart0, "Movimento suave entre 0° e 180°\r\n");  // Envia mensagem via UART
}

void servo_loop() {  // Realiza um loop de movimentação suave do servo
    for (uint16_t angulo = 180; angulo > 0; angulo--) {  // De 180° até 0°
        posicao(calcula_pulso(angulo));  // Define a posição do servo
        sleep_ms(10);  // Aguarda 10 ms
    }

    for (uint16_t angulo = 0; angulo <= 180; angulo++) {  // De 0° até 180°
        posicao(calcula_pulso(angulo));  // Define a posição do servo
        sleep_ms(10);  // Aguarda 10 ms
    }
}

// Incremento de ciclo ativo de ±5µs, com um atraso de ajuste de 10ms
void servo_movimento_periodico() {  // Rotina de movimentação periódica suave
    while (true) {  // Loop infinito para movimentação constante
        for (uint16_t ciclo = 500; ciclo <= 2400; ciclo += 5) {  // Incremento suave de ciclo ativo
            posicao(ciclo);  // Define a posição do servo
            sleep_ms(10);  // Atraso de ajuste de 10 ms
        }
        for (uint16_t ciclo = 2400; ciclo >= 500; ciclo -= 5) {  // Decremento suave de ciclo ativo
            posicao(ciclo);  // Define a posição do servo
            sleep_ms(10);  // Atraso de ajuste de 10 ms
        }
                }
}