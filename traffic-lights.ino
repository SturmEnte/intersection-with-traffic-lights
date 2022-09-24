/*
* Ampel 1: Pins  11-13
* Ampel 2: Pins   8-10
*/

const int RED1 = 13;
const int YELLOW1 = 12;
const int GREEN1 = 11;

const int RED2 = 10;
const int YELLOW2 = 9;
const int GREEN2 = 8;

const int LONG_PHASE = 9000;
const int SHORT_PHASE = 1000;

void setup() {
	pinMode(RED1, OUTPUT);
	pinMode(YELLOW1, OUTPUT);
	pinMode(GREEN1, OUTPUT);
	pinMode(RED2, OUTPUT);
	pinMode(YELLOW2, OUTPUT);
	pinMode(GREEN2, OUTPUT);
}

void loop() {
  // Ampel 1 Grün
  setRed(1, LOW);
  setYellow(1, LOW);
  setGreen(1, HIGH);

  // Ampel 2 Rot
  setYellow(2, LOW);
  setRed(2, HIGH);

  delay(LONG_PHASE);

  // Ampel 1 Gelb
  setGreen(1, LOW);
  setYellow(1, HIGH);

  // Ampel 2 Rot, Gelb
  setYellow(2, HIGH);

  delay(SHORT_PHASE);

  // Ampel 1 Rot
  setYellow(1, LOW);
  setRed(1, HIGH);

  // Ampel 2 Grün
  setRed(2, LOW);
  setYellow(2, LOW);
  setGreen(2, HIGH);

  delay(LONG_PHASE);

  // Ampel 1 Rot, Gelb
  setYellow(1, HIGH);

  // Ampel 2 Gelb
  setGreen(2, LOW);
  setYellow(2, HIGH);

  delay(SHORT_PHASE);

}

void setGreen(int ampel, int value) {
	if (ampel == 1) {
		digitalWrite(GREEN1, value);
	}
	else {
		digitalWrite(GREEN2, value);
	}
}

void setYellow(int ampel, int value) {
	if (ampel == 1) {
		digitalWrite(YELLOW1, value);
	}
	else {
		digitalWrite(YELLOW2, value);
	}
}

void setRed(int ampel, int value) {
	if (ampel == 1) {
		digitalWrite(RED1, value);
	}
	else {
		digitalWrite(RED2, value);
	}
}