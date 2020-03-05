#include<iostream>
#include<stack>
using namespace std;
int n,mi[100][100]; 
int path(int i, int j){
    if(j+ 1< n&&!mi[i][j+ 1])
        return 1;//右面能走 
    else if(i+ 1< n&& !mi[i+ 1][j])
        return 2;// 下面能走 
    else if(j- 1>= 0&&!mi[i][j- 1])
        return 3;//左边能走 
    else if(i- 1>= 0&&!mi[i- 1][j])
        return 4;//上面能走 
        return 0;
}
int main(){ 
    int t;
    int ii[]= {0, 0, 1, 0, -1};//CSDN给的思路 
    int jj[]= {0, 1, 0, -1, 0};//
    cin>>t;
    while(t--){
        cin>>n;
        stack <int> stx;
        stack <int> sty;
 
        for(int i= 0; i< n; i++)
        for(int j= 0; j< n; j++)
        cin>>mi[i][j];
 
        stx.push(0);
        sty.push(0);
        mi[0][0]= 1;
        int i= 0;
        int j= 0;
        while(1){
            int k= path(i, j);
     
            if(k){
                i+= ii[k];
                j+= jj[k];
                mi[i][j]= 1;
                stx.push(i);
                sty.push(j);
 
             }
            else if(!stx.empty()&&!sty.empty()){
                i= stx.top();
                j= sty.top();
                if(!path(i, j)){
                    stx.pop();
                    sty.pop();
                   }
        
             }
     
            if((stx.empty()&&sty.empty())|| (i== n-1&&j== n-1))
              break;
         } 
           
          if(stx.empty()&&sty.empty())
          {
            cout<<"no path"<<endl;
          }
          else{
              int lu[100];
              int length= 0;
              int l= 0;
               
            while(!stx.empty()&&!sty.empty()){
             length+= 2;
             lu[l++]= stx.top();
             lu[l++]= sty.top();
             stx.pop();
             sty.pop();
             }
              
             int flag= 1;
             for(int i=length-1;i>= 0;){
                 
                cout<<'['<<lu[i--]<<','<<lu[i--]<<']'<<"--";
                if((flag++)%4== 0)
                cout<<endl;
              }
              cout<<"END"<<endl;
           } 
        }
}
