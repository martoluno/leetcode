#include<iostream>
#include<vector>
using namespace std;
class Sort
{
public:
    void sort(int a[],int n){
        int h=n/3;
        while (h>=1)
        {
            for(int i=h;i<n;i++){
                for(int j=i;j>=h && a[j]<a[j-h];j-=h){
                    swap(a[j],a[j-h]);
                    print(a,n);
                }
            }
            h=h/3;
        }
        
    }
    void print(int a[],int n){
        for(int i=0;i<n;i++){
            cout<<a[i]<<' ';
        }
        cout<<endl;
    }
};
int main(){
    int a[10]={8,9,1,7,2,3,5,4,6,0};
    Sort A;
    A.sort(a,10);
}
