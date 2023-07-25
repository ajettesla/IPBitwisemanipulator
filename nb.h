#ifndef _NB_H_
#define _NB_H_

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cstdint>

class nb
{
    std::string ipAdd;
    std::vector<uint8_t> ipArray;
public:

     nb(std::string &&ip);
     nb(std::vector <uint8_t>& ipA);
     
     
     std::string printIp(){
         return ipAdd;}
         
     void printIpArray(){
         for(size_t i=0; i < ipArray.size(); i++){
             std::cout << ipArray[i] << std::endl;}}
             
      int getMaskNumber();
      
     int getMaskNumber();
     std::string getMaskstring();
         
     std::string getinString(int num);
     
     nb operator|(nb &subnetmask);
     
     nb operator&(nb &subnetmask);
     
     friend nb operator~(nb &rhs);
     
     nb operator^(nb &subnetmask);
     
     bool operator==(nb &rhs);

     nb operator>>(int &&rhs);
     
     
     nb operator<<(int &&rhs);          
      
    ~nb();

};

#endif // _NB_H_
