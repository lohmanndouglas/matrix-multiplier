/*!
 * \file adder.cpp
 * \brief Adder Implementation
 *
 * The implementation file for Adder class
 */
#include "matrix_mult.h"

void matrix_mult::mult(){
  int i,j;
  while(true){
  	for(i=0; i < 16; i=i+4){
  		for (j=0; j<4; j++){
			C[i+j].write(A[0+i].read()*B[j].read()  +  A[1+i].read()*B[4+j].read() + A[2+i].read()*B[8+j].read() + A[3+i].read()*B[12+j].read());
		}
  	}
    wait();
  }
}
