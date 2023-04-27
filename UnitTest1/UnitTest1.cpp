#include "pch.h"
#include "CppUnitTest.h"
#include "../AP_Lab12.2/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LinkedListUnitTest
{
    TEST_CLASS(SortListUnitTest)
    {
    public:
        TEST_METHOD(TestSortList)
        {
            // Arrange
            Elem* L = NULL;
            AddToList(L, 6);
            AddToList(L, 2);
            AddToList(L, 8);
            AddToList(L, 2);
            AddToList(L, 9);
            AddToList(L, 3);
            int expected[] = { 2, 2, 3, 6, 8, 9 };
            int i = 0;

            // Act
            SortList(L);

            // Assert
            while (L != NULL) {
                Assert::AreEqual(expected[i], L->info);
                L = L->link;
                i++;
            }
        }
    };
}
