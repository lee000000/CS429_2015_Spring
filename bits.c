/*
 * CS:APP Data Lab
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the "dlc"
 * checker. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#include "btest.h"
#include <limits.h>

/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

// You will provide your solution to the Data Lab by
// editing the collection of functions in this source file.
// 
// CODING RULES:
// 
//   Replace the "return" statement in each function with one
//   or more lines of C code that implements the function. Your code
//   must conform to the following style:
// 
//   int Funct(arg1, arg2, ...) {
//       /* brief description of how your implementation works */
//       int var1 = Expr1;
//       ...
//       int varM = ExprM;
// 
//       varJ = ExprJ;
//       ...
//       varN = ExprN;
//       return ExprR;
//   }
// 
//   Each "Expr" is an expression using ONLY the following:
//   1. Integer constants 0 through 255 (0xFF), inclusive. You are
//       not allowed to use big constants such as 0xffffffff.
//   2. Function arguments and local variables (no global variables).
//   3. Unary integer operations ! ~
//   4. Binary integer operations & ^ | + << >>
// 
//   Some of the problems restrict the set of allowed operators even further.
//   Each "Expr" may consist of multiple operators. You are not restricted to
//   one operator per line.
// 
//   You are expressly forbidden to:
//   1. Use any control constructs such as if, do, while, for, switch, etc.
//   2. Define or use any macros.
//   3. Define any additional functions in this file.
//   4. Call any functions.
//   5. Use any other operations, such as &&, ||, -, or ?:
//   6. Use any form of casting.
// 
//   You may assume that your machine:
//   1. Uses 2s complement, 32-bit representations of integers.
//   2. Performs right shifts arithmetically.
//   3. Has unpredictable behavior when shifting an integer by more
//      than the word size.
// 
// EXAMPLES OF ACCEPTABLE CODING STYLE:
//   /*
//    * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
//    */
//   int pow2plus1(int x) {
//      /* exploit ability of shifts to compute powers of 2 */
//      return (1 << x) + 1;
//   }
// 
//   /*
//    * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
//    */
//   int pow2plus4(int x) {
//      /* exploit ability of shifts to compute powers of 2 */
//      int result = (1 << x);
//      result += 4;
//      return result;
//   }
// 
// 
// NOTES:
//   1. Use the dlc (data lab checker) compiler (described in the handout) to
//      check the legality of your solutions.
//   2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
//      that you are allowed to use for your implementation of the function.
//      The max operator count is checked by dlc. Note that '=' is not
//      counted; you may use as many of these as you want without penalty.
//   3. Use the btest test harness to check your functions for correctness.
//   4. The maximum number of ops for each function is given in the
//      header comment for each function. If there are any inconsistencies
//      between the maximum ops in the writeup and in this file, consider
//      this file the authoritative source.

/*
 * STEP 2: Modify the following functions according to the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the btest test harness to check that your solutions produce
 *      the correct answers. Watch out for corner cases around Tmin and Tmax.
 *   3. If you have Perl installed, you can use driver.pl to calculate
 *      your final score.
 */

/*
 * bitAnd - x&y using only ~ and |
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  return ( ~(~x | ~y ) );
}
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 2
 */
