#include <string>
#include <map>
#include <iostream>
#include <fstream>


class Env
{
private:
    std::map<std::string, std::string> envMap;

public:
    Env(std::string path);
    std::map<std::string,std::string> getEnvMap();
    std::string getVal(std::string key);

    ~Env();
};

Env::Env(std::string path)
{
    std::string line, currentVar, currentVal;
    std::ifstream envfile(path);
    if (envfile.is_open())
    {
        while (getline(envfile, line))
        {
            
            /* 
            general rules of env files:
            var=val
            # ->ignore
            blank line ->ignore
            */
           if(!(line.length()<2||line[0]=='#')){
               //std::cout << line << '\n'; 
                size_t found = line.find('=');//get first delimer of line
                if (found != std::string::npos){
                //std::cout << "First occurrence is " << found << std::endl;
                currentVar=line.substr(0,found);
                currentVal=line.substr(found+1,line.length());
                std::cout<<"ck: "<<currentVar<<"; cv: "<<currentVal<<std::endl;
                envMap.insert(std::pair<std::string, std::string>(currentVar, currentVal));
                }

           }
        }
        envfile.close();
    }

    else
        std::cout << "Unable to open env file";
}

Env::~Env()
{
    envMap.empty();
}

std::map<std::string, std::string> Env::getEnvMap(){
    return envMap;
}
std::string Env::getVal(std::string key){
  //void function(const MAP &map, const std::string &findMe) {
    try
    {
        /* code */ 
        const std::string& value = envMap.at(key);
        //std::cout << "Value of key \"" << key.c_str() << "\": " << value.c_str() << std::endl;
        // TODO: Handle the element found.
        return value.c_str();
    }
    catch(const std::exception& e)
    {
        //std::cerr << e.what() << '\n';
        std::cerr << "LibEnvCPP: Key " << key << "not found"<<std::endl;
        
    }
    
       
    

}