#include <bits/stdc++.h>
using namespace std;
int func(vector<string> &b,int x,int y){
    static int count=0;
    stack<int,int> s;
    for (int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j) {
            if(b[i][j]=='k'){
                stack.push(make_pair(i,j));
            }
        }
    }
    
}
int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        cin >> n;
        vector<string> board(n);
        for(int board_i = 0; board_i < n; board_i++){
           cin >> board[board_i];
        }
        func(board,n-1,n-1);

    }

    return 0;
}
