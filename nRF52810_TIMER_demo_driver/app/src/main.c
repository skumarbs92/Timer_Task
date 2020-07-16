/*
 * file   : main.c contains main application
 * time   : HH-MM
 * date   : DD/MM/YYYY
 * author : Shashikumar BS
 */

/* ============================================
 * macro definitions
 * ============================================
 */

/*
 * This macro is used for executing the code on PC (using GCC compiler)
 */
#define EXECUTE_ON_PC

#include <stdio.h>
#include "../../inc/types.h"
#include "../../drv/TIMER/inc/timer.h"
#ifdef EXECUTE_ON_PC
#include <time.h>
#endif /* EXECUTE_ON_PC */

/* ============================================
 * USER INTERRUPT "509 mili seconds"
 * ============================================
 */
#define TIME_INTERVAL_IN_US (509000)

/* ============================================
 * global variables
 * ============================================
 */

/* ============================================
 * static function declarations
 * ============================================
 */
static void timer_callback(void *callback_param);

/* ============================================
 * function definations
 * ============================================
 */
#ifdef EXECUTE_ON_PC

/* ============================================
 * generate delay of given mili seconds
 * ============================================
 */
static void delay(unsigned int mseconds)
{
	clock_t goal = mseconds + clock();
	while (goal > clock())
		;
}
#endif /* EXECUTE_ON_PC */

/* ============================================
 * callback to be invoked when timer ticks to set value
 * ============================================
 */
static void timer_callback(void *callback_param)
{
	/* print incremented count value */
	printf("timer value = %d\n", timer_get_capture_value());

	/* initiate the timer again for periodic event
	 * Note:Assumed that periodic interrupt for timer module is not supported
	 */
	timer_start_timer(TIME_INTERVAL_IN_US, (void*) timer_callback);
}

/* ============================================
 * sample application is written here for demo
 * ============================================
 */
int main()
{
	bool_t status;

	/* initialize and start timer */
	status = timer_start_timer(TIME_INTERVAL_IN_US, (void*) timer_callback);

	/*
	 * after triggering all the required tasks application goes to
	 * low power mode waiting for an even to occur
	 */
	while (1)
	{
		/* when run on simulator trigger the interrupt in application loop */
#ifdef EXECUTE_ON_PC
		delay(TIME_INTERVAL_IN_US / 1000);
		timer_callback((void*) clock());
#endif /* EXECUTE_ON_PC */
	}
}

