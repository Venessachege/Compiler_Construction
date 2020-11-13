//include libraries
#include <iterator>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <regex>
#include <list>
#include <map>
using namespace std;

void lexer(string str){
        // patterns to be identified
    map<string,string> patterns {
        { "[0-9]+" ,   "Number" },
        { "[a-zA-Z]+" ,   "Identifier" },
        { "\\*|\\+|\\-|\\/|\\>|\\<|\\=|\\!",  "Operator" },
        { "\\,|\\(|\\)|\\;|\\{|\\}|\\[|\\]", "Separator"}
    };

    // store matched results
    map< size_t, pair<string,string> > matches;
   // loop through patterns and match string to pattern
    for ( auto pattern = patterns.begin(); pattern != patterns.end(); ++pattern )
    {
        regex r(pattern->first);
        auto words_begin = sregex_iterator( str.begin(), str.end(), r );
        auto words_end   = sregex_iterator();

        for ( auto it = words_begin; it != words_end; ++it )
            matches[ it->position() ] = make_pair( it->str(), pattern->second );
    }
    // output pattern and string
    for ( auto match = matches.begin(); match != matches.end(); ++match )
        cout<< match->second.first << " -" << match->second.second << endl;
}

int main(){
    string str = "Venessa Chege, Born on: 29/05, Age (22-1)";
    lexer(str);
}