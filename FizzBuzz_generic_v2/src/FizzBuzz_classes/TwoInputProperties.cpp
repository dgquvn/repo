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
#include "TwoInputProperties.h"

/**
 * default constructor initilized by a unordered_map
 */
TwoInputProperties::TwoInputProperties(const std::unordered_map<std::string, std::string>& input_mp):
mp{input_mp}
{
}

/**
 * read parameters from input file and store the information as
 * pairs of {key, value}
 */
TwoInputProperties::TwoInputProperties(std::string& file_loc){

	std::ifstream file(file_loc);
	if (file.is_open()){
		std::string line;
        while(std::getline(file,line)){

        	// find the expression with "="
			auto pos = line.find('=');
			if (pos != -1){

				// set the key to the left side of '='
				std::string key = line.substr(0, pos);

				// delete white spaces from key
                boost::algorithm::trim(key);

                // transform key to uppercase
				std::transform(key.begin(), key.end(), key.begin(), ::toupper);

				// set the value to the right side of '='
				std::string val = line.substr(pos+1, line.size()-pos-1);

				// delete white spaces from value
                boost::algorithm::trim(val);

                // store key and value to the map
				mp[key] = val;
//                std::cout << "key: " << key << " val: " << val << "\n";
			}
		}

		file.close();
	}
	else{
		throw("wrong input file location");
	}
}

/**
 * return the saved pairs of key and values
 */
const std::unordered_map<std::string, std::string>& TwoInputProperties::getVar() const{
	return mp;
}



