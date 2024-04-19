#include "pch.h"
#include "CppUnitTest.h"
#include "mapping_r.h"
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Moves
{
    TEST_CLASS(TestPossibleMoves)
    {
    public:

        //Blackbox testing
        TEST_METHOD(TestGetPossibleMoves1)
        {
            Map map = populateMap();
            Point p1 = { 0, 0 };
            Point backpath = { 0, 1 };
            Route possibleMoves = getPossibleMoves(&map, p1, backpath);

            //Assert
            Assert::AreEqual(2, possibleMoves.numPoints);
            Assert::IsTrue(eqPt(Point{ 1, 0 }, possibleMoves.points[0]));

        }
        
        TEST_METHOD(TestGetPossibleMoves2) {

            Map map = populateMap();
            Point p2 = { 5, 5 };
            Point backpath = { 6, 5 };
            Route possibleMoves = getPossibleMoves(&map, p2, backpath);

            //Assert
            Assert::AreEqual(3, possibleMoves.numPoints);
            Assert::IsTrue(eqPt(Point{ 5, 6 }, possibleMoves.points[0]));
            Assert::IsTrue(eqPt(Point{ 4, 5 }, possibleMoves.points[1]));
            Assert::IsTrue(eqPt(Point{ 5, 4 }, possibleMoves.points[2]));

        }

        //Whitebox testing
        TEST_METHOD(TestGetPossibleMoves3) {
            Map map = populateMap();
            Point p3 = { 10, 10 };
            Point backpath = { 9, 10 };
            Route possibleMoves = getPossibleMoves(&map, p3, backpath);

            //Assert
            Assert::AreEqual(3, possibleMoves.numPoints);
            Assert::IsTrue(eqPt(Point{ 10, 9 }, possibleMoves.points[3]));
            Assert::IsTrue(eqPt(Point{ 11, 10 }, possibleMoves.points[5]));
            Assert::IsTrue(eqPt(Point{ 10, 11 }, possibleMoves.points[6]));

        }

        TEST_METHOD(TestGetPossibleMoves4) {

            Map map = populateMap();
            Point p4 = { 0, 0 };
            Point backpath = { 1, 0 };
            Route possibleMoves = getPossibleMoves(&map, p4, backpath);

            //Assert
            Assert::AreEqual(1, possibleMoves.numPoints);
            Assert::IsTrue(eqPt(Point{ 0, 1 }, possibleMoves.points[0]));

        }

        TEST_METHOD(TestGetPossibleMoves5) {

            Map map = populateMap();
            Point p5 = { 19, 19 };
            Point backpath = { 18, 19 };
            Route possibleMoves = getPossibleMoves(&map, p5, backpath);

            //Assert
            Assert::AreEqual(1, possibleMoves.numPoints);
            Assert::IsTrue(eqPt(Point{ 19, 18 }, possibleMoves.points[0]));

        }

    };

}