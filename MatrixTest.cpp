#include "stdafx.h"
#include "MatrixTest.h"
#include "MatrixCreatingException.h"
#include "MatrixUpdatingException.h"
#include "MatrixSearchingException.h"
#include <regex>


//*****************************************************************************
MatrixTest::MatrixTest(const MatrixTest &other)
{
	this->reactToRequestCopyTestObject();
}
//*****************************************************************************
void MatrixTest::operator=(const MatrixTest &other) 
{
	this->reactToRequestCopyTestObject();
}
//*****************************************************************************
MatrixTest::MatrixTest() : Test::Test()
{

}
//*****************************************************************************
MatrixTest::MatrixTest(ostream * const outputStream) 
	: Test::Test(outputStream)
{

}
//*****************************************************************************
void MatrixTest::runTests() 
{
	this->Test::runTests();
	this->matrixShouldBeCreatedByDefault();
	this->matrixShouldBeCreatedByAmountsOfRowsAndColumns();
	this->matrixShouldNotBeCreatedByAmountsOfRowsAndColumns();
	this->matrixShouldBeCreatedByGivenOneDimensionalArrayOfValuesAndAmountsOfRowsAndColumns();
	this->matrixShouldNotBeCreatedByGivenOneDimensionalArrayOfValuesAndAmountsOfRowsAndColumns();
	this->matrixShouldBeCreatedByGivenTwoDimensionalArrayOfValuesAndAmountsOfRowsAndColumns();
	this->matrixShouldNotBeCreatedByGivenTwoDimensionalArrayOfValuesAndAmountsOfRowsAndColumns();
	this->matrixShouldBeCreatedByGivenAlreadyCreatedMatrix();
	this->amountOfRowsOfMatrixShouldBeGot();
	this->amountOfColumnsOfMatrixShouldBeGot();
	this->valueOfElementOfMatrixShouldBeUpdated();
	this->valueOfElementOfMatrixShouldNotBeUpdated();
	this->elementOfMatrixShouldBeFoundByIndexesOfItsRowAndColumn();
	this->elementOfMatrixShouldNotBeFoundByIndexesOfItsRowAndColumn();
	this->sumOfElementsUnderMainDiagonalShouldBeFound();
	this->twoMatrixShouldBeEqual();
	this->twoMatrixShouldNotBeEqual();
	this->matrixShouldBeUpdatedByAssignmentOperator();
}
//*****************************************************************************
void MatrixTest::matrixShouldBeCreatedByDefault()
{
	const Matrix<double> * const matrix = new Matrix<double>();
	this->incrementCorrespondingAmountTests(
		MatrixTest::isMatrixCreatedByDefault(*matrix));
	delete matrix;
}
//*****************************************************************************
template<class MatrixElementType>
bool MatrixTest::isMatrixCreatedByDefault(const Matrix<MatrixElementType> &matrix) 
{
	if (matrix.getAmountOfRows() != Matrix<MatrixElementType>::DEFAULT_VALUE_OF_AMOUNT_OF_ROWS) 
	{
		return false;
	}
	if (matrix.getAmountOfColumns() != Matrix<MatrixElementType>::DEFAULT_VALUE_OF_AMOUNT_OF_COLUMNS) 
	{
		return false;
	}
	return MatrixTest::isMatrixContainOnlyDefaultElements(matrix);
}
//*****************************************************************************
template<class MatrixElementType>
bool MatrixTest::isMatrixContainOnlyDefaultElements(const Matrix<MatrixElementType> &matrix) 
{
	MatrixElementType *currentElement;
	for (int i = 0; i < matrix.getAmountOfRows(); i++)
	{
		for (int j = 0; j < matrix.getAmountOfColumns(); j++)
		{
			currentElement = matrix[i] + j;
			if (*currentElement != Matrix<MatrixElementType>::DEFAULT_VALUE_OF_ELEMENT)
			{
				return false;
			}
		}
	}
	return true;
}
//*****************************************************************************
void MatrixTest::matrixShouldBeCreatedByAmountsOfRowsAndColumns() 
{
	const int amountOfRowsOfMatrix = 5;
	const int amountOfColumnsOfMatrix = 6;
	const Matrix<double> * const matrix = new Matrix<double>(
		amountOfRowsOfMatrix, amountOfColumnsOfMatrix);
	const int expectedAmountOfRowsOfMatrix = amountOfRowsOfMatrix;
	const int expectedAmountOfColumnsOfMatrix = amountOfColumnsOfMatrix;
	const int actualAmountOfRowsOfMatrix = matrix->getAmountOfRows();
	const int actualAmountOfColumnsOfMatrix = matrix->getAmountOfColumns();
	this->incrementCorrespondingAmountTests(
		   actualAmountOfRowsOfMatrix == expectedAmountOfRowsOfMatrix
		&& actualAmountOfColumnsOfMatrix == expectedAmountOfColumnsOfMatrix
		&& MatrixTest::isMatrixContainOnlyDefaultElements<double>(*matrix));
	delete matrix;
}
//*****************************************************************************
void MatrixTest::matrixShouldNotBeCreatedByAmountsOfRowsAndColumns()
{
	const int amountOfRows = 0;
	const int amountOfColumns = 5;
	bool exceptionIsArisen = false;
	const Matrix<double> *matrix;
	try
	{
		matrix = new Matrix<double>(amountOfRows, amountOfColumns);
		delete matrix;
	}
	catch (MatrixCreatingException * const expectedException)
	{
		delete expectedException;
		exceptionIsArisen = true;
	}
	this->incrementCorrespondingAmountTests(exceptionIsArisen);
}
//*****************************************************************************
void MatrixTest::matrixShouldBeCreatedByGivenOneDimensionalArrayOfValuesAndAmountsOfRowsAndColumns()
{
	const int amountOfRowsOfMatrix = 4;
	const int amountOfColumnsOfMatrix = 5;
	const int amountOfElementsOfMatrix 
		= amountOfRowsOfMatrix * amountOfColumnsOfMatrix;
	double * const valuesOfElementsOfMatrix 
		= MatrixTest::ELEMENTS_GENERATOR.generateElements(amountOfElementsOfMatrix);
	const Matrix<double> * const matrix = new Matrix<double>(valuesOfElementsOfMatrix,
		amountOfRowsOfMatrix, amountOfColumnsOfMatrix);
	const int expectedAmountOfRowsOfMatrix = amountOfRowsOfMatrix;
	const int expectedAmountOfColumnsOfMatrix = amountOfColumnsOfMatrix;
	const int actualAmountOfRowsOfMatrix = matrix->getAmountOfRows();
	const int actualAmountOfColumnsOfMatrix = matrix->getAmountOfColumns();
	this->incrementCorrespondingAmountTests(
		   actualAmountOfRowsOfMatrix == expectedAmountOfRowsOfMatrix
		&& actualAmountOfColumnsOfMatrix == expectedAmountOfColumnsOfMatrix
		&& this->areElementsOfMatrixEqualElementsOfArray(*matrix, valuesOfElementsOfMatrix));
	delete[] valuesOfElementsOfMatrix;
	delete matrix;
}
//*****************************************************************************
const double MatrixTest::MINIMAL_BORDER_OF_GENERATION = -10;
//*****************************************************************************
const double MatrixTest::MAXIMAL_BORDER_OF_GENERATION = 10;
//*****************************************************************************
const ElementsGenerator<double> MatrixTest::ELEMENTS_GENERATOR
	= ElementsGenerator<double>(MatrixTest::MINIMAL_BORDER_OF_GENERATION,
		MatrixTest::MAXIMAL_BORDER_OF_GENERATION);
