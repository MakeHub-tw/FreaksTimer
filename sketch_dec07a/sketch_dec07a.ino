#include <TimerOne.h>

#define Pin_Buzzer 11
#define Pin_EncoderA 0
#define Pin_EncoderB 1
#define Pin_Button 10

unsigned char Minute0 = 0;
unsigned char Minute1 = 0;
unsigned char Second0 = 0;
unsigned char Second1 = 0;

unsigned char Number_LED = 0;

unsigned char Button_Flag = 0;

unsigned char Count_Flag = 0;

int m = 0;

void Number_0()
{
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
}

void Number_1()
{
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
}

void Number_2()
{
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
}

void Number_3()
{
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
}

void Number_4()
{
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
}

void Number_5()
{
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
}

void Number_6()
{
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
}

void Number_7()
{
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
}

void Number_8()
{
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
}

void Number_9()
{
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
}

void Display_Number(unsigned char Number)
{
    switch(Number)
    {
        case 0:
            Number_0();
        break;

        case 1:
            Number_1();
        break;

        case 2:
            Number_2();
        break;

        case 3:
            Number_3();
        break;

        case 4:
            Number_4();
        break;

        case 5:
            Number_5();
        break;

        case 6:
            Number_6();
        break;

        case 7:
            Number_7();
        break;

        case 8:
            Number_8();
        break;

        case 9:
            Number_9();
        break;
    }
}

void Display_Choose(unsigned char Select, unsigned char Number)
{
    switch(Select)
    {
        case 0:
        digitalWrite(13, HIGH);
        digitalWrite(12, LOW);
        Display_Number(Number);
        break;

        case 1:
        digitalWrite(13, LOW);
        digitalWrite(12, HIGH);
        Display_Number(Number);
        break;
    }
}

void Display_NixieTube_Minute()
{
    Display_Choose(0, Minute0);
    delay(3);
    Display_Choose(1, Minute1);
    delay(3);
}

void Display_NixieTube_Second()
{
    Display_Choose(0, Second0);
    delay(5);
    Display_Choose(1, Second1);
    delay(5);
}

void Display_NixieTube()
{
    //if((Minute1 == 0) && (Minute0 == 0) && (Button_Flag == 1))
    //{
        //Display_NixieTube_Second();
    //}
    //else
    //{
        Display_NixieTube_Minute();
    //}
}

void LED_0()
{
    digitalWrite(A5, HIGH);
    digitalWrite(A4, LOW);
    digitalWrite(A3, LOW);
    digitalWrite(A2, LOW);
    digitalWrite(A1, LOW);
    digitalWrite(A0, LOW);
    digitalWrite(17, LOW);
    digitalWrite(SCK, LOW);
}

void LED_1()
{
    digitalWrite(A5, LOW);
    digitalWrite(A4, HIGH);
    digitalWrite(A3, LOW);
    digitalWrite(A2, LOW);
    digitalWrite(A1, LOW);
    digitalWrite(A0, LOW);
    digitalWrite(17, LOW);
    digitalWrite(SCK, LOW);
}

void LED_2()
{
    digitalWrite(A5, LOW);
    digitalWrite(A4, LOW);
    digitalWrite(A3, HIGH);
    digitalWrite(A2, LOW);
    digitalWrite(A1, LOW);
    digitalWrite(A0, LOW);
    digitalWrite(17, LOW);
    digitalWrite(SCK, LOW);
}

void LED_3()
{
    digitalWrite(A5, LOW);
    digitalWrite(A4, LOW);
    digitalWrite(A3, LOW);
    digitalWrite(A2, HIGH);
    digitalWrite(A1, LOW);
    digitalWrite(A0, LOW);
    digitalWrite(17, LOW);
    digitalWrite(SCK, LOW);
}

void LED_4()
{
    digitalWrite(A5, LOW);
    digitalWrite(A4, LOW);
    digitalWrite(A3, LOW);
    digitalWrite(A2, LOW);
    digitalWrite(A1, HIGH);
    digitalWrite(A0, LOW);
    digitalWrite(17, LOW);
    digitalWrite(SCK, LOW);
}

