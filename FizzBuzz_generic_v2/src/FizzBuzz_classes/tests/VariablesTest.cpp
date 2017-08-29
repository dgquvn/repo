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
#define BOOST_TEST_MODULE TEST_VARIABLE
#include <boost/test/included/unit_test.hpp>
#include "Variables.h"

BOOST_AUTO_TEST_CASE(test_d_v){
	/**
	 * testing default constructor
	 */
	Variables var(10,3,5,"F","B");
	int max_I, l_d, u_d;
	std::string l_d_l, u_d_l;
	var.outputVar(max_I, l_d, u_d, l_d_l, u_d_l);
	BOOST_CHECK(max_I == 10);
	BOOST_CHECK(l_d == 3);
	BOOST_CHECK(u_d == 5);
	BOOST_CHECK(l_d_l == "F");
	BOOST_CHECK(u_d_l == "B");
}

BOOST_AUTO_TEST_CASE(test_w){
	std::unordered_map<std::string, std::string> input_mp;
	input_mp.insert({"MAX_INT", "100"});
	input_mp.insert({"LOWER_DIVISOR", "3"});
	input_mp.insert({"UPPER_DIVISOR", "5"});
	input_mp.insert({"LOWER_DIVISOR_LABEL", "Fizz"});
	input_mp.insert({"UPPER_DIVISOR_LABEL", "Buzz"});
    InputProperties input(input_mp);
    Variables var(input);
	BOOST_CHECK_EQUAL(var.isValid(), true);
	int max_I, l_d, u_d;
	std::string l_d_l, u_d_l;
	var.outputVar(max_I, l_d, u_d, l_d_l, u_d_l);
	BOOST_CHECK(max_I == 100);
	BOOST_CHECK(l_d == 3);
	BOOST_CHECK(u_d == 5);
	BOOST_CHECK(l_d_l == "Fizz");
	BOOST_CHECK(u_d_l == "Buzz");
//	std::cout << "test_w done\n";
}

