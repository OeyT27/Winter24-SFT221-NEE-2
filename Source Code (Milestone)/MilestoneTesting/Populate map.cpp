#include "pch.h"
#include "CppUnitTest.h"
#include "mapping_r.h"
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Populate
{
    TEST_CLASS(PopulateTest)
    {
    public:

        //Blackbox test
        // 
        // Test populateMap function
        TEST_METHOD(TestPopulateMap1)
        {
            Map map = populateMap();

            // Assert
            Assert::AreEqual(MAP_ROWS, getNumRows(&map));
            Assert::AreEqual(MAP_COLS, getNumCols(&map));
            Assert::AreEqual(0, map.squares[0][0]);


        }

        //Adding points to map
        TEST_METHOD(TestPopulateMap2)
        {
            struct Map testMap = populateMap();
            Assert::AreEqual(MAP_ROWS, testMap.numRows);
            Assert::AreEqual(MAP_COLS, testMap.numCols);
            Assert::AreEqual(1, testMap.squares[0][4]); 
            Assert::AreEqual(1, testMap.squares[5][1]); 
            Assert::AreEqual(0, testMap.squares[2][19]); 
            Assert::AreEqual(0, testMap.squares[13][20]); 


        }

        
        TEST_METHOD(TestPopulateMap3) {
            Map map = populateMap();

            //Assert
            Assert::AreEqual(1, map.squares[2][2]);
            Assert::AreEqual(1, map.squares[5][23]);
        }

        TEST_METHOD(TestPopulateMap4) {
            // Test populateMap function
            Map map = populateMap();

            //Assert
            Assert::AreEqual(0, map.squares[15][15]);
            Assert::AreEqual(0, map.squares[21][18]);

        }

        //Whitebox testing
        // 
        // Test when the map is properly populated
        TEST_METHOD(TestPopulateMap5)
        {
            Map map = populateMap();

            // Check if the map dimensions are correct
            Assert::AreEqual(MAP_ROWS, map.numRows);
            Assert::AreEqual(MAP_COLS, map.numCols);

            // Check specific points on the map
            Assert::AreEqual(0, map.squares[0][0]);
            Assert::AreEqual(1, map.squares[5][5]);
            Assert::AreEqual(1, map.squares[10][10]);
            Assert::AreEqual(0, map.squares[15][15]);
            Assert::AreEqual(1, map.squares[20][20]);
        }

        // Test when the map is fully populated
        TEST_METHOD(TestPopulateMap6)
        {
            Map map = populateMap();

            // Check if the map dimensions are correct
            Assert::AreEqual(MAP_ROWS, map.numRows);
            Assert::AreEqual(MAP_COLS, map.numCols);

            // Check specific points on the map
            for (int i = 0; i < MAP_ROWS; ++i) {
                for (int j = 0; j < MAP_COLS; ++j) {
                    Assert::IsTrue(map.squares[i][j] == 0 || map.squares[i][j] == 1);
                }
            }
        }

        // Test when the map is empty
        TEST_METHOD(TestPopulateMap7)
        {
            Map map = populateMap();

            // Check if the map dimensions are correct
            Assert::AreEqual(MAP_ROWS, map.numRows);
            Assert::AreEqual(MAP_COLS, map.numCols);

            // Check if all points on the map are empty
            for (int i = 0; i < MAP_ROWS; ++i) {
                for (int j = 0; j < MAP_COLS; ++j) {
                    Assert::AreEqual(0, map.squares[i][j]);
                }
            }
        }


    };

}