#include "schedule.h"

const LightPattern DUMMY_PATTERN = {0, true, true, true};

void setPattern(Schedule* schedule, int index, int duration, bool red, bool yellow, bool green) {
    if(index < MAX_PATTERNS) {
        schedule->patterns[index].duration = duration;
        schedule->patterns[index].red = red;
        schedule->patterns[index].yellow = yellow;
        schedule->patterns[index].green = green;
    }
}

uint16_t cycleTime(Schedule* schedule) {
    uint16_t sum=0;
    int i;

    for(i = 0 ; i < MAX_PATTERNS ; i++) {
        if(schedule->patterns[i].duration == 0) {
            break;
        }
        sum += schedule->patterns[i].duration;
    }

    return sum;
}

const LightPattern* currentPattern(Schedule* schedule, int time) {
    int pattern_end_time = 0;
    int i;

    for(i = 0 ; i < MAX_PATTERNS ; i++) {
        if(schedule->patterns[i].duration == 0) {
            break;
        }

        pattern_end_time += schedule->patterns[i].duration;

        if(time < pattern_end_time) {
            return &schedule->patterns[i];
        }
    }

    // nothing found
    return &DUMMY_PATTERN;
}
