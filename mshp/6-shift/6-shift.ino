const byte PIN_SEG_SER = 2;
const byte PIN_SEG_RCLK = 3;
const byte PIN_SEG_SRCLK = 4;

unsigned long timer = 0;
byte digit = 0;

byte symbols[10] = {
    0b01101111,
    0b01000100,
    0b01110011,
    0b01110110,
    0b01011100,
    0b00111110,
    0b00111111,
    0b01100100,
    0b01111111,
    0b01111110
};

void segWrite(byte symbol) {
    shiftOut(PIN_SEG_SER, PIN_SEG_SRCLK, LSBFIRST, symbols[symbol]);
    digitalWrite(PIN_SEG_RCLK, HIGH);
    digitalWrite(PIN_SEG_RCLK, LOW);
}

void setup() {
    pinMode(PIN_SEG_SER, OUTPUT);
    pinMode(PIN_SEG_RCLK, OUTPUT);
    pinMode(PIN_SEG_SRCLK, OUTPUT);

    segWrite(digit);
}

void loop() {
    if (millis() - timer >= 1000) {
        digit = (digit + 1) % 10;
        segWrite(digit);
        timer = millis();
    }
}