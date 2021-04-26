#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Student\ Tkachenko.Marharyta.IK11\Lab5.1.A\Lab5.1.A\MyException.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			MyException A("Negative argument");
			string m1 = "Negative argument";
			string m2 = A.What();
			Assert::AreEqual(m1, m2);
		}
	};
}
