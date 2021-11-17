// this program includes basic instruction on how to use classes in c++\
// replace all   length,   A,   size with length, A, size
#include<iostream>
using namespace std;
class Array{
    private:
        int *A;
        int size;
        int length;
        void swap(int*x, int*y);
    public:
        Array(){
            size = 10;
            length = 0;
            A = new int[size];
        }
        Array(int sz){
            size = sz;
            length = 0;
            A = new int[size];
        }
        ~Array(){
            delete []A;
        }
        void Display();
        void Append( int x);
        void Insert( int index, int value);
        int Delete(int index);
        
        int LinearSearch( int key);
        int BinarySearch( int key);
        //int RBinarySearch(int arr[],int h, int l, int key);
        int Get( int index);
        void Set( int index, int x);
        int Max();
        int Min();
        int Sum();
        int Avg();
        void Reverse();
        void Lshift();
        void InsertSort(int x);
        int isSorted();
        void ReArrange();
        Array* Merge(Array *arr2);
        Array* UnionS(Array *arr2);
        Array* IntersectionS(Array *arr2);
        Array* DifferenceS(Array *arr2);
};

void Array::Display(){
    int i;
    cout << "Elements are" << endl;
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << endl;;
}

void Array::Append(int x){
    if (length < size)
        A[length++] = x;
}

void Array::Insert(  int index, int value){
    if (index >= 0 && index <  length){
        for (int i =  length; i > index; i--)
             A[i] =  A[i-1];
    }
     A[index] = value;
     length++;
}

