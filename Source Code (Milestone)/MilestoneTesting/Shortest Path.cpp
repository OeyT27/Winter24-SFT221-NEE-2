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

        //Whitebox testing
        // 
        // Test shortest path when the start and destination are both on the edge
        TEST_METHOD(ShortestPathTests5)
        {
            Map map;
            map.numRows = 25;
            map.numCols = 25;

            Point start = { 0, 12 };
            Point dest = { 24, 12 }; // Straight path along the edge

            Route result = shortestPath(&map, start, dest);

            Assert::AreEqual(25, result.numPoints);
            Assert::AreEqual(dest.row, result.points[24].row);
            Assert::AreEqual(dest.col, result.points[24].col);
        }

        // Test shortest path when the start and destination are diagonal
        TEST_METHOD(ShortestPathTests6)
        {
            Map map;
            map.numRows = 25;
            map.numCols = 25;

            Point start = { 10, 10 };
            Point dest = { 15, 15 }; // Diagonal path

            Route result = shortestPath(&map, start, dest);

            Assert::AreEqual(6, result.numPoints);
            Assert::AreEqual(dest.row, result.points[5].row);
            Assert::AreEqual(dest.col, result.points[5].col);
        }

        //Whitebox testing
        // 
        // Test shortest path when there is no path available
        TEST_METHOD(ShortestPathTests7)
        {
            Map map;
            map.numRows = 25;
            map.numCols = 25;

            Point start = { 0, 0 };
            Point dest = { 4, 4 }; // Blocked destination

            Route result = shortestPath(&map, start, dest);

            Assert::AreEqual(0, result.numPoints); // No path available
        }

        // Test shortest path when the start and destination are far apart
        TEST_METHOD(ShortestPathTests8)
        {
            Map map;
            map.numRows = 25;
            map.numCols = 25;

            Point start = { 0, 0 };
            Point dest = { 24, 24 }; // Diagonal path across the map

            Route result = shortestPath(&map, start, dest);

            Assert::AreEqual(48, result.numPoints);
            Assert::AreEqual(dest.row, result.points[47].row);
            Assert::AreEqual(dest.col, result.points[47].col);
        }


    };
}