//*****************************************************************************
template<class MatrixElementType>
bool MatrixTest::areElementsOfMatrixEqualElementsOfArray(
	const Matrix<MatrixElementType> &matrix, MatrixElementType * const array)
{
	int indexOfCurrentElementInArray = 0;
	for (int i = 0; i < matrix.getAmountOfRows(); i++) 
	{
		for (int j = 0; j < matrix.getAmountOfColumns(); j++) 
		{
			if (*(matrix[i] + j) != *(array + indexOfCurrentElementInArray))
			{
				return false;
			}
		}
	}
	return true;
}
//*****************************************************************************
void MatrixTest::matrixShouldNotBeCreatedByGivenOneDimensionalArrayOfValuesAndAmountsOfRowsAndColumns() 
{
	const int amountOfRowsOfMatrix = 4;
	const int amountOfColumnsOfMatrix = 5;
	double * const valuesOfElementsOfMatrix = 0;
	bool exceptionIsArisen = false;
	const Matrix<double> *matrix;
	try
	{
		matrix = new Matrix<double>(valuesOfElementsOfMatrix, amountOfRowsOfMatrix,
			amountOfColumnsOfMatrix);
		delete matrix;
	}
	catch (MatrixCreatingException * const expectedException)
	{
		delete expectedException;
		exceptionIsArisen = true;
	}
	this->incrementCorrespondingAmountTests(exceptionIsArisen);
}
//*****************************************************************************
void MatrixTest::matrixShouldBeCreatedByGivenTwoDimensionalArrayOfValuesAndAmountsOfRowsAndColumns() 
{
	const int amountOfRowsOfCreatedMatrix = 5;
	const int amountOfColumnsOfCreatedMatrix = 6;
	double **valuesOfElementsOfMatrix      
		= MatrixTest::generateTwoDimensionalArray<double>(
		amountOfRowsOfCreatedMatrix, amountOfColumnsOfCreatedMatrix);
	const Matrix<double> * const createdMatrix = new Matrix<double>( 
		valuesOfElementsOfMatrix, amountOfRowsOfCreatedMatrix,
		amountOfColumnsOfCreatedMatrix);
	const int expectedAmountOfRowsOfCreatedMatrix = amountOfRowsOfCreatedMatrix;
	const int expectedAmountOfColumnsOfCreatedMatrix = amountOfColumnsOfCreatedMatrix;
	double **expectedValuesOfElementsOfMatrix = valuesOfElementsOfMatrix; 
	const int actualAmountOfRowsOfCreatedMatrix = createdMatrix->getAmountOfRows();
	const int actualAmountOfColumnsOfCreatedMatrix = createdMatrix->getAmountOfColumns();
	bool testIsSuccess
		=  actualAmountOfRowsOfCreatedMatrix == expectedAmountOfRowsOfCreatedMatrix
		&& actualAmountOfColumnsOfCreatedMatrix == expectedAmountOfColumnsOfCreatedMatrix
		&& MatrixTest::areElementsOfMatrixEqualElementsOfArray(
			*createdMatrix, expectedValuesOfElementsOfMatrix);
	MatrixTest::freeMemoryAllocatedForElements(valuesOfElementsOfMatrix,
		amountOfRowsOfCreatedMatrix);
	delete createdMatrix;
	this->incrementCorrespondingAmountTests(testIsSuccess);
}
//*****************************************************************************
template<class GeneratedElementType>
GeneratedElementType** MatrixTest::generateTwoDimensionalArray(
	const int amountOfRows, const int amountOfColumns) 
{
	GeneratedElementType **generatedElements
		= new GeneratedElementType*[amountOfRows];
	for (int i = 0; i < amountOfRows; i++)
	{
		*(generatedElements + i) 
			= MatrixTest::ELEMENTS_GENERATOR.generateElements(amountOfColumns);
	}
	return generatedElements;
}
//*****************************************************************************
template<class MatrixElementType>
bool MatrixTest::areElementsOfMatrixEqualElementsOfArray(
	const Matrix<MatrixElementType> &matrix, MatrixElementType **array)
{
	for (int i = 0; i < matrix.getAmountOfRows(); i++)
	{
		for (int j = 0; j < matrix.getAmountOfColumns(); j++) 
		{
			if (*(matrix[i] + j) != *(*(array + i) + j))
			{
				return false;
			}
		}
	}
	return true;
}
//*****************************************************************************
template<class ElementType>
void MatrixTest::freeMemoryAllocatedForElements(ElementType **elements,
	const int amountOfRows) 
{
	for (int i = 0; i < amountOfRows; i++)
	{
		delete[] *(elements + i);
	}
	delete[] elements;
}
//*****************************************************************************
void MatrixTest::matrixShouldNotBeCreatedByGivenTwoDimensionalArrayOfValuesAndAmountsOfRowsAndColumns()
{
	const int amountOfRowsOfCreatedMatrix = 5;
	const int amountOfColumnsOfCreatedMatrix = 6;
	double **valuesOfElementsOfMatrix      
		= MatrixTest::generateTwoDimensionalArray<double>(
			amountOfRowsOfCreatedMatrix, amountOfColumnsOfCreatedMatrix);
	delete[] *valuesOfElementsOfMatrix;
	*valuesOfElementsOfMatrix = 0;
	const Matrix<double> *createdMatrix = 0; 
	bool exceptionIsArisen = false;
	try 
	{
		createdMatrix = new Matrix<double>(valuesOfElementsOfMatrix,
			amountOfRowsOfCreatedMatrix, amountOfColumnsOfCreatedMatrix);
	}
	catch (const MatrixCreatingException * const expectedException)
	{
		delete expectedException;
		exceptionIsArisen = true;
	}
	MatrixTest::freeMemoryAllocatedForElements(valuesOfElementsOfMatrix,
		amountOfRowsOfCreatedMatrix);
	delete createdMatrix;
	this->incrementCorrespondingAmountTests(exceptionIsArisen);
}
//*****************************************************************************
void MatrixTest::matrixShouldBeCreatedByGivenAlreadyCreatedMatrix() 
{
	const int amountOfRowsOfOriginalMatrix = 5;
	const int amountOfColumnsOfOriginalMatrix = 6;
	double **valuesOfElementsOfOriginalMatrix        
		= MatrixTest::generateTwoDimensionalArray<double>(
			amountOfRowsOfOriginalMatrix, amountOfColumnsOfOriginalMatrix);
	const Matrix<double> * const originalMatrix = new Matrix<double>(  
		valuesOfElementsOfOriginalMatrix, amountOfRowsOfOriginalMatrix,
		amountOfColumnsOfOriginalMatrix);
	MatrixTest::freeMemoryAllocatedForElements<double>(
		valuesOfElementsOfOriginalMatrix, amountOfRowsOfOriginalMatrix);
	const Matrix<double> * const copyMatrix = new Matrix<double>(*originalMatrix);  
	const bool testIsSuccess = (*originalMatrix == *copyMatrix);
	delete originalMatrix;
	delete copyMatrix;
	this->incrementCorrespondingAmountTests(testIsSuccess);
}
//*****************************************************************************
void MatrixTest::amountOfRowsOfMatrixShouldBeGot() 
{
	const int amountOfRowsOfCreatedMatrix = 5;
	const int amountOfColumnsOfCreatedMatrix = 6;
	const Matrix<double> *createdMatrix = new Matrix<double>(
		amountOfRowsOfCreatedMatrix, amountOfColumnsOfCreatedMatrix);
	const int expectedAmountOfRowsOfCreatedMatrix = amountOfRowsOfCreatedMatrix;
	const int actualAmountOfRowsOfCreatedMatrix = createdMatrix->getAmountOfRows();
	delete createdMatrix;
	const bool testIsSuccess 
		= (actualAmountOfRowsOfCreatedMatrix == expectedAmountOfRowsOfCreatedMatrix);
	this->incrementCorrespondingAmountTests(testIsSuccess);
}
//*****************************************************************************
void MatrixTest::amountOfColumnsOfMatrixShouldBeGot()
{
	const int amountOfRowsOfMatrix = 5;
	const int amountOfColumnsOfMatrix = 6;
	const Matrix<double> *matrix = new Matrix<double>(amountOfRowsOfMatrix,
		amountOfColumnsOfMatrix);
	const int expectedAmountOfColumnsOfMatrix = amountOfColumnsOfMatrix;
	const int actualAmountOfColumnsOfMatrix = matrix->getAmountOfColumns();
	delete matrix;
	const bool testIsSuccess 
		= (actualAmountOfColumnsOfMatrix == expectedAmountOfColumnsOfMatrix);
	this->incrementCorrespondingAmountTests(testIsSuccess);
}
//*****************************************************************************
void MatrixTest::valueOfElementOfMatrixShouldBeUpdated()
{
	const int amountOfRowsOfMatrix = 5;
	const int amountOfColumnsOfMatrix = 6;
	Matrix<double> *matrix = new Matrix<double>(amountOfRowsOfMatrix,
		amountOfColumnsOfMatrix);
	const int indexOfRowOfUpdatedElement = amountOfRowsOfMatrix - 1;
	const int indexOfColumnOfUpdatedElement = amountOfColumnsOfMatrix - 1;
	const double newValueOfUpdatedElement = 10;
	bool testIsSuccess;
	try
	{
		matrix->updateValueOfElement(newValueOfUpdatedElement,
			indexOfRowOfUpdatedElement, indexOfColumnOfUpdatedElement);
	}
	catch (MatrixUpdatingException * const notExpectedException) 
	{
		delete notExpectedException;
		testIsSuccess = false;
		this->incrementCorrespondingAmountTests(testIsSuccess);
		return;
	}
	const int expectedNewValueOfUpdatedElement = newValueOfUpdatedElement;
	const int actualNewValueOfUpdatedElement
		= matrix->findElement(indexOfRowOfUpdatedElement, 
			indexOfColumnOfUpdatedElement);
	delete matrix;
	testIsSuccess = (actualNewValueOfUpdatedElement
		== expectedNewValueOfUpdatedElement);
	this->incrementCorrespondingAmountTests(testIsSuccess);
}
//*****************************************************************************
void MatrixTest::valueOfElementOfMatrixShouldNotBeUpdated()
{
	const int amountOfRowsOfMatrix = 5;
	const int amountOfColumnsOfMatrix = 6;
	Matrix<double> *matrix = new Matrix<double>(amountOfRowsOfMatrix,
		amountOfColumnsOfMatrix);
	const int indexOfRowOfUpdatedElement = amountOfRowsOfMatrix;
	const int indexOfColumnOfUpdatedElement = amountOfColumnsOfMatrix;
	const double newValueOfUpdatedElement = 10;
	bool exceptionIsArisen = false;
	try 
	{
		matrix->updateValueOfElement(newValueOfUpdatedElement,
			indexOfRowOfUpdatedElement, indexOfColumnOfUpdatedElement);
	}
	catch (MatrixUpdatingException * const expectedException) 
	{
		delete expectedException;
		exceptionIsArisen = true;
	}
	delete matrix;
	this->incrementCorrespondingAmountTests(exceptionIsArisen);
}
//*****************************************************************************
void MatrixTest::elementOfMatrixShouldBeFoundByIndexesOfItsRowAndColumn() 
{
	const int amountOfRowsOfMatrix = 5;
	const int amountOfColumnsOfMatrix = 6;
	double **valuesOfElementsOfMatrix
		= MatrixTest::generateTwoDimensionalArray<double>(amountOfRowsOfMatrix,
			amountOfColumnsOfMatrix);
	const Matrix<double> *matrix = new Matrix<double>(valuesOfElementsOfMatrix,
		amountOfRowsOfMatrix, amountOfColumnsOfMatrix);
	const int indexOfRowOfFoundElement = amountOfRowsOfMatrix - 1;
	const int indexOfColumnOfFoundElement = amountOfColumnsOfMatrix - 1;
	const double expectedValueOfFoundElement
		= *(*(valuesOfElementsOfMatrix + indexOfRowOfFoundElement) 
			+ indexOfColumnOfFoundElement);
	MatrixTest::freeMemoryAllocatedForElements(valuesOfElementsOfMatrix,
		amountOfRowsOfMatrix);
	double actualValueOfFoundElement;
	bool testIsSuccess;
	try 
	{
		actualValueOfFoundElement = matrix->findElement(
			indexOfRowOfFoundElement, indexOfColumnOfFoundElement);
	}
	catch (const MatrixSearchingException * const notExpectedException) 
	{
		delete notExpectedException;
		testIsSuccess = false;
		this->incrementCorrespondingAmountTests(testIsSuccess);
		return;
	}
	delete matrix;
	testIsSuccess = (actualValueOfFoundElement == expectedValueOfFoundElement);
	this->incrementCorrespondingAmountTests(testIsSuccess);
}
//*****************************************************************************
void MatrixTest::elementOfMatrixShouldNotBeFoundByIndexesOfItsRowAndColumn() 
{
	const int amountOfRowsOfMatrix = 5;
	const int amountOfColumnsOfMatrix = 6;
	const Matrix<double> *matrix = new Matrix<double>(amountOfRowsOfMatrix,
		amountOfColumnsOfMatrix);
	const int indexOfRowOfFoundElement = amountOfRowsOfMatrix;
	const int indexOfColumnsOfFoundElement = amountOfColumnsOfMatrix;
	bool exceptionIsArisen = false;
	try 
	{
		matrix->findElement(indexOfRowOfFoundElement, indexOfColumnsOfFoundElement);
	}
	catch (MatrixSearchingException * const expectedException) 
	{
		delete expectedException;
		exceptionIsArisen = true;
	}
	delete matrix;
	this->incrementCorrespondingAmountTests(exceptionIsArisen);
}
//*****************************************************************************
void MatrixTest::sumOfElementsUnderMainDiagonalShouldBeFound() 
{
	const int amountOfRowsOfMatrix = 5;
	const int amountOfColumnsOfMatrix = 5;
	double **valuesOfElementsOfMatrix = MatrixTest::generateTwoDimensionalArray<double>(amountOfRowsOfMatrix,
		amountOfColumnsOfMatrix);
	const Matrix<double> *matrix = new Matrix<double>(valuesOfElementsOfMatrix, amountOfRowsOfMatrix, 
		amountOfColumnsOfMatrix);
	const double expectedSumOfElementsUnderMainDiagonal = MatrixTest
		::findSumOfElementsUnderMainDiagonal<double>(valuesOfElementsOfMatrix, amountOfRowsOfMatrix,
			amountOfColumnsOfMatrix);
	MatrixTest::freeMemoryAllocatedForElements(valuesOfElementsOfMatrix, amountOfRowsOfMatrix);
	const double actualSumOfElementsUnderMainDiagonal = matrix->findSumOfElementsUnderMainDiagonal();
	const bool testIsSuccess = (actualSumOfElementsUnderMainDiagonal == expectedSumOfElementsUnderMainDiagonal);
	delete matrix;
	this->incrementCorrespondingAmountTests(testIsSuccess);
}
//*****************************************************************************
template<class ElementType>
ElementType MatrixTest::findSumOfElementsUnderMainDiagonal(ElementType **elements, const int amountOfRows,
	const int amountOfColumns)
{
	ElementType sumOfElementsUnderMainDiagonal = 0;
	for (int i = 0; i < amountOfRows; i++) 
	{
		for (int j = i + 1; j < amountOfColumns; j++) 
		{
			sumOfElementsUnderMainDiagonal += *(*(elements + i) + j);
		}
	}
	return sumOfElementsUnderMainDiagonal;
}
//*****************************************************************************
void MatrixTest::twoMatrixShouldBeEqual()
{
	const int amountOfRowsOfFirstMatrix = 5;
	const int amountOfColumnsOfFirstMatrix = 6;
	const int amountOfElementsOfMatrix = amountOfRowsOfFirstMatrix * amountOfColumnsOfFirstMatrix;
	double *valuesOfElementsOfMatrix = MatrixTest::ELEMENTS_GENERATOR
		.generateElements(amountOfElementsOfMatrix);
	const Matrix<double> *firstMatrix = new Matrix<double>(valuesOfElementsOfMatrix, 
		amountOfRowsOfFirstMatrix, amountOfColumnsOfFirstMatrix);
	delete[] valuesOfElementsOfMatrix;
	const Matrix<double> *secondMatrix = new Matrix<double>(*firstMatrix);  
	const bool testIsSuccess = (*firstMatrix == *secondMatrix);
	delete firstMatrix;
	delete secondMatrix;
	this->incrementCorrespondingAmountTests(testIsSuccess);
}
//*****************************************************************************
void MatrixTest::twoMatrixShouldNotBeEqual()
{
	const int amountOfRowsOfFirstMatrix = 5;
	const int amountOfColumnsOfFirstMatrix = 6;
	const int amountOfElementsOfFirstMatrix = amountOfRowsOfFirstMatrix 
		* amountOfColumnsOfFirstMatrix;
	double *valuesOfElementsOfFirstMatrix = MatrixTest::ELEMENTS_GENERATOR  
		.generateElements(amountOfElementsOfFirstMatrix);
	const Matrix<double> * const firstMatrix = new Matrix<double>(valuesOfElementsOfFirstMatrix,
		amountOfRowsOfFirstMatrix, amountOfColumnsOfFirstMatrix);
	delete[] valuesOfElementsOfFirstMatrix;
	Matrix<double> * const secondMatrix = new Matrix<double>(*firstMatrix);
	const int indexOfRowOfUpdatedElementOfSecondMatrix = secondMatrix->getAmountOfRows() - 1;
	const int indexOfColumnOfUpdatedElementOfSecondMatrix = secondMatrix->getAmountOfColumns() - 1;
	const double newValueOfUpdatedElementOfSecondMatrix = secondMatrix
		->findElement(indexOfRowOfUpdatedElementOfSecondMatrix, 
			indexOfColumnOfUpdatedElementOfSecondMatrix) + 1;
	secondMatrix->updateValueOfElement(newValueOfUpdatedElementOfSecondMatrix,
		indexOfRowOfUpdatedElementOfSecondMatrix, indexOfColumnOfUpdatedElementOfSecondMatrix);
	const bool testIsSuccess = (*firstMatrix != *secondMatrix);
	delete firstMatrix;
	delete secondMatrix;
	this->incrementCorrespondingAmountTests(testIsSuccess);
}
//*****************************************************************************
void MatrixTest::matrixShouldBeUpdatedByAssignmentOperator()
{
	const int amountOfRowsOfFirstMatrix = 5;
	const int amountOfColumnsOfFirstMatrix = 6;
	const int amountOfElementsOfFirstMatrix = amountOfRowsOfFirstMatrix 
		* amountOfColumnsOfFirstMatrix;
	double *valuesOfElementsOfFirstMatrix = MatrixTest::ELEMENTS_GENERATOR
		.generateElements(amountOfElementsOfFirstMatrix);
	const Matrix<double> * const firstMatrix = new Matrix<double>(valuesOfElementsOfFirstMatrix,
		amountOfRowsOfFirstMatrix, amountOfColumnsOfFirstMatrix);
	delete[] valuesOfElementsOfFirstMatrix;
	Matrix<double> * const secondMatrix = new Matrix<double>();
	*secondMatrix = *firstMatrix;
	const bool testIsSuccess = (*secondMatrix == *firstMatrix);
	this->incrementCorrespondingAmountTests(testIsSuccess);
	delete firstMatrix;
	delete secondMatrix;
}
//*****************************************************************************
MatrixTest::~MatrixTest()
{

}
//*****************************************************************************