
#include "tools.h"
// ALL PURPOSE
int myPow_helper(int x, int p, int result)
{
    if (p == 0)
    {
        return result;
    }
    else
    {
        return myPow_helper(x, p-1, result*x);
    }
}

int myPow(int x, int p)
{
    if (p<1) return 1;
    return myPow_helper(x, p, 1);
}

int rankit (int i)
{
    int k=0;
    while (i+2>myPow(2,k))
    {
        k++;
    };
    return k-1;
}
int distance(int i, int j, int n)  //facility, client
{
    int k=i-myPow(2,rankit(i))+1;
    int d=myPow(2,n);
    for (int a=2; a<myPow(2,rankit(i)+1); a=a*2)
    {
        if (j%a==k%a)
        {
            d=d/2;
        }
    }
//max(d,rankit(i))
    return d;
}
//TREETEST
int  treetest(int essais)
{
    const int sizemax=100;
    int compteur = 2;
    int niveau = 2;
    float a= 1;
    int valeurs[sizemax]  = { };
    for (int j=0; j<sizemax; j++)
    {
        valeurs[j]=0;
    }
    std::mt19937 mt(std::time(NULL));

    for (int i=0; i<essais; i++)
    {
    exponential_distribution<double> distribution(1);
        compteur =2;
        a=1;
        niveau=2;
        double clockinit=distribution(mt);

        while (compteur>0 and compteur <1000)
        {
            a= 1/((log (niveau))+1);

            for (int initial =compteur; initial >0; initial--)
            {
                double c=distribution(mt);
              std::cout <<c<< " , " << a << " , " << compteur << " , " << initial << clockinit<<'\n';
                if (c>clockinit/a)
                {
                    ++compteur;
                }
                else
                {
                    --compteur;
                }

            }

            niveau++;
            if (compteur>1) niveau=sizemax;
        }
        for (int j=0; j<niveau; j++)
        {
            valeurs[j]++;
        }
    }
    std::cout << '\n';
    for (int j=0; j<(sizemax); j=j+5)
        std::cout <<  valeurs[j] << " , " << valeurs[j+1]<< " , " << valeurs[j+2]<< " , " << valeurs[j+3]<< " , " << valeurs[j+4] << '\n';


    return 0;
}
void treetest2(){

{{
     std::srand(std::time(NULL)); // outside the loop

     for(int n=0; n<15; ++n)
         std::cout << rand()%64 << ' ';
     std::cout << '\n';
}
}}

//                                                                          TESTS
/*
    std::cout << "facilities contains:";
  std::cout << '\n';
  for (int i=0; i<(m-1); ++i)
    std::cout << "(" << facilities[i].number << "," << facilities[i].order << "," <<  facilities[i].target << ',' << facilities[i].chosen << ',' << facilities[i].radius << ")";
  std::cout << '\n';
     std::cout << "clients contains:";
  std::cout << '\n';
  for (int i=0; i<(m); ++i)
    std::cout << "(" << clients[i].number << "," << clients[i].order << "," << clients[i].target << ") ";
  std::cout << '\n';

  std::cout << '\n';

  std::cout << "permvectorf contains:";
  for (std::vector<int>::iterator it=permvectorf.begin(); it!=permvectorf.end(); ++it)
    std::cout << ' ' << *it;
*/
