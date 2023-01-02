class Solution {
    public boolean detectCapitalUse(String word) {
        int n=word.length();
        if(n==1)return true;
        int flag=0;
        if(Character.isUpperCase(word.charAt(n-1))){
            flag=1;
        }
        for(int i=n-2;i>0;i--){
            if(flag==1){
                if(!Character.isUpperCase(word.charAt(i)))return false;
            }
            if(flag==0){
                if(!Character.isLowerCase(word.charAt(i)))return false;
            }
        }
        if(flag==1){
            if(!Character.isUpperCase(word.charAt(0)))return false;
        }
        return true;
    }
}