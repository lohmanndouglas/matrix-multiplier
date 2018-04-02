/*!
 * \file voter.h
 * \brief voter class declaration
 *
 * The declaration file for the voter
 */

#include <systemc.h>


/*! \class voter
 *  \brief voter class.
 *
 *   Class for voter
 */
SC_MODULE(voter)  {

  sc_in<sc_int<16> > input_A[16];
  sc_in<sc_int<16> > input_B[16];
  sc_in<sc_int<16> > input_C[16];

  sc_out<sc_int<16> > output[16];

  /*!
   * This method do the vote of sc_in
   */
  void vote();


  /*!
   * This method contruct the voter
   * \param in voter is a adder name
   */
  SC_CTOR(voter) {
    std::cout <<" BUILD VOTER " << endl;
    int j;
    SC_THREAD(vote);
    for(j=0; j<16; j++)
      sensitive << input_A[j] << input_B[j];
  }
};
