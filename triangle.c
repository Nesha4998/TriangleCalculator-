//
//  triangle.c
//  TriangleCalculator
//
//  Created by Nesha Escoffery Markland on 4/21/26.
//

#include <stdio.h>
#include <math.h>
#include "triangle.h"

int isValidTriangle(double a, double b, double c) {
   return (a + b > c && a + c > b && b + c > a);
}

double calculateArea(double a, double b, double c) {
   double s = (a + b + c) / 2.0;
   return sqrt(s * (s - a) * (s - b) * (s - c));
}
