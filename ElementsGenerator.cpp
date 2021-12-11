#include "stdafx.h"
#include "ElementsGenerator.h"
#include <time.h>
#include "ElementsGeneratorCreatingException.h"
#include "ElementsGeneratorUpdatingException.h"

//*************************************************************
template class ElementsGenerator<double>;      //TODO: убрать кастыль
//*************************************************************
template<class GeneratedElementType>
ElementsGenerator<GeneratedElementType>::ElementsGenerator(
	const GeneratedElementType &minimalGeneratedValue,
	const GeneratedElementType &maximalGeneratedValue)
{
	if (!ElementsGenerator<GeneratedElementType>::ELEMENTS_GENERATOR_VALIDATOR
		.areValidBordersOfGeneration<GeneratedElementType>(
			minimalGeneratedValue, maximalGeneratedValue))
	{
		throw new ElementsGeneratorCreatingException(
			"Given minimal and maximal borders of generation "
			"for initializing generator of elements aren't valid. "
		    "Given borders: \n\tminimal border = "
			+ std::to_string(minimalGeneratedValue) + "\n\tmaximal border = " 
			+ std::to_string(maximalGeneratedValue) + "\n");
	}
	this->minimalGeneratedValue = minimalGeneratedValue;
	this->maximalGeneratedValue = maximalGeneratedValue;
}
//*************************************************************
template<class GeneratedElementType>
const ElementsGeneratorValidator ElementsGenerator<GeneratedElementType>
   ::ELEMENTS_GENERATOR_VALIDATOR = ElementsGeneratorValidator();
//*************************************************************
template<class GeneratedElementType>
void ElementsGenerator<GeneratedElementType>::setMinimalGeneratedValue(
	const GeneratedElementType &minimalGeneratedValue)
{
	if (!ElementsGenerator<GeneratedElementType>::ELEMENTS_GENERATOR_VALIDATOR
		.areValidBordersOfGeneration<GeneratedElementType>
		(minimalGeneratedValue, this->maximalGeneratedValue))
	{
		throw new ElementsGeneratorUpdatingException("Given minimal border of "
			"generation for initializing generator of elements isn't valid. "
			"Given minimal morder is " + std::to_string(minimalGeneratedValue));
	}
	this->minimalGeneratedValue = minimalGeneratedValue;
}
//*************************************************************
template<class GeneratedElementType>
const GeneratedElementType& ElementsGenerator<GeneratedElementType>::getMinimalGeneratedValue() const
{
	return this->minimalGeneratedValue;
}
//*************************************************************
template<class GeneratedElementType>
void ElementsGenerator<GeneratedElementType>::setMaximalGeneratedValue(
	const GeneratedElementType &maximalGeneratedValue)
{
	if (!ElementsGenerator<GeneratedElementType>::ELEMENTS_GENERATOR_VALIDATOR
		.areValidBordersOfGeneration<GeneratedElementType>
		(this->minimalGeneratedValue, maximalGeneratedValue))
	{
		throw new ElementsGeneratorUpdatingException("Given maximal border of "
			"generation for initializing generator of elements isn't valid. "
			"Given maximal morder is " + std::to_string(maximalGeneratedValue));
	}
	this->maximalGeneratedValue = maximalGeneratedValue;
}
//*************************************************************
template<class GeneratedElementType>
const GeneratedElementType& ElementsGenerator<GeneratedElementType>::getMaximalGeneratedValue() const
{
	return this->maximalGeneratedValue;
}
//*************************************************************
template<class GeneratedElementType>
GeneratedElementType* ElementsGenerator<GeneratedElementType>::generateElements(
	const unsigned int amountElements) const
{
	GeneratedElementType *generatedElements = new GeneratedElementType[amountElements];   
	for (int i = 0; i < amountElements; i++)
	{
		*(generatedElements + i)
			= (rand() % int(this->maximalGeneratedValue - this->minimalGeneratedValue + 1)
				+ this->minimalGeneratedValue);
	}
	return generatedElements;
}
//*************************************************************
template<class GeneratedElementType>
ElementsGenerator<GeneratedElementType>::~ElementsGenerator()
{

}
//*************************************************************