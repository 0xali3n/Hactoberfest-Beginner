import java.util.Scanner;
import java.util.HashSet;

class longConsecutiveSubseq{

static int findLongestConseqSubseq(int arr[], int N){
	HashSet<Integer> st = new HashSet<>();
	for(int x : arr){
	    st.add(x);
	}
	int res = 0;
	int count = 0;
	for(int i=0;i<N;i++){
	    if(st.contains(arr[i]-1) == false){
	        //reset count for every new element found
	        count=1;
	        while(st.contains(arr[i]+count)){
	            // arr[i] is fixed so add 'count' to find sub-sequences
	            count++;
	        }
	        res = Math.max(res,count);
	    }
	}
	return res;
}

public static void main(String[]args){

    Scanner sc = new Scanner(System.in);
    System.out.println("Enter size of array ");
    int n = sc.nextInt();
    int []arr = new int[n];
    System.out.println("Enter array elements ");
    for(int i=0;i<n;i++){
        arr[i] = sc.nextInt();
    }

    System.out.println(findLongestConseqSubseq(arr,n) + " is the longest count");
    
}
}