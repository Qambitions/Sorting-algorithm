#include <bits/stdc++.h>
#include <time.h>
using namespace std;

double Selection_Sort(int a[], int n){
     clock_t start = clock();
     for (int i=0; i<n-1; i++)
          for (int j=i+1; j<n; j++)
               if (a[i] > a[j])
                    swap(a[i],a[j]);;
     return (double)(clock() - start)/CLOCKS_PER_SEC;
}

double Insertion_Sort(int a[], int n){
     clock_t start = clock();
     for (int i=1; i<n; i++){
          int key = a[i];
          int j = i-1;
          while (j >= 0 && a[j] > key){
               a[j+1] = a[j];
               j--;
          }
          a[j+1] = key;
     }
     return (double)(clock() - start)/CLOCKS_PER_SEC;
}

double Bubble_Sort(int a[], int n){
     clock_t start = clock();
     for (int i=0; i<n-1; i++)
          for (int j=0; j<n-i-1; j++)
               if (a[j] > a[j+1])
                    swap(a[j],a[j+1]);
     return (double)(clock() - start)/CLOCKS_PER_SEC;
}

void down_heap(int a[],int n,int k)
{
     int j = k;
     while (2*k+1 < n){
          j = 2*k+1;
          if (j+1 < n && a[j] > a[j+1])
               j++;
          if (a[k] > a[j]){
               swap(a[k],a[j]);
               k = j;
          }
          else break;
     }
}

double Heap_sort(int a[], int n){
     clock_t start = clock();
     int i = (n-1)/2;
     while (i>=0){
          down_heap(a,n,i);
          i--;
     }
     return (double)(clock() - start)/CLOCKS_PER_SEC;
}

void do_merge(int a[], int l, int r){
     if (l==r) return;

     do_merge(a,l,(l+r)/2);
     do_merge(a,(l+r)/2+1,r);
     int *b, n=0;
     b = new int[r-l+1];
     int j = (l+r)/2+1; int i= l;
     while (i<=(l+r)/2 || j<=r){
          int key=0;
          if (i > (l+r)/2) key = a[j++];
          else if (j > r) key = a[i++];
          else if (a[i] <= a[j]) key = a[i++];
          else if (a[i] > a[j]) key = a[j++];
          b[n++] = key;
     }

     for (int t=l; t<=r;t++)
          a[t] = b[t-l];
     delete []b;
}

double Merge_Sort(int a[], int n){
     clock_t start = clock();
     do_merge(a,0,n-1);
     return (double)(clock() - start)/CLOCKS_PER_SEC;
}

void do_quicksort(int a[],int l, int r)
{
     int i = l, j = r;
     int pivot = a[rand()%(r-l) + l];
     do{
          while (a[i] < pivot) i++;
          while (a[j] > pivot) j--;
          if (i<=j)
               swap(a[i++],a[j--]);
     }while (i<=j);
     if (i<r) do_quicksort(a,i,r);
     if (l<j) do_quicksort(a,l,j);
}

double Quick_Sort(int a[], int n){
     clock_t start = clock();
     do_quicksort(a,0,n-1);
     return (double)(clock() - start)/CLOCKS_PER_SEC;
}

void do_radix(int a[], int n, int p){
     vector <int> num[10];
     for (int i=0; i<10; i++) num[i].clear();
     for (int i=0; i<n; i++)
          num[(a[i]/p) %10].push_back(a[i]);
     n=0;
     for (int i=0; i<10; i++)
          for (int j=0; j<num[i].size(); j++)
               a[n++] = num[i][j];
}

double Radix_Sort(int a[], int n){
     clock_t start = clock();

     int num = 0;
     for (int i=0; i<n; i++)
          num = max(num,a[i]);
     int p=1;
     for (int i=0; i<(int)log10(num) + 1; i++)
     {
          do_radix(a,n,p);
          p*=10;
     }

     return (double)(clock() - start)/CLOCKS_PER_SEC;
}

double Shaker_Sort(int a[], int n) //https://www.stdio.vn/giai-thuat-lap-trinh/bubble-sort-va-shaker-sort-01Si3U
{
     clock_t start = clock();
	int Left = 0;
	int Right = n - 1;
	int k = 0;
	while (Left < Right){
		for (int i = Left; i < Right; i++){
			if (a[i] > a[i + 1]){
				swap(a[i], a[i + 1]);
				k = i;
			}
		}
		Right = k;
		for (int i = Right; i > Left; i--){
			if (a[i] < a[i - 1]){
				swap(a[i], a[i - 1]);
				k = i;
			}
		}
		Left = k;
	}
	return (double)(clock() - start)/CLOCKS_PER_SEC;
}

double Shell_Sort(int a[], int n){
     clock_t start = clock();
    for (int gap = n/2; gap > 0; gap /= 2)
        for (int i = gap; i < n; i += 1)
        {
            int temp = a[i];
            int j;
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
                a[j] = a[j - gap];
            a[j] = temp;
        }

     return (double)(clock() - start)/CLOCKS_PER_SEC;
}

double Count_Sort(int a[], int n){
     clock_t start = clock();

     int RANGE = 300000;
     vector <int> countt(RANGE);

     for (int i=0; i<n; i++)
          countt[a[i]]++;
     n=0;
     for (int i=0; i<RANGE; i++)
          while (countt[i]-- !=0 )
               a[n++] = i;
     countt.clear();
     return (double)(clock() - start)/CLOCKS_PER_SEC;
}

double Flash_Sort(int a[], int n){
     clock_t start = clock();
     int maxn = 0, minn = a[0];
     int m = 0.4*n;
     vector <int> l(m+1);
     //int l[m+1];
     for (int i=0; i<m+1; i++)
          l[i] = 0;
     for (int i=0; i<n; i++){
          minn = min(a[i],minn);
          if (a[i] > a[maxn])
               maxn = i;
     }
     if (minn == a[maxn]) return (double)(clock() - start)/CLOCKS_PER_SEC;

     double c1 = (double)(m-1)/(a[maxn] - minn);

     for (int j=0; j<n; j++){
          int k = floor(c1 * (a[j] - minn));
          l[k]++;
     }

     for (int j=1; j<m; j++)
          l[j] += l[j-1];


     swap(a[0],a[maxn]);

     int movee = 0, t, flash;
     int j = 0;
     int k = m - 1;

     while (movee < n) {
          while (j > l[k]) {
               ++j;
               k = floor(c1 * (a[j] - minn));
          }
          if (k < 0) break;
          flash = a[j];
          while (j <= l[k]) {
               k = floor(c1 * (flash - minn));
               int hold = a[l[k]-1];
               a[l[k]-1] = flash;
               l[k]--;
               flash = hold;
               ++movee;
        }
    }

     for (int i=1; i<n; i++){
          int key = a[i];
          int j = i-1;
          while (j >= 0 && a[j] > key){
               a[j+1] = a[j];
               j--;
          }
          a[j+1] = key;
     }
     l.clear();
     return (double)(clock() - start)/CLOCKS_PER_SEC;
}

int binarySearch(int a[], int item,int n)
{
     int l=-1;
     int r=n+1;
     while (r-l > 1){
          int m = (l+r)/2;
          if (a[m] <= item) l = m;
          else r = m;
     }
     return r;
}


double Binary_Insertion_Sort(int a[], int n)
{
     clock_t start = clock();
    int i, loc, j, k, selected;
    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        selected = a[i];
        loc = binarySearch(a, selected, j);
        while (j >= loc){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = selected;
    }
    return (double)(clock() - start)/CLOCKS_PER_SEC;
}