int Array::Delete( int index){
    int x =  A[index];
    if(index <  length){
        for (int i = index; i <  length; i++)
             A[i] =  A[i+1];
         length--;
    }
    return x;
}
void Array::swap(int*x, int*y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int Array::LinearSearch( int key){
    for(int i = 0; i <  length; i++){
        if( A[i] == key){
            swap(& A[i], & A[i-1]);
            return i-1;
        }
    }
    return -1;
}

int Array::BinarySearch( int key){
    int l = 0; int h =   length-1;
    int mid;
    while(l <=h){
        mid = (l+h)/2;
        if(key ==   A[mid])
            return mid;
        else if(key >   A[mid])
            l = mid+1;
        else
            h = mid-1; 
    }  
    return -1; 
}

int Array::Get( int index){
    if(index >=0 && index <=   length)
        return   A[index];
    return -1;
}

void Array::Set( int index, int x){
    if(index >=0 && index <=  length)
         A[index] =  x;
}
int Array::Max( ){
    int max =   A[0];
    for(int i = 1; i <   length; i++){
        if(  A[i] > max)
            max =   A[i];
    }
    return max;
}

int Array::Min( ){
    int min =   A[0];
    for(int i = 1; i <   length; i++){
        if(  A[i] < min)
            min =   A[i];
    }
    return min;
}

int Array::Sum( ){
    int sum =   A[0];
    for(int i = 1; i <   length; i++)
        sum = sum +   A[i];
    return sum;
}
int Array::Avg( ){
    return (Sum()/  length);
}

void Array::Reverse( ){
    for(int i = 0, j =  length-1; i < j; i++,j-- ){
        int temp =  A[i];
         A[i] =  A[j];
         A[j] = temp;
    }
}
void Array::Lshift( ){
    for(int i = 0; i <  length-1; i++){
         A[i] =  A[i+1];
    }
     length--;

}
void Array::InsertSort(int x){
    if( size ==  length){
        return;
    }
    int i =  length - 1;
    for(; i > 0 && x <  A[i]; i--){
         A[i+1] =  A[i];
    }
     A[i+1] = x;
     length++; 
}
int Array::isSorted( ){
    int i = 0;
    while(i <   length - 1){
        if(  A[i] >   A[i+1]){
            return -1;
        }
        i++;
    }
    return 0;
}
void Array::ReArrange( ){
    int i = 0, j =  length -1;
    while(i < j){
        while( A[i] > 0){i++;}
        while( A[j] < 0){j--;}
        if(i < j){
            swap(& A[i], & A[j]);
        }
    }

}
Array* Array:: Merge( Array *arr2){
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = new struct Array;            //To create some space in heap using int 
    while(i <   length && j < arr2->length){
        if(  A[i] < arr2->A[j])
            arr3->A[k++] =   A[i++];
        else   
            arr3->A[k++] = arr2->A[j++];
    }
    for(; i <   length; i++)
        arr3->A[k++] =   A[i];
    for(; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    
    arr3->length =   length + arr2->length;
    arr3->size =   size + arr2->size;

    return arr3;
}

Array* Array::UnionS(Array *arr2){
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = new struct Array;            //To create some space in heap using int 
    while(i <   length && j < arr2->length){
        if(  A[i] < arr2->A[j])
            arr3->A[k++] =   A[i++];
            
        else if(  A[i] == arr2->A[j]){
            arr3->A[k++] = arr2->A[j++];
            i++;
        }
        else  
            arr3->A[k++] = arr2->A[j++];
    }
    for(; i <   length; i++)
        arr3->A[k++] =   A[i];
    for(; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    
    arr3->length = k;
    arr3->size =   size + arr2->size;

    return arr3;
}

Array* Array::IntersectionS(Array *arr2){
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = new struct Array;            //To create some space in heap using int 
    while(i <   length && j < arr2->length){
        if(  A[i] < arr2->A[j])
            i++;
        else if(  A[i] == arr2->A[j]){
            arr3->A[k++] = arr2->A[j++];
            i++;
        }
        else   
            j++;
    }
    // for(; i <   length; i++)
    //     arr3->A[k++] =   A[i];
    // for(; j < arr2->length; j++)
    //     arr3->A[k++] = arr2->A[j];
    
    arr3->length = k;
    arr3->size =   size + arr2->size;

    return arr3;
}

Array* Array::DifferenceS(Array *arr2){
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = new struct Array;            //To create some space in heap using int 
    while(i <   length && j < arr2->length){
        if(  A[i] < arr2->A[j])
            arr3->A[k++] =   A[i++];

        else if(  A[i] == arr2->A[j]){
            j++;
            i++;
        }

        else   
            j++;
    }
    for(; i <   length; i++)
        arr3->A[k++] =   A[i];
    
    
    arr3->length = k;
    arr3->size =   size + arr2->size;

    return arr3;
}
int main(){
    Array *arr;
    cout << "Enter size of array" << endl;
    int temp;
    int x, index;
    cin >> temp;
    arr = new Array(temp);
    
    temp = 1;
        cout << "Menu" << endl;
        cout << "-1 End" << endl;
        cout << "1 Insert" << endl;
        cout << "2 Delete" << endl;
        cout << "3 Search" << endl;
        cout << "4 Sum" << endl;
        cout << "5 Display" << endl;
    while (temp > 0 ){
        cout << "Enter Your choice" << endl;
        cin >> temp;
        switch(temp){
            case -1:
            break;
            case 1: cout << "Enter an element and index" << endl;
            cin >> x >> index;
            arr->Insert(index,x);
            break;
            case 2:
            break;
            case 4: cout << "Sum of the elements are:" <<  arr->Sum() << endl; break;
            case 5:
            arr->Display();
            break;            
        }
    }
    
    

    //Append(&arr, 10);
    //Insert(&arr,3,10);
    //cout << Delete(&arr,2) << endl;
    //int x;
    //cin >> x;
    //cout << "The Sum " << x << " is present at " << Get(arr,x) << endl;
    // Display(arr1);
    // Display(arr2);
    //cout << "The Merged Array ";
    //Lshift(&arr);
    //InsertSort(&arr,6);
    //cout << isSorted(arr) << endl;
    // arr3 = Merge(&arr1, &arr2);
    //Display(*arr3); 
    //arr3 = UnionS(&arr1, &arr2);
    //Display(*arr3);
    //arr3 = IntersectionS(&arr1, &arr2);
    //Display(*arr3);
    //arr3 = DifferenceS(&arr1, &arr2);
    //Display(*arr3);
    return 0;
}