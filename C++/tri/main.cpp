#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> vec(1, 1);
    vector<int> prevec;
    
    for (int i = 0; i < n; i++) {
        prevec = vec;

        
        for (int j = 0; j < (n - i) * 2; j++) {
            cout << ' ';
        }

        for (auto v: vec) {
            cout.width(4);
            cout << v;
        }
        cout << endl;

        vec.clear();
        vec.push_back(1);

        for (int j = 1; j < prevec.size(); j++) {
            vec.push_back(prevec[j - 1] + prevec[j]);
        }
        
        vec.push_back(1);
    }
    
    system("pause");
    return 0;
}