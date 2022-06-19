// https://community.nxp.com/t5/i-MX-RT/imxrt-1050-Millisecond-ticks/m-p/1204336/highlight/true#M11878

#include "timer.h"

#include "fsl_common.h"
#include "fsl_gpt.h"

namespace rp{ namespace arch{

void rp_timer_init()
{
    gpt_config_t gpt1Config;

    GPT_GetDefaultConfig(&gpt1Config);
//     The default values are:
//       config.clockSource = kGPT_ClockSource_Periph;
//       config.divider = 1U;
//       config.enableRunInStop = true;
//       config.enableRunInWait = true;
//       config.enableRunInDoze = false;
//       config.enableRunInDbg = false;
//       config.enableFreeRun = false;
//       config.enableMode  = true;

    GPT_Init(GPT1, &gpt1Config);                    // Set config to defaults
    GPT_SetClockSource(GPT1, kGPT_ClockSource_Osc); // 24 MHz
    GPT_SetClockDivider(GPT1, 24);                  // Prescaler = 24

    gpt1Config.enableFreeRun = true;                // Free run
    gpt1Config.enableMode  = false;                 // No reset of counter

    GPT_StartTimer(GPT1);                           // Start Timer
}

_u64 rp_getus()
{
	return GPT_GetCurrentTimerCount(GPT1);
}

_u32 rp_getms()
{
    return rp_getus()/1000L;
}

void rp_delay(_word_size_t ms)
{
	SDK_DelayAtLeastUs(1000 * ms, CLOCK_GetOscFreq());
}
}}
