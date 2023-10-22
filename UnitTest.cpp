#include "pch.h"
#include "CppUnitTest.h"
#include "./Code/Calculator.cpp"
#include "./Code/refs.h"
#include "./Code/FoolProof.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTestGood)
	{
	public:
		
		TEST_METHOD(Calculator_ArgumentCorrect)
		{
			Calculator c;
			Assert::AreEqual(0, c.ArgumentCorrect('r', -12.21));
		}
		TEST_METHOD(Calculator_GetPriority)
		{
			Calculator c;
			Assert::AreEqual(3, c.GetPriority("^"));
		}
		TEST_METHOD(Calculator_Calculate)
		{
			Calculator c;
			string eq = "1+1";
			double result = 0;
			// Assert::AreEqual({ "3" }, c.InfixToPostfix(eq));
			Assert::AreEqual(1.0, c.Calculate(eq, &result));
		}



		TEST_METHOD(refs_RegexFind)
		{
			Assert::AreEqual(1, RegexFind("bebra", "e"));
		}
		TEST_METHOD(refs_SaveSplit)
		{
			vector<string> a = { "b", "e", "bra" };
			Assert::IsTrue(a == SaveSplit("bebra", "e"));
		}
		TEST_METHOD(refs_Split)
		{
			vector<string> a = { "b", "bra" };
			Assert::IsTrue(a == Split("bebra", "e"));
		}



		TEST_METHOD(fp_AllCorrect)
		{
			FoolProof f;
			string s = "1+2";
			Assert::IsTrue(1 == f.AllCorrect(&s));
		}
	};


	TEST_CLASS(UnitTestBad)
	{
	public:

		TEST_METHOD(Calculator_ArgumentCorrect)
		{
			Calculator c;
			Assert::AreEqual(1, c.ArgumentCorrect('n', 0));
		}
		TEST_METHOD(Calculator_GetPriority)
		{
			Calculator c;
			Assert::AreEqual(3, c.GetPriority("n"));
		}
		TEST_METHOD(Calculator_Calculate)
		{
			Calculator c;
			string eq = "2+3";
			double result = 0;
			Assert::AreEqual(1.3, c.Calculate(eq, &result));
		}



		TEST_METHOD(refs_RegexFind)
		{
			Assert::AreEqual(1, RegexFind("danil", "e"));
		}
		TEST_METHOD(refs_SaveSplit)
		{
			vector<string> a = { "da", "ni", "l" };
			Assert::IsTrue(a == SaveSplit("danil", "e"));
		}
		TEST_METHOD(refs_Split)
		{
			vector<string> a = { "dani", "l" };
			Assert::IsTrue(a == Split("danil", "i"));
		}



		TEST_METHOD(fp_AllCorrect)
		{
			FoolProof f;
			string s = "1+2+3";
			Assert::IsTrue(0 == f.AllCorrect(&s));
		}
	};
}
