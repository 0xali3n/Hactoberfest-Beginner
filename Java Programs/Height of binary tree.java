class Solution {
    int height(Node node) 
    {
        if(node==null) return 0;
        if(node.left==null&&node.right==null) return 1;
        return Math.max(height(node.left),height(node.right))+1;
    }
}
