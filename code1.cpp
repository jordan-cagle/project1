#include <random>
#include <cmath>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <cstdlib>

int math();

int main(int argc, char **argv) 
{
    int array[101] = {0};
    std::ofstream fout;
    int in;
    int i;
    int amount = std::stoi(argv[2]);
    double average = 0;
    int clicks = 0;
    int highest = 0;
    int highest_at = 0;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    if (argc != 3) //checking to see if enough parts are here for the exe to run
    {
        std::cout << "code1.exe <text file> <amount of runs>" << std::endl;
        return 0;
    }
    
    fout.open(argv[1]);
    if (!fout.is_open()) 
    {
        std::cout << "Unable to open the file: " << argv[1] << std::endl;
        return 0;
    }
    
    for (i = 0; i < amount; i++) 
    {
        in = math();
        array[in]++;
        if (highest < in) {
            highest = in;
            highest_at = i;
        }
    }
    
    for (i = 0; i < 101; i++) \
    {
        clicks = array[i] * i + clicks;
    }
    
    average = static_cast<double>(clicks) / amount;
    
    fout << "amount of runs: " << amount << std::endl;
    fout<< "total clicks: " << clicks << std::endl;
    fout << "average: " << average << std::endl;
    fout << "highest: " << highest << std::endl;
    fout << "highest happened at: " << highest_at << std::endl;
    
    for (i = 0; i < 101; i++) 
    {
        fout << "times it failed at " << i << ": " << array[i] << std::endl;
    }
    
    fout.close();
    return 0;
}

int math() 
{
    bool good = true;
    int count = 0;
    int random;
    
    
    while (good) 
    {
        random = std::rand() % 100;
        if (count > random) {
            good = false;
            return count;
        }
        count++;
    }
    return count;
}

