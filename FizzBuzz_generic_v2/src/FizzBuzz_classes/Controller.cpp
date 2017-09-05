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
#include "Controller.h"

/**
 * Controller constructor for getting input properties
 * and get the corresponding variables, and finally
 * generate the output
 */
Controller::Controller(std::string inputfile_loc){
	// check theinput file is which type of input
	std::ifstream file{inputfile_loc};
	if (file.is_open()){
		std::string line;

		// move to next line if there is no input parameter
		while(line.find('_', 0) == std::string::npos){
			std::getline(file, line);
		}
		file.close();

		// check which input it is, '=' is only for TwoInputProperties
		auto pos = line.find('=', 0);
		if (pos != std::string::npos){
			input = new TwoInputProperties(inputfile_loc);
			var = new TwoVariables(input);
			output = new TwoOutputGenerator(var);
		}
		else{
			input = new GeneralInputProperties(inputfile_loc);
			var = new GeneralVariables(input);
			output = new GeneralOutputGenerator(var);
		}
	}
}

/**
 * destructor
 */
Controller::~Controller(){
	delete input;
	delete var;
	delete output;
}
/**
 * write the output to the specific file location
 */
void Controller::print(std::string outputfile_loc){
	FileWriter object;
    object.writer(output->getOutput(), outputfile_loc);
}

