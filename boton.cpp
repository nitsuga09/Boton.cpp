#include <Arduino.h>
#include <boton.h>

boton::boton(byte pin)
{
    _pin = pin;
    pinMode(_pin, INPUT);
    debounceTimeMs = 100;
    state = Idle;
    Presstype = NoPress;
}

void boton::Refresh() {
    switch(state){
        case Idle:
            PressType = NoPress;
            if(digitalRead(_pin)){
                state = DevouncingFirstPress;
                startDebouncingMillis = millis();
            }
            break;
        case DevouncingFirstPress:
            if(millis() - startDebouncingMillis >= debounceTimeMs){
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

boton::PressTypes boton::GetPressType(){
    return Press;
}
