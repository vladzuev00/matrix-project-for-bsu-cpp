#include "stdafx.h"
#include "MeasurerOfTimeOfExecution.h"
#include <ctime>
#include <chrono>

//****************************************************************************************
MeasurerOfTimeOfExecution::MeasurerOfTimeOfExecution()
{
	
}
//****************************************************************************************
template<class ReturnTypeOfExecutedFunction>
double MeasurerOfTimeOfExecution::mesuareExecutionBySeconds(ReturnTypeOfExecutedFunction(*execute)()) const 
{
	std::chrono::steady_clock::time_point startOfExecution = std::chrono::high_resolution_clock::now();
	execute();
	std::chrono::steady_clock::time_point endOfExecution = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> durationOfExecution = endOfExecution - startOfExecution;
	return durationOfExecution.count();
}
//****************************************************************************************
MeasurerOfTimeOfExecution::~MeasurerOfTimeOfExecution()
{

}
//****************************************************************************************