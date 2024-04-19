#include "pch.h"
#include "CppUnitTest.h"
#include "mapping_r.h"
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AddRoute
{
    TEST_CLASS(AddRouteTest)
    {
    public:

        //Proper initialization
        TEST_METHOD(TestAddRoute1)
        {
            Map map = populateMap();

            //Assert
            Assert::AreEqual(MAP_ROWS, getNumRows(&map));
            Assert::AreEqual(MAP_COLS, getNumCols(&map));
            Assert::AreEqual(0, map.squares[0][0]);

        }

        //Check blue route
        TEST_METHOD(TestAddRoute2) {

            struct Map baseMap = populateMap();
            struct Route blueRoute = getBlueRoute();
            struct Map routeMap = addRoute(&baseMap, &blueRoute);

            // Check if the route has been added correctly by verifying if any squares have the route symbol
            bool routeAdded = false;
            for (int r = 0; r < routeMap.numRows; r++)
            {
                for (int c = 0; c < routeMap.numCols; c++)
                {
                    if (routeMap.squares[r][c] == BLUE)
                    {
                        routeAdded = true;
                        break;
                    }
                }
                if (routeAdded)
                    break;
            }

            //Assert
            Assert::IsTrue(routeAdded);

        }

        //Add yellow route
        TEST_METHOD(TestAddRoute3) {

            struct Map baseMap = populateMap();
            struct Route yellowRoute = getYellowRoute();
            struct Map routeMap = addRoute(&baseMap, &yellowRoute);
            bool routeAdded = false;

            // Check if the route has been added correctly by verifying if any squares have the route symbol
            for (int r = 0; r < routeMap.numRows; r++)
            {
                for (int c = 0; c < routeMap.numCols; c++)
                {
                    if (routeMap.squares[r][c] == YELLOW)
                    {
                        routeAdded = true;
                        break;
                    }
                }
                if (routeAdded)
                    break;
            }

            //Assert
            Assert::IsTrue(routeAdded);

        }
        
        //Adding a green route
        TEST_METHOD(TestAddRoute4) {

            struct Map mapWithRoute = populateMap();
            struct Route greenRoute = getGreenRoute();
            struct Map mapWithGreenRoute = addRoute(&mapWithRoute, &greenRoute);

            //Assert
            Assert::AreEqual(GREEN, mapWithGreenRoute.squares[4][11]);
            Assert::AreEqual(GREEN, mapWithGreenRoute.squares[9][24]);

        }

    };

}