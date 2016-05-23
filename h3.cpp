#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <iomanip>
#include <math.h> 
using namespace std;

// g++ -std=c++11 -Wall h3.cpp
// a < test-hw3.txt

struct Point
{
	double x, y, r;
	
	Point(double paramx, double paramy) : x(paramx), y(paramy) 
	{
		r = sqrt(x*x + y*y);
	}
	
	bool operator() (Point i,Point j) 
	{ 
		if(i.r != j.r)
		{
			return (i.r<j.r);
		}
		else if( i.x != j.x)
		{
			return (i.x < j.x);
		}
		else
		{
			return (i.y < j.y);
		}
	}
};

vector<Point> A;


void printArray()
{
	cout << showpos;
	for(int i = 0; i < (int)A.size(); i++)
	{
		//cout << A[i].r << "(" << A[i].x << ", " << A[i].y << ")" << endl;
		cout << A[i].x << " " << A[i].y << endl;
	}
	//cout << endl;
}

void bucketSort()
{
	int n = (int)A.size();
	
	vector<vector<Point>> B(A.size());
	
	vector<double> buckets;
	
	cout << setprecision(6) << fixed;
	
	// create buckets
	for (int i = 0; i < n; i++)
	{
		double g = (double)(i + 1)/(double)n;
		
		double radii = sqrt(g);
		
		//print radius
		cout << radii << endl;
		
		buckets.push_back(radii);		
	}
	
	
	
	// place items into buckets
	for(int i = 0; i < n; i++)
	{
		int k = floor((double)A[i].r * (double)n);
		B[k].push_back(A[i]);
	}
	
	// sort each bucket
	for(int p = 0; p < n; p++)
	{
		sort(B[p].begin(), B[p].end(), 
				[]( const Point &left, const Point &right )
						 { 
							if(left.r != right.r)
								return ( left.r < right.r ); 
							else if(left.x != right.x)
								return ( left.x < right.x ); 
							else
								return ( left.y < right.y ); 
						} );
	}
	
	// place back into vector A
	int k = 0;
	for(int i = 0; i < (int)A.size(); i++)
	{
		for(int j = 0; j < (int)B[i].size(); j++)
		{
			A[k] = B[i][j];
			k++;
		}
	}
}

int main()
{
	double numx, numy;
	while (cin >> numx >> numy)
	{
		A.push_back(Point(numx, numy));
	}
	
	bucketSort();
	
	printArray();
}