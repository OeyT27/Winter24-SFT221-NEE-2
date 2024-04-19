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
           
            Map map = populateMap();
            Route route = getBlueRoute();

         
            Map mapWithRoute = addRoute(&map, &route);

          
            Assert::IsNotNull(&mapWithRoute);

          
            Assert::AreEqual(2, mapWithRoute.squares[0][0]);
            Assert::AreEqual(2, mapWithRoute.squares[1][0]);
            Assert::AreEqual(2, mapWithRoute.squares[15][0]);
            Assert::AreEqual(2, mapWithRoute.squares[32][0]);
        }

        TEST_METHOD(TestShortestPathIntegration)
        {
           
            Map map = populateMap();
            Point start = { 0, 0 };
            Point dest = { 5, 5 };

         
            Route shortest = shortestPath(&map, start, dest);

         
            Assert::IsNotNull(&shortest); // Ensure shortest path is not null
            Assert::AreEqual(5, shortest.numPoints);

            // Check specific points in the path to ensure correctness
            Assert::IsTrue(eqPt(start, shortest.points[0]));
            Assert::IsTrue(eqPt(dest, shortest.points[shortest.numPoints - 1]));
            Assert::IsTrue(eqPt(dest, shortest.points[shortest.numPoints + 1]));
            Assert::IsTrue(eqPt(dest, shortest.points[shortest.numPoints + 1000]));
        }

        TEST_METHOD(TestGetPossibleMovesIntegration)
        {
         
            Map map = populateMap();
            Point p1 = { 0, 0 };
            Point backpath = { 0, 1 };

         
            Route possibleMoves = getPossibleMoves(&map, p1, backpath);

         
            Assert::IsNotNull(&possibleMoves); // Ensure possibleMoves is not null
            Assert::AreEqual(2, possibleMoves.numPoints);

            // Check specific points in the possible moves
            Assert::IsTrue(eqPt(Point{ 1, 0 }, possibleMoves.points[0]));
            Assert::IsTrue(eqPt(Point{ 0, 1 }, possibleMoves.points[1]));
            Assert::IsTrue(eqPt(Point{ 0, 0 }, possibleMoves.points[0]));
            Assert::IsTrue(eqPt(Point{ -1, -1 }, possibleMoves.points[-1]));
        }
    };
}
