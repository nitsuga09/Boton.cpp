#include <Arduino.h>
#include <boton.h>

boton::boton(byte pin)
{
    _pin = pin;
    pinMode(_pin, INPUT)
    debounceTimeMs = 100;
    state = Idle;
}

void Boton::Refresh() {
    switch(state){
        case Idle:
            PressType = NoPress;
            if(digitalRead(_pin)){
                state = DevouncingFirstPress;
                startDebouncingMillis = millis();
            }
            break;
        case DevouncingFirstPress:
            if(Millis() - startDebouncingMillis >= debounceTimeMs){
                if(digitalRead(_pin)){
                    state = WaitingStopPress;   //Si todavia esta pretado el boton (digital read) se va a poner en el estado WaitingStopPress si no esta presionado se pone en estado Idle
                }
            }
        break;
        case WaitingStopPress:
            if(!digitalRead(_pin)){
                state = Idle;
                Presstype = Press;
            }
            break;

        default:
            break;
        }
    }
}
boton::PressType boton::GetPressType(){
    return Press;
}
