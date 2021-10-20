#include "CppUnitTest.h"
#include "../BadUSB/ScriptLang.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BadUSBTests
{
	TEST_CLASS(BadUSBTests)
	{
	public:

		TEST_METHOD(TestOneChar)
		{
			char buffer[30] = { '\0' };

			ScriptLang::getFinalBytesArray("OS r d", buffer);
		}
	};
}
