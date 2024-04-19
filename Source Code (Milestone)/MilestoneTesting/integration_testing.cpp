#include "CppUnitTest.h"
#include "mapping_r.h" 
#include "PopulateMapTest.h" 
#include "PossibleMovesTest.h" 
#include "AddRouteTest.h" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IntegrationTests
{
    TEST_CLASS(AllIntegrationTests)
    {
    public:
        TEST_METHOD(TestIntegration)
        {
            // 1. Integration Testing between "PopulateMap" and "AddRoute"
            Map map = PopulateMapTest::populateMap();
            Route greenRoute = AddRouteTest::getGreenRoute(); 
            Map mapWithGreenRoute = AddRouteTest::addRoute(&map, &greenRoute); 
            Assert::AreEqual(GREEN, mapWithGreenRoute.squares[4][11]); 
            Assert::AreEqual(GREEN, mapWithGreenRoute.squares[9][24]);

            // 2. Integration Testing between "PossibleMoves" and "PopulateMap"
            Map map2 = PopulateMapTest::populateMap();
            Point p = {5, 5}; 
            Route possibleMoves = PossibleMovesTest::getPossibleMoves(&map2, p); 
            Assert::AreEqual(3, possibleMoves.numPoints);

            // 3. Integration Testing between "PossibleMoves" and "AddRoute"
            Map map3 = PopulateMapTest::populateMap();
            Route greenRoute2 = AddRouteTest::getGreenRoute(); 
            Map mapWithGreenRoute2 = AddRouteTest::addRoute(&map3, &greenRoute2); 
            Point p2 = {5, 5}; 
            Route possibleMoves2 = PossibleMovesTest::getPossibleMoves(&mapWithGreenRoute2, p2); 
            // Assert statements as necessary
        }
    };
}
