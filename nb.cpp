#include "nb.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>
#include <cstdint>
#include <bitset>

nb::nb(std::string &&ip)
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

nb::nb(std::vector <uint8_t>& ipA)
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


int nb::getMaskNumber(){
    std::stringstream test(this->ipAdd);
    std::string te;
    char delimiter = '.';
    std::string segment;
    while(std::getline(test, segment, delimiter)){
             int temp = stoi(segment);
           te = te + (std::bitset<8>(temp)).to_string();
           std::cout << temp << std::endl;
           std::cout << te << std::endl;
             }
     const char *b = te.c_str();
     int number {0};
     for(size_t i= 0 ; i < std::strlen(b); i++){
       std::string m = std::string(1,b[i]);
       int j = std::stoi(m);
       if(j == 1){
           number += 1;
           }
       
     }
     
     return number;     
     }
     
std::string nb::getMaskstring(int num){
    std::string subnet;
    for(size_t i=0; i < 32 << i++){
        if(num > 0){
            subnet = subnet + "1";
            }
        else {
            subnet = subnet + "0";}

         }
         std::cout << subnet << std::endl;
    return subnet;
    }




std::string nb::getinString(){
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
    
nb nb::operator|(nb &subnetmask){
    std::vector <uint8_t> orGate;
    for(size_t i=0 ; i < this->ipArray.size(); i++){
         orGate.push_back(ipArray[i]|subnetmask.ipArray[i]);
        }
    nb temp(orGate);
    return temp;
    }

nb nb::operator&(nb &subnetmask){
    std::vector <uint8_t> andGate;
    for(size_t i=0 ; i < this->ipArray.size(); i++){
         andGate.push_back(ipArray[i]&subnetmask.ipArray[i]);
        }
    nb temp(andGate);
    return temp;
    }

nb nb::operator^(nb &subnetmask){
    std::vector <uint8_t> xorGate;
    for(size_t i=0 ; i < this->ipArray.size(); i++){
         xorGate.push_back(ipArray[i]^subnetmask.ipArray[i]);
        }
    nb temp(xorGate);
    return temp;
    }

nb operator~(nb &rhs){
    std::vector <uint8_t> negationGate;
    for(size_t i=0 ; i < rhs.ipArray.size(); i++){
         negationGate.push_back(~(rhs.ipArray[i]));
        }
        nb temp(negationGate);
return temp;}
        

nb nb::operator<<(int &&rhs){
    std::vector<uint8_t> vtemp;
    std::string temp1;
    for(size_t i=0; i < this->ipArray.size(); i++){
        temp1 = temp1 + std::bitset<8>(this->ipArray[i]).to_string();
        }
        std::bitset<32> bits(temp1);
        bits = bits << rhs;
        for(size_t j=1; j < 5 ; j++){
            int k = (j-1)*8;
        std::bitset<8> bitset(bits.to_string().substr(k,8));
        uint8_t value = static_cast<uint8_t>(bitset.to_ulong());
        vtemp.push_back(value);}
        nb vec(vtemp);
        return vec;}
        
        
nb nb::operator>>(int &&rhs){
    std::vector<uint8_t> vtemp;
    std::string temp1;
    for(size_t i=0; i < this->ipArray.size(); i++){
        temp1 = temp1 + std::bitset<8>(this->ipArray[i]).to_string();
        }
        std::bitset<32> bits(temp1);
        bits = bits >> rhs;
        for(size_t j=1; j < 5 ; j++){
            int k = (j-1)*8;
        std::bitset<8> bitset(bits.to_string().substr(k,8));
        uint8_t value = static_cast<uint8_t>(bitset.to_ulong());
        vtemp.push_back(value);}
        nb vec(vtemp);
        return vec;}


bool nb::operator==(nb &rhs){
     if((rhs.printIp() == this->printIp())==0){
         return true;}
      else {          
          return false;}
    }
    

nb::~nb()
{
}

