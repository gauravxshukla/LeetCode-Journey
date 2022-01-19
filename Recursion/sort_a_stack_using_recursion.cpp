#include<bits/stdc++.h>
using namespace std;

    void push(vector<int>& arr,int val,int top){
        //Base Condition - If there is no element in the array, we will directly insert an element.
        // If the value is greater than the top value it means
        //it is already sorted and we just have to insert our element, right?
        if(top==-1 || arr[top]<=val){
            arr.push_back(val);
            top++;
            return;
        }

        //Hypothesis - We are making input small and refining the value of our push function.
        //If the base condition is not working, it surely means the value is less than the top,
        // So, removing an element and pushing the value again and calling the function.
        int temp=arr[top];
        arr.pop_back();
        top--;
        push(arr,val,top);

        //Induction - Where the magic or calculation happens
        // We did remove a value above right?
        //Now, we do have to insert it again, right bro?
        //Well, We are doing it here.
        arr.push_back(temp);
        top++;
        return;

    }

    void sortstack(vector<int>& arr, int top){
        //Base Condition - Top =0 (It means stack has only one element, which essentially means it is sorted.)
        if(top==0){
            return;
        }

        //Hypothesis - Removing a value out of the array and defining the sortstack() function
        // to smaller input since we removed one element
        int val=arr[top];
        arr.pop_back();
        top--;
        sortstack(arr,top);

        // Induction - The place where the magic happens or calculation
        //Push function inserts the element at the same time, 
        //it inserts at the right position in terms of sorting.
        push(arr,val,top);
        top++;
        return;
    }



int main(){
        vector<int> arr={6,5,2,3,4,1};
        sortstack(arr,arr.size()-1);
        cout<<arr.size()<<endl;
        for(int i=0;i<arr.size();i++) cout<<arr[i]<<" ";

    return 0;
}