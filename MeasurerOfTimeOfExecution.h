#ifndef MEASUREROFTIMEOFEXECUTION_H
#define MEASUREROFTIMEOFEXECUTION_H

//****************************************************************************************
class MeasurerOfTimeOfExecution
{
public:
	MeasurerOfTimeOfExecution();
public:
	template<class ReturnTypeOfExecutedFunction>
	double mesuareExecutionBySeconds(ReturnTypeOfExecutedFunction (*execute)()) const;
public:
	~MeasurerOfTimeOfExecution();
};
//****************************************************************************************

#endif MEASUREROFTIMEOFEXECUTION_H