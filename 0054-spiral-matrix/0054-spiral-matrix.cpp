class Solution
{
    public:
        vector<int> spiralOrder(vector<vector < int>> &matrix)
        {
           	//There is only one Aprroach which is the most optimal soltuion to this problem. 
           	//We will take 4 Pointers, which will be Left, Right, Bottom, Top. 
            /*
           Left Right
             |   | 
             *   *   
       Top-> 1 2 3
             4 5 6 
    Bottom-> 7 8 9  

  	//Now the "Top" Pointer will Point to the Top Left Element and Same will be the "Left" Pointer.
  	//Now the "Bottom" Pointer will point to the Bottom Left Element and the Right Pointer will Point to the Top Right Element. 

  	//Now we have to basically Print the Whole Boundary, in the Fashion of 
Top Row (Left to Right)->Right Most Column(Top to Bottom)->Bottom Most Row(Right to Left)->Left Most Column(Bottom to Top)
        */
            int n = matrix.size();
            int m = matrix[0].size();
            int top = 0, left = 0, bottom = n - 1, right = m - 1;
            vector<int> ans;

            while (top <= bottom and left <= right)
            {

               	//Case-1 : When we will iterate over the First Row, we will use a For Loop from Top to Right.
                for (int i = top; i <= right; i++)
                {
                    ans.push_back(matrix[top][i]);
                }
                top++;
               	//Case-2 : When we will iterate over the Right Most Column, we will use the For Loop from Top to Bottom
                for (int i = top; i <= bottom; i++)
                {
                    ans.push_back(matrix[i][right]);
                }
                right--;
                if (top <= bottom)
                {
                   	//Case-3 : When we will iterate over the Last Row, we will use the For Loop form Right to Left
                    for (int i = right; i >= left; i--)
                    {
                        ans.push_back(matrix[bottom][i]);
                    }
                    bottom--;
                }
                if (left <= right)
                {
                   	//Case-4 : When we williterate over the First or the Left Most Column, we will use the For Loop from Bottom to Top.
                    for (int i = bottom; i >= top; i--)
                    {
                        ans.push_back(matrix[i][left]);
                    }
                    left++;
                }
            }
            return ans;
        }
};