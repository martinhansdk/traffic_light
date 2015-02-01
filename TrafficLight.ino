volatile int timer_overflow_count = 0;

#define RED_PIN 0
#define YELLOW_PIN 1
#define GREEN_PIN 2

volatile int timer_interrupt = 0;
boolean is_master = false;

/**
  A LightPattern specifies a duration and which lamps are on for that duration.
  A schedule is a series of LightPatterns that are repeated in a circular fashion.
  
  A patterns with duration 0 indicates no pattern and is used to mark the end of the schedule.
*/
class LightPattern {
public:
  int duration; // unit: 1/2 seconds
  boolean red;
  boolean yellow;
  boolean green;
};

const int MAX_PATTERNS = 8;
  
const LightPattern DUMMY_PATTERN = {0, true, true, true};

class Schedule {
public:
  LightPattern patterns[MAX_PATTERNS];
  
  void setPattern(int index, int duration, boolean red, boolean yellow, boolean green) {
     if(index < MAX_PATTERNS) {
        patterns[index].duration = duration;
        patterns[index].red = red;
        patterns[index].yellow = yellow;
        patterns[index].green = green;
     } 
  }
  
  int cycle_time() {
    int sum=0;
    
    for(int i = 0 ; i < MAX_PATTERNS ; i++) {
       if(patterns[i].duration == 0) {
          break; 
       }
       sum += patterns[i].duration;
    }
    
    return sum;
  }
  
  const LightPattern* currentPattern(int time) {
    int pattern_end_time = 0;
    for(int i = 0 ; i < MAX_PATTERNS ; i++) {
       if(patterns[i].duration == 0) {
          break; 
       }
       
       pattern_end_time += patterns[i].duration;
       
       if(time < pattern_end_time) {
         return &patterns[i];  
       }
    }
    
    // nothing found
    return &DUMMY_PATTERN;
  }
  
};

/**
  light_time contains the global time which is shared by all traffic lights
  The correct state of the lights is computed from this.
  The unit is 1/2 seconds.
*/
int light_time = 0;
int cycle_time = 1;
Schedule schedule;

void set_lights(int light_time) {
  const LightPattern* pattern = schedule.currentPattern(light_time);
  
  digitalWrite(RED_PIN, pattern->red);
  digitalWrite(YELLOW_PIN, pattern->yellow);
  digitalWrite(GREEN_PIN, pattern->green);
}

ISR(TIMER1_COMPA_vect)          // timer compare interrupt service routine
{
  digitalWrite(13, digitalRead(13) ^ 1);   // toggle LED pin
  timer_interrupt = 1;
}

void setup() {
  // define schedule
  int i = 0;
  schedule.setPattern(i++, 1*2, true, true, false); // yellow/red
  schedule.setPattern(i++, 18*2, false, false, true); // green
  schedule.setPattern(i++, 4*2, false, true, false); // yellow
  // the duration of the red signal must be just so long that the light pointing
  // in the other direction can cycle through yellow-green-yellow plus a
  // little margin where both are red
  schedule.setPattern(i, 0, false, false, false); // temporary end marker
  int red_duration = schedule.cycle_time() + 1*2;
  schedule.setPattern(i++, red_duration, true, false, false); // red 
  schedule.setPattern(i, 0, false, false, false); // end marker

  cycle_time = schedule.cycle_time();

  // Set LED ports to output
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);

  // initialize timer1 
  noInterrupts();           // disable all interrupts
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;

  OCR1A = 31250;            // compare match register 16MHz/256/2Hz
  TCCR1B |= (1 << WGM12);   // CTC mode
  TCCR1B |= (1 << CS12);    // 256 prescaler 
  TIMSK1 |= (1 << OCIE1A);  // enable timer compare interrupt
  interrupts();             // enable all interrupts
}

void loop() {
  // wait until timer isr was run
  while(!timer_interrupt);
  timer_interrupt = 0;

  light_time = (light_time+1) % cycle_time;
  set_lights(light_time);
}
