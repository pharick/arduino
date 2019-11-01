const byte PIN_LED = 3;
unsigned long timer_led = 0;
byte state_led = 0;
bool direction_led = true;

void setup() {
    pinMode(PIN_LED, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    if (millis() - timer_led >= 20) {
        state_led += direction_led ? 1 : -1;
        if (state_led >= 255 || state_led <= 0) direction_led = !direction_led;
        timer_led = millis();
    }

    Serial.print(state_led);
    analogWrite(PIN_LED, state_led);
}