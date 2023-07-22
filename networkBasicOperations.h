#ifndef _NETWORKBASICOPERATIONS_H_
#define _NETWORKBASICOPERATIONS_H_

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cstdint>

class networkBasicOperations
{
    std::string ipAdd;
    std::vector<uint8_t> ipArray;
public:

     networkBasicOperations(std::string &&ip);
     networkBasicOperations(std::vector <uint8_t>& ipA);
     
     
     std::string printIp(){
         return ipAdd;}
         
     void printIpArray(){
         for(size_t i=0; i < ipArray.size(); i++){
             std::cout << ipArray[i] << std::endl;}}
         
     std::string getinString();
     
     networkBasicOperations operator|(networkBasicOperations &subnetmask);
     
     networkBasicOperations operator&(networkBasicOperations &subnetmask);
     
     friend networkBasicOperations operator~(networkBasicOperations &rhs);
     
     networkBasicOperations operator^(networkBasicOperations &subnetmask);
     
      
    ~networkBasicOperations();

};

#endif // _NETWORKBASICOPERATIONS_H_