void LED_5()
{
    digitalWrite(A5, LOW);
    digitalWrite(A4, LOW);
    digitalWrite(A3, LOW);
    digitalWrite(A2, LOW);
    digitalWrite(A1, LOW);
    digitalWrite(A0, HIGH);
    digitalWrite(17, LOW);
    digitalWrite(SCK, LOW);
}

void LED_6()
{
    digitalWrite(A5, LOW);
    digitalWrite(A4, LOW);
    digitalWrite(A3, LOW);
    digitalWrite(A2, LOW);
    digitalWrite(A1, LOW);
    digitalWrite(A0, LOW);
    digitalWrite(17, LOW);
    digitalWrite(SCK, HIGH);
}

void LED_7()
{
    digitalWrite(A5, LOW);
    digitalWrite(A4, LOW);
    digitalWrite(A3, LOW);
    digitalWrite(A2, LOW);
    digitalWrite(A1, LOW);
    digitalWrite(A0, LOW);
    digitalWrite(17, HIGH);
    digitalWrite(SCK, LOW);
}

void Display_LED(unsigned char Number)
{
    switch(Number)
    {
        case 0:
            LED_0();
        break;

        case 1:
            LED_1();
        break;

        case 2:
            LED_2();
        break;

        case 3:
            LED_3();
        break;

        case 4:
            LED_4();
        break;

        case 5:
            LED_5();
        break;

        case 6:
            LED_6();
        break;

        case 7:
            LED_7();
        break;
    }
}

void Delay_10ms(unsigned char Time)
{
    unsigned char Time_Count;
    for(Time_Count = 0; Time_Count < Time; Time_Count++)
    {
        Display_NixieTube();
    }
}

void Flash_LED_Once()
{
    digitalWrite(A5, HIGH);
    digitalWrite(A4, HIGH);
    digitalWrite(A3, HIGH);
    digitalWrite(A2, HIGH);
    digitalWrite(A1, HIGH);
    digitalWrite(A0, HIGH);
    digitalWrite(17, HIGH);
    digitalWrite(SCK, HIGH);
    Delay_10ms(20);
    digitalWrite(A5, LOW);
    digitalWrite(A4, LOW);
    digitalWrite(A3, LOW);
    digitalWrite(A2, LOW);
    digitalWrite(A1, LOW);
    digitalWrite(A0, LOW);
    digitalWrite(17, LOW);
    digitalWrite(SCK, LOW);
    Delay_10ms(20);
}

void Flash_LED(int Times)
{
    int Times_Count = 0;
    for(Times_Count = 0; Times_Count < Times; Times_Count++)
    {
        Flash_LED_Once();
    }
}

void Buzzer_Timing0()
{
        digitalWrite(Pin_Buzzer, HIGH);
        delay(1);
        digitalWrite(Pin_Buzzer, LOW);
        delay(1);

        digitalWrite(Pin_Buzzer, HIGH);
        delay(1);
        digitalWrite(Pin_Buzzer, LOW);
        delay(1);

        digitalWrite(Pin_Buzzer, HIGH);
        delay(1);
        digitalWrite(Pin_Buzzer, LOW);
        delay(1);

        digitalWrite(Pin_Buzzer, HIGH);
        delay(1);
        digitalWrite(Pin_Buzzer, LOW);
        delay(1);

        digitalWrite(Pin_Buzzer, HIGH);
        delay(1);
        digitalWrite(Pin_Buzzer, LOW);
        delay(1);
}

void Buzzer_Timing1()
{
        digitalWrite(Pin_Buzzer, HIGH);
        delayMicroseconds(50);
        digitalWrite(Pin_Buzzer, LOW);
        delayMicroseconds(50);

        digitalWrite(Pin_Buzzer, HIGH);
        delayMicroseconds(50);
        digitalWrite(Pin_Buzzer, LOW);
        delayMicroseconds(50);

        digitalWrite(Pin_Buzzer, HIGH);
        delayMicroseconds(50);
        digitalWrite(Pin_Buzzer, LOW);
        delayMicroseconds(50);

        digitalWrite(Pin_Buzzer, HIGH);
        delayMicroseconds(50);
        digitalWrite(Pin_Buzzer, LOW);
        delayMicroseconds(50);

        digitalWrite(Pin_Buzzer, HIGH);
        delayMicroseconds(50);
        digitalWrite(Pin_Buzzer, LOW);
        delayMicroseconds(50);
}

