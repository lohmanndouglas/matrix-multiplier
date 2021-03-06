#include "systemc.h"
#include "matrix_mult.h"

int sc_main( int argc, char *argv[] )  {

  // Signals
  sc_signal< sc_int<16> > sg1[16];
  sc_signal< sc_int<16> > sg2[16];
  sc_signal< sc_int<16> > sg3[16];

  // Module
  matrix_mult multiplier("Multiplier");

  int z;
  for (z=0; z<16; z++) {
      multiplier.A[z](sg1[z]);
      multiplier.B[z](sg2[z]);
      multiplier.C[z](sg3[z]);
  }

  // Start of the Simulation
  sc_start(1,SC_NS);

  for(z=0; z<16; z++) {
    sg1[z] = rand()%4;
    sg2[z] = rand()%4;
  }

  sc_start(2, SC_NS);

  std::cout << "primeira matrix" << '\n';
  for(z=0; z<16; z = z+4) {
    std::cout << " " << sg1[z] << ", " << sg1[z+1] << " ," << sg1[z+2] << " ," << sg1[z+3] <<'\n';
  }
  std::cout << "segunda matrix" << '\n';
  for(z=0; z<16; z = z+4) {
    std::cout << " " << sg2[z] << " ," << sg2[z+1] << " ," << sg2[z+2] << " ," << sg2[z+3] << '\n';
  }
  std::cout << "resultado" << '\n';
  for(z=0; z<16; z = z+4) {
    std::cout << " " << sg3[z] << " ," << sg3[z+1] << " ," << sg3[z+2] << " ," << sg3[z+3] << '\n';
  }


  return 0;
};
