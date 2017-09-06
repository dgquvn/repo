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

#ifndef VARIABLES_H_
#define VARIABLES_H_

#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
#include "InputProperties.h"

/**
 * An abstract class for converting data from InputProperties
 * as needed variables
 */
class Variables{
public:

	/**
	 * check if the input parameters are valid
	 */
	bool isValid() { return valid; }

	/**
	 * virtual member function for TwoVariables
	 */
	virtual void outputVar(int& max_I, int& l_d, int& u_d, std::string& l_d_l, std::string& u_d_l) {}

	/**
	 * virtual member function for GeneralVariables
	 */
	virtual void outputVar(int& max_I, std::vector<std::pair<int, std::string>>& val_label) {}

protected:
	/**
	 * check if the input parameters are valid
	 */
	bool valid = true;

};

#endif /* VARIABLES_H_ */
