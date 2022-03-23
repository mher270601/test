#include <iostream>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>

bool isOperator(char c){
    	return (!isalpha(c) && !isdigit(c));
}

size_t ByPassOperator(const std::string& preStrm, size_t sinceIndx){
	for(size_t i = sinceIndx; i > 0; --i){
		if(isOperator(preStrm[i])){
			return i-1;
		}
	}
	return preStrm.length();
}

bool ParseLexemme(std::string& preStrm, const size_t& valIndx){
	return (!isOperator(preStrm[valIndx]) && !isOperator(preStrm[valIndx+1]));
}

void ParseExpression(std::string& preStrm){
	unsigned int j = 1;
	unsigned int firstVar = 0, lastVar = 0;
	unsigned int CountOfR = 0;
	size_t opIndx = 0;
	for(size_t i = 0; i < preStrm.length(); ++i){
		
		bool current = ParseLexemme(preStrm, i);
		switch(current){
			case 1:
				switch(isOperator(preStrm[i-1])){
					case true:
						++CountOfR;
						printf("LD R%u, %c\n", j++, static_cast<char> (preStrm[i]));
						printf("LD R%u, %c\n", j, static_cast<char> (preStrm[i+1]));
						firstVar = j-1;
					break;
					case false:
						printf("LD R%u, %c\n", j, static_cast<char> (preStrm[i+1]));
						opIndx = ByPassOperator(preStrm, i-1);
						lastVar = j-1;
					break;
				}
				switch(preStrm[i-1]){
					case '+':
						switch(isOperator(preStrm[i-2])){
							case true:
								printf("ADD R%u, R%u\n", j-1, j);
								std::cout << std::endl;
							break;
						}
					break;
					case '-':
						switch(isOperator(preStrm[i-2])){
							case true:
								printf("SUB R%u, R%u\n", j-1, j);
								std::cout << std::endl;
							break;
						}
					break;
					case '/':
						switch(isOperator(preStrm[i-2])){
							case true:	
								printf("DIV R%u, R%u\n", j-1, j);
								std::cout << std::endl;
							break;
						}
					break;
					case '*':
						switch(isOperator(preStrm[i-2])){
							case true:
								printf("MUL R%u, R%u\n", j-1, j);
								std::cout << std::endl;
							break;
						}
					break;
				}
				switch(!isOperator(preStrm[i-1])){
					case true:
						switch(preStrm[opIndx]){
							case '*':
								printf("MUL R%u, R%u\n", lastVar, lastVar+1);
								std::cout << std::endl;
							break;
							case '/':
								printf("DIV R%u, R%u\n", lastVar, lastVar+1);
								std::cout << std::endl;
							break;
							case '+':
								printf("ADD R%u, R%u\n", lastVar, lastVar+1);
								std::cout << std::endl;
							break;
							case '-':
								printf("SUB R%u, R%u\n", lastVar, lastVar+1);
								std::cout << std::endl;
							break;
						}
					break;
				}
			break;
		}
	}
	switch(preStrm[0]){
		case '+':
			printf("ADD R1, R%u", CountOfR);
			std::cout << std::endl;
		break;
		case '-':
			printf("SUB R1, R%u", CountOfR);
			std::cout << std::endl;
		break;
		case '/':
			printf("DIV R1, R%u", CountOfR);
			std::cout << std::endl;
		break;
		case '*':
			printf("MUL R1, R%u", CountOfR);
			std::cout << std::endl;
		break;
	}
	
}
 
int getPriority(char C){
    if(C == '-' || C == '+'){
        return 1;
    }
    else if(C == '*' || C == '/'){
        return 2;
    }
    else if(C == '^'){
        return 3;
    }
    return 0;
}
 
std::string infixToPostfix(std::string infix){
    infix = '(' + infix + ')';
    int l = infix.size();
    std::stack<char> char_stack;
    std::string output;
 
    for(int i = 0; i < l; ++i){
        if(isalpha(infix[i]) || isdigit(infix[i])){
            output += infix[i];
        }
        else if(infix[i] == '('){
            char_stack.push('(');
        } 
        else if(infix[i] == ')'){
            while(char_stack.top() != '('){
                output += char_stack.top();
                char_stack.pop();
            }
            char_stack.pop();
        }
 
        else{
            if(isOperator(char_stack.top())){
                if(infix[i] == '^'){
                    while(getPriority(infix[i]) <= getPriority(char_stack.top())){
                         output += char_stack.top();
                         char_stack.pop();
                    }
                }
                else{
                    while(getPriority(infix[i]) < getPriority(char_stack.top()))
                    {
                        output += char_stack.top();
                        char_stack.pop();
                    }
                }
                char_stack.push(infix[i]);
            }
        }
    }
    while(!char_stack.empty()){
        output += char_stack.top();
        char_stack.pop();
    }
    return output;
}
 
std::string infixToPrefix(std::string infix){
    int l = infix.size();
 
    reverse(infix.begin(), infix.end());
 
    for(int i = 0; i < l; ++i){
        if(infix[i] == '('){
            infix[i] = ')';
            ++i;
        }
        else if(infix[i] == ')'){
            infix[i] = '(';
            ++i;
        }
    }
    //std::cout << "Current infix expression is " << infix << std::endl;
    std::string prefix = infixToPostfix(infix);
    //std::cout << "Current prefix expression is " << prefix << std::endl;
    reverse(prefix.begin(), prefix.end());
    return prefix;
}
 
int main(const int argc, char** argv)
{	
	if(argc != 2){
		assert(false);
	}
	std::string myString = static_cast<std::string> (argv[argc-1]);
	std::string preStr = infixToPrefix(myString);
	std::cout << preStr << "\n" << std::endl; 
	ParseExpression(preStr);
	//std::cout << infixToPostfix(myString) << std::endl; 
    	return 0;
}
