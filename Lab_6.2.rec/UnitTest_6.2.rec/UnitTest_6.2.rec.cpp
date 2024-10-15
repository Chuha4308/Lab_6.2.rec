#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_6.2.rec/Lab_6.2.rec.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            const int SIZE = 10;
            int arr[SIZE]{};
            int MIN = -10;
            int MAX = 10;
            int i = 0;
            create(arr, SIZE, MIN, MAX, 0);
            Assert::AreEqual(9, FindingTheArithmetic(arr, SIZE, 0, 0), 0.0001);
        }
    };
}
