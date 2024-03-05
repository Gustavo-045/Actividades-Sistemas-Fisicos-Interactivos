void task1()
{
    enum class Task1States    {
        CONFIG,
        WAIT_DATA
    };
    static Task1States task1State = Task1States::CONFIG;
    static uint8_t TiempoParaAbrir = 5;

    switch (task1State)
    {
    case Task1States::CONFIG:
    {
        char TeclaRecibida;
        
        Serial.begin(115200);
        Serial.print("CONFIG");
        Serial.print("Tiempo para abrir la boveda: " + TiempoParaAbrir);
        Serial.print("Presiona S para aumentar la cantidad de segundos y A para disminuirla, Presiona L para aceptar los cambios");

        
        
        if (Serial.available() > 0)
        {
          TeclaRecibida = Serial.read();

          
           if (TeclaRecibida != 'L')
           {
                  
              if (TeclaRecibida == 'S')
              {
                TiempoParaAbrir++;
                Serial.print("Tiempo para abrir la boveda: " + TiempoParaAbrir);
              }
              if (TeclaRecibida == 'A')
              {
                TiempoParaAbrir--;
                Serial.print("Tiempo para abrir la boveda: " + TiempoParaAbrir);
                
              }
              
           }

           else
           {
            Serial.print("Listo");
            task1State = Task1States::WAIT_DATA;
           }

           

          
        }

        
        
        break;
    }

    case Task1States::WAIT_DATA:
    {
        // evento 1:        
        
        break;
    }

    default:
    {
        break;
    }
    }
}


void setup()
{
    task1();
}

void loop()
{

}
