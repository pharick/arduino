const byte PIN_LED_1 = 2;
const byte PIN_LED_2 = 3;
bool state_led_1 = LOW;
bool state_led_2 = HIGH;
unsigned long timer_led = 0;

void setup() {
    pinMode(PIN_LED_1, OUTPUT);
    pinMode(PIN_LED_2, OUTPUT);
}

void loop() {
    if (millis() - timer_led >= 1000) {
        state_led_1 = !state_led_1;
        state_led_2 = !state_led_2;
        digitalWrite(PIN_LED_1, state_led_1);
        digitalWrite(PIN_LED_2, state_led_2);
        timer_led = millis();
    }
}