#include <iostream>
using namespace std;

double avg(int *arr, int size);

int main()
{
    int array[5] = {122, 35, 27, 235, 60};
    double avg_value;
    
    avg_value = avg(array,5);
    
    cout << "Avg value: "<<avg_value<<endl;
    return 0;
}

double avg(int *arr, int size)
{
    int i,sum = 0;
    double avg_value;
    for (i=0;i<size;i++)
    {
        sum += arr[i];
    }
    avg_value = double(sum)/size;
    return avg_value;

}
