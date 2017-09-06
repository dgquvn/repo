/**----------------------------------------------------------------------------
 Copyright (c) 2015-, UT-Battelle, LLC
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 * Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.

 * Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.

 * Neither the name of fern nor the names of its
 contributors may be used to endorse or promote products derived from
 this software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 Author(s): Guoqiang Deng (dgquvn <at> gmail <dot> com)
 -----------------------------------------------------------------------------*/

#ifndef TWOVARIABLES_H_
#define TWOVARIABLES_H_

#include <iostream>
#include <string>
#include <unordered_map>
#include "Variables.h"
#include "TwoInputProperties.h"

/**
 * A class for converting data from unordered_map to needed variables
 */
class TwoVariables : public Variables{
public:

	/**
	 * default constructor for testing files
	 * @param m_I, l_d, u_d, l_d_l, u_d_l correspond to private members, namely
	 * max_Int, lower_divisor, upper_divisor, lower_div_lab, and upper_div_lab
	 */
	TwoVariables(int m_I, int l_d, int u_d, const std::string& l_d_l, const std::string& u_d_l);

	/**
	 * constructor for converting data from map to needed variables
	 * @param input a instance of class InputProperties with input file parameters
	 */
	TwoVariables(InputProperties* input);

	/**
	 * membere functions for accessing private members by setting the paramters
	 */
    void outputVar(int& max_I, int& l_d, int& u_d, std::string& l_d_l, std::string& u_d_l);
private:

    /**
     * max interger for outputing FizzBuzz program
     */
	int max_Int;

	/**
	 * lower divisor for testing case in class OutputGenerator
	 */
	int lower_divisor;

	/**
	 * upper divisor for testing case in class OutputGenerator
	 */
	int upper_divisor;

	/**
	 * outputing label corresponding to lower divisor
	 */
	std::string lower_div_lab;

	/**
	 * outputing label corresponding to upper divisor
	 */
	std::string upper_div_lab;
};




#endif /* TWOVARIABLES_H_ */
