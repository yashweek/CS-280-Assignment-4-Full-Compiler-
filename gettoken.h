/*
 * GetToken.h
 *
 *  Created on: Mar 16, 2019
 *      Author: gerardryan
 */

#ifndef GETTOKEN_H_
#define GETTOKEN_H_

#include "tokens.h"

class GetToken {
	static bool	pushed_back;
	static Token	pushed_token;

public:
	static Token Get(istream& in, int& line) {
		if( pushed_back ) {
			pushed_back = false;
			return pushed_token;
		}
		return getNextToken(in, line);
	}

	static void PushBack(Token& t) {
		if( pushed_back ) {
			throw std::logic_error("Cannot push back more than one token!");
		}
		pushed_back = true;
		pushed_token = t;
	}
};

#endif /* GETTOKEN_H_ */
