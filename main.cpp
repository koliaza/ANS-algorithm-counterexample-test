#include <iostream>
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include <random>
#include "tools.h"
using namespace std;

class element{
public :
    int number;
    int order;
    int target;
    element(){}
    bool chosen;
    int radius;
    int ranki;

};


float svensontest(int repeat, int n)
{
                                                    // DEFINITIONS

//n is max 23 on my desktop
    float sumd = 0;
    int m = myPow(2,n);
      std::vector<int> permvectorc;
    std::vector<int> permvectorf;
    for (int i=1; i<=m; ++i) permvectorc.push_back(i);
    for (int i=1; i<=(m-1); ++i) permvectorf.push_back(i);
 element *clients= new element[m];
   element *facilities= new element[m];



for (int rep =0;rep<repeat;rep++){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle ( permvectorc.begin(), permvectorc.end(), std::default_random_engine(seed) );
    std::shuffle ( permvectorf.begin(), permvectorf.end(), std::default_random_engine(seed) );

    // definition and ordering
       for (int i=0; i<m; ++i) {
            clients[i].number=i;
          clients[i].order=permvectorc[i]-1;
          clients[i].chosen=false;
    }


    for (int i=0; i<(m-1); ++i) {
            facilities[i].number=i;
          facilities[i].order=permvectorf[i]-1;
          facilities[i].chosen=false;
          facilities[i].radius=0;
          facilities[i].ranki=rankit(i);
    }

    //first target finding

for (int i=0; i<m; ++i) {
    int a=m;
    int b=0;
    int c=0;
    for (int j = 0;j<n;j++){
            c=(i % myPow(2,j))+myPow(2,j)-1;
            if (facilities[c].order <a ) {b=c; a=facilities[c].order;};


    }
    clients[i].target=b;
    }


for (int i=0; i<m-1; ++i) {
    int a=m;
    int b=0;
    for (int j=(i-myPow(2,facilities[i].ranki)+1);j<m;j=(j+myPow(2,facilities[i].ranki))){
            if (clients[j].order <a ) {b=j; a=clients[j].order;};


    }
    facilities[i].target=b;
    if (clients[b].target==i) {facilities[i].chosen=true;};
    }

    // target following
for (int i=0; i<m; ++i) {
    int dist=0;
   while (facilities[clients[i].target].chosen == false){
    clients[i].target = clients[facilities[clients[i].target].target].target;
    }
    dist=distance(clients[i].target, i,n);
  //std::cout << i << ' '<< j <<' '<< b<< ' '<< ' '<< dist << '\n';

    if (dist>facilities[clients[i].target].radius) {facilities[clients[i].target].radius=dist;};

    }

    //distance sum
for (int i=0; i<m-1; ++i) {
    if (facilities[i].chosen) {sumd=sumd+facilities[i].radius;}
}




}

  //std::cout << "end, the price was " <<  <<'\n';
    return sumd/(myPow(2,n)*repeat);
}

int main (){
   // treetest(3);
   // treetest2();
   float aaa=0;
   float bbb=0;
   float ccc=0;
   float ddd=0;
   for (int i=17; i<19; ++i) {
        cout<< "\n i = " << i << "\n";


            ccc= svensontest(1000,i);
            bbb=ccc;
            ddd=ccc;
            aaa=0;
     for (int j=1; j<10; ++j) {
            ccc= svensontest(1000,i);
            aaa=aaa+ccc;
            bbb=min(bbb,ccc);
            ddd=max(ddd,ccc);
            }

        cout<< "average is " << (aaa/10) << " and difference is " << (ddd-bbb);
   }

return 0;
}
