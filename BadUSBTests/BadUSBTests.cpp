#include "CppUnitTest.h"
#include "../BadUSB/ScriptLang.h"
#include "../BadUSB/ScriptManager.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BadUSBTests
{
	TEST_CLASS(ScriptLangTests)
	{
	public:

		TEST_METHOD(TestSingleChar)
		{
			char buffer = '\0';
			ScriptLang::getLineBytesArray("a", &buffer);
			Assert::AreEqual('a', buffer);

			buffer = '\0';
			ScriptLang::getLineBytesArray("b", &buffer);
			Assert::AreEqual('b', buffer);
		}

		TEST_METHOD(TestKeyCombination)
		{
			char buffer[30] = { '\0' };
			ScriptLang::getLineBytesArray("OS r d", buffer);

			Assert::AreEqual((uint8_t)0x83, (uint8_t)buffer[0]); //OS
			Assert::AreEqual('r', buffer[1]);
			Assert::AreEqual('d', buffer[2]);
		}

		TEST_METHOD(TestWordWithQuotationMarks)
		{
			char buffer[20] = { '\0' };
			ScriptLang::getLineBytesArray("\"Samochod123\"", buffer);

			Assert::AreEqual("\"Samochod123\"", buffer);
		}

		TEST_METHOD(TestWordWithQuotationMarksAndSomethingAfter)
		{
			char buffer[20] = { '\0' };
			ScriptLang::getLineBytesArray("\"Samochod123\" r", buffer); //should abandon and return empty array

			Assert::AreEqual("", buffer);
		}

		TEST_METHOD(TestWordWithQuotationMarksAndSpaces)
		{
			char buffer[30] = { '\0' };
			ScriptLang::getLineBytesArray("\"Samochod123 Ala ma kota\"", buffer); //should return bytes including spaces 

			Assert::AreEqual("\"Samochod123 Ala ma kota\"", buffer);
		}

		TEST_METHOD(TestWordWithSpecialKeyPhraseInside)
		{
			char buffer[30] = { '\0' };
			ScriptLang::getLineBytesArray("\"Samochod123 OS\"", buffer); //should return bytes including spaces, NO SPECIAL KEY

			Assert::AreEqual("\"Samochod123 OS\"", buffer);
		}

		TEST_METHOD(TestComment)
		{
			char buffer[30] = { '\0' };
			ScriptLang::getLineBytesArray("COM komentarz 123", buffer);

			Assert::AreEqual("", buffer);
		}
	};

	TEST_CLASS(ScriptManagerTests)
	{
	public:
		TEST_METHOD(ScriptManagerTest1)
		{
			ScriptManager::Row rows[20] = { {0}, 0 };

			const char* string = "OS R";
			ScriptManager::getRows((uint8_t*)string, 4, rows, 20);

			Assert::AreEqual((const char*)rows[0].rowArray, "OS R");

			string = "OS R\n\"Samochod123\"";
			ScriptManager::getRows((uint8_t*)string, 18, rows, 20);
			Assert::AreEqual((const char*)rows[0].rowArray, "OS R");
			Assert::AreEqual((const char*)rows[1].rowArray, "\"Samochod123\"");

			string = "OS R\r\n\"Samochod123\"";
			ScriptManager::getRows((uint8_t*)string, 19, rows, 20);
			Assert::AreEqual((const char*)rows[0].rowArray, "OS R");
			Assert::AreEqual((const char*)rows[1].rowArray, "\"Samochod123\"");
		}
	};
}
