#include <iostream>
#include <string>
#include <cassert>
#include <map>

using namespace std;


//Append value to the end of each of the n elements of the array and return n.
int appendToAll(string a[], int n, string value){

    if(n<0){
        return -1;
    }

    //iterate through n strings of a[]
    for (int k = 0; k < n; k++){
        a[k].append(value);
    }
    return n;
}

//Return the position of a string in the array that is equal to target; if there is more than one such string, return the smallest position number of such a matching string.
int lookup(const string a[], int n, string target){

    if(n<0){
        return -1;
    }

    //iterate through n strings of a[]
    for (int k = 0; k < n; k++){
        if(a[k] == target){
            return k;
        }
    }
    return -1;
}

//Return the position of a string in the array such that that string is >= every string in the array.
int positionOfMax(const string a[], int n){

    if(n <= 0){
        return -1;
    }

    string max = "";
    int maxPos = 0;

    //iterate through n strings of a[]
    for (int k = 0; k < n; k++){
        if(a[k] >= max){
            max = a[k];
            maxPos = k;
        }
    }
    return maxPos;
}


//Eliminate the item at position pos by copying all elements after it one place to the left.
int rotateLeft(string a[], int n, int pos){

    if(n < 0){
        return -1;
    }

    if(pos > n-1 || pos < 0){
        return -1;
    }

    if(n == 0){
        return 0;
    }



    string temp = a[pos];

    //iterate through n strings of a[]
    for (int k = pos; k < n -1; k++){
       a[k] = a[k +1];
    }
    a[n-1] = temp;
    return pos;
}


//Return the number of sequences of one or more consecutive identical items in a.
int countRuns(const string a[], int n){

    if(n<0){
        return -1;
    }

    std::map<string,int> m;

    //iterate through n strings of a[]
    for (int k = 0; k < n; k++){
        if(m.find(a[k]) != m.end()){
            m[a[k]]++;
        }
        else{
            m[a[k]] = 1;
        }

    }

    return m.size();
}


//Reverse the order of the elements of the array and return n.
int flip(string a[], int n){

    if(n<0){
        return -1;
    }


    //iterate through n strings of a[]
    for (int k = 0; k < n/2; k++){
        string temp = a[k];
        a[k] = a[n-1-k];
        a[n-1-k] = temp;
    }


    return n;
}


//Return the position of the first corresponding elements of a1 and a2 that are not equal.
int differ(const string a1[], int n1, const string a2[], int n2){

    if(n1<0 || n2 < 0){
        return -1;
    }

    int n3 = ((n1 < n2) ? n1 : n2);

    //iterate through n strings of a[]
    for (int k = 0; k < n3; k++){
        if(a1[k] != a2[k]){
            return k;
        }
    }

    return n3;
}

//If all n2 elements of a2 appear in a1, consecutively and in the same order, then return the position in a1 where that subsequence begins.
//If the subsequence appears more than once in a1, return the smallest such beginning position in the array.
int subsequence(const string a1[], int n1, const string a2[], int n2){

    if(n1<0 || n2 < 0){
        return -1;
    }

    int posOfMatch = -1;

    //iterate through n strings of a[]
    for (int k = 0; k < n1; k++){
        if(a2[0] == a1[k]){
            posOfMatch = k;
            for(int j = 0; j < n2; j++){
                if(a2[j] != a1[j+k]){
                    posOfMatch = -1;
                    break;
                }
            }
            return posOfMatch;

        }
    }

    return posOfMatch;
}


//Return the smallest position in a1 of an element that is equal to any of the elements in a2.
int lookupAny(const string a1[], int n1, const string a2[], int n2){

    if(n1<0 || n2 < 0){
        return -1;
    }


    //iterate through n strings of a[]
    for (int k = 0; k < n1; k++){

        for(int j =0; j < n2; j++){
            if(a2[j] == a1[k]){
                return k;
            }
        }
    }

    return -1;
}


