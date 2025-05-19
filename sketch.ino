#define SOUND_SENSOR_PIN 2
#define LIGHT_PIN 3
#define AC_PIN 4
#define FRIDGE_PIN 5

bool lightState = false;
bool acState = false;
bool fridgeState = false;

void setup() {
  pinMode(SOUND_SENSOR_PIN, INPUT_PULLUP);
  pinMode(LIGHT_PIN, OUTPUT);
  pinMode(AC_PIN, OUTPUT);
  pinMode(FRIDGE_PIN, OUTPUT);

  Serial.begin(9600);
  Serial.println("System Ready. Enter commands or press button.");
}

void loop() {
  static bool lastButtonState = HIGH;
  bool buttonState = digitalRead(SOUND_SENSOR_PIN);

  if (lastButtonState == HIGH && buttonState == LOW) {
    lightState = !lightState;
    digitalWrite(LIGHT_PIN, lightState ? HIGH : LOW);
    Serial.println(lightState ? "Light turned ON (via sound)" : "Light turned OFF (via sound)");
    delay(300);
  }
  lastButtonState = buttonState;

  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    command.trim();
    command.toLowerCase();
    processCommand(command);
  }
}

void processCommand(String command) {
  if (command == "light on") {
    digitalWrite(LIGHT_PIN, HIGH); lightState = true;
    Serial.println("Light turned ON");
  } else if (command == "light off") {
    digitalWrite(LIGHT_PIN, LOW); lightState = false;
    Serial.println("Light turned OFF");
  } else if (command == "ac on") {
    digitalWrite(AC_PIN, HIGH); acState = true;
    Serial.println("AC turned ON");
  } else if (command == "ac off") {
    digitalWrite(AC_PIN, LOW); acState = false;
    Serial.println("AC turned OFF");
  } else if (command == "fridge on") {
    digitalWrite(FRIDGE_PIN, HIGH); fridgeState = true;
    Serial.println("Fridge turned ON");
  } else if (command == "fridge off") {
    digitalWrite(FRIDGE_PIN, LOW); fridgeState = false;
    Serial.println("Fridge turned OFF");
  } else {
    Serial.println("Invalid command.");
  }
}
