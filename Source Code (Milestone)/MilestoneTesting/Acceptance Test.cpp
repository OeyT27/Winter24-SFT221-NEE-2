#include "pch.h"
#include "CppUnitTest.h"
#include "mapping_r.h"
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Acceptance
{
    TEST_CLASS(AcceptanceTest)
    {
    public:

        //Calculating distance
        TEST_METHOD(AcceptanceTest1)
        {
            struct Point p1 = { 0, 0 };
            struct Point p2 = { 3, 4 };
            double dist = distance(&p1, &p2);

            //Assert
            Assert::AreEqual(5.0, dist);

        }

        //Number of rows and columns
        TEST_METHOD(AcceptanceTest2)
        {
           
            struct Map testMap = populateMap();
            int numRows = getNumRows(&testMap);
            int numCols = getNumCols(&testMap);

            //Assert
            Assert::AreEqual(MAP_ROWS, numRows);
            Assert::AreEqual(MAP_COLS, numCols);

        }

        // Define a map with packages
        TEST_METHOD(AcceptanceTest3) {

            struct Map testMap = populateMap();
            struct Point package1 = { 5, 5 };
            struct Point package2 = { 15, 15 };
            struct Point package3 = { 20, 20 };
            struct Point package4 = { 8, 8 };

        }

        // Define a map with packages
        TEST_METHOD(AcceptanceTest4) {

            struct Map testMap = populateMap();

            // Define package destinations
            struct Point package1 = { 5, 5 };  
            struct Point package2 = { 15, 15 }; 
            struct Point package3 = { 20, 20 }; 
            struct Point package4 = { 8, 8 };   

            // Calculate shortest paths for each package
            struct Route path1 = shortestPath(&testMap, package1, { 10, 10 });
            struct Route path2 = shortestPath(&testMap, package2, { 5, 5 });
            struct Route path3 = shortestPath(&testMap, package3, { 0, 0 });
            struct Route path4 = shortestPath(&testMap, package4, { 15, 15 });

            // Check if the path is not empty
            Assert::IsTrue(path1.numPoints > 0); 
            Assert::IsTrue(path2.numPoints > 0); 
            Assert::IsTrue(path3.numPoints > 0);
            Assert::IsTrue(path4.numPoints > 0); 
            
            // Check if the number of points in the path is correct
            Assert::AreEqual(6, path1.numPoints);
            Assert::AreEqual(2, path2.numPoints);
            Assert::AreEqual(4, path3.numPoints);
            Assert::AreEqual(5, path4.numPoints);
        }

        // Test case to ensure no path when destination is unreachable
        TEST_METHOD(AcceptanceTest5) {

            struct Map testMap = populateMap();
            struct Point package5 = { 0, 0 };
            struct Route path5 = shortestPath(&testMap, package5, { 24, 24 });
            
            //Assert
            Assert::IsTrue(path5.numPoints == 0);
        }

        // Test case to ensure correct path calculation when start and destination are the same
        TEST_METHOD(AcceptanceTest6) {
            
            struct Map testMap = populateMap();
            struct Point package6 = { 5, 5 };
            struct Route path6 = shortestPath(&testMap, package6, package6);

            //Assert
            Assert::IsTrue(path6.numPoints == 0);
        }

    };

}