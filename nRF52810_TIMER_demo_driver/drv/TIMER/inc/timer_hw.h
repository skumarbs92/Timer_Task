/*
 * file   : timer_hw.h contains timer module register details
 * time   : HH-MM
 * date   : DD/MM/YYYY
 * author : Shashikumar BS
 */

/* ============================================
 * macro definitions
 * ============================================
 */

#include "../../../inc/types.h"

#ifndef TIMER_INC_HW_H
#define TIMER_INC_HW_H

#define TIMER_0 ( 0x40008000UL )
#define TIMER_1 ( 0x40009000UL )
#define TIMER_2 ( 0x4000A000UL )

#define TASKS_START             ( 0x000 )        /*Start Timer                                     */
#define TASKS_STOP              ( 0x004 )        /*Stop Timer                                      */
#define TASKS_COUNT             ( 0x008 )        /*Increment Timer (Counter mode only)             */
#define TASKS_CLEAR             ( 0x00C )        /*Clear time                                      */
#define TASKS_SHUTDOWN          ( 0x010 )        /*Shut down timer Deprecated                      */
#define TASKS_CAPTURE_0         ( 0x040 )        /*Capture Timer value to CC[0] register           */
#define TASKS_CAPTURE_1         ( 0x044 )        /*Capture Timer value to CC[1] register           */
#define TASKS_CAPTURE_2         ( 0x048 )        /*Capture Timer value to CC[2] register           */
#define TASKS_CAPTURE_3         ( 0x04C )        /*Capture Timer value to CC[3] register           */
#define TASKS_CAPTURE_4         ( 0x050 )        /*Capture Timer value to CC[4] register           */
#define TASKS_CAPTURE_5         ( 0x054 )        /*Capture Timer value to CC[5] register           */
#define EVENTS_COMPARE_0        ( 0x140 )        /*Compare event on CC[0] match                    */
#define EVENTS_COMPARE_1        ( 0x144 )        /*Compare event on CC[1] match                    */
#define EVENTS_COMPARE_2        ( 0x148 )        /*Compare event on CC[2] match                    */
#define EVENTS_COMPARE_3        ( 0x14C )        /*Compare event on CC[3] match                    */
#define EVENTS_COMPARE_4        ( 0x150 )        /*Compare event on CC[4] match                    */
#define EVENTS_COMPARE_5        ( 0x154 )        /*Compare event on CC[5] match                    */
#define SHORTS                  ( 0x200 )        /*Shortcut register                               */
#define INTENSET                ( 0x304 )        /*Enable interrupt                                */
#define INTENCLR                ( 0x308 )        /*Disable interrupt                               */
#define MODE                    ( 0x504 )        /*Timer mode selection                            */
#define BITMODE                 ( 0x508 )        /*Configure the number of bits used by the TIMER  */
#define PRESCALER               ( 0x510 )        /*Timer prescaler register                        */
#define CC_0                    ( 0x540 )        /*Capture/Compare register 0                      */
#define CC_1                    ( 0x544 )        /*Capture/Compare register 1                      */
#define CC_2                    ( 0x548 )        /*Capture/Compare register 2                      */
#define CC_3                    ( 0x54C )        /*Capture/Compare register 3                      */
#define CC_4                    ( 0x550 )        /*Capture/Compare register 4                      */
#define CC_5                    ( 0x554 )        /*Capture/Compare register 5                      */

#define REG_WRITE32(base_addr, offset, val) \
	( *( ( volatile uint32_t * )( base_addr + offset ) ) = val )

#define REG_READ32(base_addr, offset) \
	(uint32_t)( *( ( volatile uint32_t * )( base_addr + offset ) ) )

#endif /* TIMER_INC_HW_H */
