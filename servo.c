#include "servo.h"
#include "hardware/pwm.h"
#include "pico/stdlib.h"
#include <stdio.h>

// Variáveis globais
uint slice_num;
uint channel;

void uart_config() {
  uart_init(uart0, 115200);
  gpio_set_function(false, GPIO_FUNC_UART);
  gpio_set_function(true, GPIO_FUNC_UART);
}
uint16_t calcula_pulso(uint16_t angulo) {
    return 500 + (angulo * (2400 - 500) / 180);
}
void posicao(uint16_t pulse_us) {
    uint16_t level = (pulse_us * TOP) / 20000;
    pwm_set_chan_level(slice_num, channel, level);
}
void servo_config() {
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);
    slice_num = pwm_gpio_to_slice_num(SERVO_PIN);
    channel = pwm_gpio_to_channel(SERVO_PIN);

    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, CLOCK_DIVIDER);
    pwm_config_set_wrap(&config, TOP);
    pwm_init(slice_num, &config, true);
}
void movimentos() {
    uart_puts(uart0, "Posição: 180°\r\n");
    posicao(calcula_pulso(0));
    sleep_ms(5000);

    uart_puts(uart0, "Posição: 90°\r\n");
    posicao(calcula_pulso(90));
    sleep_ms(5000);

    uart_puts(uart0, "Posição: 0°\r\n");
    posicao(calcula_pulso(180));
    sleep_ms(5000);

    uart_puts(uart0, "Movimento suave entre 0° e 180°\r\n");
}
 // Loop contínuo para o movimento suave do servo
 // Incremento de 5 graus a cada 5 us
void servo_loop() {
    for (uint16_t angulo = 180; angulo > 0; angulo--) {
        posicao(calcula_pulso(angulo));
        sleep_ms(10);
    }

    for (uint16_t angulo = 0; angulo <= 180; angulo++) {
        posicao(calcula_pulso(angulo));
        sleep_ms(10);
    }
}