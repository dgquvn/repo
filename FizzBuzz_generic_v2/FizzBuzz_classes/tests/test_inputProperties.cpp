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
#define BOOST_TEST_MODULE TEST_INPUTPROPERTIES
#include <boost/test/included/unit_test.hpp>
#include <iostream>
#include "inputProperties.h"


BOOST_AUTO_TEST_CASE(test_c){
    std::string file{"input.txt"};
    inputProperties input(file);
    std::unordered_map<std::string, std::string> mp = input.getVar();
	if (mp.find("MAX_INT") == mp.end())
		BOOST_ERROR("MAX_INT not found");
	else
        BOOST_CHECK_EQUAL(mp["MAX_INT"], "100");

	if (mp.find("LOWER_DIVISOR") == mp.end())
		BOOST_ERROR("LOWER_DIVISOR not found");
	else
        BOOST_CHECK_EQUAL(mp["LOWER_DIVISOR"], "3");

	if (mp.find("UPPER_DIVISOR") == mp.end())
		BOOST_ERROR("UPPER_DIVISOR not found");
	else
        BOOST_CHECK_EQUAL(mp["UPPER_DIVISOR"], "5");

	if (mp.find("LOWER_DIVISOR_LABEL") == mp.end())
		BOOST_ERROR("LOWER_DIVISOR_LABEL not found");
	else
		BOOST_CHECK_EQUAL(mp["LOWER_DIVISOR_LABEL"], "Fizz");

	if (mp.find("UPPER_DIVISOR_LABEL") == mp.end())
		BOOST_ERROR("UPPER_DIVISOR_LABEL not found");
	else
		BOOST_CHECK_EQUAL(mp["UPPER_DIVISOR_LABEL"], "Buzz");

	if (mp.size() != 5)
		BOOST_ERROR("input map variable with wrong size!");
}



