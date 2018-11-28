#include <iostream>
#include <string>
#include <fstream>
 
class node
{
	public:
	std::string key;
	std::string word;
	node* next;
	node(std::string val1, std::string val2)
	{
		key = val1;
		word = val2;
		next = NULL;
	};
};
 
class hash 
{
	private:
	    node** hashMatrix;
	    unsigned int size;
	public:
	    hash(unsigned int s)
	    {
		hashMatrix = new node*[s]();
		size = s;
	    }
	    ~hash()
	    {
		delete[] hashMatrix;
	    }
	    
	    void put(std::string key, std::string word)
	    {
		unsigned int id = hashFunc(key);
		node* linkToList = hashMatrix[id];
		if (linkToList != NULL)
		{  
		    if (linkToList->key == key)
		    {
		        linkToList->word = word;
		    }
		    else
		    {
		        while (linkToList->next != NULL && linkToList->next->key != key)
		        {
		            linkToList = linkToList->next;
		        }
		        if (linkToList->next == NULL)
		        {
		            linkToList->next = new node(key, word);
		        }
		        else
		        {
		            linkToList->next->word = word;
		        }
		    }
		}
		else
		{
		    hashMatrix[id] = new node(key, word);
		}
	    }
	   
	    std::string get(std::string key)
	    {
		unsigned int id = hashFunc(key);
		node* linkToList = hashMatrix[id];
		while (linkToList != NULL)
		{
		    if (linkToList->key == key)
		    {
		        return linkToList->word;
		    }
		    else
		    {
		        linkToList = linkToList->next;
		    }
		}
		return "none";
	    }
	    
	    void deleteKey(std::string key)
	    {
		unsigned int id = hashFunc(key);
		node* linkToList = hashMatrix[id];
		node* prev = NULL;
		while (linkToList != NULL)
		{
		    if (linkToList->key != key)
		    {
		        prev = linkToList;
		        linkToList = linkToList->next;
		    }
		    else
		    {
		        if (prev != NULL)
		        {
		            prev->next = linkToList->next;
		        }
		        else
		        {
		            hashMatrix[id] = linkToList->next;
		        }
		        delete linkToList;
		        break;
		    }
		}
	    }
	    
	    int hashFunc(std::string value)
	    {
		int hash = 0;
		for (int i = 0; i < value.size(); i++)
		{
		    hash = value[i] + 13 * hash;
		}
		return hash % size;
	    }
};
 
int main()
{
    hash HASH(100000);
    std::string command;
    std::string key;
    std::string word;
 
    std::ifstream input("map.in");
    std::ofstream output("map.out");
 
    while (input >> command)
    {
        input >> key;
 
        if (command == "put")
        {
            input >> word;
            HASH.put(key, word);
        }
        else if (command == "get")
        {
            output << HASH.get(key) << '\n';
        }
        else if (command == "delete")
        {
            HASH.deleteKey(key);
        }
    }
    input.close();
    output.close();
    return 0;
}
