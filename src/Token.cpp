//
// Created by millern on 3/26/2025.
//

#include "Token.h"

Token::~Token() {}
inline char Token::getToken() const { return '.'; }
inline std::string Token::getHint() const { return ""; }