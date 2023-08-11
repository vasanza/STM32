# ⭐⭐⭐⭐⭐ (Arm Cortex-M4) USART-RX serial communication
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

## Práctica comunicacion serial USART
La práctica de comunicación serial USART con el modelo NUCLEO-F446RE tiene como objetivo establecer una comunicación bidireccional entre el microcontrolador STM32F446RE y otro dispositivo externo mediante el protocolo USART (Universal Synchronous/Asynchronous Receiver/Transmitter). El STM32F446RE es un microcontrolador avanzado basado en el núcleo Arm® Cortex®-M4 que opera a una frecuencia de 180 MHz, lo que le permite realizar tareas de procesamiento de datos de manera rápida y eficiente.
Para llevar a cabo la práctica, se conectarán los pines de transmisión (TX) y recepción (RX) del USART del microcontrolador a los correspondientes pines de comunicación serial del dispositivo externo. Además, se configurarán los parámetros de comunicación serial, como la velocidad de transmisión, el formato de datos (número de bits, paridad y bits de parada) y el modo de transmisión (síncrono o asíncrono), según las necesidades de la aplicación.
Una vez establecida la configuración, el microcontrolador enviará datos al dispositivo externo a través del pin TX y recibirá datos de vuelta a través del pin RX. Esto permitirá intercambiar información entre ambos dispositivos de manera eficiente.
La práctica de comunicación serial USART es fundamental en aplicaciones donde la transferencia de datos es crítica, como la comunicación con sensores, actuadores, pantallas o incluso con otros microcontroladores. Con el STM32F446RE y su núcleo Arm® Cortex®-M4, se puede lograr una comunicación serial confiable y rápida, lo que hace que este microcontrolador sea una opción excelente para diversas aplicaciones industriales, de automatización y electrónica embebida. Al dominar la configuración y uso del USART en este modelo, los desarrolladores pueden aprovechar al máximo su potencial para implementar sistemas complejos y de alto rendimiento.

## Steps
## Seleccion de la tarjeta de desarrollo STM32F446RE
![uart2](https://github.com/vasanza/STM32/assets/12642226/e1780153-6cae-4052-9bd4-7303efe4d19a)
![uart3](https://github.com/vasanza/STM32/assets/12642226/7884bf80-70e2-4a80-9320-936fa2ab9de8)
## Incorporar las achivos .h de los devices y los drivers
![uart4](https://github.com/vasanza/STM32/assets/12642226/61b44ee5-37c9-46fd-9eb7-1eba41dea17b)
## Escribir el codigo a utilizar
![uart](https://github.com/vasanza/STM32/assets/12642226/d03c0476-546a-4f85-8dc6-1f015bf0130c)
## Compilar
![uart5](https://github.com/vasanza/STM32/assets/12642226/d5026045-6802-4261-adee-c62b8f50cf1e)
## Pruebas de envio de datos
![uart6](https://github.com/vasanza/STM32/assets/12642226/dd3a4f6c-4212-45d1-84b7-67b4cf61ac5b)
