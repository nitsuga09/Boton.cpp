#ifndef _boton_h         //Si no esta definido

#define _boton_h         //defino boton.h

#include <Arduino.h>

class boton
{
    private:
        byte _pin;

        enum State{
            Idle,                       //Espero a que el boton se presione
            DevouncingFirstPress,       //Espero el tiempo de rebote
            WaitingStopPress,           //Espero que suelten el boton
        };
        long startDebouncingMillis;
        State state;

    public:
        enum PressTypes{
                NoPress,
                Press,
            };
        PressTypes pressType;

    public:
        boton(byte pin);
        int debounceTimeMs;
        PressTypes GetPressType();
        void Refresh();

};

#endif
