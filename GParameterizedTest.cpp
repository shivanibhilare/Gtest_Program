#include "stdafx.h"  
#include "Number.h"
#include "gtest\gtest.h"

using namespace ::testing;

struct OperationOnInt
{
	int num1;
    int num2;
	OperationType type;
	int expectedResult;
};

struct OperationOnDouble
{
	double num1;
    double num2;
	OperationType type;
	double expectedResult;

};

class ArithmaticFixtureTest
{

public:
	ArithmaticFixtureTest()
	{
		NumObject = new Number();

	}
	~ArithmaticFixtureTest()
	{
		delete NumObject;
		NumObject = NULL;
	}

	void SetUp()
	{

	}
	void TearDown()
	{
	}
	Number	*NumObject;
	
};

class ParameterizedTestForInt: public  ArithmaticFixtureTest, public TestWithParam<OperationOnInt>
{

};

class ParameterizedTestForDouble: public ArithmaticFixtureTest, public TestWithParam<OperationOnDouble>
{
public:
	ParameterizedTestForDouble()
	{
		tolerance = 0.0001;
	}
	~ParameterizedTestForDouble() {};

	double tolerance;
};

INSTANTIATE_TEST_CASE_P(DifferntIntValues, ParameterizedTestForInt, ::testing::Values(
	OperationOnInt{100, 20, E_Addition, 120},
	OperationOnInt{0, 0, E_Addition, 0},
	OperationOnInt{-10, -20, E_Addition, -30},
	OperationOnInt{100, 20, E_Subtraction, 80},
	OperationOnInt{0, 0, E_Subtraction, 0},
	OperationOnInt{-10, -20, E_Subtraction, 10},
	OperationOnInt{100, 20, E_Multiplication, 2000},
	OperationOnInt{0, 0, E_Multiplication, 0},
	OperationOnInt{0, 10, E_Multiplication, 0},
	OperationOnInt{-10, -10, E_Multiplication, 100},
	OperationOnInt{-10, 10, E_Multiplication, -100},
	OperationOnInt{0, 0, E_Division, 0},
	OperationOnInt{0, 10, E_Division, 0},
	OperationOnInt{10, 0, E_Division, 0},
	OperationOnInt{-10, -10, E_Division, 1},
	OperationOnInt{-10, 10, E_Division, -1},
	OperationOnInt{0, 10, E_None, 0},
	OperationOnInt{10, 0, E_None, 0},
	OperationOnInt{-10, -10, E_None, 0},
	OperationOnInt{-10, 10, E_None, 0}
));



INSTANTIATE_TEST_CASE_P(DifferntDoubleValues, ParameterizedTestForDouble, ::testing::Values(
	OperationOnDouble{100.0, 20.0, E_Addition, 120.0},
	OperationOnDouble{0.0, 0.0, E_Addition, 0.0},
	OperationOnDouble{-10.0, -20.0, E_Addition, -30.0},
	OperationOnDouble{100.0, 20.0, E_Subtraction, 80.0},
	OperationOnDouble{0.0, 0.0, E_Subtraction, 0.0},
	OperationOnDouble{-10.0, -20.0, E_Subtraction, 10.0},
	OperationOnDouble{100.0, 20.0, E_Multiplication, 2000.0},
	OperationOnDouble{0.0, 0.0, E_Multiplication, 0.0},
	OperationOnDouble{0.0, 10.0, E_Multiplication, 0.0},
	OperationOnDouble{-10.0, -10.0, E_Multiplication, 100.0},
	OperationOnDouble{-10.0, 10.0, E_Multiplication, -100.0},
	OperationOnDouble{0.0, 0.0, E_Division, 0.0},
	OperationOnDouble{0.0, 10.0, E_Division, 0.0},
	OperationOnDouble{10.0, 0.0, E_Division, 0.0},
	OperationOnDouble{-10.0, -10.0, E_Division, 1.0},
	OperationOnDouble{-10.0, 10.0, E_Division, -1.0},
	OperationOnDouble{0, 10, E_None, 0},
	OperationOnDouble{10.0, 0.0, E_None, 0.0},
	OperationOnDouble{-10.0, -10.0, E_None, 0.0},
	OperationOnDouble{-10.0, 10.0, E_None, 0.0}
));

TEST_P(ParameterizedTestForInt, ArithmaticOperationForInt)
{
	NumObject->operation(GetParam().type, GetParam().num1, GetParam().num2);
	EXPECT_EQ(GetParam().expectedResult, NumObject->getResult());
}

TEST_P(ParameterizedTestForDouble, ArithmaticOperationForDouble)
{
	NumObject->operation(GetParam().type, GetParam().num1, GetParam().num2);
	EXPECT_NEAR(GetParam().expectedResult, NumObject->getResult(), tolerance);
}
