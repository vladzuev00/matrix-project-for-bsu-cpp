#include "stdafx.h"
#include "Matrix.h"
#include "MatrixCreatingException.h"
#include "MatrixUpdatingException.h"
#include "MatrixSearchingException.h"

//****************************************Matrix********************************************
template class Matrix<double>;
//******************************************************************************************
template<class ElementType>
Matrix<ElementType>::Matrix()
	: amountOfRows(Matrix<ElementType>::DEFAULT_VALUE_OF_AMOUNT_OF_ROWS),
	  amountOfColumns(Matrix<ElementType>::DEFAULT_VALUE_OF_AMOUNT_OF_COLUMNS)
{
	this->allocateMemoryForElements();
	this->initializeElements(Matrix<ElementType>::DEFAULT_VALUE_OF_ELEMENT);
}
//******************************************************************************************
template<class ElementType>
const int Matrix<ElementType>::DEFAULT_VALUE_OF_AMOUNT_OF_ROWS = 1;
//******************************************************************************************
template<class ElementType>
const int Matrix<ElementType>::DEFAULT_VALUE_OF_AMOUNT_OF_COLUMNS = 1;
//******************************************************************************************
template<class ElementType>
void Matrix<ElementType>::allocateMemoryForElements()
{
	this->elements = new ElementType*[this->amountOfRows];
	for (int i = 0; i < this->amountOfRows; i++)
	{
		*(this->elements + i) = new ElementType[this->amountOfColumns];
	}
} 
//******************************************************************************************
template<class ElementType>
void Matrix<ElementType>::initializeElements(const ElementType &valueOfElements)
{
	for (int i = 0; i < this->amountOfRows; i++)
	{
		for (int j = 0; j < this->amountOfColumns; j++)
		{
			*(*(this->elements + i) + j) = valueOfElements;
		}
	}
}
//******************************************************************************************
template<class ElementType>
const ElementType Matrix<ElementType>::DEFAULT_VALUE_OF_ELEMENT = ElementType();
//******************************************************************************************
template<class ElementType>
Matrix<ElementType>::Matrix(const int amountOfRows, const int amountOfColumns) 
{
	if ( !(Matrix<ElementType>::MATRIX_VALIDATOR.isValidAmountOfRows(amountOfRows)
		&& Matrix<ElementType>::MATRIX_VALIDATOR.isValidAmountOfColumns(amountOfColumns)))
	{
		throw new MatrixCreatingException("Impossible to create matrix by given not valid "
			"amount of rows: " + std::to_string(amountOfRows) + ", amount of columns: " 
			+ std::to_string(amountOfColumns) + ".");
	}
	this->amountOfRows = amountOfRows;
	this->amountOfColumns = amountOfColumns;
	this->allocateMemoryForElements();
	this->initializeElements(Matrix<ElementType>::DEFAULT_VALUE_OF_ELEMENT);
}
//******************************************************************************************
template<class ElementType>
const MatrixValidator Matrix<ElementType>::MATRIX_VALIDATOR = MatrixValidator();
//******************************************************************************************
template<class ElementType>
Matrix<ElementType>::Matrix(ElementType * const valuesOfElements,
	const int amountOfRows, const int amountOfColumns) 
{
	if(  !(Matrix<ElementType>::MATRIX_VALIDATOR.areValidValuesOfElements<ElementType>(valuesOfElements)
		&& Matrix<ElementType>::MATRIX_VALIDATOR.isValidAmountOfRows(amountOfRows)
		&& Matrix<ElementType>::MATRIX_VALIDATOR.isValidAmountOfColumns(amountOfColumns)))
	{
		const int amountOfValuesOfElements = amountOfRows * amountOfColumns;
		const string &descriptionOfElements = Matrix<ElementType>
			::findDescriptionOfElements(valuesOfElements, amountOfValuesOfElements);
		throw new MatrixCreatingException("Impossible to create matrix by given not valid "
			"amount of rows: " + std::to_string(amountOfRows) + ", amount of columns: "
			+ std::to_string(amountOfColumns) + ", values of elements: "
			+ descriptionOfElements + ".");
	}
	this->amountOfRows = amountOfRows;
	this->amountOfColumns = amountOfColumns;
	this->allocateMemoryForElements();
	this->initializeElements(valuesOfElements);
}
//******************************************************************************************
template<class ElementType>
std::string Matrix<ElementType>::findDescriptionOfElements(ElementType * const elements, 
	const int amountOfElements)
{
	if (elements == 0) 
	{
		return Matrix<ElementType>::DESCRIPTION_OF_NULL_POINTER;
	}
	const std::string startOfDescriptionOfElements("[");
	std::string descriptionOfElements(startOfDescriptionOfElements);
	descriptionOfElements.append(std::to_string(*elements));
	const std::string delimiterOfDescriptionsOfElements = ", ";
	const std::string *descriptionOfCurrentElement;
	for (int i = 1; i < amountOfElements; i++) 
	{
		descriptionOfElements.append(delimiterOfDescriptionsOfElements);
		descriptionOfCurrentElement = &std::to_string(*(elements + i));
		descriptionOfElements.append(*descriptionOfCurrentElement);
	}
	const string endOfDescriptionOfElements("]");
	descriptionOfElements.append(endOfDescriptionOfElements);
	return descriptionOfElements;
}
//******************************************************************************************
template<class ElementType>
const std::string Matrix<ElementType>::DESCRIPTION_OF_NULL_POINTER = "nullptr";
//******************************************************************************************
template<class ElementType>
void Matrix<ElementType>::initializeElements(ElementType * const valuesOfElements) 
{
	int indexOfCurrentValue = 0;
	for (int i = 0; i < this->amountOfRows; i++)
	{
		for (int j = 0; j < this->amountOfColumns; j++) 
		{
			*(*(this->elements + i) + j) = *(valuesOfElements + indexOfCurrentValue);
		}
	}
}
//******************************************************************************************
template<class ElementType>
Matrix<ElementType>::Matrix(ElementType **valuesOfElements, const int amountOfRows,
	const int amountOfColumns) 
{
	if ( !(Matrix<ElementType>::MATRIX_VALIDATOR.areValidValuesOfElements<ElementType>(valuesOfElements, amountOfRows)
		&& Matrix<ElementType>::MATRIX_VALIDATOR.isValidAmountOfRows(amountOfRows)
		&& Matrix<ElementType>::MATRIX_VALIDATOR.isValidAmountOfColumns(amountOfColumns)))
	{
		throw new MatrixCreatingException("Impossible to create matrix by given not valid "
			"amount of rows: " + std::to_string(amountOfRows) + ", amount of columns: "
			+ std::to_string(amountOfColumns) + ", values of elements: "
			+ Matrix<ElementType>::findDescriptionOfElements(valuesOfElements,
				amountOfRows, amountOfColumns) + ".");
	}
	this->amountOfRows = amountOfRows;
	this->amountOfColumns = amountOfColumns;
	this->allocateMemoryForElements();
	this->initializeElements(valuesOfElements);
}
//******************************************************************************************
template<class ElementType>
std::string Matrix<ElementType>::findDescriptionOfElements(ElementType **elements,
	const int amountOfRows, const int amountOfColumns) 
{
	if (elements == 0) 
	{
		return Matrix<ElementType>::DESCRIPTION_OF_NULL_POINTER;
	}
	const string startOfDescriptionOfElements("[");
	std::string descriptionOfElements(startOfDescriptionOfElements);
	const std::string &descriptionOfFirstElements 
		= Matrix<ElementType>::findDescriptionOfElements(*elements, amountOfColumns);
	descriptionOfElements.append(descriptionOfFirstElements);
	const std::string delimiterOfDescriptionsOfElements = "\n ";
	const std::string *descriptionOfCurrentElements;
	for (int i = 1; i < amountOfRows; i++)
	{
		descriptionOfElements.append(delimiterOfDescriptionsOfElements);
		descriptionOfCurrentElements 
			= &Matrix<ElementType>::findDescriptionOfElements(*(elements + i),
				amountOfColumns);
		descriptionOfElements.append(*descriptionOfCurrentElements);
	}
	const string endOfDescriptionOfElements("]");
	descriptionOfElements.append(endOfDescriptionOfElements);
	return descriptionOfElements;
}
//******************************************************************************************
template<class ElementType>
void Matrix<ElementType>::initializeElements(ElementType **valuesOfElements)
{
	for (int i = 0; i < this->amountOfRows; i++)
	{
		for (int j = 0; j < this->amountOfColumns; j++) 
		{
			*(*(this->elements + i) + j) = *(*(valuesOfElements + i) + j);
		}
	}
}
//******************************************************************************************
template<class ElementType>
Matrix<ElementType>::Matrix(const Matrix<ElementType> &other) 
	: amountOfRows(other.amountOfRows),
	  amountOfColumns(other.amountOfColumns)
{
	this->allocateMemoryForElements();
	this->initializeElements(other.elements);
}
//******************************************************************************************
template<class ElementType>
int Matrix<ElementType>::getAmountOfRows() const
{
	return this->amountOfRows;
}
//******************************************************************************************
template<class ElementType>
int Matrix<ElementType>::getAmountOfColumns() const 
{
	return this->amountOfColumns;
}
//******************************************************************************************
template<class ElementType>
void Matrix<ElementType>::updateValueOfElement(const ElementType &newValueOfElement,
	const int indexOfRowOfElement, const int indexOfColumnOfElement)
{
	if ( !(Matrix<ElementType>::MATRIX_VALIDATOR.isValidIndexOfRow(indexOfRowOfElement, *this)
		&& Matrix<ElementType>::MATRIX_VALIDATOR.isValidIndexOfColumn(indexOfColumnOfElement, *this))) 
	{
		throw new MatrixUpdatingException("Updating element in matrix with given index of "
			"row : " + std::to_string(indexOfRowOfElement) + ", index of column : "
			+ std::to_string(indexOfColumnOfElement) + " - is impossible.");
	}
	*(*(this->elements + indexOfRowOfElement) + indexOfColumnOfElement) = newValueOfElement;
}
//******************************************************************************************
template<class ElementType>
const ElementType& Matrix<ElementType>::findElement(const int indexOfRowOfElement,
	const int indexOfColumnOfElement) const 
{
	if ( !(Matrix<ElementType>::MATRIX_VALIDATOR.isValidIndexOfRow(indexOfRowOfElement, *this)
		&& Matrix<ElementType>::MATRIX_VALIDATOR.isValidIndexOfColumn(indexOfColumnOfElement, *this))) 
	{
		throw new MatrixSearchingException("Searching element in matrix by given index of "
			"row : " + std::to_string(indexOfRowOfElement) + ", index of column : "
			+ std::to_string(indexOfColumnOfElement) + " - is impossible.");
	}
	return *(*(this->elements + indexOfRowOfElement) + indexOfColumnOfElement);
}
//******************************************************************************************
template<class ElementType>
std::vector<ElementType*>* Matrix<ElementType>::findElements(
	bool(*isMatch)(const ElementType&)) const
{
	std::vector<ElementType*> * const matchingElements
		= new std::vector<ElementType*>();
	ElementType *currentResearchElement;
	for (int i = 0; i < this->amountOfRows; i++) 
	{
		for (int j = 0; j < this->amountOfColumns; j++) 
		{
			currentResearchElement = *(this->elements + i) + j;
			if (isMatch(*currentResearchElement)) 
			{
				matchingElements->push_back(currentResearchElement);
			}
		}
	}
	return matchingElements;
}
//*****************************************************************************
template<class ElementType>
void Matrix<ElementType>::updateElements(const ElementType &newValueOfElements,
	bool(*isShouldBeUpdated)(const ElementType&))
{
	ElementType *currentResearchElement;
	for (int i = 0; i < this->amountOfRows; i++) 
	{
		for (int j = 0; j < this->amountOfColumns; j++)
		{
			currentResearchElement = *(this->elements + i) + j;
			if (isShouldBeUpdated(*currentResearchElement))
			{
				*currentResearchElement = newValueOfElements;
			}
		}
	}
}
//*****************************************************************************
template<class ElementType>
void Matrix<ElementType>::updateElements(
	ElementType(*generateNewValueForElement)(),
	bool(*isShouldBeUpdated)(const ElementType&)) 
{
	ElementType *currentResearchElement;
	for (int i = 0; i < this->amountOfRows; i++)
	{
		for (int j = 0; j < this->amountOfColumns; j++)
		{
			currentResearchElement = *(this->elements + i) + j;
			if (isShouldBeUpdated(*currentResearchElement))
			{
				*currentResearchElement = generateNewValueForElement();
			}
		}
	}
}
//*****************************************************************************
template<class ElementType>
std::string Matrix<ElementType>::toString() const 
{
	std::string descriptionOfMatrix("");
	descriptionOfMatrix.append(typeid(*this).name());
	descriptionOfMatrix.append("[amountOfRows = ");
	descriptionOfMatrix.append(std::to_string(this->amountOfRows));
	descriptionOfMatrix.append(", amountOfColumns = ");
	descriptionOfMatrix.append(std::to_string(this->amountOfColumns));
	descriptionOfMatrix.append(", elements = ");
	descriptionOfMatrix.append(Matrix<ElementType>::findDescriptionOfElements(
		this->elements, this->amountOfRows, this->amountOfColumns));
	descriptionOfMatrix.append("]");
	return descriptionOfMatrix;
}
//*****************************************************************************
template<class ElementType>
ElementType Matrix<ElementType>::findSumOfElementsUnderMainDiagonal() const 
{
	ElementType sumOfElementsUnderMainDiagonal = 0;
	for (int i = 0; i < this->amountOfRows; i++) 
	{
		for (int j = i + 1; j < this->amountOfColumns; j++)
		{
			sumOfElementsUnderMainDiagonal += *(*(this->elements + i) + j);
		}
	}
	return sumOfElementsUnderMainDiagonal;
}
//*****************************************************************************
template<class ElementType>
bool Matrix<ElementType>::operator==(const Matrix<ElementType> &other) const
{
	if (this == &other)
	{
		return true;
	}
	if (this->amountOfRows != other.amountOfRows || this->amountOfColumns != other.amountOfColumns)
	{
		return false;
	}
	for (int i = 0; i < this->amountOfRows; i++)
	{
		for (int j = 0; j < this->amountOfColumns; j++)
		{
			if (*(*(this->elements + i) + j) != *(*(other.elements + i) + j))
			{
				return false;
			}
		}
	}
	return true;
}
//*****************************************************************************
template<class ElementType>
bool Matrix<ElementType>::operator!=(const Matrix<ElementType> &other) const 
{
	return !(*this == other);
}
//*****************************************************************************
template<class ElementType>
const Matrix<ElementType>& Matrix<ElementType>::operator=(const Matrix<ElementType> &other) 
{
	if (this == &other) 
	{
		return *this;
	}
	this->freeMemoryAllocatedForElements();
	this->amountOfRows = other.amountOfRows;
	this->amountOfColumns = other.amountOfColumns;
	this->allocateMemoryForElements();
	this->initializeElements(other.elements);
	return *this;
}
//*****************************************************************************
template<class ElementType>
void Matrix<ElementType>::freeMemoryAllocatedForElements() 
{
	for (int i = 0; i < this->amountOfRows; i++)
	{
		delete[] *(this->elements + i);
	}
	delete[] this->elements;
}
//*****************************************************************************
template<class ElementType>
ElementType* Matrix<ElementType>::operator[](const int indexOfRow) const 
{
	if (!Matrix<ElementType>::MATRIX_VALIDATOR.isValidIndexOfRow<ElementType>(indexOfRow, *this)) 
	{
		throw new MatrixSearchingException("Impossible to find row by given "
			"index. Given index: " + std::to_string(indexOfRow) + ".");
	}
	return *(this->elements + indexOfRow);
}
//*****************************************************************************
template<class ElementType>
Matrix<ElementType>::~Matrix()
{
	this->freeMemoryAllocatedForElements();
}
//***************************************MatrixValidator************************************
bool MatrixValidator::isValidAmountOfRows(const int researchAmountOfRows) const
{
	return MatrixValidator::MINIMAL_ALLOWABLE_VALUE_OF_AMOUNT_OF_ROWS <= researchAmountOfRows
		&& researchAmountOfRows <= MatrixValidator::MAXIMAL_ALLOWABLE_VALUE_OF_AMOUNT_OF_ROWS;
}
//*****************************************************************************
const int MatrixValidator::MINIMAL_ALLOWABLE_VALUE_OF_AMOUNT_OF_ROWS = 1;
//*****************************************************************************
const int MatrixValidator::MAXIMAL_ALLOWABLE_VALUE_OF_AMOUNT_OF_ROWS = INT_MAX;
//*****************************************************************************
bool MatrixValidator::isValidAmountOfColumns(const int researchAmountOfColumns) const
{
	return MatrixValidator::MINIMAL_ALLOWABLE_VALUE_OF_AMOUNT_OF_COLUMNS <= researchAmountOfColumns
		&& researchAmountOfColumns <= MatrixValidator::MAXIMAL_ALLOWABLE_VALUE_OF_AMOUNT_OF_COLUMNS;
}
//*****************************************************************************
const int MatrixValidator::MINIMAL_ALLOWABLE_VALUE_OF_AMOUNT_OF_COLUMNS = 1;
//*****************************************************************************
const int MatrixValidator::MAXIMAL_ALLOWABLE_VALUE_OF_AMOUNT_OF_COLUMNS = INT_MAX;
//*****************************************************************************
template<class ElementType>
bool MatrixValidator::areValidValuesOfElements(
	ElementType * const researchValuesOfElements) const
{
	return researchValuesOfElements;
}
//*****************************************************************************
template<class ElementType>
bool MatrixValidator::areValidValuesOfElements(
	ElementType **researchValuesOfElements, const int amountOfRows) const 
{
	if (!researchValuesOfElements) 
	{
		return false;
	}
	ElementType *currentResearchElements;
	for (int i = 0; i < amountOfRows; i++) 
	{
		currentResearchElements = *(researchValuesOfElements + i);
		if (!this->areValidValuesOfElements<ElementType>(currentResearchElements))
		{
			return false;
		}
	}
	return true;
}
//*****************************************************************************
template<class ElementType>
bool MatrixValidator::isValidIndexOfRow(const int researchIndexOfRow,
	const Matrix<ElementType> containingMatrix) const
{
	return 0 <= researchIndexOfRow
		&& researchIndexOfRow < containingMatrix.getAmountOfRows();
}
//*****************************************************************************
template<class ElementType>
bool MatrixValidator::isValidIndexOfColumn(const int researchIndexOfColumn,
	const Matrix<ElementType> containingMatrix) const
{
	return 0 <= researchIndexOfColumn
		&& researchIndexOfColumn < containingMatrix.getAmountOfColumns();
}
//*****************************************************************************
