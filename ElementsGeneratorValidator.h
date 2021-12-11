#ifndef ELEMENTSGENERATORVALIDATOR_H
#define ELEMENTSGENERATORVALIDATOR_H

//************************************************************************************
class ElementsGeneratorValidator
{
private:
	static const unsigned int MINIMAL_ALLOWABLE_AMOUNT_OF_ELEMENTS_TO_GENERATE;
	static const unsigned int MAXIMAL_ALLOWABLE_AMOUNT_OF_ELEMENTS_TO_GENERATE;
public:
	ElementsGeneratorValidator();
public:
	template<class GeneratedElementType>
	bool areValidBordersOfGeneration(const GeneratedElementType &minimalGeneratedValue,
		const GeneratedElementType &maximalGeneratedValue) const;
	bool isValidAmountOfElementsToGenerate(const unsigned int researchAmountOfElements) const;
public:
	~ElementsGeneratorValidator();
};
//************************************************************************************

#endif ELEMENTSGENERATORVALIDATOR_H