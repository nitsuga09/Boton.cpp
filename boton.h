#ifndef _BOTON_h         //Si no esta definido

#define _BOTON_h         //defino boton.h

#include <Arduino.h>

class boton{
    public:
        boton(byte pin);
        void Refresh();
        PressTypes GetPressType();
        long startDebouncingMillis;
    
        enum PressTypes{
                NoPress;
                Press;
            }

    private:
        byte _pin;
        int debounceTimeMs;           //Tiempo de rebote
        PressTypes Presstype;

        enum State{
            Idle;                       //Espero a que el boton se presione
            DevouncingFirstPress;       //Espero el tiempo de rebote
            WaitingStopPress;           //Espero que suelten el boton
        }
        State state;
}

#endif                  //Tengo que cerrarlo
