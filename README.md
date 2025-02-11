![image](https://github.com/user-attachments/assets/f2a5c9b8-6208-4723-8f46-1d74be421827)

# Controle de Servomotor com PWM 🚀

## Sumário 📑
1. [Descrição do Projeto](#descrição-do-projeto)
2. [Pré-requisitos](#pré-requisitos)
3. [Configuração e Execução](#configuração-e-execução)
4. [Funcionalidades](#funcionalidades)
5. [Resultados](#resultados)
6. [Vídeo Ensaio](#Vídeo-Ensaio)

## Descrição do Projeto 📝
Este projeto tem como objetivo simular o controle do ângulo de um servomotor utilizando o microcontrolador **Raspberry Pi Pico W** e a técnica de **PWM (Pulse Width Modulation)**. A simulação é realizada na plataforma online **Wokwi**.

## Pré-requisitos 🛠️
- Microcontrolador Raspberry Pi Pico W
- Servomotor micro servo padrão (simulado no Wokwi)
- Ambiente de desenvolvimento **VS Code**
- SDK Pico configurado
- Conta no **GitHub** para versionamento

## Configuração e Execução 🧑‍💻
1. Clone o repositório do projeto:
   ```bash
   git clone https://github.com/ateniltonjr/servo_pwm.git
   ```
2. Abra o projeto no VS Code.
3. Certifique-se de que o SDK Pico está configurado corretamente.
4. Conecte o simulador **Wokwi** ao projeto.
5. Compile e execute o código para simular o controle do servomotor.

## Funcionalidades ⚙️
- **Configuração da frequência PWM:**
  - Aproximadamente 50Hz (período de 20ms).
- **Movimentação suave do braço do servomotor:**
  - Posições de 0°, 90° e 180° com espera de 5 segundos.
  - Rotina periódica para movimentação suave entre 0° e 180°.

## Resultados 📊
- O comportamento esperado do servomotor foi alcançado conforme os requisitos.
- O LED RGB conectado à GPIO 12 teve seu brilho fixo nos primeiros 5 segundos, teve uma pequena variação e se manteve fixa durante 5 segundos, apos 15 segundos de execução o brilho passou a variar constantimente durante os testes com a ferramenta BitDogLab.

## Vídeo Ensaio 📝
O vídeo de simulação do servo motor e o experimento com o led RGB podem ser visualizados aqui: [YouTube](###).

---
