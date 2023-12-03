#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB6_4it/LAB6_4it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(FillArrayRandom)
        {
            int n = 10;
            double arr[10];

            srand(123);
            fillArrayRandom(arr, n);

            for (int i = 0; i < n; ++i)
            {
                Assert::IsTrue(arr[i] >= -50 && arr[i] <= 50);
            }
        }
        TEST_METHOD(ProductPositiveElements)
        {
            int n = 5;
            double arr[5] = { 2.0, -1.5, 3.0, -4.0, 5.0 };
            double posProduct = productPositiveElements(arr, n);

            Assert::AreEqual(30.0, posProduct);
        }

        TEST_METHOD(ProductPositiveElements_NoPositiveElements)
        {
            int n = 5;
            double arr[5] = { -2.0, -1.5, -3.0, -4.0, -5.0 };
            double posProduct = productPositiveElements(arr, n);

            Assert::AreEqual(1.0, posProduct);
        }

        TEST_METHOD(SumElementsBeforeMinimum)
        {
            int n = 7;
            double arr[7] = { 4.0, 2.0, 1.0, 3.0, 5.0, 6.0, 7.0 };
            double sumBeforeMin = sumElementsBeforeMinimum(arr, n);

            Assert::AreEqual(6.0, sumBeforeMin, 0.00001);
        }

        TEST_METHOD(SumElementsBeforeMinimum_NoMinimum)
        {
            int n = 5;
            double arr[5] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
            double sumBeforeMin = sumElementsBeforeMinimum(arr, n);

            Assert::AreEqual(0.0, sumBeforeMin, 0.00001);
        }

        TEST_METHOD(OrderEvenOddElements)
        {
            int n = 8;
            double arr[8] = { 5.0, 2.0, 4.0, 1.0, 3.0, 6.0, 8.0, 7.0 };
            orderEvenOddElements(arr, n);

            double expectedArr[8] = { 1.0, 3.0, 5.0, 7.0, 2.0, 4.0, 6.0, 8.0 };
            for (int i = 0; i < n; ++i)
            {
                Assert::AreEqual(expectedArr[i], arr[i], 2);
            }
        }
    };
}