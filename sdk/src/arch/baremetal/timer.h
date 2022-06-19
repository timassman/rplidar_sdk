#pragma once

#include "hal/types.h"

namespace rp{ namespace arch{

void rp_timer_init();
_u64 rp_getus();
_u32 rp_getms();
void rp_delay(_word_size_t ms);

}}

#define getms() rp::arch::rp_getms()
#define delay(x) rp::arch::rp_delay(x)
