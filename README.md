# ⭐⭐⭐⭐⭐ Arm Cortex-M4

Explore the 'ARM Cortex-M4' repository, where innovation meets performance. Powered by the STM32F446RE MCU with an Arm® Cortex®-M4 core operating at 180 MHz, and utilizing the NUCLEO-F446RE development board, this repository is a hub for cutting-edge projects. With the support of STM32CubeIDE, dive into a world of seamless development, unleashing the full potential of this advanced microcontroller. Discover, contribute, and elevate your embedded systems skills in this dynamic community of developers."

## ✅ Developed by: [John Rivera Burgos](https://www.linkedin.com/in/john-rivera-burgos-bb703079/) and [vasanza](https://vasanza.blogspot.com/p/about-me.html)
## ➡️ Device:
- Development Board: [NUCLEO-F446RE](https://www.st.com/en/evaluation-tools/nucleo-f446re.html)
- Processor: [STM32F446RE MCU, Arm® Cortex®-M4 core at 180 Mhz](https://www.st.com/en/microcontrollers-microprocessors/stm32f446re.html)

## ➡️ Compiler:
- [STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html)

## ⭐ Device provided by:
- [EcuaPlus](https://www.facebook.com/Ecuapluss/?locale=es_LA)

## ⭐ When using this resource, please cite the original publication:
- [Avilés-Mendoza, K., Gaibor-León, N. G., Asanza, V., Lorente-Leyva, L. L., & Peluffo-Ordóñez, D. H. (2023). A 3D Printed, Bionic Hand Powered by EMG Signals and Controlled by an Online Neural Network. Biomimetics, 8(2), 255.](https://www.mdpi.com/2313-7673/8/2/255)

---
![nucleo](https://github.com/vasanza/STM32/assets/12642226/d1d58c13-dedf-4f7f-9a4d-3b7176690220)

# Summary
- **[USART serial communication - RX](https://github.com/vasanza/STM32/tree/main/2_uart_rx_nucleo)**
- [USART serial communication - TX](https://github.com/vasanza/STM32/tree/main/1_usart_tx)
- [Analog to Digital Converter (ADC)](https://github.com/vasanza/STM32/tree/main/4_adc_nucleo)
- [Inter-Integrated Circuit (I2C)](https://github.com/vasanza/STM32/tree/main/10_I2C_Nucleo)

# STM32
- Modelo: NUCLEO-F446RE
- Processor: STM32F446RE MCU, Arm® Cortex®-M4 core at 180 Mhz.
- Link: https://www.st.com/en/evaluation-tools/nucleo-f446re.html
- Course: https://www.udemy.com/course/embedded-systems-bare-metal-programming/?start=720#overview

# All features
- Common features
- STM32 microcontroller in an LQFP64 or LQFP48 package
- 1 user LED shared with ARDUINO®
- 1 user and 1 reset push-buttons
- 32.768 kHz crystal oscillator
- Board connectors:
- ARDUINO® Uno V3 expansion connector
- ST morpho extension pin headers for full access to all STM32 I/Os
- Flexible power-supply options: ST-LINK USB VBUS or external sources
- On-board ST-LINK debugger/programmer with USB re-enumeration capability: mass storage, Virtual COM port, and debug port
- Comprehensive free software libraries and examples available with the STM32Cube MCU Package
- Support of a wide choice of Integrated Development Environments (IDEs) including IAR Embedded Workbench®, MDK-ARM, and STM32CubeIDE
- Board-specific features
- External SMPS to generate Vcore logic supply
- 24 MHz or 48 MHz HSE
- User USB Device full speed, or USB SNK/UFP full speed
- Cryptography
- Board connectors:
- External SMPS experimentation dedicated connector
- USB Type-C®, Micro-B, or Mini-B connector for the ST-LINK
- USB Type-C® user connector
- MIPI® debug connector

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
