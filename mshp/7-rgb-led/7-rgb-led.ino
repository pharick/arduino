const byte PIN_LED_RED = 6;
const byte PIN_LED_GREEN = 5;
const byte PIN_LED_BLUE = 3;

unsigned long timer_rgb = 0;
int value_led = 0;

void rgbWrite(int hue) {
    byte zone = hue / 256;
    byte local = hue % 256;

    switch (zone) {
        case 0:
            analogWrite(PIN_LED_RED, 255);
            analogWrite(PIN_LED_GREEN, local);
            analogWrite(PIN_LED_BLUE, 0);
            break;
        case 1:
            analogWrite(PIN_LED_RED, 255 - local);
            analogWrite(PIN_LED_GREEN, 255);
            analogWrite(PIN_LED_BLUE, 0);
            break;
        case 2:
            analogWrite(PIN_LED_RED, 0);
            analogWrite(PIN_LED_GREEN, 255);
            analogWrite(PIN_LED_BLUE, local);
            break;
        case 3:
            analogWrite(PIN_LED_RED, 0);
            analogWrite(PIN_LED_GREEN, 255 - local);
            analogWrite(PIN_LED_BLUE, 255);
            break;
        case 4:
            analogWrite(PIN_LED_RED, local);
            analogWrite(PIN_LED_GREEN, 0);
            analogWrite(PIN_LED_BLUE, 255);
            break;
        case 5:
            analogWrite(PIN_LED_RED, 255);
            analogWrite(PIN_LED_GREEN, 0);
            analogWrite(PIN_LED_BLUE, 255 - local);
            break;
    }
}

void setup() {
    pinMode(PIN_LED_RED, OUTPUT);
    pinMode(PIN_LED_GREEN, OUTPUT);
    pinMode(PIN_LED_BLUE, OUTPUT);
}

void loop() {
    if (millis() - timer_rgb >= 10) {
        value_led = (value_led + 1) % 1536;
        timer_rgb = millis();
    }

    rgbWrite(value_led);
}