//
//  main.c
//  TriangleCalculator
//
//  Created by Nesha Escoffery Markland on 4/21/26.
//

#include <stdio.h>
#include "triangle.h"

int main(void) {
   FILE *inputFile;
   FILE *outputFile;

   double a, b, c;
   int record = 1;

   inputFile = fopen("input.txt", "r");
   if (inputFile == NULL) {
       printf("Error opening input file.\n");
       return 1;
   }

   outputFile = fopen("output.txt", "w");
   if (outputFile == NULL) {
       printf("Error opening output file.\n");
       return 1;
   }

   while (fscanf(inputFile, "%lf %lf %lf", &a, &b, &c) == 3) {

       if (isValidTriangle(a, b, c)) {
           double area = calculateArea(a, b, c);

           printf("Record %d: %.2lf %.2lf %.2lf -> Valid, Area = %.2lf\n",
                  record, a, b, c, area);

           fprintf(outputFile, "Record %d: %.2lf %.2lf %.2lf -> Valid, Area = %.2lf\n",
                   record, a, b, c, area);
       } else {
           printf("Record %d: %.2lf %.2lf %.2lf -> Invalid\n",
                  record, a, b, c);

           fprintf(outputFile, "Record %d: %.2lf %.2lf %.2lf -> Invalid\n",
                   record, a, b, c);
       }

       record++;
   }

   fclose(inputFile);
   fclose(outputFile);

   printf("Results written to output.txt\n");

   return 0;
}
