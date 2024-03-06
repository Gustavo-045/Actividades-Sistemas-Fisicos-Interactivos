## Actividad

En una experiencia un grupo terrorista llamado “Disedentes del tiempo” realizan la configuración de una central nuclear global con la que se realizará la emisión de radiación nuclear al mundo. El sistema utiliza una interfaz de usuario simulada mediante el puerto serial, implementada en un entorno de software de Arduino.

En esta configuración inicial el sistema inicia en modo de configuración, mostrando una vez el mensaje CONFIG. En este modo se le configura el tiempo para abrir la cámara, por defecto tiene 5 seg y puede configurarse  entre 1 y 40 segundos con los botones S(Subir) y B(Bajar) en pasos de 1 segundo. Tan pronto se ajuste el tiempo de apertura de la cámara se termina con la letra L (listo) y se observa la cuenta en una pantalla, al final de la cual se abre la cámara y se hace la emisión de la radiación.  Cuando la cuenta regresiva termine debe mostrarse el mensaje “RADIACIÓN NUCLEAR ACTIVA” y a los dos segundos pasar nuevamente al modo CONFIG.

La misión del participante de la experiencia es salvar el mundo, por lo cual debe descifrar con pistas e ingresar el código de acceso, para lo cual  se envía por el puerto serial la secuencia 'C' seguido de la clave numérica (por ejemplo, 'C1234'). Si ingresas la clave correcta debe aparecer el mensaje “SALVASTE AL MUNDO”, sino la cuenta regresiva debe continuar hasta el fatal desenlace.

## Diagrama 

![image](https://github.com/Gustavo-045/SFI1-2/assets/132119031/c3385cda-48bd-4c25-b23b-7878b9d44a9e)

## Descripcion de la experiencia

Experiencia Interactiva: "Solo contra el Cosmos: Misión de Desactivación"

Introducción:
En un futuro próximo, los "Disidentes del Tiempo" han llevado al mundo al borde del desastre al tomar control de una central nuclear global. Como experto reclutado por la Resistencia, eres la única esperanza para infiltrarse y desactivar la radiación.

Infiltración y Reconocimiento:

Inicias infiltrándote en la central nuclear y localizas la interfaz de control en modo CONFIG. y luego de seleccionar el tiempo que deseas añadir y presionlr L (listo) encuentras una carta enigmática con un acertijo para desbloquear el código de desactivación.


El Desafío del Acertijo:

El acertijo:"Cuando el Cosmos susurra, el Círculo se cierra, Cuatro estrellas guían, ocultas en la esfera terrestre. Primero, tres cometas cruzan, trazando su destino, Luego, el único satélite ilumina nuestro camino. Seguido por dos soles gemelos, que el alba despierta, Y al final, cuatro galaxias en la danza eterna se insertan."

Decodifica las pistas para obtener la clave "C3124".


Administración del Tiempo y Recursos: 
El contador muestra 5 segundos para la liberación de la radiación.

Ajusta el tiempo con los botones S (Subir) y B (Bajar), pero cada 5 segundo extra usa un "código de acceso limitado". (Cuantas veces puedes poner la clave )

Consecuencias:(Revisar)


Aumentar el tiempo brinda más oportunidades, pero agota los recursos.


desactivación: 

Introduce "C3124" tras resolver el acertijo para desactivar el mecanismo y ver el mensaje de victoria.

Implementación Práctica:
Realizable en sala de escape física o entorno virtual con dispositivos Arduino. Los "códigos de acceso limitados" son esenciales, exigiendo decisiones cruciales.