//Rearrange the elements of the array so that all the elements whose value is < splitter come before all the other elements, and all the elements whose value is > splitter come after all the other elements
int split(string a[], int n, string splitter){

    if(n < 0){
        return -1;
    }

    int i;

    for(int j = 0; j < n-1; j++){
        int iMin = j;

        for(i = j+1; i < n; i++){
            if(a[i] < a[iMin]){
                iMin = i;
            }
        }

        if(iMin != j){
            swap(a[j], a[iMin]);
        }
    }

    //return a number
    for(int k=0; k< n; k++){
        if(a[k] >= splitter){
            return k;
        }
    }

    return n;
}


//print all strings in array to cerr
void printStringArray(string a[], int n){
    for(int i = 0; i < n; i++){
        cerr << a[i] << endl;

    }
}

int main()
{
    //edge call checks (negative int size -> -1) (0 size -> don't examine array)
    string a[4] = { "hakan", "alpay", "mioko", "ayca"};
    assert(appendToAll(a,-2,"D") == -1);
    assert(appendToAll(a,0,"H") == 0 && a[0] == "hakan" && a[3] == "ayca");

    string b[4] = { "hakan", "alpay", "mioko", "ayca"};
    assert(lookup(b,-2,"D") == -1);
    assert(lookup(b,2,"mioko") == -1);
    assert(lookup(b,4,"ayca") == 3);
    assert(lookup(b,3,"ALPAY") == -1);

    string c[4] = { "hakan", "alpay", "mioko", "ayca"};
    assert(positionOfMax(c,0) == -1);
    assert(positionOfMax(c,1) == 0);
    assert(positionOfMax(c,4) == 2);

    assert(rotateLeft(c,3,-1) == -1);
    assert(rotateLeft(c,0,3) == -1);
    assert(rotateLeft(c,-2,3) == -1);
    assert(rotateLeft(c,4,0) == 0 && c[0] == "alpay");

    assert(countRuns(b,-2) == -1);
    assert(countRuns(b,2) == 2);
    assert(countRuns(b,4) == 4);

    assert(flip(b,0) == 0 && b[0] == "hakan");
    assert(flip(b,-1) == -1 && b[0] == "hakan");
    assert(flip(b,4) == 4 && b[0] == "ayca" && b[1] == "mioko");

    string d[5] = {"hakan","alpay","mioko","ayca","mahmut"};
    assert(flip(d,5) == 5 && d[2] == "mioko");
    assert(flip(d,3) == 3 && d[0] == "mioko");

    assert(differ(c,0,d,0) == 0);
    assert(differ(c,2,d,0) == 0);
    assert(differ(c,0,d,2) == 0);





    string h[7] = { "selina", "reed", "diana", "tony", "", "logan", "peter" };
    assert(lookup(h, 7, "logan") == 5);
    assert(lookup(h, 7, "diana") == 2);
    assert(lookup(h, 2, "diana") == -1);
    assert(positionOfMax(h, 7) == 3);

    string g[4] = { "selina", "reed", "peter", "sue" };
    assert(differ(h, 4, g, 4) == 2);
    assert(appendToAll(g, 4, "?") == 4 && g[0] == "selina?" && g[3] == "sue?");

    string z[4] = { "selina", "reed", "peter", "sue" };
    rotateLeft(z,4,1);


    assert(rotateLeft(g, 4, 1) == 1 && g[1] == "peter?" && g[3] == "reed?");

    string e[4] = { "diana", "tony", "", "logan" };
    assert(subsequence(h, 7, e, 4) == 2);

    string x[5] = { "reed", "reed", "reed", "tony", "tony" };
    assert(countRuns(x, 5) == 2);

    string f[3] = { "peter", "diana", "steve" };
    assert(lookupAny(h, 7, f, 3) == 2);

    assert(flip(f, 3) == 3 && f[0] == "steve" && f[2] == "peter");

    assert(split(h, 7, "peter") == 3);

    assert(split(h, -1, "peter") == -1);

    cout << "All tests succeeded" << endl;

}
