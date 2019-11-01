const byte PIN_BUTTON_PLUS = 10;
unsigned long timer_button_plus = 0;
bool state_button_plus = LOW;
bool prev_state_button_plus = state_button_plus;

const byte PIN_BUTTON_MINUS = 11;
unsigned long timer_button_minus = 0;
bool state_button_minus = LOW;
bool prev_state_button_minus = state_button_minus;

const byte PIN_LED_1 = 2;
const byte PIN_LED_2 = 3;
const byte PIN_LED_3 = 4;

byte counter = 0;

void setup() {
    pinMode(PIN_BUTTON_PLUS, INPUT);
    pinMode(PIN_BUTTON_MINUS, INPUT);

    pinMode(PIN_LED_1, OUTPUT);
    pinMode(PIN_LED_2, OUTPUT);
    pinMode(PIN_LED_3, OUTPUT);
}

void loop() {
    prev_state_button_plus = state_button_plus;
    prev_state_button_minus = state_button_minus;
    state_button_plus = digitalRead(PIN_BUTTON_PLUS);
    state_button_minus = digitalRead(PIN_BUTTON_MINUS);

    if (state_button_plus && millis() - timer_button_plus >= 200 && prev_state_button_plus != state_button_plus) {
        if (counter < 3) counter++;
        timer_button_plus = millis();
    } else if (state_button_minus && millis() - timer_button_minus >= 200 && prev_state_button_minus != state_button_minus) {
        if (counter > 0) counter--;
        timer_button_minus = millis();
    }

    digitalWrite(PIN_LED_1, counter >= 1);
    digitalWrite(PIN_LED_2, counter >= 2);
    digitalWrite(PIN_LED_3, counter >= 3);
}