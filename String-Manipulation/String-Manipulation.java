
public class StringMan {
    
    public static void main(String[] args) {
        String str="This is a string for manipulation";
        StringBuffer str1= new StringBuffer(str);
    int count=0;
        for(int i=0;i<str1.length();i++){
            if(str1.charAt(i)=='i'){
                count++;
                str1.deleteCharAt(i);
            }
            
        }
        System.out.println(count);
            System.out.println(str1);
    }
}
