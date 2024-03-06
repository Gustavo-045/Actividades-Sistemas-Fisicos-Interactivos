enum class Task1States {
    CONFIG,
    PROCESO,
    FINAL
};

static Task1States task1State = Task1States::CONFIG;
static uint8_t TiempoParaAbrir = 5;
static uint32_t lastTime;

void task1()
{
    switch (task1State)
    {
    case Task1States::CONFIG:
    {
        char TeclaRecibida;

    
              /*Serial.print("CONFIG - Tiempo para abrir la boveda: ");
              Serial.println(TiempoParaAbrir);
              Serial.println("Presiona S para aumentar la cantidad de segundos y A para disminuirla, Presiona L para aceptar los cambios");
              */




        
        if (Serial.available() > 0)
        {
    
            TeclaRecibida = Serial.read();

            if (TeclaRecibida != 'L')
            {
                if (TeclaRecibida == 'S')
                {
                    TiempoParaAbrir++;
                    Serial.println("Tiempo para abrir la boveda: " + String(TiempoParaAbrir));
                }
                else if (TeclaRecibida == 'A')
                {
                    TiempoParaAbrir--;
                    Serial.println("Tiempo para abrir la boveda: " + String(TiempoParaAbrir));
                }
            }
            else
            {
                Serial.println("Listo");
                task1State = Task1States::PROCESO;
            }
        }

        break;
    }

    case Task1States::PROCESO:
    {

      lastTime = 0;
      lastTime = TiempoParaAbrir;

      while (lastTime>0)
      {

        Serial.println(lastTime);
        lastTime--;
        delay(1000);
      }
      


              

 
       
       if (lastTime <= 0) 
       {
        Serial.println("se acabo el tiempo");
        task1State = Task1States::FINAL;
       }
      



      
        // Evento 1:

        break;
    }

        case Task1States::FINAL:
    {
   
       
        Serial.println("Radiacion Nuclear Activa");
        TiempoParaAbrir = 5;
        lastTime = 0;
        task1State = Task1States::CONFIG;

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
    task1();
    // Aquí puedes agregar otras tareas que se ejecuten en el bucle principal si es necesario.
}


