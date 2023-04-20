#include <iostream>
#include <vector>
#include <variant>
using namespace std;

struct HashTable
{
    vector <vector<int>> hashTable; //Using a two-dimensional vector to give structure to our hash table;
    
    void createHashTable() //Used to build our hash table 
    {
        cout << "How many buckets do you wish your hash table to have?" << endl;
        
        int noOfBuckets;
        cin >> noOfBuckets;
        
        hashTable.resize(noOfBuckets);
    }
    
    int hashFunction(int key) //Our simple hash function
    {
        return key % 3;
    }
    
    void insertKey(int key) //Used to insert a given value into the hash table after processing it through the hash function
    {
        int hashIndex = hashFunction(key);
        
        hashTable[hashIndex].push_back(key); //Inserts key into table at hash index obtained from hash function.
    }
    
    void displayHashTable()
    {
        for (int hashIndex = 0; hashIndex < hashTable.size(); hashIndex++)
        {
            cout << hashIndex << " : ";
            
            for (int data = 0; data < hashTable[hashIndex].size(); data++)
            {
                cout << hashTable[hashIndex][data] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
   HashTable ht;

   ht.createHashTable();

   ht.insertKey(2);
   ht.insertKey(3);
   ht.insertKey(9);
   ht.insertKey(8);

   ht.displayHashTable();

    return 0;
}
