#include "pch.h"
#include "CppUnitTest.h"
#include "../AP_Lab12.2/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LinkedListUnitTest
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            // Test case 1: Empty list
            Elem* L1 = nullptr;
            Assert::IsTrue(isNonDescending(L1));

            // Test case 2: Single element list
            Elem* L2 = new Elem{ 1, nullptr };
            Assert::IsTrue(isNonDescending(L2));

            // Test case 3: Non-descending list
            Elem* L3 = new Elem{ 1, new Elem{2, new Elem{3, nullptr}} };
            Assert::IsTrue(isNonDescending(L3));

            // Test case 4: Descending list
            Elem* L4 = new Elem{ 3, new Elem{2, new Elem{1, nullptr}} };
            Assert::IsFalse(isNonDescending(L4));
        }
    };
}