void Count()
{ 
    if(Count_Flag == 1)
    {
        if((Minute1 == 0) && (Minute0 == 0))
        {
            Button_Flag = 0;
            Timer1.stop();
            for(m = 0; m < 300; m++)
            {
                digitalWrite(A5, HIGH);
                digitalWrite(A4, HIGH);
                digitalWrite(A3, HIGH);
                digitalWrite(A2, HIGH);
                digitalWrite(A1, HIGH);
                digitalWrite(A0, HIGH);
                digitalWrite(17, HIGH);
                digitalWrite(SCK, HIGH);
                unsigned char a;
                for(a = 0; a < 20; a++)
                {
                    digitalWrite(Pin_Buzzer, HIGH);
                    if(digitalRead(Pin_Button) == 0)
                    {
                        delay(5);
                        if(digitalRead(Pin_Button) == 0)
                        {
                            while(digitalRead(Pin_Button) == 0);
                            delay(5);
                            while(digitalRead(Pin_Button) == 0);
                            m = 500;
                        }
                    }
                    Display_NixieTube();
                    digitalWrite(Pin_Buzzer, LOW);
                }
                digitalWrite(A5, LOW);
                digitalWrite(A4, LOW);
                digitalWrite(A3, LOW);
                digitalWrite(A2, LOW);
                digitalWrite(A1, LOW);
                digitalWrite(A0, LOW);
                digitalWrite(17, LOW);
                digitalWrite(SCK, LOW);
                for(a = 0; a < 20; a++)
                {
                    digitalWrite(Pin_Buzzer, HIGH);
                    if(digitalRead(Pin_Button) == 0)
                    {
                        delay(5);
                        if(digitalRead(Pin_Button) == 0)
                        {
                            while(digitalRead(Pin_Button) == 0);
                            delay(5);
                            while(digitalRead(Pin_Button) == 0);
                            m = 500;
                        }
                    }
                    Display_NixieTube();
                    digitalWrite(Pin_Buzzer, LOW);
                }
            }
        }
        else
        {
            switch(Second0)
            {
                case 0:
                switch(Second1)
                {
                    case 0:
                    switch(Minute0)
                    {
                        case 0:
                        switch(Minute1)
                        {
                            case 0:
                            Button_Flag = 0;
                            Timer1.stop();
                            for(m = 0; m < 300; m++)
                            {
                                digitalWrite(A5, HIGH);
                                digitalWrite(A4, HIGH);
                                digitalWrite(A3, HIGH);
                                digitalWrite(A2, HIGH);
                                digitalWrite(A1, HIGH);
                                digitalWrite(A0, HIGH);
                                digitalWrite(17, HIGH);
                                digitalWrite(SCK, HIGH);
                                unsigned char a;
                                for(a = 0; a < 50; a++)
                                {
                                    digitalWrite(Pin_Buzzer, HIGH);
                                    if(digitalRead(Pin_Button) == 0)
                                    {
                                        delayMicroseconds(250);
                                        if(digitalRead(Pin_Button) == 0)
                                        {
                                            while(digitalRead(Pin_Button) == 0);
                                            delayMicroseconds(250);
                                            while(digitalRead(Pin_Button) == 0);
                                            m = 500;
                                        }
                                    }
                                    //Display_NixieTube();
                                    digitalWrite(Pin_Buzzer, LOW);
                                }
                                digitalWrite(A5, LOW);
                                digitalWrite(A4, LOW);
                                digitalWrite(A3, LOW);
                                digitalWrite(A2, LOW);
                                digitalWrite(A1, LOW);
                                digitalWrite(A0, LOW);
                                digitalWrite(17, LOW);
                                digitalWrite(SCK, LOW);
                                for(a = 0; a < 50; a++)
                                {
                                    digitalWrite(Pin_Buzzer, HIGH);
                                    if(digitalRead(Pin_Button) == 0)
                                    {
                                        delayMicroseconds(250);
                                        if(digitalRead(Pin_Button) == 0)
                                        {
                                            while(digitalRead(Pin_Button) == 0);
                                            delayMicroseconds(250);
                                            while(digitalRead(Pin_Button) == 0);
                                            m = 500;
                                        }
                                    }
                                    //Display_NixieTube();
                                    digitalWrite(Pin_Buzzer, LOW);
                                }
                            }
                            break;
    
                            default:
                            Minute1--;
                            Minute0 = 9;
                            Second1 = 5;
                            Second0 = 9;
                            break;
                        }
                        break;
    
                        default:
                        Minute0--;
                        Second1 = 5;
                        Second0 = 9;
                        break;
                    }
                    break;
    
                    default:
                    Second1--;
                    Second0 = 9;
                    break;
                }
                break;
    
                default:
                Second0--;
                break;
            }
        }
        Count_Flag = 0;
    }
    else
    {
        Count_Flag = 1;
    }
    Number_LED_Minus();
    Buzzer_Timing1();
}

