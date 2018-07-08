
#include <iostream>
#include<iostream>
#include<cstdlib>
using namespace std;



class Vector {
  private:
int* Liste;
int max_size;
int current_size;
public:
  
// Constructor
  
Vector() {
max_size = 10;
current_size = 0;
Liste = new int[max_size];

}
  
  
// create a new constructor
Vector(const Vector &new_vector)
{
max_size = 10;
current_size = new_vector.current_size;
Liste = new int[max_size];
for(int i = 0; i < current_size; i++)
Liste[i] = new_vector.Liste[i];
}
  

// copy the number of datum from the original  
Vector &operator = (const Vector &new_vector)
{
current_size = new_vector.current_size;		
for(int i = 0; i < current_size; i++)
Liste[i] = new_vector.Liste[i];
return *this;
}
  
  
bool operator < (const Vector &new_vector)
{
return current_size < new_vector.current_size;
}

  
bool operator == (const Vector &new_vector)
{
if(current_size == new_vector.current_size)
{
for(int i= 0; i < current_size; i++)
{
if(Liste[i] != new_vector.Liste[i])
return false;
}
return true;
}
else
return false;
}
  
  
Vector operator +(const Vector &new_vector)
{
Vector result;
int count, num1, num2;

if(current_size > new_vector.current_size)
count = current_size;
else
count = new_vector.current_size;
  
result.current_size = count;

for(int i = 0; i < count; i++)
{

if(i < current_size)
num1 = Liste[i];
else
num1 = 0;
  

if(i < new_vector.current_size)
num2 = new_vector.Liste[i];
else
num2 = 0;
result.Liste[i] = num1+num2;
}
return result;
}
  
friend ostream& operator << (ostream& out, const Vector &new_vector)
{
cout << "[";
if(new_vector.current_size > 0)
{
cout << new_vector.Liste[0] ;
for(int i = 0; i < new_vector.current_size - 1; i++)
cout << ", " << new_vector.Liste[i];
}
cout << "]";
return out;
}
  
int operator[](int index) const
{
return Liste[index];
}
  
int& operator[](int index)
{
return Liste[index];
}
  
Vector operator++(int ) 
{
Vector copy(*this); 
  
for(int i = 0; i < current_size; i++)
Liste[i]++;
  
return copy;
  
}
  
// Destructor  
~Vector() {
delete[]Liste;
}

  	// public implimentations	

void push_back(int datum) //push is adding datum
{
if(current_size < max_size)
{
Liste[current_size++] = datum;
}
}
  
void pop_back()
{
if(current_size > 0)
{
current_size--;
}
}
  
int &at(int value) // any changes down intmain will influence to datum in the func above.
{
return Liste[value];
}
  
void clear()
{
current_size = 0;   // cleans the entire array
}
  
int size()
{
return current_size;  // how many datum in the array
}
  
};

int arr[3][3] = {
	{0, 1, 2},
	{3, 4, 5},
	{6, 7, 8} 
};


int main()
{
	Vector m;
	
	for(int i = 0; i < 5; i++){
	
		m.push_back(1 + rand() % 100);
}
		
				
		
	
	cout << m.size();
	cout << m << endl;
	Vector n(m);
	
	cout << n << endl;
	
	n++;
	
	cout << n << endl;

	Vector o;

	o = m + n;
	
	cout << o << endl;
	
	cout << (o < m) << endl;
	
	cout << (n == m) << endl;
}
