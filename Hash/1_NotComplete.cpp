#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef struct 
{
    string key;
    int num_of_people;
    int pass;
} item;

int hash_function (string key, int entrySize)
{
    int sum = 0;
    
    for(auto &it : key)
    {
        sum += it;
    }
    
    return sum % entrySize;
}

string solution(vector<string> participant, vector<string> completion) {
    const int entrySize = 100000;
    string answer = "";
    
    vector<item> HashTable(entrySize);
       
    // participant
    for (int i = 0; i < participant.size(); i++)
    {
        int index = hash_function(participant[i], entrySize);
        
        if (HashTable[index].key.empty())
        {
            HashTable[index].key = participant[i];
            HashTable[index].num_of_people = 1;
            HashTable[index].pass = 0;
        }
        else
        {
            HashTable[index].num_of_people++;
        }
    }
    
    // completion 
    for (int i = 0; i < completion.size(); i++)
    {
        int index = hash_function(completion[i], entrySize);
        
        if (!HashTable[index].key.empty())
        {
            HashTable[index].pass++;
        }
    }
    
    // result
    int result = 0;
    
    for (int i = 0; i < HashTable.size(); i++)
    {
        if (HashTable[i].key.empty())
            continue;
                
        if (HashTable[i].num_of_people - HashTable[i].pass != 0)
        {
            answer = HashTable[i].key;
            break;
        }
    }
    
    return answer;
}