/*
 * file   : timer.c contains timer module API definitions
 * time   : HH-MM
 * date   : DD/MM/YYYY
 * author : Shashikumar BS
 */

/* ============================================
 * macro definations
 * ============================================
 */
#define EXECUTE_ON_PC

#include <stdio.h>

#ifdef EXECUTE_ON_PC
#include "../inc/timer_hw_simulation.h"
#else
#include "../inc/timer_hw.h"
#endif /* EXECUTE_ON_PC */

#include "../../../inc/types.h"
#include "../inc/timer.h"

/* ============================================
 * global variables
 * ============================================
 */

/* ============================================
 * setup frequency and initialize as timer
 * ============================================
 */
static void timer_initialize()
{
	static bool_t init = FALSE;

	if (init == FALSE)
	{
		/* Set Prescalar value -> fTIMER = 16 MHz / (2^PRESCALER) = 16/2^4 = 1MHz , 1 tick is equal to 1 micro sec*/
		REG_WRITE32(TIMER_0, PRESCALER, 0x4);

		/* select timer or counter mode (note:counter mode is not used in this application hence initialized as timer always)*/
		REG_WRITE32(TIMER_0, MODE, TIMER_MODE_TIMER);

		/* initialize valid bit width for capture/compare registers */
		REG_WRITE32(TIMER_0, BITMODE, TIMER_32_BIT_WIDTH);

		/* make sure initialization doesn't happen every time the timer_start_timer is invoked*/
		init = TRUE;
	}
}

/* ============================================
 * initialize and start the timer
 * ============================================
 */
uint32_t timer_start_timer(uint32_t time_in_us, void *callback)
{
	uint32_t set_new_compare_val = 0;
	uint32_t current_capture_val = 0;

	/* initialize timer hardware */
	timer_initialize();

	/* Assumed that the timer interrupt will be enabled and callback is placed in vector table by invoking "INTR_enable"*/
//	INTR_enable(TIMER_INTERRUPT, TIMER_INTR_PRIORITY, callback);
	/* enable interrupt for EVENTS_COMPARE[0] */
	REG_WRITE32(TIMER_0, INTENSET, TIMER_INTENSET_CC0);

	/* capture timer counter value */
	current_capture_val = timer_get_capture_value();

	/* check for overflow condition*/
	if ((TIMER_MAX - current_capture_val) < time_in_us)
	{
		set_new_compare_val = (time_in_us - (TIMER_MAX - current_capture_val));
	}
	else
	{
		set_new_compare_val = current_capture_val + time_in_us;
	}

	/* set compare value */
	REG_WRITE32(TIMER_0, CC_0, set_new_compare_val);

	/* Set compare event for EVENTS_COMPARE[0] */
	REG_WRITE32(TIMER_0, EVENTS_COMPARE_0, TRUE);

	/* Start timer */
	REG_WRITE32(TIMER_0, TASKS_START, TRUE);

	return set_new_compare_val;
}

/* ============================================
 * read present timer counter value
 * ============================================
 */
uint32_t timer_get_capture_value()
{
	REG_WRITE32(TIMER_0, TASKS_CAPTURE_0, TRUE);
	return REG_READ32(TIMER_0, CC_0);
}

/* ============================================
 * stop the timer and reset counter
 * ============================================
 */
void timer_stop_timer()
{
	/* select timer counter registers to be stopped,
	 * Note: as we are considering only CC[0] and ignoring other all registers are selected
	 */
	REG_WRITE32(TIMER_0, VAR_SHORTS, TIMER_TASK_STOP);

	/* Stop timer */
	REG_WRITE32(TIMER_0, TASKS_STOP, TRUE);

	/* select timer counter registers to be cleared */
	REG_WRITE32(TIMER_0, VAR_SHORTS, TIMER_TASK_CLEAR);

	/* clear timer counter */
	REG_WRITE32(TIMER_0, TASKS_CLEAR, TRUE);

	/* clear all the interrupts */
	REG_WRITE32(TIMER_0, VAR_INTENCLR, TIMER_DISABLE_INTP);
}
