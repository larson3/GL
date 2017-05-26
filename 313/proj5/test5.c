/****************************************************************
 * File:    test4.c
 * Project: CMSC 313 Project 5, Fall 2015
 * Author:  John Larson
 * Date:    10/27/15
 * E-mail:  larson3@umbc.edu 
 *
 *   This file is a test of my frac_heap.c logic.  Filling the array with adding
 *   adding progressively large numbers to see how it is handled.  Then we delete
 *   an array member who had been re-pointed to, to make sure we delete the
 *   newest instance.
 *
 ****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "frac_heap.h"


/* Compute the greatest common divisor using Euclid's algorithm*/

unsigned int gcd ( unsigned int a, unsigned int b) {

   if (b == 0) return a ;

   return gcd (b, a % b) ;
}


/* Print a fraction out nicely
*/
void print_frac (fraction *fptr) {

   if (fptr->sign < 0) printf("-") ;

   printf("%d/%d", fptr->numerator, fptr->denominator) ;

}


 /*Initialize a fraction*/

fraction *init_frac (signed char s, unsigned int n, unsigned int d) {
   
   fraction *fp ;

   fp = new_frac() ;
   fp->sign = s ;
   fp->numerator = n ;
   fp->denominator = d ;

   return fp ;
}


/* Add two fractions
 Return value is a pointer to allocated space.
 This must be deallocated using del_frac().*/

fraction *add_frac(fraction *fptr1, fraction *fptr2) {
   unsigned int lcm, div, g, m1, m2  ;
   fraction *answer ;


   g = gcd(fptr1->denominator, fptr2->denominator) ;
   lcm = (fptr1->denominator / g) * fptr2->denominator ;

   m1 = (fptr1->denominator / g) ;
   m2 = (fptr2->denominator / g) ;
   lcm = m1 * fptr2->denominator ;

   answer = new_frac() ;
   answer->denominator = lcm ;

   if (fptr1->sign == fptr2->sign) {

      answer->sign = fptr1->sign ;
      answer->numerator = fptr1->numerator * m2 + fptr2->numerator * m1 ;

   } else if (fptr1->numerator >= fptr2->numerator) {

      answer->sign = fptr1->sign ;
      answer->numerator = fptr1->numerator * m2 - fptr2->numerator * m1 ;

   } else {

      answer->sign = fptr2->sign ;
      answer->numerator = fptr2->numerator * m2 - fptr1->numerator * m1 ;

   }

   div = gcd(answer->numerator, answer->denominator) ;
   answer->numerator /= div ;
   answer->denominator /= div ;

   return answer ;

}


int main() {

   fraction *fp1, *fp2, *fp3;

   init_heap() ;



   fraction *fp4, *fp5, *fp6 ;
   fp4 = init_frac(1, 8, 42) ;
    dump_heap() ;
   fp5 = init_frac(1, 17, 96) ;
    dump_heap() ;
   fp6 = add_frac(fp4, fp5) ;
   fp1 = add_frac(fp6,fp6);
   fp2 = add_frac(fp1,fp1);
   fp3 = add_frac(fp2,fp2);
   fp4 = add_frac(fp3,fp3);
   dump_heap() ;
   del_frac(fp4);
   dump_heap();

   return 0 ;
}
