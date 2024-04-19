// Including necessary headers
#include "mapping.h"
#include "CppUnitTest.h"
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Acceptance
{
    TEST_CLASS(AcceptanceTest)
    {
    public:

        
        TEST_METHOD(CalculateDistance)
        {
           
            struct Point p1 = { 0, 0 };
            struct Point p2 = { 3, 4 };

           
            double dist = distance(&p1, &p2);

            
            Assert::AreEqual(5.0, dist, L"Distance calculation is incorrect.");
        }

       
        TEST_METHOD(GetNumberOfRowsAndColumns)
        {
           
            struct Map testMap = populateMap();

           
            int numRows = getNumRows(&testMap);
            int numCols = getNumCols(&testMap);

           
            Assert::AreEqual(MAP_ROWS, numRows, L"Number of rows mismatch.");
            Assert::AreEqual(MAP_COLS, numCols, L"Number of columns mismatch.");
        }

       
        TEST_METHOD(DefineMapWithPackagesAndCalculateShortestPaths)
        {
           
            struct Map testMap = populateMap();
            struct Point package1 = { 5, 5 };
            struct Point package2 = { 15, 15 };
            struct Point package3 = { 20, 20 };
            struct Point package4 = { 8, 8 };

          
            struct Route path1 = shortestPath(&testMap, package1, { 10, 10 });
            struct Route path2 = shortestPath(&testMap, package2, { 5, 5 });
            struct Route path3 = shortestPath(&testMap, package3, { 0, 0 });
            struct Route path4 = shortestPath(&testMap, package4, { 15, 15 });

          
            Assert::IsTrue(path1.numPoints > 0, L"Path 1 is empty.");
            Assert::IsTrue(path2.numPoints > 0, L"Path 2 is empty.");
            Assert::IsTrue(path3.numPoints > 0, L"Path 3 is empty.");
            Assert::IsTrue(path4.numPoints > 0, L"Path 4 is empty.");

           
            Assert::AreEqual(6, path1.numPoints, L"Incorrect number of points in path 1.");
            Assert::AreEqual(2, path2.numPoints, L"Incorrect number of points in path 2.");
            Assert::AreEqual(4, path3.numPoints, L"Incorrect number of points in path 3.");
            Assert::AreEqual(5, path4.numPoints, L"Incorrect number of points in path 4.");
        }

       
        TEST_METHOD(NoPathWhenDestinationIsUnreachable)
        {
           
            struct Map testMap = populateMap();
            struct Point package5 = { 0, 0 };

            
            struct Route path5 = shortestPath(&testMap, package5, { 25, 25 });

            
            Assert::IsTrue(path5.numPoints == 0, L"Path should be empty when destination is unreachable.");
        }

      
        TEST_METHOD(CorrectPathCalculationWhenStartAndDestinationAreSame)
        {
            // Arrange
            struct Map testMap = populateMap();
            struct Point package6 = { 5, 5 };

           
            struct Route path6 = shortestPath(&testMap, package6, package6);

           
            Assert::IsTrue(path6.numPoints == 0, L"No path should exist when start and destination are the same.");
        }
    };
}
