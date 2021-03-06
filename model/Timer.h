/*
 * Timer.h
 *
 *  Created on: Feb 16, 2016
 *      Author: jlin3312
 */

#ifndef SRC_MODEL_TIMER_H_
#define SRC_MODEL_TIMER_H_
#include <time.h>

class Timer
{
	clock_t executionTime;
public:
	Timer();
	void startTimer();
	void stopTimer();
	void resetTimer();
	void displayTimerInformation();
	long getExecutionTimeInMicroseconds();

};





#endif /* SRC_MODEL_TIMER_H_ */
