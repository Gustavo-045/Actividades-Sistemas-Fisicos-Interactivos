void task1()
{
    // Definición de estados y variable de estado
    enum class Task1States
    {
        INIT,
        WAIT_TIMEOUT1,
        WAIT_TIMEOUT2,
        WAIT_TIMEOUT3
    };
    static Task1States task1State = Task1States::INIT;

    // Definición de variables static (conservan su valor entre llamadas a task1)
    static uint32_t lastTime = 0;

    // Constantes
    constexpr uint32_t INTERVAL1 = 1000;
    constexpr uint32_t INTERVAL2 = 2000;
    constexpr uint32_t INTERVAL3 = 3000;

    // MÁQUINA de ESTADOS
    switch (task1State)
    {
    case Task1States::INIT:
    {
        // Acciones:
        Serial.begin(115200);

        // Garantiza los valores iniciales para el siguiente estado.
        lastTime = millis();
        task1State = Task1States::WAIT_TIMEOUT1;

        break;
    }
    case Task1States::WAIT_TIMEOUT1:
    {
        uint32_t currentTime = millis();

        // Evento
        if ((currentTime - lastTime) >= INTERVAL1)
        {
            // Acciones:
            lastTime = currentTime;
            Serial.print(currentTime);
            Serial.print("hola este es el primer mensaje");
            Serial.print('\n');
            task1State = Task1States::WAIT_TIMEOUT2;
        }
        break;
    }


    case Task1States::WAIT_TIMEOUT2:
    {

      uint32_t currentTime = millis();
  
          // Evento
          if ((currentTime - lastTime) >= INTERVAL2)
          {
              // Acciones:
              lastTime = currentTime;
              Serial.print(currentTime);
              Serial.print("hola este es el segundo mensaje");
              Serial.print('\n');
              task1State = Task1States::WAIT_TIMEOUT3;
          }
          break;
    }
      



    case Task1States::WAIT_TIMEOUT3:
    {

      uint32_t currentTime = millis();
  
          // Evento
          if ((currentTime - lastTime) >= INTERVAL3)
          {
              // Acciones:
              lastTime = currentTime;
              Serial.print(currentTime);
              Serial.print("hola este es el 3 mensaje");
              Serial.print('\n');
              task1State = Task1States::WAIT_TIMEOUT1;
              
              
          }
          break;
      
    }
    
    
    default:
    {
        Serial.println("Error");
    }
    }
}

void setup()
{
    task1();
}

void loop()
{
    task1();
}
