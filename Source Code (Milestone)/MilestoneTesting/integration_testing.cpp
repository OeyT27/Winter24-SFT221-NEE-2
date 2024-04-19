#include "CppUnitTest.h"
#include "mapping_r.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IntegrationTests
{
    TEST_CLASS(AcceptanceIntegrationTest)
    {
    public:

        TEST_METHOD(TestDistanceCalculationIntegration)
        {
            // Calculate distance between two points
            Point p1 = { 0, 0 };
            Point p2 = { 3, 4 };
            double dist = distance(&p1, &p2);

            // Assert
            Assert::AreEqual(5.0, dist);
        }

        TEST_METHOD(TestNumRowsAndColsIntegration)
        {
            // Populate a map and get the number of rows and columns
            Map testMap = populateMap();
            int numRows = getNumRows(&testMap);
            int numCols = getNumCols(&testMap);

            // Assert
            Assert::AreEqual(MAP_ROWS, numRows);
            Assert::AreEqual(MAP_COLS, numCols);
        }

        TEST_METHOD(TestShortestPathIntegration)
        {
            // Define a map with packages
            Map testMap = populateMap();

            // Define package destinations
            Point package1 = { 5, 5 };  
            Point package2 = { 15, 15 }; 
            Point package3 = { 20, 20 }; 
            Point package4 = { 8, 8 };   
            Point package5 = { 0, 0 };

            // Calculate shortest paths for each package
            Route path1 = shortestPath(&testMap, package1, { 10, 10 });
            Route path2 = shortestPath(&testMap, package2, { 5, 5 });
            Route path3 = shortestPath(&testMap, package3, { 0, 0 });
            Route path4 = shortestPath(&testMap, package4, { 15, 15 });
            Route path5 = shortestPath(&testMap, package5, { 25, 25 });
            Route path6 = shortestPath(&testMap, package1, package1);

            // Assert
            Assert::IsTrue(path1.numPoints > 0);
            Assert::IsTrue(path2.numPoints > 0);
            Assert::IsTrue(path3.numPoints > 0);
            Assert::IsTrue(path4.numPoints > 0);
            Assert::IsTrue(path5.numPoints == 0);
            Assert::IsTrue(path6.numPoints == 0);

            // Additional assertions for path lengths if needed
            Assert::AreEqual(6, path1.numPoints);
            Assert::AreEqual(2, path2.numPoints);
            Assert::AreEqual(4, path3.numPoints);
            Assert::AreEqual(5, path4.numPoints);
        }
    };
}
