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
#include "TwoVariables.h"

/**
 * default setting of constructor
 */
TwoVariables::TwoVariables(int m_I, int l_d, int u_d, std::string l_d_l, std::string u_d_l):
max_Int{m_I}, lower_divisor{l_d}, upper_divisor{u_d},
lower_div_lab{l_d_l}, upper_div_lab{u_d_l}
{
}

/**
 * This is for setting variables from InputProperties
 */
TwoVariables::TwoVariables(InputProperties* input){

//    std::cout << "variables constructor\n";

	// store the map data from InputProperties
    std::unordered_map<std::string, std::string> mp = input->getVar();

    int count = 0;
    // find key "MAX_INT" and store the numerical value
    if (mp.find("MAX_INT") != mp.end()){
		max_Int = std::stoi(mp["MAX_INT"]);
		count++;
	}

    // find key "LOWER_DIVISOR" and store the numerical value
    if (mp.find("LOWER_DIVISOR") != mp.end()){
		lower_divisor = std::stoi(mp["LOWER_DIVISOR"]);
		count++;
	}

    // find key "UPPER_DIVISOR" and store the numerical value
    if (mp.find("UPPER_DIVISOR") != mp.end()){
		upper_divisor = std::stoi(mp["UPPER_DIVISOR"]);
		count++;
	}

    // find key "LOWER_DIVISOR_LABEL" and store value
    if (mp.find("LOWER_DIVISOR_LABEL") != mp.end()){
		lower_div_lab = mp["LOWER_DIVISOR_LABEL"];
		count++;
	}

    // find key "UPPER_DIVISOR_LABEL" and store value
    if (mp.find("UPPER_DIVISOR_LABEL") != mp.end()){
		upper_div_lab = mp["UPPER_DIVISOR_LABEL"];
		count++;
	}
    if (count != 5)
    	valid = false;
}


/**
 * Output the parameters
 */
void TwoVariables::outputVar(int& max_I, int& l_d, int& u_d, std::string& l_d_l, std::string& u_d_l){
	if (Variables::isValid()){
		max_I = max_Int;
		l_d = lower_divisor;
		u_d = upper_divisor;
        l_d_l = lower_div_lab;
        u_d_l = upper_div_lab;
	}
	else{
		throw "wrong format of input file";
	}
}

