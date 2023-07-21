# Next courses
- https://www.docker.com/
- https://www.jenkins.io/
- https://www.influxdata.com/
- https://grafana.com/
- OTA
- https://www.qt.io/

# STM32
- Modelo: NUCLEO-F446RE
- Processor: STM32F446RE MCU, Arm® Cortex®-M4 core at 180 Mhz.
- Link: https://www.st.com/en/evaluation-tools/nucleo-f446re.html
- Course: https://www.udemy.com/course/embedded-systems-bare-metal-programming/?start=720#overview

# All features
- Common features
-- STM32 microcontroller in an LQFP64 or LQFP48 package
-- 1 user LED shared with ARDUINO®
-- 1 user and 1 reset push-buttons
-- 32.768 kHz crystal oscillator
- Board connectors:
- -- ARDUINO® Uno V3 expansion connector
-- ST morpho extension pin headers for full access to all STM32 I/Os
-- Flexible power-supply options: ST-LINK USB VBUS or external sources
-- On-board ST-LINK debugger/programmer with USB re-enumeration capability: mass storage, Virtual COM port, and debug port
-- Comprehensive free software libraries and examples available with the STM32Cube MCU Package
-- Support of a wide choice of Integrated Development Environments (IDEs) including IAR Embedded Workbench®, MDK-ARM, and STM32CubeIDE
- Board-specific features
-- External SMPS to generate Vcore logic supply
-- 24 MHz or 48 MHz HSE
-- User USB Device full speed, or USB SNK/UFP full speed
-- Cryptography
- Board connectors:
-- External SMPS experimentation dedicated connector
-- USB Type-C®, Micro-B, or Mini-B connector for the ST-LINK
-- USB Type-C® user connector
-- MIPI® debug connector

![WhatsApp Image 2023-07-20 at 21 34 34](https://github.com/vasanza/STM32/assets/12642226/403a2232-6ea6-4c9a-b0f1-54bdc53203a7)

# Development Plan
## Day1
- Recursos Iniciales
- IDE: STM32CubeIDE 1.11.2
## UART Comunication
- Example # 1 UART
- Detail:
--UART1 TX PA9
--UART1 RX PA10
- Process
-- Clock Source: AHB1, APB1
-- GPIOEN, AF7, UARTEN
## GPIO
- Example # 2 GPIO
- Detail:
--Led blink PA5
- Process
-- Clock Source: AHB1
-- GPIOEN, MODER, ODR
## ADC
- Example # 8 ADC
- Detail: Use of ADC register for digitalization acquisition of analog signals.
- Development board: STM32F446RE
- Processor: Arm® Cortex®-M4 32-bit--ADC PA2
- Link: https://github.com/vasanza/STM32/tree/main/8_adc_nucleo_cgpt
## Timer
- Example # 4 Timer
- Detail:
--Timer Registers
- Process
-- Clock Source: AHB1
-- GPIOEN, MODER, ODR
