#include <iostream>
#include "generate.h"
#include "sortfunction.h"
using namespace std;

int data_size[] = {3000, 10000, 30000, 100000, 300000};
string algo[] = {"Selection_Sort", "Insertion_Sort","Bubble_Sort","Heap_Sort","Merge_Sort","Quick_Sort","Radix_Sort","Shaker_Sort",
"Shell_Sort","Counting_Sort","Flash_Sort","Binary_Insertion_Sort"};

string check_data(int a[],int n){
     for (int i=0; i<n-1; i++)
          if (a[i] > a[i+1])
               return to_string(i);

     return "True";

}

string check_heap(int a[],int n){
     a[n+1] = 2000000000;
     for (int i=0; i<(n-1)/2; i++)
          if (a[i] > a[i*2+1] && a[i] > a[i*2+2]) return "False";
     return "True";

}

void test_algorithm(int type,int order){
     int a[300000+1];
          cout << algo[type] << ',';
          for (int dsize=0; dsize <5; dsize++){
               GenerateData(a,data_size[dsize], order);
               switch (type){
                    case 0:
                         cout <<  Selection_Sort(a,data_size[dsize]) ;
                         break;
                    case 1:
                         cout  << Insertion_Sort(a,data_size[dsize]) ;
                         break;
                    case 2:
                         cout  << Bubble_Sort(a,data_size[dsize]) ;
                         break;
                    case 3:
                         cout  << Heap_sort(a,data_size[dsize]);
                         break;
                    case 4:
                         cout  << Merge_Sort(a,data_size[dsize]) ;
                         break;
                    case 5:
                         cout  << Quick_Sort(a,data_size[dsize]) ;
                         break;
                    case 6:
                         cout << Radix_Sort(a,data_size[dsize]) ;
                         break;
                    case 7:
                         cout << Shaker_Sort(a,data_size[dsize]) ;
                         break;
                    case 8:
                         cout << Shell_Sort(a,data_size[dsize]) ;
                         break;
                    case 9:
                         cout << Count_Sort(a,data_size[dsize]) ;
                         break;
                    case 10:
                         cout << Flash_Sort(a,data_size[dsize]) ;
                         break;
                    case 11:
                         cout << Binary_Insertion_Sort(a,data_size[dsize]);
                         break;

               }
               cout << ',';
          }
          cout << '\n';

}

int main()
{
    // freopen("out.out","w",stdout);
     int a[10001];
     GenerateData(a,20, 0);
     cout << Flash_Sort(a,20) << '\n';
     cout << check_data(a,20) << '\n';

//     cout << "size,300,10000,30000,100000,300000\n";
//     for (int order=0; order<4; order++)
//     {
//          for (int i=11; i<12; i++)
//               test_algorithm(i,order);
//          cout << '\n';
//     }



    return 0;
}
