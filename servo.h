#ifndef SERVO_H
#define SERVO_H

#include "hardware/pwm.h"
#include "pico/stdlib.h"
#include <stdio.h>

// Definições de parâmetros do PWM
#define PWM_FREQ 50
#define TOP 25000
#define SERVO_PIN 22
#define CLOCK_DIVIDER 100.0f

// Declaração de funções
void uart_config();
uint16_t calcula_pulso(uint16_t angulo);
void posicao(uint16_t pulse_us);
void servo_config();
void movimentos();
void servo_movimento_periodico();

#endif