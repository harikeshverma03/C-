#include<iostream>
using namespace std;
struct Array{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr){
    int i;
    cout << "Elements are" << endl;
    for (int i = 0; i < arr.length; i++)
        cout << arr.A[i] << " ";
    cout << endl;;
}

void Append(struct Array *arr, int x){
    if (arr->length < arr->size)
        arr->A [arr->length++] = x;
}

void Insert(struct Array *arr, int index, int value){
    if (index >= 0 && index < arr->length){
        for (int i = arr->length; i > index; i--)
            arr->A[i] = arr->A[i-1];
    }
    arr->A[index] = value;
    arr->length++;
}

int Delete(struct Array *arr, int index){
    int x = arr->A[index];
    if(index < arr->length){
        for (int i = index; i < arr->length; i++)
            arr->A[i] = arr->A[i+1];
        arr->length--;
    }
    return x;
}
void swap(int*x, int*y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int LinearSearch(struct Array *arr, int key){
    for(int i = 0; i < arr->length; i++){
        if(arr->A[i] == key){
            swap(&arr->A[i], &arr->A[i-1]);
            return i-1;
        }
    }
    return -1;
}

int BinarySearch(struct Array arr, int key){
    int l = 0; int h = arr.length-1;
    int mid;
    while(l <=h){
        mid = (l+h)/2;
        if(key == arr.A[mid])
            return mid;
        else if(key > arr.A[mid])
            l = mid+1;
        else
            h = mid-1; 
    }  
    return -1; 
}

int RBinarySearch(int arr[],int h, int l, int key){
    int mid;
    if(l <=h){
        mid = (l+h)/2;
        if(key == arr[mid])
            return mid;
        else if(key > arr[mid])
            return(RBinarySearch(arr,h,mid+1,key));
        else
            return(RBinarySearch(arr,mid-1,l,key));
    }  
    return -1; 
}

int Get(struct Array arr, int index){
    if(index >=0 && index <= arr.length)
        return arr.A[index];
    return -1;
}

void Set(struct Array *arr, int index, int x){
    if(index >=0 && index <= arr->length)
        arr->A[index] =  x;
}
int Max(struct Array arr){
    int max = arr.A[0];
    for(int i = 1; i < arr.length; i++){
        if(arr.A[i] > max)
            max = arr.A[i];
    }
    return max;
}

int Min(struct Array arr){
    int min = arr.A[0];
    for(int i = 1; i < arr.length; i++){
        if(arr.A[i] < min)
            min = arr.A[i];
    }
    return min;
}

int Sum(struct Array arr){
    int sum = arr.A[0];
    for(int i = 1; i < arr.length; i++)
        sum = sum + arr.A[i];
    return sum;
}
int Avg(struct Array arr){
    return (Sum(arr)/arr.length);
}

void Reverse(struct Array *arr){
    for(int i = 0, j = arr->length-1; i < j; i++,j-- ){
        int temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
}
void Lshift(struct Array *arr){
    for(int i = 0; i < arr->length-1; i++){
        arr->A[i] = arr->A[i+1];
    }
    arr->length--;

}
void InsertSort(struct Array *arr, int x){
    if(arr->size == arr->length){
        return;
    }
    int i = arr->length - 1;
    for(; i > 0 && x < arr->A[i]; i--){
        arr->A[i+1] = arr->A[i];
    }
    arr->A[i+1] = x;
    arr->length++; 
}
int isSorted(struct Array arr){
    int i = 0;
    while(i < arr.length - 1){
        if(arr.A[i] > arr.A[i+1]){
            return -1;
        }
        i++;
    }
    return 0;
}
void ReArrange(struct Array *arr){
    int i = 0, j = arr->length -1;
    while(i < j){
        while(arr->A[i] > 0){i++;}
        while(arr->A[j] < 0){j--;}
        if(i < j){
            swap(&arr->A[i], &arr->A[j]);
        }
    }

}
struct Array* Merge(struct Array *arr1, struct Array *arr2){
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = new struct Array;            //To create some space in heap using int 
    while(i < arr1->length && j < arr2->length){
        if(arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else   
            arr3->A[k++] = arr2->A[j++];
    }
    for(; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for(; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    
    arr3->length = arr1->length + arr2->length;
    arr3->size = arr1->size + arr2->size;

    return arr3;
}

struct Array* UnionS(struct Array *arr1, struct Array *arr2){
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = new struct Array;            //To create some space in heap using int 
    while(i < arr1->length && j < arr2->length){
        if(arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
            
        else if(arr1->A[i] == arr2->A[j]){
            arr3->A[k++] = arr2->A[j++];
            i++;
        }
        else  
            arr3->A[k++] = arr2->A[j++];
    }
    for(; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for(; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    
    arr3->length = k;
    arr3->size = arr1->size + arr2->size;

    return arr3;
}

struct Array* IntersectionS(struct Array *arr1, struct Array *arr2){
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = new struct Array;            //To create some space in heap using int 
    while(i < arr1->length && j < arr2->length){
        if(arr1->A[i] < arr2->A[j])
            i++;
        else if(arr1->A[i] == arr2->A[j]){
            arr3->A[k++] = arr2->A[j++];
            i++;
        }
        else   
            j++;
    }
    // for(; i < arr1->length; i++)
    //     arr3->A[k++] = arr1->A[i];
    // for(; j < arr2->length; j++)
    //     arr3->A[k++] = arr2->A[j];
    
    arr3->length = k;
    arr3->size = arr1->size + arr2->size;

    return arr3;
}

struct Array* DifferenceS(struct Array *arr1, struct Array *arr2){
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = new struct Array;            //To create some space in heap using int 
    while(i < arr1->length && j < arr2->length){
        if(arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];

        else if(arr1->A[i] == arr2->A[j]){
            j++;
            i++;
        }

        else   
            j++;
    }
    for(; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    
    
    arr3->length = k;
    arr3->size = arr1->size + arr2->size;

    return arr3;
}
int main(){
    struct Array arr = {{2,-3,4,-12,7,-10},20,6};
    struct Array arr1 = {{2,6,10,15,25},10,5};
    struct Array arr2 = {{3,6,7,15,20},10,5};
    struct Array *arr3;
    //Append(&arr, 10);
    //Insert(&arr,3,10);
    //cout << Delete(&arr,2) << endl;
    //int x;
    //cin >> x;
    //cout << "The Sum " << x << " is present at " << Get(arr,x) << endl;
    Display(arr1);
    Display(arr2);
    cout << "The Merged Array ";
    //Lshift(&arr);
    //InsertSort(&arr,6);
    //cout << isSorted(arr) << endl;
    arr3 = Merge(&arr1, &arr2);
    Display(*arr3);
    arr3 = UnionS(&arr1, &arr2);
    Display(*arr3);
    arr3 = IntersectionS(&arr1, &arr2);
    Display(*arr3);
    arr3 = DifferenceS(&arr1, &arr2);
    Display(*arr3);
    return 0;
}