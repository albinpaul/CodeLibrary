#include <iostream>
#include <vector>
using namespace std;
void displayPathtoPrincess(int n, vector <string> grid){
    //your logic here
    int i ,j ,p,q;
    if(grid[0][0]=='p'){i=0;j=0;}
    if(grid[0][n-1]=='p'){i=0;j=n-1;}
    if(grid[n-1][0]=='p'){i=n-1;j=0;}
    if(grid[n-1][n-1]=='p'){i=n-1;j=n-1;}
    for(int g=0;g<n;g++){
        for(int h=0;h<n;h++){
            if(grid[g][h]=='m'){
                p=g;q=h;
                break;
            }
        }
    }
    while(g<i){
        cout<<"DOWN"<<endl;
        g++;
    }
    while(g>i){
        cout<<"UP"<<endl;
        g--;
    }
    while(h<j){
        cout<<"RIGHT"<<endl;
        h++;
    }
    while(h>j){
        cout<<"LEFT"<<endl;
        h--;
    }
}
int main(void) {

    int m;
    vector <string> grid;

    cin >> m;

    for(int i=0; i<m; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    displayPathtoPrincess(m,grid);

    return 0;
}

