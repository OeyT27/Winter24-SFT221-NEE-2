#include "CppUnitTest.h"
#include "mapping_r.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IntegrationTests
{
    TEST_CLASS(IntegrationTest)
    {
    public:

        TEST_METHOD(TestAddRouteIntegration)
        {
            // Test the integration of populateMap and addRoute functions
            Map map = populateMap();
            Route route = getBlueRoute();

            // Add the route to the map
            Map mapWithRoute = addRoute(&map, &route);

            // Assert statements to verify the properties of the map with the added route
            Assert::AreEqual(2, mapWithRoute.squares[0][0]);
            Assert::AreEqual(2, mapWithRoute.squares[1][0]);
            Assert::AreEqual(2, mapWithRoute.squares[15][0]);
            Assert::AreEqual(2, mapWithRoute.squares[32][0]);
        }

        TEST_METHOD(TestShortestPathIntegration)
        {
            // Test the integration of populateMap and shortestPath functions
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
            Assert::IsTrue(eqPt(dest, shortest.points[shortest.numPoints + 1]));
            Assert::IsTrue(eqPt(dest, shortest.points[shortest.numPoints + 1000]));
        }

        TEST_METHOD(TestGetPossibleMovesIntegration)
        {
            // Test the integration of populateMap and getPossibleMoves functions
            Map map = populateMap();
            Point p1 = { 0, 0 };
            Point backpath = { 0, 1 };

            // Get possible moves from p1 while excluding backpath
            Route possibleMoves = getPossibleMoves(&map, p1, backpath);

            // Add assertions to check if the possible moves are correct based on expectations
            Assert::AreEqual(2, possibleMoves.numPoints);

            // Check specific points in the possible moves
            Assert::IsTrue(eqPt(Point{ 1, 0 }, possibleMoves.points[0]));
            Assert::IsTrue(eqPt(Point{ 0, 1 }, possibleMoves.points[1]));
            Assert::IsTrue(eqPt(Point{ 0, 0 }, possibleMoves.points[0]));
            Assert::IsTrue(eqPt(Point{ -1, -1 }, possibleMoves.points[-1]));
        }
    };
}
