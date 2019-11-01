const byte PIN_PHOTO = A0;
const byte PIN_LED = 3;

void setup() {
    pinMode(PIN_PHOTO, INPUT);
    pinMode(PIN_LED, OUTPUT);
    
    Serial.begin(9600);
}

void loop() {
    int value_photo = analogRead(PIN_PHOTO);

    filter1 = filter2;
    filter2 = filter3;
    filter3 = filter4;
    filter4 = value_photo;

    int value_photo_filtered = (filter1 + filter2 + filter3 + filter4) / 4;
    
    Serial.println(value_photo_filtered);
}
