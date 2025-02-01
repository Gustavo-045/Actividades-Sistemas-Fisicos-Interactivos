enum class Task1States {
    CONFIG,
    PROCESO,
    FINAL
};

static Task1States task1State = Task1States::CONFIG;
static uint8_t TiempoParaAbrir = 5;
static uint32_t lastTime;
static uint8_t intentos = 3; // Límite de intentos para ingresar el código
static unsigned long previousMillis = 0; 
static const long interval = 1000; // Intervalo de 1 segundo para la cuenta regresiva

void task1() {
    switch (task1State) {
        case Task1States::CONFIG:
            {
                char TeclaRecibida;

                if (Serial.available() > 0) {
                    TeclaRecibida = Serial.read();

                    if (TeclaRecibida != 'L') {
                        if (TeclaRecibida == 'S' && TiempoParaAbrir < 40) {
                            TiempoParaAbrir++;
                            Serial.print("Tiempo para abrir la boveda: ");
                            Serial.println(TiempoParaAbrir);
                        }
                        else if (TeclaRecibida == 'B' && TiempoParaAbrir > 1) {
                            TiempoParaAbrir--;
                            Serial.print("Tiempo para abrir la boveda: ");
                            Serial.println(TiempoParaAbrir);
                        }
                    }
                    else {
                        Serial.println("Listo");
                        task1State = Task1States::PROCESO;
                    }
                }
            }
            break;

        case Task1States::PROCESO:
            {
                unsigned long currentMillis = millis();
                if (currentMillis - previousMillis >= interval) {
                    previousMillis = currentMillis;
                    lastTime--;  // Decrementar el tiempo en cada intervalo

                    Serial.print("Cuenta regresiva: ");
                    Serial.println(lastTime);

                    if (lastTime <= 0) {
                        Serial.println("Se acabó el tiempo, RADIACION NUCLEAR ACTIVA");
                        task1State = Task1States::FINAL;
                        break;
                    }

                    // Verificar si el jugador ingresa un código
                    if (Serial.available() > 0) {
                        char inputChar = Serial.read();

                        // Verificar si el primer carácter es 'C'
                        if (inputChar == 'C') {
                            // Leer los siguientes cuatro caracteres como números
                            char code[4];
                            for (int i = 0; i < 4; ++i) {
                                if (Serial.available() > 0) {
                                    code[i] = Serial.read();
                                }
                            }

                            int enteredCode = atoi(code);

                            if (enteredCode == 3124) { // Código correcto
                                Serial.println("¡Salvaste al mundo!");
                                task1State = Task1States::FINAL;
                                break;
                            } else {
                                intentos--;
                                if (intentos > 0) {
                                    Serial.print("Código incorrecto. Intentos restantes: ");
                                    Serial.println(intentos);
                                } else {
                                    Serial.println("Se acabaron los intentos. La cuenta regresiva continúa...");
                                }
                            }
                        }
                    }
                }
            }
            break;

        case Task1States::FINAL:
            {
                // Reiniciar la misión
                TiempoParaAbrir = 5;
                lastTime = TiempoParaAbrir;
                intentos = 3; // Reiniciar los intentos
                task1State = Task1States::CONFIG;
                Serial.println("Regresando a la configuración...");
            }
            break;

        default:
            break;
    }
}

void setup() {
    Serial.begin(9600);  // Iniciar comunicación serial
    task1();  // Llamar a la tarea inicial
}

void loop() {
    task1();  // Ejecutar la tarea en el bucle principal
}
