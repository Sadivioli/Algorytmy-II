#include "dic.h"

using namespace std;

// https://stackoverflow.com/questions/440133/how-do-i-create-a-random-alpha-numeric-string-in-c
std::string gen_random(const int len) {
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";
	std::string tmp_s;
	tmp_s.reserve(len);
	
	for (int i = 0; i < len; ++i) {
		tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
	}
	
	return tmp_s;
}

int main(){
    
    Dictionary dictionaryA;
    Dictionary dictionaryB;

    srand(time(NULL));
    ofstream insert;
	ofstream remove;
    insert.open("ins.txt");
    remove.open("rm.txt");

    string setString = "Lorem ipsum dolor sit amet";
    string setString2 = "consectetur adipiscing elit";

    //inserting 10 randomly generated string for testing purposes to both dictionaries
    for(int i = 0; i < 10; i++){
        if (i == 7){
            dictionaryA.insert(setString);
        }
        string randomString = gen_random(50);
        dictionaryA.insert(randomString);
    }
    for(int i = 0; i < 10; i++){
        if (i == 6){
            dictionaryB.insert(setString2);
        }
        string randomString = gen_random(50);
        dictionaryB.insert(randomString);
    }

    //printing the dictionaries
    cout << "Dictionary A: " << endl;
    dictionaryA.printDictionary();

    cout << "\nDictionary B: " << endl;
    dictionaryB.printDictionary();

    //testing contains
    cout << "\nTesting contains: " << endl;
    cout << "Contains " << setString << " in dic A: " << dictionaryA.contains(setString) << endl;
    cout << "Contains " << setString2 << " in dic A: " << dictionaryA.contains(setString2) << endl;

    cout << "Contains " << setString << " in dic B: " << dictionaryB.contains(setString) << endl;
    cout << "Contains " << setString2 << " in dic B: " << dictionaryB.contains(setString2) << endl;

    //testing remove
    cout << "\nTesting remove: (only in dicA)" << endl;
    dictionaryA.remove(setString);

    cout << "\nDictionary A: " << endl;
    dictionaryA.printDictionary();

    cout << "\nDictionary B: " << endl;
    dictionaryB.printDictionary();

    //calculating the time it takes to insert and remove a string with a sample of 1000 tries
    //times of insertion and removal are printed to the files ins.txt and rm.txt
    //for testing purposes new dictionaries are created and inserted and removed 1000 times

    for(int i = 10; i < 1000; i++){
        
        Dictionary insertDic;

        for (int j = 0; j < i - 1; j++) {
			insertDic.insert(gen_random(50));
		}

        auto insertStart = std::chrono::system_clock::now();
        insertDic.insert(gen_random(50));
        auto insertEnd = std::chrono::system_clock::now();

        chrono::duration<double> insertTime = insertEnd - insertStart;
        insert << i << " " << insertTime.count() << endl;

    }

    for(int i = 10; i < 1000; i++){

    Dictionary removeDic;

    for (int j = 0; j < i - 1; j++) {
        removeDic.insert(gen_random(50));
    }

    auto removeStart = std::chrono::system_clock::now();
    removeDic.remove(gen_random(50));
    auto removeEnd = std::chrono::system_clock::now();

    chrono::duration<double> removeTime = removeEnd - removeStart;
    remove << i << " " << removeTime.count() << endl;

    }
    return 0;
}