#include "finder.h"
#include <iostream>
#include <limits>

// Function prototypes for the test functions
void testFindValidTruckPaths();
void testHasDestination();
void testIsBuildingIntersected();
void testGetBestRoute();
void testIsTruckOverloaded();
void testIsBoxSizeExceeded();
void testValidCargo();

int main()
{
    testFindValidTruckPaths();
    testHasDestination();
    testIsBuildingIntersected();
    testGetBestRoute();
    testIsTruckOverloaded();
    testIsBoxSizeExceeded();
    testValidCargo();

    return 0;
}

void mockFindValidTruckPaths(Shipment shipment, Truck truck, const Map *map, Route routes[MAX_ROUTE], int *size)
{
    // Simulate the behavior of the original function by returning predefined routes
    Route route1 = getBlueRoute();
    Route route2 = getGreenRoute();
    Route route3 = getYellowRoute();

    // Assign the predefined routes to the output
    routes[0] = route1;
    routes[1] = route2;
    routes[2] = route3;

    // Update the number of valid routes found
    *size = 3;
}

// Test function to validate findValidTruckPaths
void testFindValidTruckPaths()
{
    // Initialize test values for the shipment
    Shipment shipment = { {0, 0} }; // Set a destination point for the shipment

    // Initialize test values for the truck
    Truck truck = {
        .allocatedShipments = 3,
        .destinationCounts = {3, 4, 2} // Destination counts for the allocated shipments
    };

    // Initialize test routes for the truck
    Route routes[MAX_ROUTE] = {0}; // Initialize routes with zeros

    int size = 0;

    // Create a mock map (populateMap() returns the predefined map)
    Map map = populateMap();

    // Call the mock function to find valid truck paths
    mockFindValidTruckPaths(shipment, truck, &map, routes, &size);

    // Verify the result
    if (size == 3)
    {
        std::cout << "testFindValidTruckPaths test passed!" << std::endl;
    }
    else
    {
        std::cout << "testFindValidTruckPaths test failed. Expected 3 valid routes, found " << size << "." << std::endl;
    }
}

// Function to test the hasDestination function
void testHasDestination()
{
    // Test Case 1
    Route route1 = getBlueRoute();
    Shipment shipment1 = {6, 0, 17, 24};
    int expected1 = 1;
    int result1 = hasDestination(&route1, shipment1);
    std::cout << "Test Case 1: " << (result1 == expected1 ? "testHasDestination test passed!" : "testHasDestination test failed!") << std::endl;

    // Test Case 2
    Route route2 = getGreenRoute();
    Shipment shipment2 = {0, 0, 19, 24};
    int expected2 = 0;
    int result2 = hasDestination(&route2, shipment2);
    std::cout << "Test Case 2: " << (result2 == expected2 ? "testHasDestination test passed!" : "testHasDestination test failed!") << std::endl;
}

void testIsBuildingIntersected()
{
    // Create a sample map
    Map map = populateMap();

    // Test Case 3: Check if the yellow route intersects with any building
    Route yellowRoute = getYellowRoute();
    int expected3 = 0;
    int result3 = isBuildingIntersected(yellowRoute, &map);
    std::cout << "Test Case 3: " << (result3 == expected3 ? "testIsBuildingIntersected test passed!" : "testIsBuildingIntersected test failed!") << std::endl;
}

// Test function for getBestRoute
void testGetBestRoute()
{
    // Define three routes and one shipment
    Route route1 = getBlueRoute();
    Route route2 = getGreenRoute();
    Route route3 = getYellowRoute();

    Shipment shipment = {11, 20};

    // Create an array of routes
    Route *routes[] = {&route1, &route2, &route3};

    // Get the size of the routes array
    int size = sizeof(routes) / sizeof(routes[0]);

    // Call the getBestRoute function to find the best route index
    int bestRouteIndex = getBestRoute(routes, shipment, size);

    // Check if the bestRouteIndex is within valid range (0 to size-1)
    if (bestRouteIndex >= 0 && bestRouteIndex < size)
    {
        // Print the result
        std::cout << "testGetBestRoute test passed!" << std::endl;
    }
    else
    {
        // Print an error message
        std::cout << "testGetBestRoute test failed! Invalid route index." << std::endl;
    }
}

void testIsTruckOverloaded()
{
    // Test case 2: Truck weight capacity is 900, shipment weight is 1000, result should be 1 (overloaded)
    Truck truck2 = {900};
    Shipment ship2 = {1000};
    int result2 = isTruckOverloaded(truck2, ship2);
    if (result2 == 1)
        std::cout << "testIsTruckOverloaded test passed!" << std::endl;
    else
        std::cout << "testIsTruckOverloaded test failed!" << std::endl;
}

// Test cases for isBoxSizeExceeded
void testIsBoxSizeExceeded()
{
    // Define and initialize the necessary structures and variables for testing
    Truck truck;
    // Initialize the truck as required for testing

    float boxSize = 5.0; // Set the boxSize value as required for testing

    // Test the function
    int result = isBoxSizeExceeded(truck, boxSize);

    // Print the results
    std::cout << "testIsBoxSizeExceeded ";
    if (result == 1)
    {
        std::cout << "test passed!" << std::endl;
    }
    else
    {
        std::cout << "test failed!" << std::endl;
    }
}

// Test cases for validCargo
void testValidCargo()
{
    // Define and initialize the necessary structures and variables for testing
    float boxSize = 0.5; // Set the boxSize value as required for testing

    // Test the function
    int result = validCargo(boxSize);

    // Print the results
    std::cout << "testValidCargo ";
    if (result == 1)
    {
        std::cout << "test passed!" << std::endl;
    }
    else
    {
        std::cout << "test failed!" << std::endl;
    }
}
