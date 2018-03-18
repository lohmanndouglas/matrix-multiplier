/*!
 * \file adder.cpp
 * \brief Adder Implementation
 *
 * The implementation file for Adder class
 */
#include "matrix_mult.h"

void matrix_mult::mult(){
  int i;
  while(true){
    for(i=0; i<16; i++){
      C[i].write(A[i].read()+B[i].read());
    }
    wait();
  }
}
