/****************************************************************
 * File:    test4.c
 * Project: CMSC 313 Project 5, Fall 2015
 * Author:  John Larson
 * Date:    10/27/15
 * E-mail:  larson3@umbc.edu 
 *
 *   This file is a test of my frac_heap.c logic.  We are filling the array with
 *   values, then deleting all values.  We loop through to do it again to make
 *   sure the program is able to handle substantial adding and deletion of
 *   fractions to the array.
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

  
   fraction *fp1, *fp2, *fp3, *fp4, *fp5, *fp6, *fp7, *fp8;
   fraction *fp9, *fp10, *fp11, *fp12 , *fp13, *fp14;
   fraction *fp15 , *fp16, *fp17, *fp18, *fp19, *fp20; 
   int i;
   init_heap() ;
	i = 0;
while(i<2)
{
   fp1 = new_frac() ;
   fp1->sign = -1 ;
   fp1->numerator = 2 ;
   fp1->denominator = 3 ;
 
   fp2 = new_frac();
   fp2->sign = -1 ;
   fp2->numerator = 22 ;
   fp2->denominator = 330 ;


   fp3 = new_frac() ;
   fp3->sign = -1 ;
   fp3->numerator = 7 ;
   fp3->denominator = 8 ;
   
   fp4 = new_frac();
   fp4->sign = -1 ;
   fp4->numerator = 22 ;
   fp4->denominator = 330 ;

   
   fp5 = new_frac() ;
   fp5->sign = -1 ;
   fp5->numerator = 2 ;
   fp5->denominator = 3 ;
 


   fp6 = new_frac() ;
   fp6->sign = -1 ;
   fp6->numerator = 7 ;
   fp6->denominator = 8 ;
   
   fp7 = new_frac() ;
   fp7->sign = -1 ;
   fp7->numerator = 2 ;
   fp7->denominator = 3 ;
 
   fp8 = new_frac();
   fp8->sign = -1 ;
   fp8->numerator = 22 ;
   fp8->denominator = 330 ;
   

   fp9 = new_frac() ;
   fp9->sign = -1 ;
   fp9->numerator = 7 ;
   fp9->denominator = 8 ;
   
   fp10 = new_frac() ;
   fp10->sign = -1 ;
   fp10->numerator = 2 ;
   fp10->denominator = 3 ;
 
   fp11 = new_frac();
   fp11->sign = -1 ;
   fp11->numerator = 22 ;
   fp11->denominator = 330 ;


   fp12 = new_frac() ;
   fp12->sign = -1 ;
   fp12->numerator = 7 ;
   fp12->denominator = 8 ;
   
   fp13 = new_frac() ;
   fp13->sign = -1 ;
   fp13->numerator = 2 ;
   fp13->denominator = 3 ;
 
   fp14 = new_frac();
   fp14->sign = -1 ;
   fp14->numerator = 22 ;
   fp14->denominator = 330 ;
   
   fp15 = new_frac() ;
   fp15->sign = -1 ;
   fp15->numerator = 7 ;
   fp15->denominator = 8 ;
   
   fp16 = new_frac() ;
   fp16->sign = -1 ;
   fp16->numerator = 2 ;
   fp16->denominator = 3 ;
 
   fp17 = new_frac();
   fp17->sign = -1 ;
   fp17->numerator = 22 ;
   fp17->denominator = 330 ;
   
   fp18 = new_frac() ;
   fp18->sign = -1 ;
   fp18->numerator = 7 ;
   fp18->denominator = 8 ;
   
   fp19 = new_frac() ;
   fp19->sign = -1 ;
   fp19->numerator = 2 ;
   fp19->denominator = 3 ;
 
   fp20 = new_frac();
   fp20->sign = -1 ;
   fp20->numerator = 22 ;
   fp20->denominator = 330 ;
   dump_heap();


   del_frac(fp1) ;
   del_frac(fp2) ;
   del_frac(fp3) ;
   del_frac(fp4) ;
   del_frac(fp5) ;
   del_frac(fp6) ;
   del_frac(fp7) ;
   del_frac(fp8) ;
   del_frac(fp9) ;
   del_frac(fp10) ;
   del_frac(fp11) ;
   del_frac(fp12) ;
   del_frac(fp13) ;
   del_frac(fp14) ;
   del_frac(fp15) ;
   del_frac(fp16) ;
   del_frac(fp17) ;
   del_frac(fp18) ;
   del_frac(fp19) ;
   del_frac(fp20) ;
   dump_heap();
   i+=1;
}


   return 0 ;
}
