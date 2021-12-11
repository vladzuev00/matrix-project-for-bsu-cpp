#ifndef MATRIXTEST_H
#define MATRIXTEST_H

#include "Test.h"
#include "ElementsGenerator.h"
#include <vector>
#include "Matrix.h"

//*****************************************************************************
class MatrixTest : public Test
{
private:
	MatrixTest(const MatrixTest&);
	void operator=(const MatrixTest&);
private:
	static const double MINIMAL_BORDER_OF_GENERATION;
	static const double MAXIMAL_BORDER_OF_GENERATION;
	static const ElementsGenerator<double> ELEMENTS_GENERATOR;
private:
	void matrixShouldBeCreatedByDefault();
	void matrixShouldBeCreatedByAmountsOfRowsAndColumns();
	void matrixShouldNotBeCreatedByAmountsOfRowsAndColumns();
	void matrixShouldBeCreatedByGivenOneDimensionalArrayOfValuesAndAmountsOfRowsAndColumns();
	void matrixShouldNotBeCreatedByGivenOneDimensionalArrayOfValuesAndAmountsOfRowsAndColumns();
	void matrixShouldBeCreatedByGivenTwoDimensionalArrayOfValuesAndAmountsOfRowsAndColumns();
	void matrixShouldNotBeCreatedByGivenTwoDimensionalArrayOfValuesAndAmountsOfRowsAndColumns();
	void matrixShouldBeCreatedByGivenAlreadyCreatedMatrix();
	void amountOfRowsOfMatrixShouldBeGot();
	void amountOfColumnsOfMatrixShouldBeGot();
	void valueOfElementOfMatrixShouldBeUpdated();
	void valueOfElementOfMatrixShouldNotBeUpdated();
	void elementOfMatrixShouldBeFoundByIndexesOfItsRowAndColumn();
	void elementOfMatrixShouldNotBeFoundByIndexesOfItsRowAndColumn();
	void sumOfElementsUnderMainDiagonalShouldBeFound();
	void twoMatrixShouldBeEqual();
	void twoMatrixShouldNotBeEqual();
	void matrixShouldBeUpdatedByAssignmentOperator();
private:
	template<class MatrixElementType>
	static bool isMatrixCreatedByDefault(const Matrix<MatrixElementType> &matrix);
	template<class MatrixElementType>
	static bool isMatrixContainOnlyDefaultElements(const Matrix<MatrixElementType> &matrix);
	template<class MatrixElementType>
	static bool areElementsOfMatrixEqualElementsOfArray(const Matrix<MatrixElementType> &matrix,
		MatrixElementType * const array);
	template<class GeneratedElementType>
	static GeneratedElementType** generateTwoDimensionalArray(
		const int amountOfRows, const int amountOfColumns);
	template<class MatrixElementType>
	static bool areElementsOfMatrixEqualElementsOfArray(
		const Matrix<MatrixElementType> &matrix, MatrixElementType **array);
	template<class ElementType>
	static void freeMemoryAllocatedForElements(ElementType **elements,
		const int amountOfRows);
	template<class ElementType>
	static ElementType findSumOfElementsUnderMainDiagonal(ElementType **elements, const int amountOfRows,
		const int amountOfColumns);
public:
	MatrixTest();
	MatrixTest(ostream * const outputStream);
public:
	virtual void runTests() override;
public:
	virtual ~MatrixTest() override;
};
//*****************************************************************************

#endif MATRIXTEST_H