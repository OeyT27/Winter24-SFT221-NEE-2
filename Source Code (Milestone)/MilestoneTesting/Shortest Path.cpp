#include "pch.h"
#include "CppUnitTest.h"
#include "mapping.h"
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Path
{
    TEST_CLASS(TestShortestPaths)
    {
    public:

        // Test shortestPath function
        TEST_METHOD(TestShortestPath1)
        {
            Map map = populateMap();
            Point start = { 0, 0 };
            Point dest = { 5, 5 };

            // Calculate the shortest path from start to dest
            Route shortest = shortestPath(&map, start, dest);

            // Assert statements to verify properties of the shortest path
            Assert::AreEqual(5, shortest.numPoints);

            // Check specific points in the path to ensure correctness
            Assert::IsTrue(eqPt(start, shortest.points[0]));
            Assert::IsTrue(eqPt(dest, shortest.points[shortest.numPoints - 1]));
        }

        // Check if the shortest path has been found by verifying the number of points in the route
        TEST_METHOD(TestShortestPath2) {
            Map map = populateMap();
            Point start = { 0, 0 };
            Point dest = { 17, 24 };

            // Calculate the shortest path from start to dest
            Route shortest = shortestPath(&map, start, dest);

            // Assert statements to verify properties of the shortest path
            Assert::IsTrue(shortest.numPoints > 0);
        }

        // Test shortestPath function with custom map size and points
        TEST_METHOD(TestShortestPath3) {

            Map customMap = populateMap();

            // Define custom start and destination points
            Point start = { 2, 3 };
            Point dest = { 8, 10 };
            Route shortest = shortestPath(&customMap, start, dest);

            // Assert statements to verify properties of the shortest path
            Assert::IsTrue(shortest.numPoints > 0);
            Assert::AreEqual(10, shortest.numPoints);
            Assert::IsTrue(eqPt(start, shortest.points[0]));
            Assert::IsTrue(eqPt(dest, shortest.points[shortest.numPoints - 1]));
        }

        TEST_METHOD(TestShortestPath4) {

            Map customMap = populateMap();
            Point start = { 1, 1 };
            Point dest = { 4, 6 };
            Route shortest = shortestPath(&customMap, start, dest);

            // Assert statements to verify properties of the shortest path
            Assert::IsTrue(shortest.numPoints > 0);
            Assert::AreEqual(6, shortest.numPoints);
            Assert::IsTrue(eqPt(start, shortest.points[0]));
            Assert::IsTrue(eqPt(dest, shortest.points[shortest.numPoints - 1]));
        }
    };
}
