class Solution {
public:
	bool Find(int target, vector<vector<int>> array)
	{

		int i = 0;
		int j = array[0].size() - 1;
		while (i < array.size() && j >= 0)
		{
			if (target < array[i][j]){ //array[i][j]一定是当前行大的，当前列小的  
				//target < array[i][j] 排除当前列    
				j--;


			}
			else if (target > array[i][j])
			{ 
				//target > array[i][j] 排除当前行    
				i++;
			}
			else{
				//找到            
				return true;
			}
		}
		return false;
	}
};