void Minute_Minus()
{
    switch(Minute0)
    {
        case 0:
        switch(Minute1)
        {
            case 0:
            Minute0 = 0;
            Minute1 = 0;
            break;

            default:
            Minute0 = 9;
            Minute1--;
            break;
        }
        break;

        default:
        Minute0--;
        break;
    }
}

void Minute_Plus()
{
    switch(Minute0)
    {
        case 9:
        switch(Minute1)
        {
            case 9:
            Minute1 = 9;
            Minute0 = 9;
            break;

            default:
            Minute1++;
            Minute0 = 0;
            break;
        }
        break;

        default:
        Minute0++;
        break;
    }
}

void Number_LED_Minus()
{
    switch(Number_LED)
    {
        case 0:
        Number_LED = 7;
        break;

        default:
        Number_LED--;
        break;
    }
}

void Number_LED_Plus()
{
    switch(Number_LED)
    {
        case 7:
        Number_LED = 0;
        break;

        default:
        Number_LED++;
        break;
    }
}

void Encoder()
{
    if(Button_Flag == 0)
    {
        if(digitalRead(Pin_EncoderA) == 0)
        {
            delay(1);
            if(digitalRead(Pin_EncoderA) == 0)
            {
                if(digitalRead(Pin_EncoderB) == 0)
                {
                    while(digitalRead(Pin_EncoderA) == 0)
                    {
                        Display_NixieTube_Minute();
                        if(digitalRead(10) == 0)
                        {
                            delay(5);
                            if(digitalRead(10) == 0)
                            {
                                while(digitalRead(10) == 0)
                                {
                                    Display_NixieTube_Minute();
                                }
                                while(digitalRead(10) == 0)
                                {
                                    Display_NixieTube_Minute();
                                }
                                Button_Flag = 1;
                            }
                        }
                    }
                    if(Button_Flag == 0)
                    {
                    while(digitalRead(Pin_EncoderA) == 0)
                    {
                        Display_NixieTube_Minute();
                        if(digitalRead(10) == 0)
                        {
                            delay(5);
                            if(digitalRead(10) == 0)
                            {
                                while(digitalRead(10) == 0)
                                {
                                    Display_NixieTube_Minute();
                                }
                                while(digitalRead(10) == 0)
                                {
                                    Display_NixieTube_Minute();
                                }
                                Button_Flag = 1;
                            }
                        }
                    }
                    }
                    if(Button_Flag == 0)
                    {
                    while(digitalRead(Pin_EncoderB) == 0)
                    {
                        Display_NixieTube_Minute();
                        if(digitalRead(10) == 0)
                        {
                            delay(5);
                            if(digitalRead(10) == 0)
                            {
                                while(digitalRead(10) == 0)
                                {
                                    Display_NixieTube_Minute();
                                }
                                while(digitalRead(10) == 0)
                                {
                                    Display_NixieTube_Minute();
                                }
                                Button_Flag = 1;
                            }
                        }
                    }
                    }
                    if(Button_Flag == 0)
                    {
                    while(digitalRead(Pin_EncoderB) == 0)
                    {
                        Display_NixieTube_Minute();
                        if(digitalRead(10) == 0)
                        {
                            delay(5);
                            if(digitalRead(10) == 0)
                            {
                                while(digitalRead(10) == 0)
                                {
                                    Display_NixieTube_Minute();
                                }
                                while(digitalRead(10) == 0)
                                {
                                    Display_NixieTube_Minute();
                                }
                                Button_Flag = 1;
                            }
                        }
                    }
                    }
                    Minute_Minus();
                    Number_LED_Minus();
                }
                else
                {
                    while(digitalRead(Pin_EncoderA) == 0)
                    {
                        Display_NixieTube_Minute();
                        if(digitalRead(10) == 0)
                        {
                            delay(5);
                            if(digitalRead(10) == 0)
                            {
                                while(digitalRead(10) == 0)
                                {
                                    Display_NixieTube_Minute();
                                }
                                while(digitalRead(10) == 0)
                                {
                                    Display_NixieTube_Minute();
                                }
                                Button_Flag = 1;
                            }
                        }
                    }
                    if(Button_Flag == 0)
                    {
                    while(digitalRead(Pin_EncoderA) == 0)
                    {
                        Display_NixieTube_Minute();
                        if(digitalRead(10) == 0)
                        {
                            delay(5);
                            if(digitalRead(10) == 0)
                            {
                                while(digitalRead(10) == 0)
                                {
                                    Display_NixieTube_Minute();
                                }
                                while(digitalRead(10) == 0)
                                {
                                    Display_NixieTube_Minute();
                                }
                                Button_Flag = 1;
                            }
                        }
                    }
                    }
                    if(Button_Flag == 0)
                    {
                    while(digitalRead(Pin_EncoderB) == 0)
                    {
                        Display_NixieTube_Minute();
                        if(digitalRead(10) == 0)
                        {
                            delay(5);
                            if(digitalRead(10) == 0)
                            {
                                while(digitalRead(10) == 0)
                                {
                                    Display_NixieTube_Minute();
                                }
                                while(digitalRead(10) == 0)
                                {
                                    Display_NixieTube_Minute();
                                }
                                Button_Flag = 1;
                            }
                        }
                    }
                    }
                    if(Button_Flag == 0)
                    {
                    while(digitalRead(Pin_EncoderB) == 0)
                    {
                        Display_NixieTube_Minute();
                        if(digitalRead(10) == 0)
                        {
                            delay(5);
                            if(digitalRead(10) == 0)
                            {
                                while(digitalRead(10) == 0)
                                {
                                    Display_NixieTube_Minute();
                                }
                                while(digitalRead(10) == 0)
                                {
                                    Display_NixieTube_Minute();
                                }
                                Button_Flag = 1;
                            }
                        }
                    }
                    }
                    Minute_Plus();
                    Number_LED_Plus();
                }
            }
        }
    }
}

