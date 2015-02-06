#ifndef _SCHEDULE_H
#define _SCHEDULE_H value

#include <stdbool.h>


/**
  A LightPattern specifies a duration and which lamps are on for that duration.
  A schedule is a series of LightPatterns that are repeated in a circular fashion.

  A patterns with duration 0 indicates no pattern and is used to mark the end of the schedule.
*/

// maximum number of patterns in a schedule
#define MAX_PATTERNS 8

typedef struct {
  int duration; // unit: 1/2 seconds
  bool red;
  bool yellow;
  bool green;
} LightPattern;


extern const LightPattern DUMMY_PATTERN;

typedef struct {
  LightPattern patterns[MAX_PATTERNS];
} Schedule;

extern int cycleTime(Schedule* schedule);
extern void setPattern(Schedule* schedule, int index, int duration, bool red, bool yellow, bool green);
extern const LightPattern* currentPattern(Schedule* schedule, int time);

#endif
