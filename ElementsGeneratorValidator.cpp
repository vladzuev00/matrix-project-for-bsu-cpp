#include "stdafx.h"
#include "ElementsGeneratorValidator.h"
#include <climits>

//************************************************************************************
template   //TODO: убрать кастыль
bool ElementsGeneratorValidator::areValidBordersOfGeneration(
	const double &minimalGeneratedValue,
	const double &maximalGeneratedValue) const;
//************************************************************************************
ElementsGeneratorValidator::ElementsGeneratorValidator()
{

}
//************************************************************************************
template<class GeneratedElementType>
bool ElementsGeneratorValidator::areValidBordersOfGeneration(
	const GeneratedElementType &minimalGeneratedValue,
	const GeneratedElementType &maximalGeneratedValue) const
{
	return minimalGeneratedValue <= maximalGeneratedValue;
}
//************************************************************************************
bool ElementsGeneratorValidator::isValidAmountOfElementsToGenerate(
	const unsigned int researchAmountOfElements) const
{
	return ElementsGeneratorValidator::MINIMAL_ALLOWABLE_AMOUNT_OF_ELEMENTS_TO_GENERATE
		<= researchAmountOfElements && researchAmountOfElements <= 
		ElementsGeneratorValidator::MAXIMAL_ALLOWABLE_AMOUNT_OF_ELEMENTS_TO_GENERATE;
}
//************************************************************************************
const unsigned int ElementsGeneratorValidator::MINIMAL_ALLOWABLE_AMOUNT_OF_ELEMENTS_TO_GENERATE = 1;
//************************************************************************************
const unsigned int ElementsGeneratorValidator::MAXIMAL_ALLOWABLE_AMOUNT_OF_ELEMENTS_TO_GENERATE = UINT_MAX;
//************************************************************************************
ElementsGeneratorValidator::~ElementsGeneratorValidator()
{

}
//************************************************************************************