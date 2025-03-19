const int RED = 9;
const int YELLOW = 10;
const int GREEN = 11;
const int BUTTON = 8;

const int arr[] = {RED, YELLOW, GREEN};
const int size = sizeof(arr) / sizeof(arr[0]);

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
}

// Corrected blink function
void blink(const int arr[], int size) {
  for (int i = 0; i < size; i++) {
    if (digitalRead(BUTTON) == LOW) {
      digitalWrite(RED, HIGH);
      while (digitalRead(BUTTON) == LOW);
      digitalWrite(RED, LOW);
      return;
    }
    
    digitalWrite(arr[i], HIGH);
    delay(1000);
    digitalWrite(arr[i], LOW);
    delay(1000);
  }
}

void loop() {
  blink(arr, size);
}