int bitXor(int x, int y) {
  return (~ ( x & y ) & ( ~ ( ~ x & ~ y )));
}
/*
 * isEqual - return 1 if x == y, and 0 otherwise
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int isEqual(int x, int y) {
  return  (1 >> ( x ^ y )) & ( ! ( x ^ y ) );
}
/*
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
int evenBits(void) {
  int x =  0x55 ;
  return x << 24 | x << 16 | x << 8 | x;
}
/*
 * fitsBits - return 1 if x can be represented as an
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  int shift = 32 + ( ~n + 1 ); 
  int y = !((( x << shift) >> shift ) ^ x );
   
  return (( !y & !((~x) >> shift)) + ( y & !(x >> shift))); 

}
/*
 * bitMask - Generate a mask consisting of all 1's
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit) {
  int i = ~0;
  return ((( i << highbit ) << 1) ^ (i << lowbit) )& ( i << lowbit);
}
/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  //return ((( !(!x)) << 31 ) & y ) + ((( !x ) << 31 ) & z);
  int mask = !x;
  mask = ( mask << 31 ) >> 31;
  return ( mask & z ) | (~mask & y );
}
/*
 * reverseBytes - reverse the bytes of x
 *   Example: reverseBytes(0x01020304) = 0x04030201
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 */
int reverseBytes(int x) {
  return ((x >> 24) & 0xff) | ((( x >> 16 ) & 0xff ) << 8 ) | ((( x >> 8 ) & 0xff ) << 16 ) | (( x & 0xff ) << 24 );
}
/*
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int bang(int x) {
  return ~ ( x | ( ~x + 1 ) ) >> 31 & 0x01;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  int m1, m2, m3, m4, m5;
  int mask1, mask2, mask3, mask4, mask5;
  int ans ;

  m1 = 0x55;
  m2 = 0x33;
  m3 = 0x0F;
  m4 = 0xFF;
  m5 = 0xFF;

  m1 = m1 | ( m1 << 8 );
  mask1 = m1 | (m1 << 16);

  m2 = m2 | ( m2 << 8 );
  mask2 = m2 | ( m2 << 16);

  m3 = m3 | ( m3 << 8 );
  mask3 = m3 | ( m3 << 16);

  mask4 = m4 | ( m4 << 16 );

  mask5 = m5 | ( m5 << 8 );

  ans = ( x & mask1 ) + (( x >> 1 ) & mask1);
  ans = ( ans & mask2 ) + (( ans >> 2 ) & mask2);
  ans = ( ans + ( ans >> 4 )) & mask3;
  ans = ( ans + ( ans >> 8 ) ) & mask4 ;
  ans = ( ans + ( ans >> 16 )) & mask5;
  return ans;
}
/*
 * isZero - returns 1 if x == 0, and 0 otherwise
 *   Examples: isZero(5) = 0, isZero(0) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int isZero(int x) {
  return !x;
}
/*
 * isNegative - return 1 if x < 0, return 0 otherwise
 *   Example: isNegative(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNegative(int x) {
  x >>= 31;
  x = x + 1;
  return !x;
}
/*
 * multFiveEights - multiplies by 5/8 rounding toward 0.
 *   Examples: multFiveEights(77) = 48
 *             multFiveEights(-22) = -13
 *   You can assume |x| < (1 << 29)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int multFiveEights(int x) {
  int y = (x << 2) + x;
  int z = y >> 3;
  return ( ~y & z ) | ( y & ( z + 1 ) ); 
 
}
/*
 * sum3 - x+y+z using only a single '+'
 *   Example: sum3(3, 4, 5) = 12
 *   Legal ops: ! ~ & ^ | << >>
 *   Max ops: 16
 *   Rating: 3
 */
/* A helper routine to perform the addition.  Don't change this code */
static int sum(int x, int y) {
  return x+y;
}
int sum3(int x, int y, int z) {
  int word1;
  int word2;
  /**************************************************************
     Fill in code below that computes values for word1 and word2
     (note that the + operation is not allowed here!)
  ***************************************************************/
  int foo = 1;
  int bar = 1;
  word1 = foo;
  word2 = bar;
  /**************************************************************
     Don't change anything below here
  ***************************************************************/
  return sum(word1,word2);
}
/*
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1,
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
  int z = x + y ;
  return !(( ( x ^ z ) & ( y ^ z )) >> 31);
}
/*
 * isLess - if x < y  then return 1, else return 0
 *   Example: isLess(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLess(int x, int y) {
  int x_sign = ( x >> 31 ) ;
  int y_sign = ( y >> 31 ) ;
  int xminusy_sign = ( x + ( ~y + 1 ) ) >> 31;

  int a = (( x_sign ^ y_sign ) & x_sign ) | ( ~ ( x_sign ^ y_sign ) & xminusy_sign ); 
 

  return ( a & 1 ) | (~a & 0 ) ; 
}
/*
 * abs - absolute value of x (except returns TMin for TMin)
 *   Example: abs(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int abs(int x) {
  int y = x >> 31;
  return ( y & (~x + 1) ) | (~y & x );

}
/*
 * isNonZero - Check whether x is nonzero using
 *              the legal operators except !
 *   Examples: isNonZero(3) = 1, isNonZero(0) = 0
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int isNonZero(int x) {
  int pos = ( x >> 31 ) & 1;
  int neg = ( (~x + 1) >> 31 ) & 1;
  return pos | neg;
}
/*
 * tc2sm - Convert from two's complement to sign-magnitude
 *   where the MSB is the sign bit
 *   You can assume that x > TMin
 *   Example: tc2sm(-5) = 0x80000005.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int tc2sm(int x) {

//  int z = ( x >> 31 ) ;
//  int y = ( z << 31 ) ^ ( ~x + 1 );
  
//  int mask = !x;
//  mask = ( mask << 31 ) >> 31;

 // return ( mask & x ) | ( ~mask & y );
 int z = x >> 31;
 return (x & (~z)) | ((( z << 31 ) | ( ~x + 1 ) ) & z );
}
