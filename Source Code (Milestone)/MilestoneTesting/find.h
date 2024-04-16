#ifndef FIND_H
#define FIND_H

#include "mapping.h"

struct Shipment
{
    float weight;
    float volume;
    Point destination;
};

void findValidTruckPaths(Shipment shipment, Truck truck, const Map *map, Route routes[MAX_ROUTE], int *size);

int hasDestination(const Route *route, Shipment shipment);

void printRoute(Route route, Shipment shipment);

int isBuildingIntersected(const Route route, const Map *map);

int getBestRoute(Route *routes[MAX_ROUTE], Shipment shipment, int size);

int isTruckOverloaded(Truck truck, Shipment ship);

int isBoxSizeExceeded(Truck truck, float boxSize);

int validCargo(float boxSize);

void postCommitHook();
void preCommitHook();

#endif // FIND_H
