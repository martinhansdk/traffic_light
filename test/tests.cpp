#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../messages.h"

// returns a bit mask with the n least significant bits set
// n must be in the range 0 to 31.
uint32_t bit_mask(size_t n) {
  return (1<<n)-1;
}


TEST_CASE( "Encoding sync message", "[messages]" ) {

  for(bool manual_mode : {false, true}) {

    for(uint16_t light_time = 0 ; light_time < 512 ; light_time++) {

      SECTION("with manual_mode=" + std::to_string(manual_mode) + " light_time=" + std::to_string(light_time)) {
        
        uint32_t msg = make_sync_message(manual_mode, light_time);        
        bool decoded_manual_mode = !manual_mode;
        uint16_t decoded_light_time = ~decoded_light_time;

        // only the MESSAGE_WIDTH most least significant bits get sent
        msg &= bit_mask(MESSAGE_WIDTH);
        
        extract_sync_message(msg, &decoded_manual_mode, &decoded_light_time);
        
        CHECK( decoded_manual_mode == manual_mode );
        CHECK( decoded_light_time == light_time );
        CHECK( extract_command(msg) == IR_SYNC_CMD );
      }
    }
  }
}


