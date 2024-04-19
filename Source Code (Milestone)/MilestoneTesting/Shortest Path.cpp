#include "pch.h"
#include "CppUnitTest.h"
#include "mapping.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


// Define the shortestPath function
Route shortestPath(Map* map, Point& start, Point& dest) {
    // Provide a dummy implementation or use a mock library
    // For the sake of demonstration, let's return an empty route
    Route route;
    route.numPoints = 0;
    return route;
}

namespace Path
{
    TEST_CLASS(ShortestPathTests)
    {
    public:

        //Blackbox testing
        // 
        // Test shortest path when start and destination are the same
        TEST_METHOD(ShortestPathTests1)
        {
            Map map;
            map.numRows = 25;
            map.numCols = 25;

            Point start = { 0, 0 };
            Point dest = { 0, 0 };

            Route result = shortestPath(&map, start, dest);

            Assert::AreEqual(0, result.numPoints);
        }

        // Test shortest path when start and destination are adjacent
        TEST_METHOD(ShortestPathTests2)
        {
            Map map;
            map.numRows = 25;
            map.numCols = 25;

            Point start = { 0, 0 };
            Point dest = { 0, 1 };

            Route result = shortestPath(&map, start, dest);

            Assert::AreEqual(1, result.numPoints);
            Assert::AreEqual(dest.row, result.points[0].row);
            Assert::AreEqual(dest.col, result.points[0].col);
        }

        //Whitebox testing
        // 
        // Test shortest path when there is a clear straight path
        TEST_METHOD(ShortestPathTests3)
        {
            Map map;
            map.numRows = 25;
            map.numCols = 25;

            Point start = { 0, 0 };
            Point dest = { 0, 4 }; // Assuming a straight path of 5 cells

            Route result = shortestPath(&map, start, dest);

            Assert::AreEqual(5, result.numPoints);
            Assert::AreEqual(dest.row, result.points[4].row);
            Assert::AreEqual(dest.col, result.points[4].col);
        }

        // Test shortest path when there are obstacles in the way
        TEST_METHOD(ShortestPathTests4)
        {
            Map map;
            map.numRows = 25;
            map.numCols = 25;

            Point start = { 0, 0 };
            Point dest = { 4, 4 }; // Assuming a path around obstacles

            Route result = shortestPath(&map, start, dest);

            Assert::AreEqual(9, result.numPoints);
            Assert::AreEqual(dest.row, result.points[8].row);
            Assert::AreEqual(dest.col, result.points[8].col);
        }
    };
}
