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

#ifndef GENERALVARIABLES_H_
#define GENERALVARIABLES_H_

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Variables.h"
#include "GeneralInputProperties.h"

/**
 * A class for converting data from unordered_map to needed variables
 */
class GeneralVariables : public Variables{
public:

	/**
	 * default constructor for testing files
	 * @param max_I, val_label correspond to private members, namely
	 * max_Int, var
	 */
	GeneralVariables(int max_I, const std::vector<std::pair<int, std::string>>& val_label);

	/**
	 * constructor for converting data from general input to needed variables
	 * @param input a instance of class GeneralInputProperties with input file parameters
	 */
	GeneralVariables(InputProperties* input);


	/**
	 * membere functions for accessing private members by setting the paramters
	 */
    void outputVar(int& max_I, std::vector<std::pair<int, std::string>>& val_label);
private:

    /**
     * max interger for outputing FizzBuzz program
     */
	int max_Int;

	/**
	 * pairs of {val, label} as ordered
	 */
	std::vector<std::pair<int, std::string>> var;
};




#endif /* GENERALVARIABLES_H_ */
