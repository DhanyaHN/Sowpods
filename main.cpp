#include <iostream>
#include <fstream>
#include <string.h>
#include <unordered_map>
#include <algorithm>

using namespace std;
unsigned long int hashFunction(string word){
    int i;
    unsigned long int key = 1;
    int arrayOfPrimeNumbers[26] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

    for (i = 0;i < word.size(); i++) {
       int index =  word[i]-'a';
       key *= arrayOfPrimeNumbers[index];
    }
    return key;

}

int countSpace(string word)
{
    int count = 0;
    for ( int i = 0;i < word.size() ; i++ ){
        if( word[i] == ' ')
            count++;
    }
    return count;
}
int main () {
    ofstream outFile ("output.txt");
    string line;
    ifstream myfile ("sowpods.txt");
    int c = 0;
    unordered_map <unsigned long int, string> map;
    string out = "";
    if (myfile.is_open()) {
        while ( getline (myfile,line) ) {
            if ( c > 1 ) {
                unsigned long int hashcode= hashFunction(line);
                map[hashcode]= map[hashcode] + line+" ";
            }
            else {
                c++;
            }
        }
        myfile.close();
        int count = 0;
        for ( unsigned i = 0; i < map.bucket_count(); ++i) {
            for ( auto local_it = map.begin(i); local_it!= map.end(i); ++local_it ) {
                string s = local_it->second;
                if ( countSpace(s) >= 2 ) {
                    count++;
                    out = local_it->second + "\n";
                    outFile << out;
                }
            }
        }
        outFile << count << endl;
   }
   else {
       cout << "Unable to open file";
   }
   outFile.close();
   return 0;
}
