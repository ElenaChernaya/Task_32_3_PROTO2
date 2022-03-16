#include <iostream>
#include "nlohmann/json.hpp"
#include <fstream>
#include <map>

using json = nlohmann::json;

struct Company
{
    std::string name = "Intel";
    int year_of_creation = 1968;
    std::string the_address = "2200 Mission College Boulevard, RNB-4-151, Santa Clara, US-CA 95054";

    std::map<std::string, std::vector<std::string>> matier = {
            {"Manufacturer",
                     {"processors",
                        "microprocessors",
                        "flash memory",
                        "SSD drives",
                        "chipsets",
                        "network equipment",
                        "motherboards",
                        "servers"}}};
};


void add()
{
   Company company;
   std::ofstream file("company.json");
   json dict;
   dict["name"] = company.name;
   dict["year of creation"] = company.year_of_creation;
   dict["the address"] = company.the_address;



   for (auto it = company.matier.begin(); it != company.matier.end(); ++it)
   {
       dict[it->first].push_back(it->second);
   }

   file << dict;

   file.close();
}

void read()
{
    std::ifstream file("company.json");
    json dict;
    file >> dict;
    std::cout << dict.dump(4) << std::endl;
}

int main() {
    add();
    read();
    return 0;
}
