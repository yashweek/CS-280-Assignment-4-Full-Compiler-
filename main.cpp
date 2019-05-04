//
//  main.cpp
//  assignment3
//
//  Created by Yashwee Kothari on 3/23/19.
//  Copyright © 2019 Yashwee Kothari. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "tokens.h"
#include "gettoken.h"
#include "parse.h"
#include "tree.h"

using namespace std;
int line = 0;
istream *input = &cin;
ifstream inFile;

int main(int argc, const char * argv[]) {
    
    for(int i =1; i<argc; i++){
        
        string vari(argv[i]);
        
            if (i == argc-1){
            
            inFile.open(vari);
            
            if( inFile.is_open() == false ) {
                cerr << "COULD NOT OPEN "<< vari << endl;
                return -1;
            }
            input = &inFile;
        }
        
        else{
            
            cerr << "TOO MANY FILENAMES" <<endl;
            return -1;
        }
        
        
        
    }
    
     ParseTree *tree = Prog(*input,line);
    if(tree ==0){
    //null 
    
    }
    
    if(tree !=0){
        
        
        
        
        try {
       tree->Eval();
            }
        catch( std::logic_error& e ) {
        cout << "RUNTIME ERROR " << e.what() << endl;
        
       }
        
        
        
        //traverse tree 
     /*   
       if(tree->NodeCount()!= 0){ 
        cout<<"NODE COUNT: " << tree->NodeCount()<<endl;
        }
        
        if((tree->NodeCount()- tree->leaves())!= 0){ 
        cout<<"INTERIOR COUNT: " << (tree->NodeCount()- tree->leaves())<< endl;
        }
        
        if(tree->ops()!= 0){ 
        cout<<"OPS COUNT: " << tree->ops()<<endl;
        }
        
        if(tree->strings()!= 0){ 
        cout<<"STRING COUNT: " << tree->strings()<<endl;
        }
        
        if(tree->maxdepth()!= 0){ 
        cout<<"MAX DEPTH: " << tree->maxdepth()<<endl;
        } */
       
    }
 
   
    return 0;
}
