/*!
 * \file voter.cpp
 * \brief voter Implementation
 *
 * The implementation file for voter class
 */
#include "voter.h"
#include <vector>

void voter::vote(){
  
  while(true){

  	int i;
  	for(i=0; i < 16; i++){
	  	if (input_A[i].read() == input_B[i].read()) 
	  		output[i].write(input_A[i].read());
	    else if(input_A[i].read() == input_C[i].read()) 
	    	output[i].write(input_A[i].read());
	    else if(input_B[i].read() == input_C[i].read())
	    	output[i].write(input_B[i].read());
	    else output[i].write(input_A[i].read());
	}
    wait();
  }
}