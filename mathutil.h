#ifndef _MATHUTIL_H
#define _MATHUTIL_H

#include <vector>
#include "polar.h"
#include "cartesian.h"

template<class T>
int sgn(T num);

int dimensions(polar);
int dimensions(cartesian);

std::vector<double> bounding(std::vector<cartesian> cvec);

void print_histogram(std::vector<cartesian> cvec);
void print_histogram(std::vector<cartesian> cvec, double variation);
long int distribution(std::vector<cartesian> cvec);

#endif