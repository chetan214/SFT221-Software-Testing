#include "pch.h"
#include "CppUnitTest.h"
#include "customerinfo.h"
extern "C"
{
#include "customerinfo.h"
}
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		int isValidPostalCode(const char* postalCode) {

			if (isalpha(postalCode[0]) && isdigit(postalCode[1]) &&
				isalpha(postalCode[2]) && (postalCode[3] == ' ' || postalCode[3] == '\0') &&
				isdigit(postalCode[4]) && isalpha(postalCode[5]) && isdigit(postalCode[6]) && postalCode[7] == '\0') {
				return 1;
			}
			return 0;
		}

		TEST_METHOD(CheckCodeBlackBoxTest1)
		{
			char postalCode[] = "M9W 7B9";
			Assert::IsTrue(isValidPostalCode(postalCode));
		}
		
		TEST_METHOD(CheckCodeBlackBoxTest2)
		{
			char postalCode[] = "M9W7B9";
			Assert::IsFalse(isValidPostalCode(postalCode));
		}
		
		TEST_METHOD(CheckCodeBlackBoxTest3)
		{
			char postalCode[] = "M9W 7b9";
			Assert::IsTrue(isValidPostalCode(postalCode));
		}

		TEST_METHOD(CheckCodeBlackBoxTest4)
		{
			char postalCode[] = "M9W 7B";
			Assert::IsFalse(isValidPostalCode(postalCode));
		}

		TEST_METHOD(CheckCodeBlackBoxTest5)
		{
			char postalCode[] = "123 456";
			Assert::IsFalse(isValidPostalCode(postalCode));
		}

		TEST_METHOD(CheckCodeBlackBoxTest6)
		{
			char postalCode[] = "m9w 7b9";
			Assert::IsTrue(isValidPostalCode(postalCode));
		}

		TEST_METHOD(CheckCodeWhiteBoxTest1)
		{
			char postalCode[] = "M9W\07B9";
			Assert::IsTrue(isValidPostalCode(postalCode));
		}
		TEST_METHOD(CheckCodeWhiteBoxTest2)
		{
			char postalCode[] = "M9W 7B9\0";
			Assert::IsTrue(isValidPostalCode(postalCode));
		}
		TEST_METHOD(CheckCodeWhiteBoxTest3)
		{
			char postalCode[] = "\0M9W 7B9";
			Assert::IsFalse(isValidPostalCode(postalCode));
		}

		TEST_METHOD(CheckCodeWhiteBoxTest4)
		{
			char postalCode[] = "$9W 7B9";
			Assert::IsFalse(isValidPostalCode(postalCode));
		}

		TEST_METHOD(CheckCodeWhiteBoxTest5)
		{
			char postalCode[] = "M9W 7B@";
			Assert::IsFalse(isValidPostalCode(postalCode));
		}

		TEST_METHOD(CheckCodeWhiteBoxTest6)
		{
			char postalCode[] = "M9W 7B9\n";
			Assert::IsFalse(isValidPostalCode(postalCode));
		}
	};
}
