/*
 * only for experimenting on PC using GCC compiler should not be included more then once
 */

#include "../../../inc/types.h"

/* ============================================
 * define dummy hardware address for execution on PC
 * ============================================
 */
uint32_t VAR_TASKS_START = 0;
uint32_t VAR_TASKS_STOP = 0;
uint32_t VAR_TASKS_COUNT = 0;
uint32_t VAR_TASKS_CLEAR = 0;
uint32_t VAR_TASKS_SHUTDOWN = 0;
uint32_t VAR_TASKS_CAPTURE_0 = 0;
uint32_t VAR_TASKS_CAPTURE_1 = 0;
uint32_t VAR_TASKS_CAPTURE_2 = 0;
uint32_t VAR_TASKS_CAPTURE_3 = 0;
uint32_t VAR_TASKS_CAPTURE_4 = 0;
uint32_t VAR_TASKS_CAPTURE_5 = 0;
uint32_t VAR_EVENTS_COMPARE_0 = 0;
uint32_t VAR_EVENTS_COMPARE_1 = 0;
uint32_t VAR_EVENTS_COMPARE_2 = 0;
uint32_t VAR_EVENTS_COMPARE_3 = 0;
uint32_t VAR_EVENTS_COMPARE_4 = 0;
uint32_t VAR_EVENTS_COMPARE_5 = 0;
uint32_t VAR_SHORTS = 0;
uint32_t VAR_INTENSET = 0;
uint32_t VAR_INTENCLR = 0;
uint32_t VAR_MODE = 0;
uint32_t VAR_BITMODE = 0;
uint32_t VAR_PRESCALER = 0;
uint32_t VAR_CC_0 = 0;
uint32_t VAR_CC_1 = 0;
uint32_t VAR_CC_2 = 0;
uint32_t VAR_CC_3 = 0;
uint32_t VAR_CC_4 = 0;
uint32_t VAR_CC_5 = 0;

#define TIMER_0 ( 0x0 )
#define TIMER_1 ( 0x0 )
#define TIMER_2 ( 0x0 )

#define TASKS_START             ( &VAR_TASKS_START      )
#define TASKS_STOP              ( &VAR_TASKS_STOP       )
#define TASKS_COUNT             ( &VAR_TASKS_COUNT      )
#define TASKS_CLEAR             ( &VAR_TASKS_CLEAR      )
#define TASKS_SHUTDOWN          ( &VAR_TASKS_SHUTDOWN   )
#define TASKS_CAPTURE_0         ( &VAR_TASKS_CAPTURE_0  )
#define TASKS_CAPTURE_1         ( &VAR_TASKS_CAPTURE_1  )
#define TASKS_CAPTURE_2         ( &VAR_TASKS_CAPTURE_2  )
#define TASKS_CAPTURE_3         ( &VAR_TASKS_CAPTURE_3  )
#define TASKS_CAPTURE_4         ( &VAR_TASKS_CAPTURE_4  )
#define TASKS_CAPTURE_5         ( &VAR_TASKS_CAPTURE_5  )
#define EVENTS_COMPARE_0        ( &VAR_EVENTS_COMPARE_0 )
#define EVENTS_COMPARE_1        ( &VAR_EVENTS_COMPARE_1 )
#define EVENTS_COMPARE_2        ( &VAR_EVENTS_COMPARE_2 )
#define EVENTS_COMPARE_3        ( &VAR_EVENTS_COMPARE_3 )
#define EVENTS_COMPARE_4        ( &VAR_EVENTS_COMPARE_4 )
#define EVENTS_COMPARE_5        ( &VAR_EVENTS_COMPARE_5 )
#define SHORTS                  ( &VAR_SHORTS           )
#define INTENSET                ( &VAR_INTENSET         )
#define INTENCLR                ( &VAR_INTENCLR         )
#define MODE                    ( &VAR_MODE             )
#define BITMODE                 ( &VAR_BITMODE          )
#define PRESCALER               ( &VAR_PRESCALER        )
#define CC_0                    ( &VAR_CC_0             )
#define CC_1                    ( &VAR_CC_1             )
#define CC_2                    ( &VAR_CC_2             )
#define CC_3                    ( &VAR_CC_3             )
#define CC_4                    ( &VAR_CC_4             )
#define CC_5                    ( &VAR_CC_5             )

#define REG_WRITE32(base_addr, offset, val) \
	( *( ( volatile uint32_t * )( base_addr + offset ) ) = val )

#define REG_READ32(base_addr, offset) \
	(uint32_t)( *( ( volatile uint32_t * )( base_addr + offset ) ) )
