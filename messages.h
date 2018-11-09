#ifndef _MESSAGES_H_
#define _MESSAGES_H_

#include "stdbool.h"
#include "stdint.h"

#define CMD_SHIFT 10
#define START_BIT      0x80
#define IR_SYNC_CMD    ((uint32_t)(START_BIT | 0x5a))
#define IR_PROGRAM_CMD ((uint32_t)(START_BIT | 0x45))
#define IR_ROLE_CMD    ((uint32_t)(START_BIT | 0x57))

// sync command message format
#define MODE_SHIFT 9

// program command message format
#define INDEX_SHIFT  10
#define RED_SHIFT    9
#define YELLOW_SHIFT 8
#define GREEN_SHIFT  7

uint8_t extract_command(uint32_t msg) {
  return (msg >> CMD_SHIFT) & 0xff; // 7 bits of command + 1 start bit
}

uint32_t inline make_sync_message(bool manual_mode, uint16_t light_time) {
  return (IR_SYNC_CMD<<CMD_SHIFT) | (manual_mode << MODE_SHIFT) | light_time;
}

void inline extract_sync_message(uint32_t msg, bool *manual_mode, uint16_t *light_time) {
  *manual_mode = (msg >> MODE_SHIFT) & 0x1;
  *light_time = msg & 0x1ff;
}


#endif /* _MESSAGES_H_ */
