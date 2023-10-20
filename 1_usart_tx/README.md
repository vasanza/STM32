# ⭐⭐⭐⭐⭐ (Arm Cortex-M4) USART serial communication

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
![nucleo](https://github.com/vasanza/STM32/assets/12642226/5645a53e-c9e9-49b1-9f98-01fbad3fd3ec)

## USART Serial Communication Practice
Welcome to our USART Serial Communication Practice Tutorial! In this session, we explore USART communication using the NUCLEO-F446RE model. Our goal is to establish a bidirectional connection between the STM32F446RE microcontroller and an external device. We'll configure parameters like transmission speed and data format. This practice is crucial for applications involving sensors, displays, and microcontrollers. The STM32F446RE, with its Cortex-M4 core, ensures rapid and reliable communication. Join us in mastering USART communication and unlocking the potential for high-performance systems. Happy learning!

### ✅ practice description:
The practice of USART serial communication with the NUCLEO-F446RE model has a specific objective: to establish a bidirectional communication link between the STM32F446RE microcontroller and an external device. This connection is facilitated through the use of the USART (Universal Synchronous/Asynchronous Receiver/Transmitter) protocol. The STM32F446RE microcontroller, on which this communication method is implemented, stands out as an advanced device built upon the Arm Cortex-M4 core. Operating at a high frequency of 180 MHz, this microcontroller possesses remarkable processing capabilities, allowing it to swiftly and efficiently execute a wide array of data processing tasks.

To carry out the practice, the transmission (TX) and reception (RX) pins of the microcontroller's USART will be connected to the corresponding serial communication pins of the external device. Additionally, serial communication parameters such as transmission speed, data format (number of bits, parity, and stop bits), and transmission mode (synchronous or asynchronous) will be configured according to the application's requirements.

Once the configuration is set, the microcontroller will send data to the external device through the TX pin and receive data back through the RX pin. This will allow the exchange of information between both devices efficiently.

USART serial communication practice is essential in applications where data transfer is critical, such as communication with sensors, actuators, displays, or even other microcontrollers. With the STM32F446RE and its Arm® Cortex®-M4 core, reliable and fast serial communication can be achieved, making this microcontroller an excellent choice for various industrial, automation, and embedded electronics applications.

By mastering the configuration and usage of USART in this model, developers can fully harness its potential to implement complex and high-performance systems.

### ✅ Steps:
## Selection of the STM32F446RE Development Board:
- Choose the NUCLEO-F446RE board as the foundation for the practice. Ensure all necessary components are correctly connected.
![uart2](https://github.com/vasanza/STM32/assets/12642226/e1780153-6cae-4052-9bd4-7303efe4d19a)
![uart3](https://github.com/vasanza/STM32/assets/12642226/7884bf80-70e2-4a80-9320-936fa2ab9de8)

## Including the .h Files of Devices and Drivers:
- Add the header (.h) files of the devices and drivers required for USART communication. These files are essential for proper interaction with the microcontroller's peripherals.
![uart4](https://github.com/vasanza/STM32/assets/12642226/61b44ee5-37c9-46fd-9eb7-1eba41dea17b)

## Write the Code to be Used:
- Write the code in the corresponding source file. Implement the necessary functions and configurations for USART communication initialization and handling. Ensure adherence to best programming practices.
![uart](https://github.com/vasanza/STM32/assets/12642226/d03c0476-546a-4f85-8dc6-1f015bf0130c)

## Compile the Project:
- Compile the project using the selected development environment (e.g., STM32CubeIDE). Verify there are no compilation errors and the code compiles correctly for the STM32F446RE microcontroller.
![uart5](https://github.com/vasanza/STM32/assets/12642226/d5026045-6802-4261-adee-c62b8f50cf1e)

## Data Transmission Tests:
- Perform data transmission tests to verify bidirectional communication between the microcontroller and the external device. In this step, send and receive data through the USART transmission (TX) and reception (RX) pins.
![uart6](https://github.com/vasanza/STM32/assets/12642226/dd3a4f6c-4212-45d1-84b7-67b4cf61ac5b)

## Folders of the codes:
![image](https://github.com/vasanza/STM32/assets/12642226/a69509af-89e0-45a6-93ca-d7ac08d6a8fb)

### ✅ Conclusions:
- In this section, share the conclusions drawn from the practice. Discuss encountered challenges, implemented solutions, and lessons learned. Analyze how USART serial communication is applied in real-world scenarios and emphasize the importance of understanding and mastering this technology in the context of microcontroller programming.
