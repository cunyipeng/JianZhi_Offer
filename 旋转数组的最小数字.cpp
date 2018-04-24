class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size()==0)
            return 0;
        int left = 0;
        int right = rotateArray.size()-1;
        
        for(int i = 0; i < rotateArray.size(); i++){
            if(rotateArray[i] > rotateArray[i+1])
                return rotateArray[i+1];
        }
        return rotateArray[0];
    }
};


/*
class Solution {
public:
    int minNumberInRotateArray(vector<int> arr) {
        if(arr.size()==0)
            return 0;
        int index1 = 0;
        int index2 = arr.size()-1;
        int middle = index1;
        
        while(arr[index1] >= arr[index2]){
            if(index2 - index1 == 1){
                  middle = index2;
                  break;
            }
            middle = (index1 + index2) / 2;
            if(arr[middle] == arr[index1] && arr[index1] == arr[index2])
                return MinInOrder(arr, index1, index2);
            if(arr[middle] >= arr[index1])
                index1 = middle;
            if(arr[middle] <= arr[index2])
                index2 = middle;
        }
        
        return arr[middle];
    }
    
    int MinInOrder(vector<int> &arr, int index1, int index2){
        int result = arr[index1];
        for(int i = index1 + 1; i <= index2; i++){
            if(result > arr[i])
                result = arr[i];
        }
        return result;
    }
};
*/
