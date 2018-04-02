#include <systemc.h>
#include "matrix_mult.h"
#include "voter.h"

/*! \class Top
 *  \brief Top class.
 *
 *   Class for Top
 */
SC_MODULE(dut) {

  sc_in<sc_int<16> > A[16];
  sc_in<sc_int<16> > B[16];

  // sc_out<sc_int<16> > C[16];

  sc_port<sc_signal_inout_if<sc_int<16> > , 2> C[16];


  sc_signal< sc_int<16> > sg1[16];
  sc_signal< sc_int<16> > sg2[16];
  sc_signal< sc_int<16> > sg3[16];
  // sc_signal< sc_int<16> > sg4[16];

  // Modules
  matrix_mult m1;
  matrix_mult m2;
  matrix_mult m3;
  voter vt;

  /*!
   * This method contruct the DUT
   * \param in Adder is a adder name
   */
  SC_CTOR(dut) : m1("m1"), m2("m2"), m3("m3"), vt("vt") {

    int z;
    for (z=0; z<16; z++) {
        
        m1.A[z](A[z]);
        m1.B[z](B[z]);
        m1.C[z](sg1[z]);

        m2.A[z](A[z]);
        m2.B[z](B[z]);
        m2.C[z](sg2[z]);

        m3.A[z](A[z]);
        m3.B[z](B[z]);
        m3.C[z](sg3[z]);


        vt.input_A[z](sg1[z]);
        vt.input_B[z](sg2[z]);
        vt.input_C[z](sg3[z]);

        vt.output[z](C[z]);
    }
  }

};
