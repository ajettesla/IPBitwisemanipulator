#include "networkBasicOperations.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>
#include <cstdint>

networkBasicOperations::networkBasicOperations(std::string &&ip)
:ipAdd{ip}
{        
         std::stringstream test(ip);
         char delimiter = '.';
         std::string segment;
         while(std::getline(test, segment, delimiter)){
             int temp = stoi(segment);
             ipArray.push_back(temp);
             }
    
}




networkBasicOperations::networkBasicOperations(std::vector <uint8_t>& ipA)
:ipArray{ipA}{ 
    
      std::vector<uint8_t> vec = ipArray;
      std::string ipString;
    for(size_t i = 0 ; i < vec.size() ; i++){        
        if(i == vec.size()-1){
            ipString = ipString + std::to_string(vec[i]);
            }
        else{
            ipString = ipString + std::to_string(vec[i]) + '.';
            }
        }
     ipAdd =  ipString;  
    }

  




std::string networkBasicOperations::getinString(){
      std::vector<uint8_t> vec {ipArray};
      std::string ipString;
    for(size_t i = 0 ; i < vec.size() ; i++){        
        if(i == vec.size()-1){
            ipString = ipString + std::to_string(vec[i]);
            }
        else{
            ipString = ipString + std::to_string(vec[i]) + '.';
            }
        }
        return ipString;
    }
    
networkBasicOperations networkBasicOperations::operator|(networkBasicOperations &subnetmask){
    std::vector <uint8_t> orGate;
    for(size_t i=0 ; i < this->ipArray.size(); i++){
         orGate.push_back(ipArray[i]|subnetmask.ipArray[i]);
        }
    networkBasicOperations temp(orGate);
    return temp;
    }

networkBasicOperations networkBasicOperations::operator&(networkBasicOperations &subnetmask){
    std::vector <uint8_t> andGate;
    for(size_t i=0 ; i < this->ipArray.size(); i++){
         andGate.push_back(ipArray[i]&subnetmask.ipArray[i]);
        }
    networkBasicOperations temp(andGate);
    return temp;
    }

networkBasicOperations networkBasicOperations::operator^(networkBasicOperations &subnetmask){
    std::vector <uint8_t> xorGate;
    for(size_t i=0 ; i < this->ipArray.size(); i++){
         xorGate.push_back(ipArray[i]^subnetmask.ipArray[i]);
        }
    networkBasicOperations temp(xorGate);
    return temp;
    }

networkBasicOperations operator~(networkBasicOperations &rhs){
    std::vector <uint8_t> negationGate;
    for(size_t i=0 ; i < rhs.ipArray.size(); i++){
         negationGate.push_back(~(rhs.ipArray[i]));
        }
        networkBasicOperations temp(negationGate);
        return temp;}

networkBasicOperations::~networkBasicOperations()
{
}

