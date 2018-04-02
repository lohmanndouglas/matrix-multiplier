/*!
 * \file matrix_mult.h
 * \brief matrix_mult class declaration
 *
 * The declaration file for the matrix_mult
 */

#include<systemc.h>


/*! \class matrix_mult
 *  \brief matrix_mult class.
 *
 *   Class for matrix_mult
 */
SC_MODULE(matrix_mult)  {

  sc_in<sc_int<16> > A[16];
  sc_in<sc_int<16> > B[16];
  sc_out<sc_int<16> > C[16];

  /*!
   * This method do the mult of sc_in
   */
  void mult();


  /*!
   * This method contruct the matrix_mult
   * \param in matrix_mult is a adder name
   */
  SC_CTOR(matrix_mult) {
    int j;
    SC_THREAD(mult);
    for(j=0; j<16; j++)
      sensitive << A[j] << B[j];
  }
};
