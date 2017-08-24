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
#include "inputProperties.h"


inputProperties::inputProperties(std::string& file_loc){
	/**
	 * reading variable from the file and set the variables
	 * as pair of {key, value} in strings
	 */
 //   std::cout << "inputProperties constructor\n";
	std::ifstream file(file_loc);
	if (file.is_open()){
		std::string line;
        while(std::getline(file,line)){
			auto pos = line.find('=');
			if (pos != -1){
				std::string key = line.substr(0, pos);
                boost::algorithm::trim(key);
				std::transform(key.begin(), key.end(), key.begin(), ::toupper);
				std::string val = line.substr(pos+1, line.size()-pos-1);
                boost::algorithm::trim(val);
				mp[key] = val;
//                std::cout << "key: " << key << " val: " << val << "\n";
			}
		}
		file.close();
	}
}

const std::unordered_map<std::string, std::string>& inputProperties::getVar() const{
	/**
	 * return the saved pairs of key and values
	 */
	return mp;
}



