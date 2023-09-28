#pragma once
#include <string>
template < typename T >

class IntersectionContainer{
public:
SafeArray < T > Intersection;
bool added = false;
//--
void add(SafeArray < T > a){
    if (added == false){
        for (int i = 0; i < a.size(); i++){
            Intersection.push_back(a[i]);
        }
        added = true;
    }
    else {
        SafeArray < T > newAr;
        for (int i = 0; i < Intersection.size(); i++){
            for (int j = 0; j < a.size(); j++){
                if (Intersection[i] == a[j]){
                    newAr.push_back(a[j]);
                }
            }
        }
        Intersection = newAr;
    }

}
//--
SafeArray < T >& getCommonElements(){
    return Intersection;
}
//--
bool look(string d, char c){
    for (int i = 0; i < 5; i++){
        if (d[i] == c) return true;
    }
    return false;
}
//--
void printersection(){
    for (int i = 0; i < Intersection.size(); i++){
        int count = 0;
        for (int j = 0; j < 5; j++){
            if (Intersection[i][j] == 'l') count++;
            else if (Intersection[i][j] == 'o') count++;
            else if (Intersection[i][j] == 'a') count++;
            else if (Intersection[i][j] == 'r') count++;
        }
        if (count >= 4) cout << Intersection[i] << endl;
    } 
}
private:
};