#include "find.h"
#include <iostream> // For std::cout
#include <iomanip>  // For std::setw

void findValidTruckPaths(Shipment shipment, Truck truck, const Map *map, Route routes[MAX_ROUTE], int *size)
{
    int count = 0;
    for (int i = 0; i < truck.allocated_shipments; i++)
    {
        if (truck.destination_counts[i] == hasDestination(&routes[i], shipment) && !isBuildingIntersected(routes[i], map))
        {
            routes[count++] = routes[i];
        }
    }
    *size = count;
}

int hasDestination(const Route *route, Shipment shipment)
{
    for (int i = 0; i < route->numPoints; i++)
    {
        if (route->points[i] == shipment.destination)
        {
            return 1;
        }
    }
    return 0;
}

void printRoute(Route route, Shipment shipment)
{
    std::cout << "Route to Shipment (Destination: (" << shipment.destination.row << ", " << shipment.destination.col << ")):\n";
    for (int i = 0; i < route.numPoints; i++)
    {
        std::cout << "(" << route.points[i].row << ", " << route.points[i].col << ") ";
    }
    std::cout << std::endl;
}

int isBuildingIntersected(const Route route, const Map *map)
{
    for (int i = 0; i < route.numPoints; i++)
    {
        if (map->squares[route.points[i].row][route.points[i].col] == 2)
        {
            return 1;
        }
    }
    return 0;
}

int getBestRoute(Route *routes[MAX_ROUTE], Shipment shipment, int size)
{
    int shortestDistance = INT_MAX;
    int shortestIndex = -1;

    for (int i = 0; i < size; i++)
    {
        int routeDistance = distance(&routes[i]->points[0], &shipment.destination);
        if (routeDistance < shortestDistance)
        {
            shortestDistance = routeDistance;
            shortestIndex = i;
        }
    }

    return shortestIndex;
}

int isTruckOverloaded(Truck truck, Shipment ship)
{
    int result = 0;

    if (truck.weight_capacity <= 1000)
    {
        truck.weight_capacity += ship.weight;

        if (truck.weight_capacity <= 1000)
        {
            result = 1;
        }
    }

    return result;
}

int isBoxSizeExceeded(Truck truck, float boxSize)
{
    int result = 0;

    if (truck.volume_capacity <= 36)
    {
        truck.volume_capacity += boxSize;

        if (truck.volume_capacity <= 36)
        {
            result = 1;
        }
    }

    return result;
}

int validCargo(float boxSize)
{
    const double minSize = 0.25;
    const double halfSize = 0.5;
    const double maxSize = 1.0;
    int result = 0;

    if (boxSize == minSize || boxSize == halfSize || boxSize == maxSize)
    {
        result = 1;
    }
    else
    {
        std::cout << "Box size is not valid." << std::endl;
    }

    return result;
}

void postCommitHook()
{
    std::cout << "This edit is to test post commit hook" << std::endl;
}

void preCommitHook()
{
    std::cout << "another test" << std::endl;
}
