### **Ejercicio 1: comunicación entre computador y controlador**


```
void setup() {
  Serial.begin(115200);
}

void loop() {
if(Serial.available()){
if(Serial.read() == '1'){
      Serial.print("Hello from Raspberry Pi Pico");
    }
  }
}
```

- Prueba la aplicación con ScriptCommunicator. ¿Cómo funciona?

  Si se envia el numero 1 a la placa imprimira un mensaje
  
- Analiza:

  ### ¿Por qué es importante considerar las propiedades *PortName* y *BaudRate*?

    Es importante considerar las propiedades PortName y BaudRate al trabajar con comunicación serie por varias razones:

    PortName: Esta propiedad especifica el nombre del puerto serie al que se conectará el programa. En sistemas como Windows, los puertos serie se       
    identifican mediante nombres como COM1, COM2, COM3, etc. En sistemas Unix/Linux, los puertos serie se identifican generalmente como /dev/ttyS0, 
    /dev/ttyS1, etc. Es importante especificar correctamente el nombre del puerto serie al que se conectará el programa para asegurarse de que esté 
    comunicándose con el dispositivo deseado.

    BaudRate: Esta propiedad define la velocidad de transmisión de datos en bits por segundo (baudios). Ambos dispositivos (el que envía y el que recibe) 
    deben estar configurados para la misma velocidad de baudios para que la comunicación sea efectiva. Si los dispositivos están configurados con 
    velocidades de baudios diferentes, la comunicación puede ser inestable o no funcionar en absoluto.
  
   ### ¿Qué relación tienen las propiedades anteriores con el controlador?

     La relación entre estas propiedades y el controlador es directa y crucial para el éxito de la comunicación. El controlador de puerto serie es el     
     software que permite a la computadora interactuar con el hardware del puerto serie (por ejemplo, un puerto USB a serie o un puerto serie integrado en 
     la placa madre). Al configurar correctamente las propiedades PortName y BaudRate, estás informando al controlador sobre cómo comunicarse con el     
     dispositivo conectado al puerto serie. El controlador utiliza esta información para establecer la comunicación con el dispositivo y garantizar que los 
     datos se transmitan correctamente entre la computadora y el dispositivo externo.

-  Ejecuta la aplicación en Unity. Verás un número cambiar rápidamente en pantalla. Ahora presiona la tecla A (no olvides dar click en la pantalla Game). ¿Qué pasa? ¿Por qué crees que ocurra esto?

      porque la seccion del codigo que se encarga de aumentar el contador esta dentro de la funcion update, lo que causa que se actualize en cada frame del 
      juego, es decir si el programa se ejectua a 20 frames por segundo entonces a esa velocidad se actualizara el contador
