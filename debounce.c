#include "debounce.h"
#include <stdint.h>

#define CHECK_MSEC 5 // Read hardware every 5 msec
#define PRESS_MSEC 10 // Stable time before registering pressed
#define RELEASE_MSEC 100 // Stable time before registering released

// This holds the debounced state of the key.
bool DebouncedKeyPress = false;
// Service routine called every CHECK_MSEC to
// debounce both edges
void DebounceSwitch(bool *Key_changed, bool *Key_pressed)
{
  static uint8_t Count = RELEASE_MSEC / CHECK_MSEC;
  bool RawState;
  *Key_changed = false;
  *Key_pressed = DebouncedKeyPress;
  RawState = RawKeyPressed();
  if (RawState == DebouncedKeyPress) {
    // Set the timer which allows a change from current state.
    if (DebouncedKeyPress) Count = RELEASE_MSEC / CHECK_MSEC;
    else Count = PRESS_MSEC / CHECK_MSEC;
  } else {
    // Key has changed - wait for new state to become stable.
    if (--Count == 0) {
      // Timer expired - accept the change.
      DebouncedKeyPress = RawState;
      *Key_changed=true;
      *Key_pressed=DebouncedKeyPress;
      // And reset the timer.
      if (DebouncedKeyPress) Count = RELEASE_MSEC / CHECK_MSEC;
      else Count = PRESS_MSEC / CHECK_MSEC;
    }
  }

}
