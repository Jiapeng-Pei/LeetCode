#include <stdio.h>
#include <unordered_map>
#include <iostream>

using namespace::std;

int main()
{
    unordered_map<string, double> 
        myRecipe, 
        myPantry = {{"milk", 2.0}, {"flour", 1.5}};

    pair<string, double> myshopping("baking powder", 0.3);

    myRecipe.insert(myshopping);
    myRecipe.insert(make_pair("eggs", 6.0));
    myRecipe.insert(myPantry.begin(), myPantry.end()); 
    myRecipe.insert({"bread", 3.3});

    cout << "My Recipe contains: " << endl;
    for (auto& x : myRecipe) 
        cout << x.first << ": " << x.second << endl;
    
    myRecipe.erase("bread123");
    myRecipe.erase("egg");
    
    cout << "My Recipe contains: " << endl;
    for (auto& x : myRecipe) 
        cout << x.first << ": " << x.second << endl;
    cout << endl;
    return 0;
}