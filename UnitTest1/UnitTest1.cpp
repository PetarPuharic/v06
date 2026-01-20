#include "pch.h"
#include "CppUnitTest.h"
#include "../app/money.h"

using std::string_literals::operator""s;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace vsite::oop::v7;

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
			Assert::AreEqual("3 eur, 05 ct"s, oss.str());
		}

		TEST_METHOD(Output_NoCents)
		{
			std::ostringstream oss;
			money m1(4, 0);
			oss << m1;
			Assert::AreEqual("4 eur"s, oss.str());
		}

		TEST_METHOD(Output_NoEuros)
		{
			std::ostringstream oss;
			money m1(0, 9);
			oss << m1;
			Assert::AreEqual("09 ct"s, oss.str());
		}
	};
}
	