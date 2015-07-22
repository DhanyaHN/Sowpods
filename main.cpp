// reading a text file
#include <iostream>
#include <fstream>
#include <string.h>
#include <unordered_map>

using namespace std;
unsigned long int hashFunction(string word){
     int i;
     unsigned long int key = 1;
     int arrayOfPrimeNumbers[26] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
     for (i=0;i<word.size();i++){
        int index = 'a' - word[i];
        key *= arrayOfPrimeNumbers[index];
     }
     return key;

}

int main () {
//    int primeNumber[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,101};
//	unordered_map <string, string> map;
//
//	map["foo"] = "hello";
//	map["foo"] = "hello1";
//	map["foo1"] = "hello2";
//	//if(map[]
//cout << map["foo"] << endl;
//cout << map["foo1"] << endl;
//  int primeNumber[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,101};


    string line;
    ifstream myfile ("sowpods.txt");
    int count=0;
    unordered_map <unsigned long int, string> map;
    if (myfile.is_open()) {
        while ( getline (myfile,line) ) {
            //cout << line << '\n';
            unsigned long int hashcode= hashFunction(line);
            cout << line <<"   "<<hashcode;

            map[hashcode]= map[hashcode] +" "+ line;
            cout << map[hashcode] << endl;
            // TODO process the inp here
//            int key = hashFunction(word);
//            string wordOfSameKey = hashTable.find(key);
//            wordOfSameKey = wordOfSameKey + word;
//            hashTable.insert(make_pair(key, wordOfSameKey));
            count++;
            if(count==3)
                    break;
        }
        myfile.close();

        for ( unsigned i = 0; i < map.bucket_count(); ++i) {
            std::cout << "bucket #" << i << " contains:";
            for ( auto local_it = map.begin(i); local_it!= map.end(i); ++local_it )
            std::cout << " " << local_it->first << ":" << local_it->second<<endl;
            std::cout << std::endl;
        }
    }
    else {
        cout << "Unable to open file";
    }
    return 0;
}
