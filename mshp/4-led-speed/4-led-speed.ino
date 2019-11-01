const byte PIN_LED = 3;
unsigned long timer_led = 0;
byte value_led = 0;
bool direction_led = true;

const byte PIN_POT_SPEED = A0;
const byte PIN_POT_MAX = A1;

void setup() {
    pinMode(PIN_LED, OUTPUT);
    pinMode(PIN_POT_SPEED, INPUT);
    pinMode(PIN_POT_MAX, INPUT);

    Serial.begin(9600);
}

void loop() {
    int status_pot_speed = analogRead(PIN_POT_SPEED);
    int status_pot_max = analogRead(PIN_POT_MAX);

    int speed_led = map(status_pot_speed, 0, 1023, 100, 2000);
    int max_led = map(status_pot_max, 0, 1023, 0, 255);

    if (millis() - timer_led >= speed_led) {
        value_led += direction_led ? 1 : -1;

        if (value_led >= max_led || value_led <= 0) direction_led = !direction_led;

        timer_led = millis();
    }

    Serial.print(value_led);
    Serial.print("\n");

    analogWrite(PIN_LED, value_led);
}