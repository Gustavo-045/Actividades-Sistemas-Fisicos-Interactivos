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
