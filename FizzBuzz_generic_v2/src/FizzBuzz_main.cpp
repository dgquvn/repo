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
#include <boost/program_options.hpp>
#include <iostream>
#include <string>
#include "Controller.h"

using namespace boost::program_options;

/**
* Main program for getting argument from user
* and read the file with specific location
* finally output the strings
*/
int main(int argc, char** argv){

	try{

		/**
		 * inputfile_loc, storing input file location
		 * outputfile_loc, storing output file location
		 */
		std::string inputfile_loc, outputfile_loc;

		/**
		 * generalOptions, storing parsed arguments
		 */
		options_description generalOptions{"General"};
		generalOptions.add_options()
				("help,h", "Help screen")
				("input", value<std::string>(&inputfile_loc), "Input file location")
				("output", value<std::string>(&outputfile_loc), "Output file location");
		variables_map vm;

		// parse arguments to generalOptions and store to vm
		store(parse_command_line(argc, argv, generalOptions), vm);
		notify(vm);

		if (vm.count("help"))
			std::cout << generalOptions << "\n";
		else if (inputfile_loc.empty())
			std::cout << "input file location missing, enter --help for instruction.\n";
		else if (outputfile_loc.empty())
			std::cout << "output file location missing, enter --help for instruction.\n";
		else{
			// reading input file in Controller
			Controller main_body(inputfile_loc);

			// print out the log to output file
			main_body.print(outputfile_loc);

		}
	}
    catch(char const* ex){
    	std::cerr << ex << "\n";
    	std::cout << "enter --help to see instruction\n";
    }


    return 0;
}



