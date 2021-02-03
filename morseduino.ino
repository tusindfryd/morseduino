/* 
    ~`.* morseduino *.`~

    signal a text string received from the Arduino Serial Monitor in the Morse code

    the circuit: 
    an LED connected from digital pin 13 to ground
    
    2021 ~ by tusindfryd

    this code is in public domain

*/

const uint8_t LED = 13;
const uint8_t UNIT = 50;

void signal(const String pattern)
{
    if (pattern == "-------")
    {
        digitalWrite(LED, LOW);
        delay(7 * UNIT);
    }
    else
    {
        for (uint8_t i = 0; i < pattern.length(); i++)
        {
            if (pattern[i] == '.')
            {
                digitalWrite(LED, HIGH);
                delay(UNIT);
                digitalWrite(LED, LOW);
                delay(UNIT);
            }
            else if (pattern[i] == '-')
            {
                digitalWrite(LED, HIGH);
                delay(3 * UNIT);
                digitalWrite(LED, LOW);
                delay(UNIT);
            }
        }
        delay(2 * UNIT); // gap between letters (standard 3 time units in total)
    }
}

void encode(const char letter)
{
    String pattern = "";

    switch (letter)
    {
    case ' ':
        pattern = "-------";
        break;

    case '0':
        pattern = "-----";
        break;

    case '1':
        pattern = ".----";
        break;

    case '2':
        pattern = "..---";
        break;

    case '3':
        pattern = "...--";
        break;

    case '4':
        pattern = "....-";
        break;

    case '5':
        pattern = ".....";
        break;

    case '6':
        pattern = "-....";
        break;

    case '7':
        pattern = "--...";
        break;

    case '8':
        pattern = "---..";
        break;

    case '9':
        pattern = "----.";
        break;

    case 'a':
        pattern = ".-";
        break;

    case 'b':
        pattern = "-...";
        break;

    case 'c':
        pattern = "-.-.";
        break;

    case 'd':
        pattern = "-..";
        break;

    case 'e':
        pattern = ".";
        break;

    case 'f':
        pattern = "..-.";
        break;

    case 'g':
        pattern = "--.";
        break;

    case 'h':
        pattern = "....";
        break;

    case 'i':
        pattern = "..";
        break;

    case 'j':
        pattern = ".---";
        break;

    case 'k':
        pattern = "-.-";
        break;

    case 'l':
        pattern = ".-..";
        break;

    case 'm':
        pattern = "--";
        break;

    case 'n':
        pattern = "-.";
        break;

    case 'o':
        pattern = "---";
        break;

    case 'p':
        pattern = ".--.";
        break;

    case 'q':
        pattern = "--.-";
        break;

    case 'r':
        pattern = ".-.";
        break;

    case 's':
        pattern = "...";
        break;

    case 't':
        pattern = "-";
        break;

    case 'u':
        pattern = "..-";
        break;

    case 'v':
        pattern = "...-";
        break;

    case 'w':
        pattern = ".--";
        break;

    case 'x':
        pattern = "-..-";
        break;

    case 'y':
        pattern = "-.--";
        break;

    case 'z':
        pattern = "--..";
        break;

    default:
        break;
    }

    signal(pattern);
}

void setup()
{
    pinMode(LED, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    while (Serial.available() > 0)
    {
        String message = Serial.readString();
        message.trim();        // get rid of trailing whitespace
        message.toLowerCase(); // standardize the input

        for (int i = 0; i < message.length(); i++)
        {
            encode(message[i]);
        }
    }
}