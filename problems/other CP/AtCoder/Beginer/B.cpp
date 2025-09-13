#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int N, Q, c1, c2;
    cin >> N >> Q;

    string s;
    for(int i = 0; i < N; i++) s += (char)('A' + i);

    for(int i = 0; i < N - 1; i++) for(int j = i + 1; j < N; j++){
        cout << "? " << s[i] << " " << s[j] << endl;
        fflush(stdout);
        char ans; cin >> ans;
        if(ans == '>') swap(s[i], s[j]);
    }

    cout << "! " << s << endl;
    fflush(stdout);

    return 0;
}