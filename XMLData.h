#include <iostream>
#include <string>
using namespace std;
class XMLData {
    string tag;
    unsigned int line;
    int size;
    //bool open;
    bool isValid(){//this is a necessary helper function. Do not use other methods is tag is not valid
        int size=tag.size();
        if (tag[0]=='<' && tag[size-1]=='>'){
             return true;
        }
        return false;
    }
    public:
    XMLData(string obj, unsigned int line_number){
        tag=obj;
        line=line_number;
        size=tag.size();
        if (!isValid){
            cout<<"This is not a valid tag. \n";
            cout<<"String: "<<tag<<endl;
            cout<<"Line number: "<<line<<endl;
        }
    }
    bool isHeader(){
        
        if (tag.substr(0, 2)=="<?"&&tag.substr(size-2,2)=="?>"){
            return true;
        }
        return false;
    }
     bool isComment(){
        
        if (tag.substr(0, 4)=="<!--"&&tag.substr(size-2,3)=="-->"){
            return true;
        }
        return false;
    }
    
    bool checkIfOpen(){
        if (tag[1]=='/'){
            //open=0;
            return false;
        }
        //open=1;
        return true;
    }
    bool quotesBalanced(){
        int count=0;
        for (int i=0;i<size;i++){
            if (tag[i]=='\"')
                count++;
        }
        if (count%2==0)
            return true;
        return false;
    }

};