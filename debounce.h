#ifndef _DEBOUNCE_H
#define _DEBOUNCE_H

#include <stdbool.h>

extern bool RawKeyPressed();
extern bool DebouncedKeyPress;

void DebounceSwitch(bool *Key_changed, bool *Key_pressed);

#endif
