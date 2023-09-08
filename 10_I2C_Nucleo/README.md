# ⭐⭐⭐⭐⭐ (Arm Cortex-M4) I2C
## ✅ Developed by: [John Rivera Burgos](https://www.linkedin.com/in/john-rivera-burgos-bb703079/)
## ➡️ Device:
- Development Board: [NUCLEO-F446RE](https://www.st.com/en/evaluation-tools/nucleo-f446re.html)
- Processor: [STM32F446RE MCU, Arm® Cortex®-M4 core at 180 Mhz](https://www.st.com/en/microcontrollers-microprocessors/stm32f446re.html)
## ➡️ Compiler:
- [STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html)
## ⭐ Device provided by:
- [EcuaPlus](https://www.facebook.com/Ecuapluss/?locale=es_LA)
## ⭐ When using this resource, please cite the original publication:
- [Avilés-Mendoza, K., Gaibor-León, N. G., Asanza, V., Lorente-Leyva, L. L., & Peluffo-Ordóñez, D. H. (2023). A 3D Printed, Bionic Hand Powered by EMG Signals and Controlled by an Online Neural Network. Biomimetics, 8(2), 255.](https://www.mdpi.com/2313-7673/8/2/255)

![nucleo](https://github.com/vasanza/STM32/assets/12642226/d1d58c13-dedf-4f7f-9a4d-3b7176690220)

## Práctica I2C
I2C stands for Inter-Integrated Circuit. It is a bus interface connection protocol incorporated into devices for serial communication. It was originally designed by Philips Semiconductor in 1982. Recently, it is a widely used protocol for short-distance communication.

Certainly! I2C, which stands for Inter-Integrated Circuit, is a popular serial communication protocol used in electronic devices for exchanging data between a master device (like a microcontroller) and multiple slave devices. It's a two-wire communication protocol consisting of a data line (SDA) and a clock line (SCL).

Here's a brief overview of I2C:

1. **SDA (Serial Data)**: This line carries the actual data between the master and slave devices.

2. **SCL (Serial Clock)**: This line carries the clock signal that synchronizes the data transmission.

3. **Master and Slave Devices**: In an I2C bus, there's usually one master device that initiates communication and one or more slave devices that respond to the master's requests.

4. **Addresses**: Each slave device on the bus has a unique address. The master device uses this address to communicate with a specific slave.

5. **Data Transfer**: Data is transferred in packets of 8 bits (1 byte) with an additional bit for acknowledging the reception of data.

Now, let's talk about STM32Cube IDE:

**STM32Cube IDE** is an Integrated Development Environment (IDE) provided by STMicroelectronics for programming their STM32 microcontrollers. It's based on the Eclipse platform and is designed specifically for STM32 microcontrollers.

Key features of STM32Cube IDE include:

1. **Support for STM32 Microcontrollers**: It's tailored for working with STM32 microcontrollers, which are based on ARM Cortex-M cores.

2. **HAL (Hardware Abstraction Layer)**: STM32Cube IDE comes with a HAL library that provides an abstraction layer between the hardware and the application code, making it easier to configure and use peripheral devices.

3. **CubeMX Integration**: It's tightly integrated with STM32CubeMX, a graphical software configuration tool that allows you to set up peripheral configurations, clock settings, and generate initialization code for your project.

4. **Debugger and Emulator Support**: It supports debugging using ST-Link, which is STMicroelectronics' debugging and programming interface.

5. **Peripheral Drivers**: The IDE provides pre-written drivers for the STM32 peripherals, which simplifies the process of interfacing with hardware components.

6. **RTOS (Real-Time Operating System) Support**: It includes support for popular RTOS like FreeRTOS, making it easier to develop multitasking applications.

In the context of I2C, STM32Cube IDE provides libraries and examples for configuring and using the I2C peripheral on STM32 microcontrollers, making it relatively straightforward to implement I2C communication in your projects.

Keep in mind that my knowledge is based on information available up until September 2021, and there might have been updates or changes after that date.

## Steps
## Seleccion de la tarjeta de desarrollo STM32F446RE
![uart2](https://github.com/vasanza/STM32/assets/12642226/e1780153-6cae-4052-9bd4-7303efe4d19a)
![uart3](https://github.com/vasanza/STM32/assets/12642226/7884bf80-70e2-4a80-9320-936fa2ab9de8)
## Incorporar las achivos .h de los devices y los drivers
![uart4](https://github.com/vasanza/STM32/assets/12642226/61b44ee5-37c9-46fd-9eb7-1eba41dea17b)
## Escribir el codigo a utilizar
![image](https://github.com/vasanza/STM32/assets/62295761/1ea4694e-0f4f-4e3f-abb3-8bf3b4791871)

## Compilar .h & .c
![image](https://github.com/vasanza/STM32/assets/62295761/21820a64-a310-4e7d-b347-5d91b67d1522)

![image](https://github.com/vasanza/STM32/assets/62295761/5896ea35-e5bc-470a-b3ce-b86b4d1d1513)

![image](https://github.com/vasanza/STM32/assets/62295761/8e377fec-c90f-4bc0-8fed-94d2eb9c3902)

![image](https://github.com/vasanza/STM32/assets/62295761/d301643c-a281-405f-b540-4ea996bf2317)

## Debug
![image](https://github.com/vasanza/STM32/assets/62295761/473dd3e5-8f2a-40c3-8e20-ea16baa69096)