void setup()
{
    pinMode(MOSI, OUTPUT);
    pinMode(12, OUTPUT);
    
    pinMode(2, OUTPUT); 
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);

    pinMode(A5, OUTPUT);
    pinMode(A4, OUTPUT);
    pinMode(A3, OUTPUT);
    pinMode(A2, OUTPUT);
    pinMode(A1, OUTPUT);
    pinMode(A0, OUTPUT);
    pinMode(17, OUTPUT);
    pinMode(SCK, OUTPUT);

    pinMode(Pin_Buzzer, OUTPUT);

    pinMode(10, INPUT);
    pinMode(Pin_EncoderA, INPUT);
    pinMode(Pin_EncoderB, INPUT);
    digitalWrite(Pin_EncoderA, HIGH);
    digitalWrite(Pin_EncoderB, HIGH);
    digitalWrite(10, HIGH);

    attachInterrupt(2, Encoder, FALLING);

    Timer1.initialize(500000);

    Serial.begin(9600);
}

void loop()
{
    Display_NixieTube();
    Display_LED(Number_LED);
    if(digitalRead(Pin_Button) == 0)
    {
        delay(5);
        if(digitalRead(Pin_Button) == 0)
        {
            if(Button_Flag == 0)
            {
                Button_Flag = 1;
                Timer1.attachInterrupt(Count);
            }
            else
            {
                Button_Flag = 0;
                Timer1.stop();
            }
            while(digitalRead(Pin_Button) == 0);
            delay(5);
            while(digitalRead(Pin_Button) == 0);
        }
    }
}
