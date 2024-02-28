# SFI1-2
segundo repositorio sistemas fisicos interactivos

### **Ejercicio 5: documentación**

Para programar el raspberry pi pico tienes mucha documentación con información. Algunos sitios que pueden serte de utilidad son:

- [API de arduino](https://www.arduino.cc/).
- [Port para raspberry pi pico del API de arduino](https://arduino-pico.readthedocs.io/en/latest/#).
- [Sitio oficial del raspberry pi pico](https://www.raspberrypi.com/products/raspberry-pi-pico/).

En el archivo README.md de este ejercicio realiza por favor con tus palabras, preferiblemente a mano, un resumen de los elementos más importantes que identificaste en esta documentación. No olvides enviarla al repositorio remoto.

**¿Qué es una Raspberry Pi?**

Una Raspberry Pi es un pequeño ordenador de placa única (SBC, por sus siglas en inglés) desarrollado por la Fundación Raspberry Pi, aunque parezca una placa arduino, la Raspberry Pi es se considera mas más potente y versátil, ya que funciona como un microordenador y requiere un sistema operativo para ejecutar una variedad de proyectos complejos.

Gracias a su sistema operativo, la Raspberry Pi se usa comunmente como un ordenador de sobremesa, lo que la distingue de las placas programables como Arduino. Esta versatilidad la ha convertido en una herramienta popular en proyectos de bricolaje, educativos y de desarrollo.

**Características Principales de la Raspberry Pi Pico:**

1. **Microcontrolador RP2040:** La Raspberry Pi Pico está impulsada por el microcontrolador RP2040, un componente dual-core ARM Cortex-M0+ diseñado por Raspberry Pi. Este microcontrolador se enfoca en aplicaciones embebidas y de bajo consumo.

2. **Memoria RAM:** Con 264 KB de RAM, la Pico puede almacenar datos temporales y ejecutar programas de manera eficiente.

3. **Pines GPIO (Entrada/Salida de Propósito General):** Con 26 pines GPIO, la Pico facilita la conexión a diversos dispositivos y sensores para proyectos electrónicos.

4. **Entradas/Salidas Analógicas:** Ofrece 3 entradas/salidas analógicas (pines ADC), que permite la lectura de señales analógicas útiles en aplicaciones como sensores de luz o temperatura.

5. **Conectividad:**  no cuenta con conectividad incorporada, como Wi-Fi o Bluetooth, pero se pueden agregar módulos externos para habilitar estas funciones.

6. **Programación:** Compatible con diversos lenguajes, incluyendo MicroPython y C/C++, a través del SDK de Raspberry Pi Pico. Además, es compatible con herramientas populares como Thonny y entornos de desarrollo integrado (IDE) de C/C++.

7. **Relación Calidad-Precio:** es Conocida por su bajo costo en comparación con otras placas de desarrollo similares, la Raspberry Pi Pico es atractiva para proyectos que requieren un microcontrolador potente y barato.

8. **Soporte de Comunidad:** Al igual que otros productos de Raspberry Pi, la Pico se beneficia de una comunidad activa en línea, que comparte recursos como tutoriales, proyectos y foros de discusión.

**Otras Características Relevantes:**

- **Adaptador USB incorporado:** La Pico cuenta con un adaptador USB incorporado, simplificando la conexión, la programación y la alimentación.

## Ejercicio 6: caso de estudio

- ¿Cómo se ejecuta este programa?
  Este programa implementa una máquina de estados finitos (FSM) en un entorno Arduino. Aquí hay un resumen de cómo funciona:

1. **Definición de Estados y Variables:**
   - Se define un tipo enumerado `Task1States` con dos estados: `INIT` y `WAIT_TIMEOUT`.
   - Se declara una variable estática `task1State` para mantener el estado actual de la máquina de estados.

2. **Inicialización:**
   - En la función `task1()`, se utiliza un `switch` para gestionar diferentes estados.
   - En el estado `INIT`, se realiza la inicialización, como la configuración de la comunicación serial (`Serial.begin(115200)`), se establece el tiempo inicial y se cambia al estado `WAIT_TIMEOUT`.

3. **Máquina de Estados:**
   - En el estado `WAIT_TIMEOUT`, se verifica si ha pasado un intervalo de tiempo (`INTERVAL`) desde la última acción.
   - Si se cumple la condición, se realiza la acción (en este caso, imprimir el tiempo actual en milisegundos).

4. **Función de Configuración:**
   - La función `setup()` llama a `task1()` y se ejecuta una vez al inicio para realizar configuraciones iniciales.

5. **Bucle Principal:**
   - La función `loop()` llama repetidamente a `task1()`, permitiendo que la máquina de estados FSM continúe operando en un bucle infinito.

En resumen, este programa utiliza una máquina de estados para ejecutar acciones en intervalos regulares, donde la acción específica depende del estado actual. En este caso, el programa imprime el tiempo actual en milisegundos en la comunicación serial cada vez que ha transcurrido un intervalo definido.

- Pudiste ver este mensaje: `Serial.print("Task1States::WAIT_TIMEOUT\n");`. ¿Por qué crees que ocurre esto?

  - principalmente no, porque la instruccion de imprimir el texto esta despues de la instruccion de cambiar el estado de la maquina, por lo que la maquina cambiaba de estado antes de poder imprimir el mensaje, pero agregando un delay y moviendo la instruccion arriba del cambio de estado, permite al micro-controlador procesar e imprimir el mensaje correctamente
    
- ¿Cuántas veces se ejecuta el código en el case Task1States::INIT?

  solo una vez que es cuando inicia el programa, posteriormente se cambia al estado WAIT_TIMEOUT y se queda en bucle en este estado.

  ## Ejercicio 7: análisis del programa de prueba

- Observa la función millis(); ¿Para qué sirve? Recuerda que puedes buscar en Internet.

  La funcion millis(); sirve para devolver el nuemero de milisegundos transcurridos desde que el programa comienza a ejecutarse ,es útil para medir el tiempo entre eventos, realizar acciones periódicas o implementar temporizadores en programas para plataformas Arduino.

## Ejercicio 8: retrieval practice (evaluación formativa)

En el README.md del repositorio responde:

- ¿Cuáles son los estados del programa?
  
    INIT, WAIT_TIMEOUT1, WAIT_TIMEOUT2, WAIT_TIMEOUT3
  
- ¿Cuáles son los eventos?
  
  Transiciones entre estados: INIT-WAITTIMEOUT1, WAITTIMEOUT1-WAITTIMEOUT2, WAITTIMEOUT2-WAITTIMEOUT3, estos eventos tienen una condicion, que consiste en un IF que verifica si el     
  tiempo transcurrido es superior o igual a los distintos intervalos establecidos anteriormente (INTERVAL1, INTERVAL2, INTERVAL3), si la condicion se cumple, se pasa a los siguientes 
  estados
  
- ¿Cuáles son las acciones?
  
    imprimir los textos (hola, este es el mensaje #) mediante serial.print

 ## Ejercicio 11: realiza algunas pruebas

 - Analiza el programa. ¿Por qué enviaste la letra con el botón send? ¿Qué evento verifica si ha llegado algo por el puerto serial?
   
     if (Serial.available() > 0)
   
 - Analiza los números que se ven debajo de las letras. Nota que luego de la r, abajo, hay un número. ¿Qué es ese número?
   
 - ¿Qué relación encuentras entre las letras y los números?
   
    que cada letra corresponde a la posicion numerica del numero , es decir "6f", la f esta en la posicion numero 6 del abecedario

- ¿Qué es el 0a al final del mensaje y para qué crees que sirva?

    El "0a" al final del mensaje es un valor hexadecimal que representa el 10, 0a (10) indica que después de la palabra "computador", debería comenzar una nueva línea en el mensaje.
  
## Ejercicio 12: punteros

- ¿Cómo se declara un puntero?
  
  uint32_t *pvar

- ¿Cómo se define un puntero? (cómo se inicializa)

- ¿Cómo se obtiene la dirección de una variable?
  
  uint32_t *pvar = &var;
  
- ¿Cómo se puede leer el contenido de una variable por medio de un puntero?
  
  Serial.print(*pvar);
  
- ¿Cómo se puede escribir el contenido de una variable por medio de un puntero?
  
  *pvar = 10;

## Ejercicio 15
Piensa en las siguientes cuestiones:

- ¿Por qué es necesario declarar `rxData` static? y si no es static ¿Qué pasa? ESTO ES IMPORTANTE, MUCHO.

    Con static:
  
    Al ser estático, rxData mantiene su valor entre llamadas a la función task1(). Esto significa que los datos almacenados en rxData no se reinician a cero cada vez que se llama a la      función task1(). Si, por ejemplo, la función es llamada repetidamente en el bucle principal (loop()), rxData retiene su estado entre llamadas, lo que es crucial para acumular los       datos recibidos hasta que se complete un conjunto de 5 bytes.
    Sin static:
    
    Si rxData no se declara como static, se comportará como una variable local dentro de la función task1(). Esto significa que cada vez que se llama a la función, se crea una nueva 
    instancia de rxData y su contenido se reinicia. Si, por ejemplo, estás esperando recibir 5 bytes y acumularlos en rxData, sin el calificador static, cada vez que se llame a la 
    función task1(), rxData se reiniciará, y no se acumularán los datos como se espera.


- dataCounter se define static y se inicializa en 0. Cada vez que se ingrese a la función loop dataCounter se inicializa a 0? ¿Por qué es necesario declararlo static?

  el funcionamiento es similar a rxData, cada vez que ingresa a el loop no se inizializa en 0, dataCounter conserva su valor entre llamadas de funiones debido a que se declara static, 
  esto sirve para poder llevar seguimiento de la cantidad de datos ingresados

  
- Finalmente, la constante `0x30` en `(pData[i] - 0x30)` ¿Por qué es necesaria?

    La expresión pData[i] - 0x30 se utiliza para convertir un carácter numérico ASCII en su equivalente numérico. En el conjunto de caracteres ASCII, los dígitos numéricos del 0 al 9 tienen códigos ASCII consecutivos desde 0x30 hasta 0x39. Al restar 0x30, se realiza una conversión para obtener el valor numérico correspondiente.

  Por ejemplo:
  
  El carácter '0' tiene un código ASCII de 0x30. Restar 0x30 resultará en 0.
  El carácter '1' tiene un código ASCII de 0x31. Restar 0x30 resultará en 1.
  El carácter '2' tiene un código ASCII de 0x32. Restar 0x30 resultará en 2.
  Y así sucesivamente.

## Ejercicio 16

Qué crees que ocurre cuando:

- ¿Qué pasa cuando hago un [Serial.available()](https://www.arduino.cc/reference/en/language/functions/communication/serial/available/)?

    Verifico si la placa recibio algun dato
  
- ¿Qué pasa cuando hago un [Serial.read()](https://www.arduino.cc/reference/en/language/functions/communication/serial/read/)?

    Leo el dato que recibio la placa

- ¿Qué pasa cuando hago un Serial.read() y no hay nada en el buffer de recepción?

    Cuando ejecutas Serial.read() y no hay nada en el buffer de recepción (Serial.available() devuelve 0), la función Serial.read() devuelve -1. Esta es una indicación de que no se ha 
    recibido ningún dato.

    
- Un patrón común al trabajar con el puerto serial es este:

**`if**(Serial.available() > 0){
    int dataRx = Serial.read()
}`

- ¿Cuántos datos lee Serial.read()?

    La función Serial.read() en Arduino lee un solo byte de datos del buffer de recepción serie. En términos de tipo de datos, devuelve un valor de tipo int, que representa el byte 
    leído como un valor entre 0 y 255.
  
- ¿Y si quiero leer más de un dato? No olvides que no se pueden leer más datos de los disponibles en el buffer de recepción porque no hay más datos que los que tenga allí.

    Se podria utilizar un arreglo como en el codigo del punto 15
- ¿Qué pasa si te envían datos por serial y se te olvida llamar Serial.read()?

    
  Si se te olvida llamar a Serial.read() después de verificar que hay datos disponibles (Serial.available() > 0) en la función task1(), los datos que se envían por el puerto serie no 
  se leerán y se acumularán en el búfer de recepción serial, si la comunicación serial está configurada para esperar la recepción de ciertos datos antes de continuar con la ejecución 
  del programa, el código puede quedar bloqueado indefinidamente en el estado WAIT_DATA, ya que nunca se lee y procesa correctamente la información.
  Ademas, Si el código asume que siempre habrá datos disponibles y no se implementa una lógica adecuada para manejar la falta de datos, el programa puede comportarse de manera 
 impredecible o generar errores.
 
 
