#ifndef MATRIX_H
#define MATRIX_H

#include <string>
#include <vector>

//******************************************************************************************
class MatrixValidator;
//******************************************************************************************
template<class ElementType>
class Matrix
{
private:
	ElementType **elements;
	int amountOfRows;
	int amountOfColumns;
private:
	static const MatrixValidator MATRIX_VALIDATOR;
public:
	static const int DEFAULT_VALUE_OF_AMOUNT_OF_ROWS;
	static const int DEFAULT_VALUE_OF_AMOUNT_OF_COLUMNS;
	static const ElementType DEFAULT_VALUE_OF_ELEMENT;
	static const std::string DESCRIPTION_OF_NULL_POINTER;
private:
	void allocateMemoryForElements();
	void initializeElements(const ElementType &valueOfElements);
	void initializeElements(ElementType * const valuesOfElements);
	void initializeElements(ElementType **valuesOfElements);
	void freeMemoryAllocatedForElements();
private:
	static std::string findDescriptionOfElements(ElementType * const elements,
		const int amountOfElements);
	static std::string findDescriptionOfElements(ElementType **elements, const int amountOfRows,
		const int amountOfColumns);
public:
	Matrix();
	Matrix(const int amountOfRows, const int amountOfColumns);
	Matrix(ElementType * const valuesOfElements, const int amountOfRows, const int amountOfColumns);
	Matrix(ElementType **valuesOfElements, const int amountOfRows, const int amountOfColumns);
	Matrix(const Matrix<ElementType> &other);
public:
	inline int getAmountOfRows() const;
	inline int getAmountOfColumns() const;
public:
	void updateValueOfElement(const ElementType &newValueOfElement, const int indexOfRowOfElement,
		                      const int indexOfColumnOfElement);
	const ElementType& findElement(const int indexOfRowOfElement,
		const int indexOfColumnOfElement) const;
	//TODO: test this method
	std::vector<ElementType*>* findElements(bool(*isMatch)(const ElementType&)) const;
	//TODO: test this method
	void updateElements(const ElementType &newValueOfElements,
		bool(*isShouldBeUpdated)(const ElementType&));
	//TODO: test this method
	void updateElements(ElementType(*generateNewValueForElement)(),
		bool(*isShouldBeUpdated)(const ElementType&));
	//TODO: test this method
	std::string toString() const;
	//TODO: test this method
	ElementType findSumOfElementsUnderMainDiagonal() const;
public:
	bool operator==(const Matrix<ElementType> &other) const;
	bool operator!=(const Matrix<ElementType> &other) const;
	const Matrix<ElementType>& operator=(const Matrix<ElementType> &other);
	//TODO: test this method
	ElementType* operator[](const int indexOfRow) const;
public:
	~Matrix();
};
//******************************************************************************************
class MatrixValidator
{
private:
	static const int MINIMAL_ALLOWABLE_VALUE_OF_AMOUNT_OF_ROWS;
	static const int MAXIMAL_ALLOWABLE_VALUE_OF_AMOUNT_OF_ROWS;
	static const int MINIMAL_ALLOWABLE_VALUE_OF_AMOUNT_OF_COLUMNS;
	static const int MAXIMAL_ALLOWABLE_VALUE_OF_AMOUNT_OF_COLUMNS;
public:
	bool isValidAmountOfRows(const int researchAmountOfRows) const;
	bool isValidAmountOfColumns(const int researchAmountOfColumns) const;
	template<class ElementType>
	bool areValidValuesOfElements(ElementType * const researchValuesOfElements) const;
	template<class ElementType>
	bool areValidValuesOfElements(ElementType **researchValuesOfElements,
		const int amountOfRows) const;
	template<class ElementType>
	bool isValidIndexOfRow(const int researchIndexOfRow,
		const Matrix<ElementType> containingMatrix) const;
	template<class ElementType>
	bool isValidIndexOfColumn(const int researchIndexOfColumn,
		const Matrix<ElementType> containingMatrix) const;
};
//******************************************************************************************

#endif MATRIX_H