#ifndef ELEMENTSGENERATOR_H
#define ELEMENTSGENERATOR_H

#include "ElementsGeneratorValidator.h"

//******************************************************************************************
template<class GeneratedElementType>
class ElementsGenerator
{
private:
	GeneratedElementType minimalGeneratedValue;
	GeneratedElementType maximalGeneratedValue;
private:
	static const ElementsGeneratorValidator ELEMENTS_GENERATOR_VALIDATOR;
public:
	ElementsGenerator(const GeneratedElementType &minimalGeneratedValue,
		const GeneratedElementType &maximalGeneratedValue);
public:
	void setMinimalGeneratedValue(const GeneratedElementType &newMinimalGeneratedValue);
	const GeneratedElementType& getMinimalGeneratedValue() const;
	void setMaximalGeneratedValue(const GeneratedElementType &newMaximalGeneratedValue);
	const GeneratedElementType& getMaximalGeneratedValue() const;
	GeneratedElementType* generateElements(const unsigned int amountElements) const;
public:
	~ElementsGenerator();
};
//******************************************************************************************


#endif ELEMENTSGENERATOR_H