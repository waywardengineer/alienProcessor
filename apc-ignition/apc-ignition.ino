const int solenoidPin = 0;
const int igniterPin = 1;


const int fill_solenoid = HIGH; 
const int fill_igniter = LOW;

const int ignite_solenoid = HIGH;
const int ignite_igniter = HIGH;

const int purge_solenoid = LOW;
const int purge_igniter = LOW;

const int fill_time = 5000;
const int ignite_time = 200;
const int purge_time = 800;

const int STATE_FILL = 0;
const int STATE_IGNITE = 1;
const int STATE_PURGE = 2;

// Variables will change:
int solenoidState = LOW;    
int igniterState = LOW;     
int state = STATE_FILL;

unsigned long previousMillis = 0;

long interval = 0;           // interval at which to blink (milliseconds)

void setup() {
  // set the digital pin as output:
  pinMode(solenoidPin, OUTPUT);
  pinMode(igniterPin, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    
    previousMillis = currentMillis;

    if (state == STATE_FILL) {
      state = STATE_IGNITE;
      interval = fill_time;
      solenoidState = fill_solenoid;
      igniterState = fill_igniter;
    } else if (state == STATE_IGNITE) {
      state = STATE_PURGE;
      interval = ignite_time;
      solenoidState = ignite_solenoid;
      igniterState = ignite_igniter;
    } else {
      state = STATE_FILL;
      interval = purge_time;
      solenoidState = purge_solenoid;
      igniterState = purge_igniter;
    }

    digitalWrite(solenoidPin, solenoidState);
    digitalWrite(igniterPin, igniterState);
  }
}
