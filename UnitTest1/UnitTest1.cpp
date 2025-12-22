#include "pch.h"
#include "CppUnitTest.h"
#include "..\app\money.h"

using namespace vsite::oop::v7;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;


// NoEuros, NoCents, Overflow, Underflow, +=, -=, ouput
namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(NoEuros)
		{
			money m1(0, 50);
			Assert::AreEqual(50, m1.get_total_cents());
		}
		TEST_METHOD(NoCents)
		{
			money m1(3, 0);
			Assert::AreEqual(300, m1.get_total_cents());
		}

		TEST_METHOD(Overflow)
		{
			money m1(2, 75);
			money m2(1, 50);
			m1 += m2;
			Assert::AreEqual(425, m1.get_total_cents());
		}

		TEST_METHOD(Underflow)
		{
			money m1(5, 0);
			money m2(2, 50);
			m1 -= m2;
			Assert::AreEqual(250, m1.get_total_cents());
		}

		TEST_METHOD(IsZero0)
		{
			money m1(0, 0);
			Assert::AreEqual(0, m1.get_total_cents());
		}

		TEST_METHOD(Output)
		{
			std::ostringstream oss;
			money m1(3, 5);
			oss << m1;
			Assert::AreEqual(std::string("3 eur, 05 ct"), oss.str());
		}
	};
}
