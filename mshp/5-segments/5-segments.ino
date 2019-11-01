const byte PIN_SEG_A = 2;
const byte PIN_SEG_B = 3;
const byte PIN_SEG_C = 4;
const byte PIN_SEG_D = 5;
const byte PIN_SEG_E = 6;
const byte PIN_SEG_F = 7;
const byte PIN_SEG_G = 8;
const byte PIN_SEG_DP = 9;

const byte PIN_SEG_1 = 11;
const byte PIN_SEG_2 = 10;

bool current_seg = true;
unsigned long timer_seg = 0;
unsigned long timer_indication = 0;
byte number = 0;

void segWrite(byte number) {
    switch (number) {
        case 0:
            digitalWrite(PIN_SEG_A, HIGH);
            digitalWrite(PIN_SEG_B, HIGH);
            digitalWrite(PIN_SEG_C, HIGH);
            digitalWrite(PIN_SEG_D, HIGH);
            digitalWrite(PIN_SEG_E, HIGH);
            digitalWrite(PIN_SEG_F, HIGH);
            digitalWrite(PIN_SEG_G, LOW);
            digitalWrite(PIN_SEG_DP, LOW);
            break;
        case 1:
            digitalWrite(PIN_SEG_A, LOW);
            digitalWrite(PIN_SEG_B, HIGH);
            digitalWrite(PIN_SEG_C, HIGH);
            digitalWrite(PIN_SEG_D, LOW);
            digitalWrite(PIN_SEG_E, LOW);
            digitalWrite(PIN_SEG_F, LOW);
            digitalWrite(PIN_SEG_G, LOW);
            digitalWrite(PIN_SEG_DP, LOW);
            break;
        case 2:
            digitalWrite(PIN_SEG_A, HIGH);
            digitalWrite(PIN_SEG_B, HIGH);
            digitalWrite(PIN_SEG_C, LOW);
            digitalWrite(PIN_SEG_D, HIGH);
            digitalWrite(PIN_SEG_E, HIGH);
            digitalWrite(PIN_SEG_F, LOW);
            digitalWrite(PIN_SEG_G, HIGH);
            digitalWrite(PIN_SEG_DP, LOW);
            break;
        case 3:
            digitalWrite(PIN_SEG_A, HIGH);
            digitalWrite(PIN_SEG_B, HIGH);
            digitalWrite(PIN_SEG_C, HIGH);
            digitalWrite(PIN_SEG_D, HIGH);
            digitalWrite(PIN_SEG_E, LOW);
            digitalWrite(PIN_SEG_F, LOW);
            digitalWrite(PIN_SEG_G, HIGH);
            digitalWrite(PIN_SEG_DP, LOW);
            break;
        case 4:
            digitalWrite(PIN_SEG_A, LOW);
            digitalWrite(PIN_SEG_B, HIGH);
            digitalWrite(PIN_SEG_C, HIGH);
            digitalWrite(PIN_SEG_D, LOW);
            digitalWrite(PIN_SEG_E, LOW);
            digitalWrite(PIN_SEG_F, HIGH);
            digitalWrite(PIN_SEG_G, HIGH);
            digitalWrite(PIN_SEG_DP, LOW);
            break;
        case 5:
            digitalWrite(PIN_SEG_A, HIGH);
            digitalWrite(PIN_SEG_B, LOW);
            digitalWrite(PIN_SEG_C, HIGH);
            digitalWrite(PIN_SEG_D, HIGH);
            digitalWrite(PIN_SEG_E, LOW);
            digitalWrite(PIN_SEG_F, HIGH);
            digitalWrite(PIN_SEG_G, HIGH);
            digitalWrite(PIN_SEG_DP, LOW);
            break;
        case 6:
            digitalWrite(PIN_SEG_A, HIGH);
            digitalWrite(PIN_SEG_B, LOW);
            digitalWrite(PIN_SEG_C, HIGH);
            digitalWrite(PIN_SEG_D, HIGH);
            digitalWrite(PIN_SEG_E, HIGH);
            digitalWrite(PIN_SEG_F, HIGH);
            digitalWrite(PIN_SEG_G, HIGH);
            digitalWrite(PIN_SEG_DP, HIGH);
            break;
        case 7:
            digitalWrite(PIN_SEG_A, HIGH);
            digitalWrite(PIN_SEG_B, HIGH);
            digitalWrite(PIN_SEG_C, HIGH);
            digitalWrite(PIN_SEG_D, LOW);
            digitalWrite(PIN_SEG_E, LOW);
            digitalWrite(PIN_SEG_F, LOW);
            digitalWrite(PIN_SEG_G, LOW);
            digitalWrite(PIN_SEG_DP, LOW);
            break;
        case 8:
            digitalWrite(PIN_SEG_A, HIGH);
            digitalWrite(PIN_SEG_B, HIGH);
            digitalWrite(PIN_SEG_C, HIGH);
            digitalWrite(PIN_SEG_D, HIGH);
            digitalWrite(PIN_SEG_E, HIGH);
            digitalWrite(PIN_SEG_F, HIGH);
            digitalWrite(PIN_SEG_G, HIGH);
            digitalWrite(PIN_SEG_DP, LOW);
            break;
        case 9:
            digitalWrite(PIN_SEG_A, HIGH);
            digitalWrite(PIN_SEG_B, HIGH);
            digitalWrite(PIN_SEG_C, HIGH);
            digitalWrite(PIN_SEG_D, HIGH);
            digitalWrite(PIN_SEG_E, LOW);
            digitalWrite(PIN_SEG_F, HIGH);
            digitalWrite(PIN_SEG_G, HIGH);
            digitalWrite(PIN_SEG_DP, HIGH);
            break;
    }
}

void setup() {
    pinMode(PIN_SEG_A, OUTPUT);
    pinMode(PIN_SEG_B, OUTPUT);
    pinMode(PIN_SEG_C, OUTPUT);
    pinMode(PIN_SEG_D, OUTPUT);
    pinMode(PIN_SEG_E, OUTPUT);
    pinMode(PIN_SEG_F, OUTPUT);
    pinMode(PIN_SEG_G, OUTPUT);
    pinMode(PIN_SEG_DP, OUTPUT);

    pinMode(PIN_SEG_1, OUTPUT);
    pinMode(PIN_SEG_2, OUTPUT);
}

void loop() {
    if (millis() - timer_seg >= 1000) {
        number = (number + 1) % 100;
        timer_seg = millis();
    }

    if (millis() - timer_indication >= 1) {
        if (current_seg) {
            digitalWrite(PIN_SEG_2, HIGH);
            segWrite(number / 10);
            digitalWrite(PIN_SEG_1, LOW);
        } else {
            digitalWrite(PIN_SEG_1, HIGH);
            segWrite(number % 10);
            digitalWrite(PIN_SEG_2, LOW);
        }

        timer_indication = millis();
    }

    current_seg = !current_seg;
}