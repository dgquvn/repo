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

#ifndef TWOINPUTPROPERTIES_H_
#define TWOINPUTPROPERTIES_H_

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <ctype.h>
#include <boost/algorithm/string/trim.hpp>
#include "InputProperties.h"

/**
 * This class read the input file parameters and store the values in
 * a unordered_map
 */
class TwoInputProperties : public InputProperties{
public:

	/**
	 * default constructor for testing files
	 */
    TwoInputProperties(const std::unordered_map<std::string, std::string>& input_mp);

    /**
     * constructor used in the program
     * @param file_loc the input file location
     */
    TwoInputProperties(const std::string& file_loc);


    /**
     * member function for accessing stored map
     * @return the private member
     */
    const std::unordered_map<std::string, std::string>& getVar() const;
private:

    /**
     * private member map for storing parameters
     * containing keys "INT_MAX", "LOWER_DIVISOR", "UPPER_DIVISOR",
     * "LOWER_DIVISOR_LABEL", and "UPPER_DIVISOR_LABEL", and their
     * corresponding string values
     */
	std::unordered_map<std::string, std::string> mp;
};



#endif /* TWOINPUTPROPERTIES_H_ */
