const int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
const int numLeds = sizeof(ledPins) / sizeof(ledPins[0]);
int timer= 100;
void setup() {
// Initialize all LED pins as outputs
for (int i = 0; i < numLeds; i++) {
pinMode(ledPins[i], OUTPUT);
}
randomSeed(analogRead(A0)); // Seed the random number generator for randomness
}

void loop() {

for(int thisPin = 2; thisPin <= 10; thisPin++){
digitalWrite(thisPin, HIGH);
delay(timer);
}
for(int thisPin = 2; thisPin <= 10; thisPin++){
digitalWrite(thisPin, LOW);
delay(timer);
}

for (int i = 0; i < numLeds; i++) {
if (ledPins[i] % 2 == 0) { // Even pins
for (int j = 0; j < 3; j++) {
digitalWrite(ledPins[i], HIGH);
delay(50);
digitalWrite(ledPins[i], LOW);
delay(50);
}
}
}

// Turn on and off LEDs on odd-numbered pins
for (int i = 0; i < numLeds; i++) {
if (ledPins[i] % 2 != 0) { // Odd pins
for (int j = 0; j < 3; j++) {
digitalWrite(ledPins[i], HIGH);
delay(50);
digitalWrite(ledPins[i], LOW);
delay(50);
}
}
}

delay(1000);

digitalWrite(ledPins[0], HIGH);
digitalWrite(ledPins[numLeds - 1], HIGH);
delay(500);

// Move LEDs from the outer edges towards the center--c
int start = 0;
int end = numLeds - 1;
while (start <= end) {
digitalWrite(ledPins[start], HIGH);
digitalWrite(ledPins[end], HIGH);
delay(100);
start++;
end--;
}

// Turn off LEDs from the inner to the outer
start = 0;
end = numLeds - 1;
while (start <= end) {
digitalWrite(ledPins[start], LOW);
digitalWrite(ledPins[end], LOW);
delay(100);
start++;
end--;
}

delay(1000); // Pause before starting the next task--d

// Task d: Randomly turn LEDs on or off
for (int i = 0; i < numLeds; i++) {
if (random(0, 2) == 0) {
digitalWrite(ledPins[i], HIGH);
} else {
digitalWrite(ledPins[i], LOW);
}
}

delay(1000); // Wait a second before repeating the entire loop
}