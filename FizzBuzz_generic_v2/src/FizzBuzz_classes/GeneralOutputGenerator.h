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

#ifndef GENERALOUTPUTGENERATOR_H_
#define GENERALOUTPUTGENERATOR_H_

#include <omp.h>
#include <iostream>
#include <string>
#include <vector>
#include "OutputGenerator.h"
#include "GeneralVariables.h"

/**
 * a class for generating the output log based on input parameters
 */
class GeneralOutputGenerator : public OutputGenerator{
public:

	/**
	 * default constructor for testing file
	 */
    GeneralOutputGenerator(const std::vector<std::string>& op);

    /**
     * constructor for building the output log based on the parameters
     * @param a an instance of class Variables containing the parameters
     */
    GeneralOutputGenerator(Variables* a);

    /**
     * get output log
     */
    const std::vector<std::string>& getOutput() const;

private:
	/**
	 * private member containing output log
	 */
	std::vector<std::string> output;
};



#endif /* GENERALOUTPUTGENERATOR_H_ */
