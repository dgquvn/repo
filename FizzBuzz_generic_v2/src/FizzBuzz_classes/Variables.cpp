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
#include "Variables.h"

Variables::Variables(int m_I, int l_d, int u_d, std::string l_d_l, std::string u_d_l):
max_Int{m_I}, lower_divisor{l_d}, upper_divisor{u_d},
lower_div_lab{l_d_l}, upper_div_lab{u_d_l}, count{5}
{
	/**
	 * default setting of constructor
	 */
}

Variables::Variables(const InputProperties& input){
	/**
	 * This is for setting variables
	 */
//    std::cout << "variables constructor\n";
    std::unordered_map<std::string, std::string> mp = input.getVar();
    if (mp.find("MAX_INT") != mp.end()){
		max_Int = std::stoi(mp["MAX_INT"]);
		count++;
	}
    if (mp.find("LOWER_DIVISOR") != mp.end()){
		lower_divisor = std::stoi(mp["LOWER_DIVISOR"]);
		count++;
	}
    if (mp.find("UPPER_DIVISOR") != mp.end()){
		upper_divisor = std::stoi(mp["UPPER_DIVISOR"]);
		count++;
	}
    if (mp.find("LOWER_DIVISOR_LABEL") != mp.end()){
		lower_div_lab = mp["LOWER_DIVISOR_LABEL"];
		count++;
	}
    if (mp.find("UPPER_DIVISOR_LABEL") != mp.end()){
		upper_div_lab = mp["UPPER_DIVISOR_LABEL"];
		count++;
	}
}

bool Variables::isValid(){
	if (count == 5)
		return true;
	else
		return false;
}


void Variables::outputVar(int& max_I, int& l_d, int& u_d, std::string& l_d_l, std::string& u_d_l){
	if (isValid()){
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



