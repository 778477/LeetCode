
//	Accepted	4 ms	c
bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int left = 0,right = matrixColSize * matrixRowSize - 1;
    
    
    while(left <= right){
        int mid = left + ((right - left)>>1);
        int row = mid/matrixColSize;
        int col = mid%matrixColSize;
        if(matrix[row][col] == target) return true;
        else if(matrix[row][col] > target){
            right = mid - 1;
        }
        else{
            left = mid+1;
        }
    }
    
    return false;
}
