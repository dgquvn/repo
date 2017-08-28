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
#include "generate_output.h"

generate_output::generate_output(const std::vector<std::string>& op):
output{op}
{
	/**
	 * default constructor
	 */
}

generate_output::generate_output(variables& a){
	/**
	 * This is engine for generating the output string
	 */
 //   std::cout << "generate_output constructor\n";
	int max_Int, lower_div, upper_div;
	std::string lower_div_lab, upper_div_lab;
	a.outputVar(max_Int, lower_div, upper_div, lower_div_lab, upper_div_lab);

	int product_div = lower_div * upper_div;
	output.resize(max_Int);
	std::string combined = lower_div_lab + upper_div_lab;
    for (int i = 1; i < max_Int; i++){
		if (i % product_div == 0)
            output[i-1] = combined;
		else if (i % upper_div == 0)
            output[i-1] = upper_div_lab;
		else if (i % lower_div == 0)
            output[i-1] = lower_div_lab;
		else
            output[i-1] = std::to_string(i);
	}
}

std::vector<std::string>& generate_output::getOutput(){
	/**
	 * return output vector
	 */
	return output;
}



