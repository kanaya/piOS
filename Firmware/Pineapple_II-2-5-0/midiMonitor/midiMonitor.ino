
#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  while (!Serial) {
    // wait.
  }
  Serial.println("Hello.");
  MIDI.setHandleNoteOn(handleNoteOn);
  MIDI.setHandleNoteOff(handleNoteOff);
  MIDI.begin(MIDI_CHANNEL_OMNI);
}

void handleNoteOn(byte channel, byte pitch, byte velocity) {
  Serial.print("Ch.");
  Serial.print(channel);
  Serial.print(" N.");
  Serial.print(pitch);
  Serial.print(" V.");
  Serial.println(velocity);
}

void handleNoteOff(byte channel, byte pitch, byte velocity) {
  Serial.print("Ch.");
  Serial.print(channel);
  Serial.print(" N.");
  Serial.print(pitch);
  Serial.println(" Off");
}

void loop() {
  if (MIDI.read()) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
  }
}
