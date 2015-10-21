#include <stdint.h>
#include <stdlib.h>
#include "teclas.h"
#include "io.h"

extern port_t PORTA;
extern port_t PORTB;

void teclas(char puerto)
{
    uint8_t pin;
    pin = getch();
    if(puerto=='a')
    {
        if(pin=='0')  { if ((PORTA.Pins&1)==0)       {   changePinPortA(0,HIGH);  }   else  {   changePinPortA(0,LOW);}   }
        if(pin=='1')  { if ((PORTA.Pins&(1<<1))==0)  {   changePinPortA(1,HIGH);  }   else  {   changePinPortA(1,LOW);}   }
        if(pin=='2')  { if ((PORTA.Pins&(1<<2))==0)  {   changePinPortA(2,HIGH);  }   else  {   changePinPortA(2,LOW);}   }
        if(pin=='3')  { if ((PORTA.Pins&(1<<3))==0)  {   changePinPortA(3,HIGH);  }   else  {   changePinPortA(3,LOW);}   }
        if(pin=='4')  { if ((PORTA.Pins&(1<<4))==0)  {   changePinPortA(4,HIGH);  }   else  {   changePinPortA(4,LOW);}   }
        if(pin=='5')  { if ((PORTA.Pins&(1<<5))==0)  {   changePinPortA(5,HIGH);  }   else  {   changePinPortA(5,LOW);}   }
        if(pin=='6')  { if ((PORTA.Pins&(1<<6))==0)  {   changePinPortA(6,HIGH);  }   else  {   changePinPortA(6,LOW);}   }
        if(pin=='7')  { if ((PORTA.Pins&(1<<7))==0)  {   changePinPortA(7,HIGH);  }   else  {   changePinPortA(7,LOW);}   }
    }
    if(puerto=='b')
    {
        if(pin=='0')  { if ((PORTB.Pins&1)==0)       {   changePinPortB(0,HIGH);  }   else  {   changePinPortB(0,LOW);}   }
        if(pin=='1')  { if ((PORTB.Pins&(1<<1))==0)  {   changePinPortB(1,HIGH);  }   else  {   changePinPortB(1,LOW);}   }
        if(pin=='2')  { if ((PORTB.Pins&(1<<2))==0)  {   changePinPortB(2,HIGH);  }   else  {   changePinPortB(2,LOW);}   }
        if(pin=='3')  { if ((PORTB.Pins&(1<<3))==0)  {   changePinPortB(3,HIGH);  }   else  {   changePinPortB(3,LOW);}   }
        if(pin=='4')  { if ((PORTB.Pins&(1<<4))==0)  {   changePinPortB(4,HIGH);  }   else  {   changePinPortB(4,LOW);}   }
        if(pin=='5')  { if ((PORTB.Pins&(1<<5))==0)  {   changePinPortB(5,HIGH);  }   else  {   changePinPortB(5,LOW);}   }
        if(pin=='6')  { if ((PORTB.Pins&(1<<6))==0)  {   changePinPortB(6,HIGH);  }   else  {   changePinPortB(6,LOW);}   }
        if(pin=='7')  { if ((PORTB.Pins&(1<<7))==0)  {   changePinPortB(7,HIGH);  }   else  {   changePinPortB(7,LOW);}   }
    }
}
